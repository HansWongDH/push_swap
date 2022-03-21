/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:31:26 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 04:45:13 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(int n)
{
	t_stack	*hold;

	hold = (t_stack *)malloc(sizeof(hold));
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

int	ft_stacksize(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk = stk->next;
		i++;
	}
	return (i);
}

int	ft_stacksize_n(t_stack *stk, t_stack *last)
{
	int	i;

	i = 0;
	while (stk && stk != last)
	{
		i++;
		stk = stk->next;	
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *stk)
{
	while (stk)
	{
		if (!stk->next)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}

t_stack	*ft_iter_stop(t_stack *stk, t_stack *last)
{
	while (stk)
	{
		if (stk->next == last)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}

