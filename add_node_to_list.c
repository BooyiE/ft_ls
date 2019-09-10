/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:52:28 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/10 18:14:25 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_node_to_list(t_list **list, t_list *node)
{
	t_list *tmp;

	if (list != NULL)
	{
		tmp = *list;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
		else
			*list = node;
	}
}
