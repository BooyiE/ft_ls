/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:31:16 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/22 13:45:50 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	receive(int i, int j, char **argv, t_flags *flag)
{
	if (argv[i][j] == 'a')
		flag->a = 1;
	else if (argv[i][j] == 'l')
		flag->l = 1;
	else if (argv[i][j] == 't')
		flag->t = 1;
	else if (argv[i][j] == 'R')
		flag->rec = 1;
	else if (argv[i][j] == 'r')
		flag->r = 1;
	else
		ft_putendl("wrong flag");
}

t_flags		*read_flags(int argc, char **argv)
{
	int		i;
	int		j;
	t_flags	*flag;

	i = 1;
	flag = (t_flags *)malloc(sizeof(flag) * 1);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			while (argv[i][j])
			{
				receive(i, j, argv, flag);
				j++;
			}
		}
		i++;
	}
	return (flag);
}
