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

void flag_failure(char flag)
{
    ft_putstr(TITLE);
    ft_putstr(": ");
    ft_putstr(" illegal option -- ");
    ft_putchar(flag);
    ft_putchar('\n');
    ft_putstr("usage: ");
    ft_putstr(TITLE);
    ft_putendl(" [-lRart] [file ...]");
    exit(1);
}