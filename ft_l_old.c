/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_-l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:07:08 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/10 18:47:25 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list(const char *filename)
{
	DIR				*dir;
	struct			dirent *dirp;
	struct			stat s;
	struct	passwd	*p;
	struct	group	*g;
	time_t			t;
	t_list			*files;
	t_list			*one_node;

	dir = opendir(filename);
	if (dir == NULL)
	{
		ft_putstr("error");
		exit(1);
	}
	while ((dirp = readdir(dir)) && dirp != NULL)
	{
		if (*dirp->d_name != '.')
		{
			lstat(dirp->d_name, &s);
			p = getpwuid(s.st_uid);
			g = getgrgid(s.st_gid);
			one_node = node(dirp->d_name, s, p->pw_name, g->gr_name);
			add_node_to_list(&files, one_node);
		}
	}
	sort_alpha(&files);
	print_list(files);
	ft_putstr("\n");
	closedir(dir);
}

int		main(int argc, char **argv)
{
	ft_list(argv[1]);
	if (argc != 2)
		return (1);
	return (0);
}

/*void	ft_checkflags(char *arg_flags, struct my_flags flags)
{
	int i;

	i = 0;
	while(arg_flags[i] != '\0') {
		if (arg_flags[i] == 'l')
		struct	my_flags.lflag = 1;
		else if (arg_flags[i] == 'a')
		struct	my_flags.aflag = 1;
		else if (arg_flags[i] == 't')
			my_flag.tflag = 1;
		else if (arg_flgs[i] == 'r')
			my_flag.rflag = 1;
		else if (arg_flags[i] == 'R')
			my_flag.Rflag = 1;
		arg_flags++;
}*/
