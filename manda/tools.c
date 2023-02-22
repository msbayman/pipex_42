/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:08:19 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 11:07:46 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	end_procc(void)
{
	write(2, "command not found\n", 18);
}

void	end_proc(void)
{
	write(2, "command not found\n", 18);
	exit(1);
}

void	er(char *s)
{
	perror(s);
	exit(1);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (1)
	{
		if (*str == (char)c)
			return (str);
		if (*str == 0)
			return (0);
		str++;
	}
	return (0);
}
