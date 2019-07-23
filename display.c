/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:08:26 by anben             #+#    #+#             */
/*   Updated: 2019/07/22 17:08:31 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		listdisplay(char *alt, char *d_root)
{
	if (display1)
	{
		if (display1 < 2)
			ft_putchar('\n');
		if (display1 < 3)
		{
			ft_putstr(d_root);
			ft_putstr(":\n");
		}
	}
}
