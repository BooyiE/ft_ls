/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:55:04 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 15:53:32 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rec(char *basepath, flags *flag)
{
	t_list	*files;
	t_list	*file;

	files = create_list(basepath);
	file = files;
	sort_alpha(&files);
	if (flag->t)
		sort_t(&files);
	if (flag->r)
		//sort_rev(&files);
		ft_putendl("reverse ........");

	print(files, flag);
	
	if (flag->R)
		while (file)
		{
			if (S_ISDIR(file->fstat.st_mode))
			{
				ft_putstr("recurse into ");
				ft_putendl(file->name);
			}
			file = file->next;
		}

}

