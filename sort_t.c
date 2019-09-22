/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:30:20 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/18 15:19:37 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
