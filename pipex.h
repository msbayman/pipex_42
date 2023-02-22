/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:45:18 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/20 16:41:37 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define _POSIX_SOURCE

# include<stddef.h>
# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdio.h> 
# include<string.h>
# include<fcntl.h>

typedef struct s_pp
{
	char			**argf;
	char			**args;
	char			**paths;
	int				fin;
	int				fout;
	char			*avin;
	char			*avout;
	char			*ja;
	char			*jb;
	int				ac;
	char			**av;
	int				i;
	int				cpp;
	int				*fd;
}	t_pp;

char	*ft_strjoin(char	*s1, char	*s2);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *c);
void	parsing(char **av, int ac, t_pp *k);
int		ft_strncmp(char *s1, char *s2, size_t n);

void	end_proc(void);
void	er(char *s);
char	*ft_strchr(char *s, int c);
void	spath(char **env, t_pp *k);
void	parent(int *fd, t_pp *k, char **env);
void	child(int *fd, t_pp *k, char **env);
void	parsing_bon(char **av, int ac, t_pp *k);
void	spath_bon(char **env, t_pp *k);
void	child_bon(int *fd, t_pp *k, char **env);
void	parent_bon(int *fd, t_pp *k, char **env);
void	mproc_bon(int *fd, t_pp *k, char **env, int i);
void	end_procc(void);

#endif
