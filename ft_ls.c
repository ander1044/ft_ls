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
	char			contents[2000];
	DIR				*dir;
	struct dirent	*d;

	dir = opendir(content);
	if (!dir)
	return ;
	while ((d = readdir(dir)) != NULL)
	{
		if(ft_strcmp(d->d_name, ".") != 0 && ft_strcmp(d->d_name, "..")!=  0)
		{
		ft_putendl(d->d_name);
		ft_strcpy(contents, content);
		ft_strcat(contents, "/");
		ft_strcat(contents, d->d_name);
		o_dir(contents);
		}

	}
	closedir(dir);
}

int	main(void)
{
	char content[100];

	printf("typesomething");
	scanf ("%s", content);
	o_dir(content);
	return (0);
}