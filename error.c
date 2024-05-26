/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:21:16 by yait-nas          #+#    #+#             */
/*   Updated: 2024/02/28 17:21:30 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}

void	ft_perror(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}
