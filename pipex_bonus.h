/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:14:22 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/11 00:43:49 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
char	*get_secure_path(char **env);
char	*get_path(char *secure_path, char **cmd_splited);
void	ft_error(char *error);
void	ft_perror(char *error);
void	free_one(char **ptr);
void	free_two(char **ptr1, char **ptr2);
void	free_three(char *ptr1, char **ptr2);
void	free_in_case(char **cmd1_splited, char *path, char *secure_path);
void	child_processes_bonus(int argc, char **argv, char **env, char *sec);
void	run_child_processses(int argc, char **av_env[2], int **fd, char *sec);
void	free_fd(int **fd, int argc);
void	last_child(int argc, char **av_env[2], int **fd, char *secure_path);
void	mid_child(char **av_env[2], int **fd, int i, char *secure_path);
int		how_many_args(char **argv);
void	first_child(int argc, char **av_env[2], int **fd, char *secure_path);
void	close_unneeded2(int **fd, int argc, int needed);
void	close_unneeded1(int **fd, int argc, int needed);
void	close_them_all(int **fd, int argc);
int		**prepare_pipe(int argc);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	here_doc(char **argv, char **env, char *secure_path);
void	child_process_here_doc(char **argv, int fd[2], char **env, char *sec);
void	child_p1(char **argv, int fd[4], char *secure_path, char **env);
void	child_p2(char **argv, int fd[4], char *secure_path, char **env);
void	execution(char *path, char **cmd_splited, char **env, char *sec);
void	dup_close1(char **av_env[2], int **fd, int argc, char *sec);
void	free_sec_fd_quit(int argc, char *sec, int **fd);
void	free_sec_fd_cmd_quit(int argc, char *sec, int **fd, char **cmd);
void	dup_close2(int **fd, int i, int argc);
void	dup_close3(char **av_env[2], int **fd, int argc, char *secure_path);
void	free_sec_quit(char *secure_path);
void	free_sec_cmd_quit(char *secure_path, char **cmd);
void	dup_close5(char **argv, int fd[4], char *secure_path);
void	dup_close4(int fd[4]);
void	keep_going(char *tmp1, char *limiter, int fd[2]);

#endif
