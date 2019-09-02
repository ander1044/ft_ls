/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:09:37 by anben             #+#    #+#             */
/*   Updated: 2019/09/01 13:41:07 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	o_dir(const char *content)
{
	DIR				*d;
	struct dirent	*entries;
	const char		*d_name;

	if (!(d = opendir(content)))
	{
		ft_putstr("ft_ls:");
		perror(content);
		exit(1);
	}
	while (1)
	{
		if (!(entries = readdir(d)))
		{
			break ;
		}
		d_name = entries->d_name;
		if (!(entries->d_type & DT_DIR))
		{
			ft_putendl(d_name);
		}
	}
	closedir(d);
}

int		main(void)
{
	o_dir(".");
	return (0);
}
