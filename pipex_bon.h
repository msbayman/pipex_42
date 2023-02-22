/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bon.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:40:59 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/22 11:58:26 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BON_H
# define PIPEX_BON_H

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
	char			*limit;
	int				i;
	char			**env;
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
void	parent(int file, int *fd, t_pp *k, char **env);
void	child(int file, int *fd, t_pp *k, char **env);
void	parsing_bon(char **av, int ac, t_pp *k, char **env);
void	spath_bon(char **env, t_pp *k);
void	child_bon(int *fd, t_pp *k, char **env);
void	parent_bon(int *fd, t_pp *k, char **env);
void	mproc_bon(int *fd, t_pp *k, char **env, int i);
char	*get_next_line(int fd);
size_t	ft_strlenn( const char *c);
char	*ft_strdup(char *s1);
char	*ft_strjoinn(char	*s1, char	*s2);
char	*ft_substr(char	*s, unsigned int start, size_t len);
#endif