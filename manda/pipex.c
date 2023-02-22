/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:46:27 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/20 18:01:31 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execution(t_pp *k, char **env)
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
		child(fd, k, env);
		end_procc();
	}
	else
		parent(fd, k, env);
}

int	main(int ac, char **av, char **env)
{
	t_pp	k;

	if (!*env)
		er("no env");
	parsing(av, ac, &k);
	k.avin = av[1];
	k.avout = av[4];
	spath(env, &k);
	k.i = 0;
	k.fout = open(k.avout, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (k.fout < 0)
		perror("");
	k.fin = open(k.avin, O_RDONLY, 0666);
	if (k.fin < 0)
		perror("file not found");
	execution(&k, env);
}
