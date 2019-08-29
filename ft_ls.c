/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:09:37 by anben             #+#    #+#             */
/*   Updated: 2019/08/29 13:09:57 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	o_dir(const char *dir_name)
{
	DIR			*dir;
	struct		dirent *d_path;
	char		path[259] = {0};

	if ((dir = opendir(dir_name)) == NULL)
	{
		ft_putendl("ls: No such directory found");
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
			ft_putendl(dir_name);
			ft_putendl(d_path->d_name);
			ft_listdir(path);
		}
		else
			ft_putstr(d_path->d_name);
	}
	closedir(dir);
}
