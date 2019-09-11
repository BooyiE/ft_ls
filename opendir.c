/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:02:18 by bphofuya          #+#    #+#             */
/*   Updated: 2019/08/08 17:05:47 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(void)
{
	struct dirent	*sd;
	DIR				*dirp;

	dirp = opendir(".");
	if (dirp == NULL)
	{
		ft_putstr("Could not open current directory");
		return (0);
	}
	while ((sd = readdir(dirp)) != NULL)
		ft_putendl(sd->d_name);
	closedir(dirp);
	return (0);
}
