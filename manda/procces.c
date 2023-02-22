/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procces.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:43:37 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/20 17:49:12 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child(int *fd, t_pp *k, char **env)
{
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		er("");
	close(fd[1]);
	if (dup2(k->fin, 0) == -1)
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

void	parent(int *fd, t_pp *k, char **env)
{
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		er("");
	close(fd[0]);
	if (dup2(k->fout, 1) == -1)
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
	end_procc();
}
