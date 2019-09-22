/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filepath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:54:00 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/20 13:44:37 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*filepath(const char *path, const char *file)
{
	char tmp[1024];

	ft_strcpy(tmp, path);
	ft_strcat(tmp, "/");
	return (ft_strjoin(tmp, file));
}
