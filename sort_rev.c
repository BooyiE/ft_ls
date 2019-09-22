/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:56:24 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/20 14:05:48 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_rev(t_list **head)
{
	t_list	*prev;
	t_list	*next;
	t_list	*current;

	prev = NULL;
	current = *head;
	next = current->next;
	while (current != NULL)
	{
		current->next = prev;
		prev = current;
		current = next;
		if (current != NULL)
			next = current->next;
	}
	*head = prev;
}
