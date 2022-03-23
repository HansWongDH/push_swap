/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:31:26 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 16:20:53 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		stk = stk->next;
		i++;
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
