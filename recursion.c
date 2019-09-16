/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:28:49 by anben             #+#    #+#             */
/*   Updated: 2019/09/12 15:27:20 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion(t_dir *list, unsigned char flags, char *path)
{
	t_dir	*ptr;
	char	*s1;
	char	*s2;

	ptr = list;
	if (flags & 4)
		while (ptr != NULL)
		{
			if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
			&& (ft_strcmp(ptr->name, "..") != 0))
			{
				if (!(flags & 2) && (ptr->name[0] == '.'))
				{
					ptr = ptr->next;
					continue ;
				}
				s1 = ft_strjoin("/", ptr->name);
				s2 = ft_strjoin(path, s1);
				free(s1);
				ft_ls(s2, flags);
				free(s2);
			}
			ptr = ptr->next;
		}
}
