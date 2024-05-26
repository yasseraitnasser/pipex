/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:50:59 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/10 17:04:20 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int argc, char **argv, char **env)
{
	char	*secure_path;

	if (argc != 5)
		ft_error("Bad argument set!\n");
	secure_path = get_secure_path(env);
	if (!secure_path)
		ft_error("Path not found!\n");
	child_processes(argv, env, secure_path);
	free(secure_path);
	return (0);
}
