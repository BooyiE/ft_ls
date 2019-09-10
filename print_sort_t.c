/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:06:03 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/10 18:11:51 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_sort_t(t_list *list)
{
	while (list != NULL)
	{
		ft_putstr(list->name);
		ft_putstr("\n");
		list = list->next;
	}
}
