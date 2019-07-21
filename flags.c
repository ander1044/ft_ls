/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:14:23 by anben             #+#    #+#             */
/*   Updated: 2019/07/15 15:14:26 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned char   scan_flag(unsigned char *sign)
{
     flag404("-");
    return (sign);
}
int run_flags(char flag)
{
    if (flag == 'l')
    return (1);
    if (flag == 'r')
    return (2);
    if (flag == 'a')
    return (3);
    if (flag == 't')
    return (4);
    if (flag == 'R')
    return (5);
    return (0);
}
unsigned char   return_flag(int ac, char *av[])
{
    char flags;
    int i;
    int j;

    i = 1;
    flags = '\0';
    while (i < av)
    {
        j = 0;
        if (av[i][0] == '-')
        {
            j++;
            if (av[i][1] == '\0')
            return (scan_flag(flags));
        }
    }
}