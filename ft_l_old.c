/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:07:08 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 14:10:31 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_l(const char *filename)
{
	t_list			*files;

	files = create_list(filename);
	sort_alpha(&files);
	print_list(files);
	ft_putstr("\n");
}
