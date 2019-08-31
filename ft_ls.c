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

void	o_dir(const char *content)
{
	char			c_path[2000];
	struct dirent	*d;
	DIR				*dir; 
	
	dir = opendir(content);
	if (!dir)
	{
		ft_putstr("ft_ls:");
		perror(content);
		exit(1);
	}
	while ((d = readdir(dir)) != NULL)
	{
		if(ft_strcmp(d->d_name, ".") != 0 && ft_strcmp(d->d_name, "..")!= 0)
		{
			ft_putstr(">>");
			ft_putendl(d->d_name);
			ft_strcpy(c_path, content);
			ft_strcat(c_path, "/");
			ft_strcat(c_path, d->d_name);
			o_dir(c_path);
		}

	}
	closedir(dir);
}

int	main(int ac, char *av[])
{
	char c_path;
	if(ac == 1)

	o_dir(c_path);
	return (0);
}