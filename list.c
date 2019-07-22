/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:46:46 by anben             #+#    #+#             */
/*   Updated: 2019/07/15 11:03:09 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_listdir(char *alt, char *rootname, size_t root_len)
{
	DIR		*d_root;
	t_list	*list;

	//if (d_root->d_name[0] != '.')

	if ((d_root = opendir(rootname)) == NULL)
	{
		ft_putendl("No such directory found");
		exit(1);
	}
	list = listread(alt, rootname, root_len, d_root);
	if (list)
	{

	}

closedir(d_root);
}

t_list	*listread(char *alt, char *rootname, size_t root_len, DIR *d_root)
{
	t_folder	*d_path;
	t_list		*list;	

	list = NULL;
	while ((d_path = readdir(d_root)) != NULL)
	{
		if (d_path->d_type == DT_DIR)
		{
			if ((ft_strcmp(d_path->d_name, ".") == 0) ||
					(ft_strcmp(d_path->d_name, "..") == 0))
				continue;
			ft_putendl(d_path->d_name);
			//ft_putendl(rootname);
			ft_putendl(d_path->d_name);
	//		ft_listdir(path);
		}
		else
			ft_putstr(d_path->d_name);
	}

	
}
