/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesher_bon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:26:40 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/20 18:29:20 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bon.h"

void	child(int file, int *fd, t_pp *k, char **env)
{
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		er("");
	close(fd[1]);
	if (dup2(file, 0))
		er("");
	if (!*k->argf)
		end_proc();
	if (ft_strchr(k->argf[0], '/'))
	{
		execve(k->argf[0], k->argf, env);
		end_proc();
	}
	while (k->paths[k->i])
	{
		if (access(k->paths[k->i], F_OK) == 0)
		{
			k->ja = ft_strjoin("/", k->argf[0]);
			k->jb = ft_strjoin(k->paths[k->i], k->ja);
			free(k->ja);
			execve(k->jb, k->argf, env);
		}
		free(k->jb);
		(k->i)++;
	}
}

void	parent(int file, int *fd, t_pp *k, char **env)
{
	unlink("temp");
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		er("");
	close(fd[0]);
	if (dup2(file, 1) == -1)
		er("");
	if (!*k->args)
		end_proc();
	if (ft_strchr(k->args[0], '/'))
	{
		execve(k->args[0], k->args, env);
		end_proc();
	}
	while (k->paths[k->i])
	{
		if (access(k->paths[k->i], F_OK) == 0)
		{
			k->ja = ft_strjoin("/", k->args[0]);
			k->jb = ft_strjoin(k->paths[k->i], k->ja);
			execve(k->jb, k->args, env);
		}
		(k->i)++;
	}
	end_proc();
}
