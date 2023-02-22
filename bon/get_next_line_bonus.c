/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:05:58 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/13 16:51:02 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bon.h"

char	*linee(char *cont)
{
	int	i;

	i = 0;
	if (!cont)
		return (NULL);
	if (ft_strchr(cont, '\n'))
	{
		while (cont[i] != '\n')
			i++;
		cont = ft_substr(cont, 0, i + 1);
		return (cont);
	}
	return (cont);
}

char	*linee_next(char *cont)
{
	int		i;
	char	*temp;

	i = 0;
	if (!cont)
		return (NULL);
	if (ft_strchr(cont, '\n'))
	{
		while (cont[i] != '\n')
			i++;
		if (cont + i +1 == '\0')
		{
			free(cont);
			return (NULL);
		}
		temp = cont;
		temp = ft_strdup(&cont[i + 1]);
		free(cont);
		return (temp);
	}
	return (NULL);
}

int	readline(int fd, char **cont)
{
	char	*buffer;
	int		i;

	buffer = malloc(1 + 1);
	i = 1;
	while (i != 0 && (!ft_strchr(*cont, '\n')))
	{
		i = read(fd, buffer, 1);
		if (i == 0)
			return (free(buffer), i);
		buffer[i] = '\0';
		*cont = ft_strjoinn(*cont, buffer);
	}
	free(buffer);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*cont;
	char		*line;
	int			k;

	if (fd < 0 || 1 <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (cont == NULL)
		cont = ft_strdup("");
	k = readline(fd, &cont);
	if (k <= 0 && !*cont)
	{
		free (cont);
		cont = NULL;
		return (NULL);
	}
	if (*cont && !ft_strchr(cont, '\n'))
		return (line = cont, cont = NULL, line);
	line = linee(cont);
	cont = linee_next(cont);
	return (line);
}
