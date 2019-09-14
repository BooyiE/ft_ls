/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:55:04 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/11 18:17:55 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_rec(char *basepath)
{
	char			*path;
	struct dirent	*dp;
	DIR				*dir;

	path = (char *)malloc(sizeof(char));
	dir = opendir(basepath);
	if (!dir)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name, "..") != 0)
			if (dp->d_name[0] != '.')
			{
				ft_putstr(dp->d_name);
				ft_putstr("\t");
				ft_strcpy(path, basepath);
				ft_putstr("\t");
				ft_strcat(path, "/");
				ft_putstr("\t");
				ft_strcat(path, dp->d_name);
				list_rec(path);
			}
		ft_putstr("\n");
		closedir(dir);
	}
}

int		main(void)
{
	char *path;

	path = ".";
	ft_putstr("\n");
	ft_putstr(path);
	list_rec("./");
	return (0);
}
