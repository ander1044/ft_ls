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
# define S_IFDIR
# define S_IRUSR

# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include "./libft/libft.h"
# include <sys/stat.h>

void		    ft_listdir(const char *rootname);
int             run_flags(char flag);
unsigned char   scan_flag(unsigned char *sign);
void             flag404(char *rootname);

# endif
