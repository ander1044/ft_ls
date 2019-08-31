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
	DIR				*d; 
	
	d = opendir(content);
	if (!d)
	{
		ft_putstr("ft_ls:");
		perror(content);
		exit(1);
	}
	while(1)
	{
		const char		*c_path;
		struct dirent	*entry;

		entry = readdir(d);
	if(!entry)
	{
		break;
	}
	c_path = entry->d_name;
	printf ("%s/%s\n", content, d_name);
	if (! (entry->d_type & DT_DIR)) 
	{
	    printf ("%s/%s\n", content, d_name);
	}
	if (entry->d_type & DT_DIR) 
	//while ((d = readdir(dir)) != NULL)
	{
		if(ft_strcmp(d->d_name, ".") != 0 && ft_strcmp(d->d_name, "..")!= 0)
		{
			char path[PATH_MAX];
			
			printf ("%s\n", path);
		/*	ft_putstr(">>");
			ft_putendl(d->d_name);
			ft_strcpy(c_path, content);
			ft_strcat(c_path, "/");
			ft_strcat(c_path, d->d_name);
			o_dir(c_path);*/
		}

	}
	closedir(dir);
}

int	main(int ac, char *av[])
{
	char *c_path;
	if(ac == 1)
	o_dir(c_path);
	return (0);
}