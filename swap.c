/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:07:53 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/18 15:08:24 by bphofuya         ###   ########.fr       */
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
