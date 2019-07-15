/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:19:40 by anben             #+#    #+#             */
/*   Updated: 2019/07/15 10:51:48 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char *av[])
{
	DIR *dir;
	struct dirent *d_path;

	if (ac != 2)
	{
		ft_putstr("Please provide directory name");
		exit(1);
	}
	ft_listdir(av[1]);
	exit(0);
}
