/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shifter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:01 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/24 20:08:43 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_ab(t_stack **stka, t_stack **stkb)
{
	t_stack	*temp;
	char	*str;

	if (!*stka)
		return (0);
	temp = (*stka)->next;
	(*stka)->next = *stkb;
	*stkb = *stka;
	*stka = temp;
	if ((*stkb)->stk == 1)
	{
		str = "pb\n";
		(*stkb)->stk = 2;
	}
	else
	{
		str = "pa\n";
		(*stkb)->stk = 1;
	}
	ft_putstr_fd(str, 1);
	return (1);
}

int	r_ab(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	char	*str;

	if (ft_stacksize(*stack) < 2)
		return (0);
	if ((*stack)->stk == 1)
		str = "ra\n";
	else
		str = "rb\n";
	if (ft_stacksize(*stack) < 2)
		return (0);
	last = ft_stacklast(*stack);
	temp = (*stack)->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	ft_putstr_fd(str, 1);
	return (1);
}

int	s_ab(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*tail;
	char	*str;

	if (!*stk && !(*stk)->next)
		return (0);
	if ((*stk)->stk == 1)
		str = "sa\n";
	else
		str = "sb\n";
	tail = (*stk)->next->next;
	temp = (*stk);
	*stk = (*stk)->next;
	(*stk)->next = temp;
	(*stk)->next->next = tail;
	ft_putstr_fd(str, 1);
	return (1);
}

int	rr_ab(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*last2;
	char	*str;

	if (ft_stacksize(*stack) < 2)
		return (0);
	if ((*stack)->stk == 1)
		str = "rra\n";
	else
		str = "rrb\n";
	temp = *stack;
	last = ft_stacklast(*stack);
	last2 = ft_iter_stop(*stack, last);
	last2->next = NULL;
	*stack = last;
	last->next = temp;
	ft_putstr_fd(str, 1);
	return (1);
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
