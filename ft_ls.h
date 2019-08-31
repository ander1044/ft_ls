/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:42:42 by anben             #+#    #+#             */
/*   Updated: 2019/07/15 09:57:34 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include "./libft/libft.h"
# include <sys/stat.h>

typedef struct t_dir
{
    DIR     *dir;
    
    char    *path;
    struct  t_dir *next;
}           s_dir;
void    o_dir(const char *dir_name);
# endif
