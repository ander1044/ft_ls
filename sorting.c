/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anben <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:27:02 by anben             #+#    #+#             */
/*   Updated: 2019/09/15 14:08:21 by anben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		reverse_list(struct s_dir **head_ref)
{
	struct s_dir *prev;
	struct s_dir *current;
	struct s_dir *next;

	prev = NULL;
	current = *head_ref;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

t_dir		*sort_merge_time(t_dir *a, t_dir *b, unsigned int flag)
{
	t_dir *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->mtime > b->mtime && !(flag & 8))
	{
		result = a;
		result->next = sort_merge_time(a->next, b, flag);
	}
	else if (a->mtime < b->mtime && flag & 8)
	{
		result = a;
		result->next = sort_merge_time(a->next, b, flag);
	}
	else
	{
		result = b;
		result->next = sort_merge_time(a, b->next, flag);
	}
	return (result);
}

void		merge_sort(t_dir **head_ref, unsigned char flags)
{
	t_dir *head;
	t_dir *a;
	t_dir *b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	inverse_split(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	if (flags & 16)
		*head_ref = sort_merge_time(a, b, flags);
	else
		*head_ref = sort_merge_list(a, b, flags);
}

t_dir		*sort_merge_list(t_dir *a, t_dir *b, unsigned char flags)
{
	t_dir *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = sort_merge_list(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0))
	{
		result = a;
		result->next = sort_merge_list(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = sort_merge_list(a, b->next, flags);
	}
	return (result);
}

void		inverse_split(t_dir *source, t_dir **front_ref, t_dir **back_ref)
{
	t_dir *fast;
	t_dir *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}
