/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:30:44 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/11 22:16:44 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_secure_path(char **env)
{
	int		i;
	char	*result;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			result = ft_strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	if (!env[i])
		return (NULL);
	return (result);
}

char	*get_path(char *secure_path, char **cmd_splited)
{
	char	**paths;
	char	*result;
	int		i;

	i = 0;
	if (!access(*cmd_splited, F_OK | X_OK))
	{
		result = ft_strdup(*cmd_splited);
		return (result);
	}
	paths = ft_split(secure_path, ':');
	while (paths[i])
	{
		result = ft_strjoin3(paths[i], "/", *cmd_splited);
		if (!access(result, F_OK | X_OK))
			break ;
		free(result);
		i++;
	}
	if (!paths[i])
		return (free_one(paths), NULL);
	free_one(paths);
	return (result);
}

int	**prepare_pipe(int argc)
{
	int	**fd;
	int	i;

	fd = malloc((argc - 4) * sizeof(int *));
	if (!fd)
		ft_perror(NULL);
	i = 0;
	while (i < argc - 4)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (!fd[i])
			ft_perror(NULL);
		i++;
	}
	return (fd);
}

int	how_many_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	char	*secure_path;

	if (argc < 5)
		ft_error("Bad argument set!\n");
	secure_path = get_secure_path(env);
	if (!secure_path)
		ft_error("Path not found!\n");
	if (!ft_strcmp(argv[1], "here_doc") && argc == 6)
		here_doc(argv, env, secure_path);
	child_processes_bonus(argc, argv, env, secure_path);
	free(secure_path);
	return (0);
}
