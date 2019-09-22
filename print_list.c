/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:52:46 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/22 13:45:14 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	total(t_list *list, t_flags *flag)
{
	int sum;

	sum = 0;
	while (list)
	{
		if (list->name[0] != '.' || flag->a)
			sum = sum + list->fstat.st_blocks;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(sum);
	ft_putendl("");
}

static void	p_mode(t_list *list)
{
	ft_putstr((S_ISDIR(list->fstat.st_mode)) ? "d" : "-");
	ft_putstr((list->fstat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((list->fstat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((list->fstat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((list->fstat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((list->fstat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((list->fstat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((list->fstat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((list->fstat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((list->fstat.st_mode & S_IXOTH) ? "x" : "-");
}

static void	p_others(t_list *list)
{
	ft_putstr("  ");
	ft_putnbr(list->fstat.st_nlink);
	ft_putstr("  ");
	ft_putstr(list->passwd);
	ft_putstr("  ");
	ft_putstr(list->group);
	ft_putstr("\t");
	ft_putnbr(list->fstat.st_size);
	ft_putstr("\t");
	ft_putstr(ft_strsub(ctime(&(list->fstat).st_mtime), 4, 12));
	ft_putstr("  ");
	ft_putstr(list->name);
	ft_putstr("\n");
}

void		print_list(t_list *list, t_flags *flag)
{
	total(list, flag);
	while (list != NULL)
	{
		if (flag->a)
		{
			p_mode(list);
			p_others(list);
		}
		else if (list->name[0] != '.')
		{
			p_mode(list);
			p_others(list);
		}
		list = list->next;
	}
}
