/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:51:40 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 11:46:02 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i ;
	size_t	n ;

	i = 0;
	n = ft_strlen(s1) + 1;
	s2 = (char *)malloc(n);
	if (s2 == NULL)
		return (0);
	if (!s1 && !s2)
		return (0);
	while (n > 0)
	{
		s2[i] = s1[i];
		n--;
		i++;
	}
	return (s2);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	size_t	sa;
	size_t	sb;
	size_t	i;
	size_t	j;
	char	*rs;

	if (!s1)
		s1 = ft_strdup(s1);
	sa = ft_strlen(s1);
	sb = ft_strlen(s2);
	j = -1;
	rs = (char *)malloc(sizeof(char) * (sa + sb + 1));
	if (!rs)
		return (NULL);
	while (s1[++j] != '\0')
		rs[j] = s1[j];
	i = 0;
	while (s2[i] != '\0')
		rs[j++] = s2[i++];
	rs[j] = 0;
	return (rs);
}
