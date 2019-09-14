/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:30:20 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 15:43:29 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
static void	swap(t_list **sp)
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

static void	swap_next(t_list *sp)
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
static int		listlen(t_list *list)
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

void	sort_t(t_list **st)
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
