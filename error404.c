/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error404.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:38:23 by anben             #+#    #+#             */
/*   Updated: 2019/07/21 15:38:26 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    flag_404(char *rootname)
{
    //flag error handler
    ft_putstr(">> ft_ls: ");
    ft_putstr(rootname);
    ft_putendl(": Such file or folder  not found");
}