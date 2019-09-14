/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_-t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:38:00 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/11 13:35:49 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap(t_list **sp)
{
	t_list *tmp;
	t_list *tmp2;

	if (*sp)
	{
		tmp = *sp;
		if (tmp->next != NULL)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			tmp2->next = tmp;
			*sp = tmp2;
		}
	}
}

void	swap_next(t_list *sp)
{
	t_list *tmp;
	t_list *tmp2;

	if (sp && sp->next)
	{
		tmp = sp->next;
		if (tmp->next != NULL)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			tmp2->next = tmp;
			sp->next = tmp2;
		}
	}
}

int		listlen(t_list *list)
{
	int i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	sort_time(t_list **st)
{
	int		num;
	t_list	*tmp;

	tmp = *st;
	num = listlen(*st);
	while (num >= 0)
	{
		if (tmp->fstat.st_mtimespec.tv_sec <
				tmp->next->fstat.st_mtimespec.tv_sec)
			swap(st);
		while (tmp->next && tmp->next->next)
		{
			if (tmp->next->fstat.st_mtimespec.tv_sec <
					tmp->next->next->fstat.st_mtimespec.tv_sec)
				swap_next(tmp);
			tmp = tmp->next;
		}
		num--;
		tmp = *st;
	}
}

void	read_file(const char *filename)
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
	sort_time(&files);
	print_sort_t(files);
	ft_putstr("\n");
	closedir(dir);
}

int		main(int argc, char **argv)
{
	read_files(argv[1]);
	if (argc != 2)
		return (1);
	return (0);
}
