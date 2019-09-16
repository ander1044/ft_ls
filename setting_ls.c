/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:29:00 by anben             #+#    #+#             */
/*   Updated: 2019/09/12 15:27:35 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*setting_lst(struct dirent *de, char *path)
{
	t_dir		*new;
	struct stat	sb;
	char		*path2;
	char		*tmp;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	tmp = ft_strjoin(path, "/");
	path2 = ft_strjoin(tmp, de->d_name);
	lstat(path2, &sb);
	new->name = ft_strdup(de->d_name);
	new->nlink = sb.st_nlink;
	new->uid = convert_un(sb.st_uid);
	new->gid = convert_gn(sb.st_gid);
	new->size = sb.st_size;
	new->type = de->d_type;
	new->mode = sb.st_mode;
	new->mtime = sb.st_mtime;
	new->block = sb.st_blocks;
	new->next = NULL;
	free(tmp);
	free(path2);
	return (new);
}
