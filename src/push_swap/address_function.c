/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:05:50 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/24 18:30:33 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_add	*ft_new_add(t_stack *tail, int len)
{
	t_add	*new;

	new = malloc(sizeof(t_add));
	if (!new)
		return (NULL);
	new->len = len;
	new->tail = tail;
	new->nxt = NULL;
	return (new);
}

void	ft_add_front(t_add **list, t_add *new)
{
	if (list && new)
	{
		new->nxt = *list;
		*list = new;
	}
}

void	delete_add(t_add **add)
{
	t_add	*temp;

	if (*add)
	{
		temp = (*add)->nxt;
		(*add)->nxt = NULL;
		free (*add);
		*add = temp;
	}
}

void	free_add(t_add **add_a, t_add **add_b)
{
	while (*add_a)
		delete_add(add_a);
	while (*add_b)
		delete_add(add_b);
}
