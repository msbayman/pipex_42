/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:16:35 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 11:45:01 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bon.h"

size_t	ft_strlenn( const char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		return (0);
	}
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
	if (!s2)
		er("");
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

char	*ft_strjoinn(char	*s1, char	*s2)
{
	size_t	sa;
	size_t	sb;
	size_t	i;
	size_t	j;
	char	*rs;

	if (!s1)
		s1 = ft_strdup(s1);
	sa = ft_strlenn(s1);
	sb = ft_strlenn(s2);
	j = -1;
	rs = (char *)malloc(sizeof(char) * (sa + sb + 1));
	if (!rs)
		er("");
	while (s1[++j] != '\0')
		rs[j] = s1[j];
	i = 0;
	free(s1);
	while (s2[i] != '\0')
		rs[j++] = s2[i++];
	rs[j] = 0;
	return (rs);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlenn(s))
		return (ft_strdup(""));
	if (len >= ft_strlenn(&s[start]))
		len = ft_strlenn(&s[start]);
	str = (char *) malloc(len + 1);
	if (!str)
		er("");
	while (s[start] && j < len)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}
