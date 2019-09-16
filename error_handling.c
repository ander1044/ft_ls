/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:25:41 by anben             #+#    #+#             */
/*   Updated: 2019/09/15 14:02:31 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_handle2(char *path)
{
	if (ft_strcmp(path, ".") != 0)
	{
		ft_putstrx3("\n", path, ":\n");
	}
}

void	permission_error(char *path)
{
	ft_putstrx3("ft_ls: ", "\033[0;31m", NULL);
	if (path[ft_strlen(path) - 1] != '/')
		ft_putstrx3("cannot open directory ", path, ": Permission denied\n");
}

void	dirfile_error(char *path)
{
	ft_putstr("\033[0;33m");
	ft_putstrx3("ft_ls: ", path, ": No such file or directory\n");
}

int		error_handle(char *path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
	else if (!dp)
	{
		if (ierrno == 13)
		{
			permission_error(path);
			return (1);
		}
		dirfile_error(path);
		return (1);
	}
	if (flag & 4)
	{
		error_handle2(path);
	}
	return (0);
}
