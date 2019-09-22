/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:52:28 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/19 18:13:18 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_node_to_list(t_list **list, t_list *node)
{
	t_list *tmp;

	if (list != NULL)
	{
		tmp = *list;
		node->next = tmp;
		*list = node;
	}
}
