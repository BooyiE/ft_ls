/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:18:59 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/19 17:58:31 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_a(t_list *file, flags *flag)
{
	while (file)
	{
		if (flag->a)
			ft_putendl(file->name);
		else if (file->name[0] != '.')
			ft_putendl(file->name);
		file = file->next;
	}
}
