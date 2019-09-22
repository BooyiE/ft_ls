/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:28:40 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/22 13:48:17 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		empty_file(char ***file)
{
	char **tmp;

	tmp = (char **)malloc(sizeof(char *) * 2);
	if (!tmp)
		return ;
	tmp[0] = ft_strdup(".");
	tmp[1] = NULL;
	*file = tmp;
}

int				main(int argc, char **argv)
{
	t_flags	*flag;
	char	**files;
	int		i;

	i = 0;
	flag = read_flags(argc, argv);
	files = read_files(argc, argv);
	if (!files || !*files)
		empty_file(&files);
	while (files[i])
	{
		ft_rec(files[i], flag);
		i++;
	}
	free(flag);
	free(files);
	return (0);
}
