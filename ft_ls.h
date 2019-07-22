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

typedef struct dirent	t_folder;
typedef struct stat		t_stat;

int		            ft_listdir(char *alt, char *rootname, size_t root_len);
int                 run_flags(char flag);
unsigned char       scan_flag(unsigned char *sign);
void                flag404(char *rootname);
void                listdisplay(char *alt, char *d_root);

# endif
