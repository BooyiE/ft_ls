/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:31:16 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 13:06:18 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

flags	*read_flags(int argc, char **argv)
{
	int i;
	int j;
	flags	*flag;

	i = 1;
	flag = (flags *)malloc(sizeof(flags) * 1);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			while(argv[i][j])
			{
				if (argv[i][j] == 'a')
					flag->a = 1;
				else if (argv[i][j] == 'l')
					flag->l = 1;
				else if (argv[i][j] == 't')
					flag->t = 1;
				else if (argv[i][j] == 'R')
					flag->R = 1;
				else if (argv[i][j] == 'r')
					flag->r = 1;
				else
					ft_putendl("wrong flag");
				j++;
			}
		}
		i++;
	}
	return (flag);
}
