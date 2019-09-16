/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:51:12 by anben             #+#    #+#             */
/*   Updated: 2019/09/12 15:25:24 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*convert_un(int uid)
{
	struct passwd	*pwd;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		perror("getpwuid");
	else
		return (pwd->pw_name);
	return (NULL);
}

char		*convert_gn(int gib)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp == NULL)
		perror("getgid");
	else
		return (grp->gr_name);
	return (NULL);
}

void		convert_date(char *str)
{
	char	ret[14];
	int		i;
	int		j;

	j = 0;
	i = 4;
	ft_strcpy(ret, "000  0 00:00 ");
	while (i < 16)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ft_putstr(ret);
}
