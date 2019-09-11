/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:53:21 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/11 13:15:21 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap(t_list **sp)
{
	t_list	*tmp;
	t_list	*tmp2;

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

void	sort_alpha(t_list **st)
{
	int		num;
	t_list	*tmp;

	tmp = *st;
	num = listlen(*st);
	while (num >= 0)
	{
		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			swap(st);
		while (tmp->next && tmp->next->next)
		{
			if (ft_strcmp(tmp->next->name, tmp->next->next->name) > 0)
				swap_next(tmp);
			tmp = tmp->next;
		}
		num--;
		tmp = *st;
	}
}
