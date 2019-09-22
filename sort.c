/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:53:21 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/20 14:04:07 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_alpha(t_list **st)
{
	int		num;
	t_list	*tmp;

	tmp = *st;
	num = listlen(tmp);
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
