/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:07:06 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/11 18:01:50 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>

typedef struct s_list
{
	char			*name;
	struct stat		fstat;
	char			*passwd;
	char			*group;
	struct s_list 	*next;
}			t_list;

t_list *node(char *name,struct stat st, char *user, char *group);
void	add_node_to_list(t_list **list, t_list *node);
void	print_list(t_list *list);
void	ft_list(const char *filename);
char	*ctime(const time_t *);
void	sort_alpha(t_list **st);
void    print_sort_t(t_list *list);
void    list_rec(char *basepath);
void    sort_rev(t_list **st);
#endif
