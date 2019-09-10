/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:53:02 by bphofuya          #+#    #+#             */
/*   Updated: 2019/09/10 18:53:22 by bphofuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*node(char *name, struct stat st, char *user, char *group)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	tmp->name = ft_strdup(name);
	tmp->fstat = st;
	tmp->passwd = ft_strdup(user);
	tmp->group = ft_strdup(group);
	tmp->next = NULL;
	return (tmp);
}
