/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:57:58 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/11 18:31:25 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list(const char *filename)
{
	DIR				*dir;
	struct dirent	*dirp;
	struct stat		s;
	struct passwd	*p;
	struct group	*g;
	t_list			*files;
	t_list			*one_node;

	dir = opendir(filename);
	if (dir == NULL)
	{
		ft_putstr("error");
		exit(1);
	}
	while ((dirp = readdir(dir)) && dirp != NULL)
	{
		if (*dirp->d_name != '.')
		{
			lstat(dirp->d_name, &s);
			p = getpwuid(s.st_uid);
			g = getgrgid(s.st_gid);
			one_node = node(dirp->d_name, s, p->pw_name, g->gr_name);
			add_node_to_list(&files, one_node);
		}
	}
	sort_rev(&files);
	print_sort_t(files);
	ft_putstr("\n");
	closedir(dir);
}

int		main(int argc, char **argv)
{
	ft_list(argv[1]);
	if (argc != 2)
		return (1);
	return (0);
}
