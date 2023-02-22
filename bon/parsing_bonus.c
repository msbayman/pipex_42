/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:37:06 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 13:47:27 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bon.h"

void	pars_help(t_pp *k, int ac, char **av)
{
	k->fin = open("temp", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (k->fin < 0)
		perror("");
	k->fout = open(k->av[ac - 1], O_RDWR | O_CREAT, 0666);
	if (k->fout < 0)
		perror("");
	k->limit = av[2];
	k->argf = ft_split(av[3], ' ');
	k->args = ft_split(av[4], ' ');
}

void	executionher(t_pp *k, char **env)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		er("");
	id = fork();
	if (id == -1)
		er("");
	if (id == 0)
	{
		child(k->fin, fd, k, env);
		write(2, "command not found\n", 18);
		exit(1);
	}
	else
	{
		parent(k->fout, fd, k, env);
		exit(1);
	}
}

int	break_loop(char *str, char *limit)
{
	if (ft_strlen(limit) == ft_strlen(str) - 1
		&& !(ft_strncmp(str, limit, ft_strlen(limit))))
	{
		free(str);
		return (1);
	}
	return (0);
}

void	parsing_bon(char **av, int ac, t_pp *k, char **env)
{
	char	*str;

	if (ac < 5)
		er("wrong args\n");
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) && ac == 6)
	{
		pars_help(k, ac, av);
		while (1)
		{
			str = get_next_line(0);
			if (!str)
				break ;
			if (break_loop(str, k->limit))
				break ;
			write(k->fin, str, ft_strlen(str));
			free(str);
		}
		close(k->fin);
		k->fin = open("temp", O_RDWR);
		if (!k->fin)
			perror("");
		executionher(k, env);
	}
}

void	spath_bon(char **env, t_pp *k)
{
	int	i;

	if (!*env)
		er("no env");
	i = 0;
	k->paths = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			k->paths = ft_split(env[i] + 5, ':');
		i++;
	}
	if (!(k->paths))
		er("PATH");
}
