/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:53:02 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/22 14:10:23 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*node(char *name, struct stat st, char *group)
{
	t_list			*tmp;
	struct passwd	*p;

	p = getpwuid(st.st_uid);
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	tmp->name = ft_strdup(name);
	tmp->fstat = st;
	tmp->passwd = ft_strdup(p->pw_name);
	tmp->group = ft_strdup(group);
	tmp->next = NULL;
	return (tmp);
}
