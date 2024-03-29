/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:56:09 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/22 13:46:16 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print(t_list *files, t_flags *flag)
{
	if (flag->l)
		print_list(files, flag);
	else
		ft_a(files, flag);
}
