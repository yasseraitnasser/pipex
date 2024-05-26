/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <yait-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:24:18 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/08 23:55:30 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		n;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	n = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc((n + 1) * sizeof(char));
	if (new_s == NULL)
		return (new_s);
	ft_strlcpy(new_s, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_s, s2, n + 1);
	return (new_s);
}
