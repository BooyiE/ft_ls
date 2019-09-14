/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:24 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 14:15:11 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*create_list(const char *filename)
{
	DIR				*dir;
	struct			dirent *dirp;
	struct			stat s;
	struct	passwd	*p;
	struct	group	*g;
	t_list			*files;
	t_list			*one_node;

	dir = opendir(filename);
	if (dir == NULL)
	{
		ft_putstr("error opening ");
		ft_putstr(filename);
		return(0);
	}
	while ((dirp = readdir(dir)) && dirp != NULL)
	{
		lstat(dirp->d_name, &s);
		p = getpwuid(s.st_uid);
		g = getgrgid(s.st_gid);
		one_node = node(dirp->d_name, s, p->pw_name, g->gr_name);
		add_node_to_list(&files, one_node);
	}
	closedir(dir);
	return (files);
}
