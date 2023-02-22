/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:50:19 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 12:59:11 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parsing(char **av, int ac, t_pp *k)
{
	if (ac != 5)
	{
		write(2, "args not 4\n", 12);
		exit(1);
	}
	k->argf = ft_split(av[2], ' ');
	k->args = ft_split(av[3], ' ');
}

void	spath(char **env, t_pp *k)
{
	int	i;

	i = 0;
	if (!*env)
		er("");
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			k->paths = ft_split(env[i] + 5, ':');
		i++;
	}
	if (!(k->paths))
		er("PATH");
}
