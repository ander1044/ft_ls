/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:42:38 by anben             #+#    #+#             */
/*   Updated: 2019/09/11 12:43:11 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <errno.h>

typedef struct		s_dir
{
	char			*name;
	char			*uid;
	char			*gid;
	int				type;
	int				block;
	mode_t			mode;
	nlink_t			nlink;
	off_t			size;
	time_t			mtime;
	struct s_dir	*next;
}					t_dir;

int					error_handle(char *path, DIR *d_path, int ierrno,
						unsigned int flag);
void				convert_date(char *str);
void				delete_list(t_dir **list);
void				list_add(t_dir **alst, struct dirent *de, char *path);
void				root_out(struct dirent *de, unsigned char flags,
						DIR *dr);
void				recursive_print(struct dirent *de, unsigned char flags,
						char *path);
unsigned char		obtain_flags(int ac, char *av[]);
void				ft_ls(char *d_path, unsigned char flags);
void				recursion(t_dir *list, unsigned char flags, char *path);
char				*convert_un(int uid);
char				*convert_gn(int gib);
void				print_list(t_dir *list, unsigned char flags, char *path);
void				standard_out(t_dir *list, unsigned char flags);
void				print_output(t_dir *list, unsigned char flags, char *path);
void				inverse_split(t_dir *source, t_dir **front_ref,
						t_dir **back_ref);
void				merge_sort(t_dir **head_ref, unsigned char flags);

void				dirfile_error(char *path);
void				ft_linkprint(char *path, t_dir *ptr);
void				display_blocks(t_dir *ptr, unsigned char flags);
void				reverse_list(struct s_dir	**head_ref);
t_dir				*sort_merge_list(t_dir *a, t_dir *b, unsigned char flags);
t_dir				*setting_lst(struct dirent *de, char *path);

#endif
