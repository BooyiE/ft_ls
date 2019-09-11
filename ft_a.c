/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:18:59 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/11 16:54:11 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list(const char *filename)
{
	DIR				*dir;
	struct dirent	*dirp;

	filename = ".";
	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putstr("error");
		exit(1);
	}
	while ((dirp = readdir(dir)) && dirp != NULL)
	{
		ft_putstr(dirp->d_name);
		ft_putstr("\n");
	}
	ft_putstr("\n");
	closedir(dir);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_list(argv[1]);
	return (0);
}
