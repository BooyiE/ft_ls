/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:09:01 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/19 18:18:03 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		listlen(t_list *list)
{
	int i;

	i = 0;
	if (list)
		while (list != NULL)
		{
			list = list->next;
			i++;
		}
	return (i);
}