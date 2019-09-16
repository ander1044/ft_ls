/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:26:05 by anben             #+#    #+#             */
/*   Updated: 2019/09/12 15:26:09 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	delete_list(t_dir **list)
{
	t_dir *content;
	t_dir *next;

	content = *list;
	while (content)
	{
		next = content->next;
		free(content->name);
		free(content);
		content = next;
	}
	*list = NULL;
}

void	list_add(t_dir **alst, struct dirent *de, char *path)
{
	t_dir *new;

	new = setting_lst(de, path);
	new->next = *alst;
	*alst = new;
}
