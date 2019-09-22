/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:55:04 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/20 14:09:31 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	recurse(char *basepath, char *filename, flags *flag)
{
	char *name;

	name = NULL;
	if (filename[0] != '.' || flag->a)
	{
		name = filepath(basepath, filename);
		ft_putendl("");
		ft_putstr(name);
		ft_putendl(":");
		ft_rec(name, flag);
		free(name);
	}
}

void		ft_rec(char *basepath, flags *flag)
{
	t_list	*files;
	t_list	*file;

	files = create_list(basepath);
	sort_alpha(&files);
	if (flag->t)
		sort_t(&files);
	if (flag->r)
		sort_rev(&files);
	print(files, flag);
	if (flag->rec)
	{
		file = files;
		while (file)
		{
			if (S_ISDIR(file->fstat.st_mode) && ft_strcmp(file->name, ".")
					&& ft_strcmp(file->name, ".."))
				recurse(basepath, file->name, flag);
			file = file->next;
		}
	}
}
