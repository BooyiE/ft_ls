/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:07:08 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 13:45:48 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**read_files(int argc, char **argv)
{
	int i;
	int j;
	char **files;

	i = 1;
	j = 0;
	while (i < argc && argv[i][0] == '-')
		i++;
	files = (char **)malloc(sizeof(char *) * (argc - i));
	while (argc > i)
	{
		files[j] = argv[i];
		i++;
		j++;
	}
	files[j] = NULL;
	return (files);
}
