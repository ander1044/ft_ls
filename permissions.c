/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:43:15 by anben             #+#    #+#             */
/*   Updated: 2019/09/02 17:15:36 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_perm(struct stat item_stats)
{
	mode_t mode;

	mode = item_stats.st_mode;
	ft_putstr((mode & S_IRUSR) ? "r" : "-");
	ft_putstr((mode & S_IWUSR) ? "w" : "-");
	ft_putstr((mode & S_IXUSR) ? "x" : "-");
	ft_putstr((mode & S_IRGRP) ? "r" : "-");
	ft_putstr((mode & S_IWGRP) ? "w" : "-");
	ft_putstr((mode & S_IXGRP) ? "x" : "-");
	ft_putstr((mode & S_IROTH) ? "r" : "-");
	ft_putstr((mode & S_IWOTH) ? "w" : "-");
	ft_putstr((mode & S_IXOTH) ? "x" : "-");
}
