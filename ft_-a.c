/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_-a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:30:00 by bphofuya          #+#    #+#             */
/*   Updated: 2019/08/12 13:28:04 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list(const char *filename)
{
	DIR				*dir;
	struct dirent	*dirp;

	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putstr("error");
		exit(1);
	}
	while ((dirp = readdir(dir)) && dirp != NULL)
	{
		//if (*dirp->d_name != '.')
			ft_putstr(dirp->d_name);
		ft_putstr(" ");
	}
	ft_putstr("\n");
	closedir(dir);
}

/*int main(int argc, char **argv)
{
   ft_list(argv[1]);
   return (0);
}*/
