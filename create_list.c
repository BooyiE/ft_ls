/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:24 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/20 14:08:04 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		*error(const char *filename)
{
	ft_putstr("error opening ");
	ft_putstr(filename);
	return (NULL);
}

static	void	grp(struct stat s, char **grpname)
{
	struct group	*g;

	g = getgrgid(s.st_gid);
	if (g)
		*grpname = g->gr_name;
	else
		*grpname = ft_strdup("4000");
}

static	t_list	*do_some_stuff(DIR *dir, const char *filename)
{
	struct dirent	*dirp;
	struct stat		s;
	t_list			*files;
	char			*name;
	char			*grpname;

	files = NULL;
	while ((dirp = readdir(dir)) && dirp != NULL)
	{
		name = filepath(filename, dirp->d_name);
		lstat(name, &s);
		grp(s, &grpname);
		add_node_to_list(&files, node(dirp->d_name, s, grpname));
		free(name);
	}
	closedir(dir);
	return (files);
}

t_list			*create_list(const char *filename)
{
	DIR	*dir;

	dir = opendir(filename);
	if (dir == NULL)
		return (error(filename));
	return (do_some_stuff(dir, filename));
}
