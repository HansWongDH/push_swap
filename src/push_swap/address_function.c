/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:05:50 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 16:22:43 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_add	*ft_new_add(t_stack *tail, int len)
{
	t_add	*new;

	new = (t_add *)malloc(sizeof(*new));
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

t_stack	*newstack(int n)
{
	t_stack	*hold;

	hold = (t_stack *)malloc(sizeof(*hold));
	if (!hold)
		return (NULL);
	hold->num = n;
	hold->stk = 1;
	hold->next = NULL;
	return (hold);
}

void	stack_addback(t_stack **stk, t_stack *new)
{
	t_stack	*next;

	if (stk && new)
	{
		if (*stk)
		{
			next = ft_stacklast(*stk);
			next->next = new;
		}
		else
			*stk = new;
	}
}
