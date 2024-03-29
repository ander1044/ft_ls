/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:51:55 by anben             #+#    #+#             */
/*   Updated: 2019/09/15 14:02:13 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *d_path, unsigned char flags)
{
	DIR				*dire;
	struct dirent	*entries;
	t_dir			*content;

	content = NULL;
	entries = NULL;
	dire = opendir(d_path);
	if (error_handle(d_path, dire, errno, flags) == 1)
		return ;
	while ((entries = readdir(dire)))
	{
		if (!content)
			content = setting_lst(entries, d_path);
		else
			list_add(&content, entries, d_path);
	}
	closedir(dire);
	if (!(flags & 64))
		merge_sort(&content, flags);
	else
		reverse_list(&content);
	print_output(content, flags, d_path);
	recursion(content, flags, d_path);
	delete_list(&content);
}

int		implement_args(int ac, char *av[], unsigned char flags)
{
	int i;
	int check;

	i = 1;
	check = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_ls(av[i], flags);
			check = 1;
		}
		if (av[i][0] == '-' && av[i][1] == '\0')
			check = 2;
		i++;
	}
	return (check);
}

int		main(int ac, char *av[])
{
	unsigned char	flags;
	int				check;

	check = 0;
	flags = obtain_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		check = implement_args(ac, av, flags);
		(check == 0) ? ft_ls(".", flags) : 0;
	}
	return (0);
}
