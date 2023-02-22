/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:46:34 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/21 11:45:50 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bon.h"

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	word_cp(const char *str, char c)
{
	int	cp;
	int	i;

	i = 0;
	cp = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			cp++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (cp);
}

char	*word(const char *s1, int *pos, char c)
{
	int		word_len;
	char	*str;
	int		i;

	word_len = 0;
	while (s1[*pos] == c)
		(*pos)++;
	i = *pos;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	str = malloc(sizeof(char) * (word_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[*pos] && s1[*pos] != c)
		str[i++] = s1[(*pos)++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		pos;
	int		cpp;
	int		i;

	pos = 0;
	i = 0;
	if (!s)
		return (NULL);
	cpp = word_cp(s, c);
	tab = malloc(sizeof(char *) * (cpp + 1));
	if (!tab)
		return (NULL);
	while (i < cpp)
	{
	tab[i] = word(s, &pos, c);
		if (!tab[i])
			return (free_tab(tab));
	i++;
	}
	tab[i] = 0;
	return (tab);
}
