/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:28:40 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/13 15:42:29 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	flags	*flag;
	char	**files;

	flag = read_flags(argc, argv);
	files = read_files(argc, argv);

	if (!*files)
		*files = "./";
	ft_rec(*files, flag);
	free(flag);
	free(files);
	return (0);
}
