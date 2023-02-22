/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:21:13 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 13:45:33 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bon.h"

void	exec(int i, t_pp *k, char **env)
{
	int		j;
	char	*path;
	char	*cmd;
	char	**s;

	j = -1;
	s = ft_split(k->av[2 + i], ' ');
	if (!*s)
		end_proc();
	if (ft_strchr(s[0], '/'))
	{
		execve(s[0], s, env);
		end_proc();
	}
	while (k->paths[++j])
	{
		path = ft_strjoin("/", s[0]);
		cmd = ft_strjoin(k->paths[j], path);
		if (access(cmd, F_OK) == 0)
			execve(cmd, s, env);
	}
	write(2, "command not found\n", 18);
}

void	fd_fun_help(int *fd, t_pp *k, int i)
{
	close(fd[0]);
	if (i == 0)
	{
		if (dup2(k->fin, 0) == -1)
			er("");
	}
	if (i == k->ac - 4)
	{
		if (dup2(k->fout, 1) == -1)
			er("");
	}
	else
	{
		if (dup2(fd[1], 1) == -1)
			er("");
	}
	close(fd[1]);
	close(fd[0]);
	exec(i, k, k->env);
	exit(1);
}

void	fd_fun(int *fd, int id, t_pp *k, int i)
{
	if (pipe(fd) == -1)
		er("");
	id = fork();
	if (id == -1)
		er("");
	if (id == 0)
		fd_fun_help(fd, k, i);
}

void	to_exec(t_pp *k, char **env)
{
	int	i;
	int	fd[2];
	int	id;
	int	c;

	k->env = env;
	i = -1;
	id = 0;
	k->fd = fd;
	while (++i < k->ac -3)
	{
		fd_fun(fd, id, k, i);
		if (dup2(fd[0], 0) == -1)
			er("");
		close(fd[1]);
		close(fd[0]);
	}
	while (wait(NULL) != -1)
		c = 1;
}

int	main(int ac, char **av, char **env)
{
	t_pp	k;

	k.ac = ac;
	k.av = av;
	spath_bon(env, &k);
	parsing_bon(av, ac, &k, env);
	k.avin = av[1];
	k.avout = av[ac - 1];
	k.fin = open(k.avin, O_RDONLY, 0666);
	k.fout = open(k.avout, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (k.fout < 0)
		perror("");
	if (k.fin < 0)
		perror("file not found");
	to_exec(&k, env);
}
