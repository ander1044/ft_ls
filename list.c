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

void	ft_listdir(const char *rootname)
{
	DIR			*dir;
	struct		dirent *d_path;
	char		path[259] = {0};

	if ((dir = opendir(rootname)) == NULL)
	{
		ft_putendl("No such directory found");
		exit(1);
	}
	while ((d_path = readdir(dir)) != NULL)
	{
		if (d_path->d_type == DT_DIR)
		{
			if ((ft_strcmp(d_path->d_name, ".") == 0) ||
					(ft_strcmp(d_path->d_name, "..") == 0))
				continue;
			ft_putendl(d_path->d_name);
			ft_putendl(rootname);
			ft_putendl(d_path->d_name);
			ft_listdir(path);
		}
		else
			ft_putstr(d_path->d_name);
	}
	closedir(dir);
}