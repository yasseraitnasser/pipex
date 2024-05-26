/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:14:22 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/10 23:58:52 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
char	*get_secure_path(char **env);
char	*get_path(char *secure_path, char **cmd_splited);
void	child_processes(char **argv, char **env, char *secure_path);
void	child_process1(int fd[4], char *secure_path, char **argv, char **env);
void	child_process2(int fd[4], char *secure_path, char **argv, char **env);
void	ft_error(char *error);
void	ft_perror(char *error);
void	free_one(char **ptr);
void	free_two(char **ptr1, char **ptr2);
void	free_three(char *ptr1, char **ptr2);
void	free_in_case(char **cmd1_splited, char *path, char *secure_path);
void	free_sec_quit(char *secure_path, char *str);
void	free_sec_cmd_quit(char *secure_path, char *str, char **cmd);
void	dup_close1(int fd[4], char *secure_path);
void	dup_close2(int fd[4]);

#endif
