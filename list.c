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

int	read_root(char *alt, char *rootname, size_t root_len)
{
	DIR		*d_root;
	t_list	*list;

	
	/*if (d_root->d_name[0] != '.')
		display rootname */
	if ((d_root = opendir(rootname)) == NULL) 
	{
		ft_putendl("No such directory found");
		exit(1);
	}
	list = open_root(alt, rootname, root_len, d_root);
	if (list)
	{
		/*if (op)
		asign
		if ()
		display
		recurscive
		free mem */
	}
	closedir(d_root);
	return (0);
}

t_list	*open_root(char *alt, char *rootname, size_t root_len, DIR *d_root)
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
				/* if ()
				retVAL
				else if
				retVAL
				else
				retVAL
				 */
			ft_putendl(d_path->d_name);
			//ft_putendl(rootname);
			ft_putendl(d_path->d_name);
	//		ft_listdir(path);
		}
		else
			ft_putstr(d_path->d_name);
	}
	return (list);	
}

/*void	listdisplay(char *alt, char *rootname, size_t root_len, t_list list)
{
	t_folder *d_path;

	//if ()
	{

	}	
}*/