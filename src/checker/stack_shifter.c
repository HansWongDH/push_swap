/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shifter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:01 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 20:35:08 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	p_ab(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;

	if (!*stacka)
		return (0);
	temp = (*stacka)->next;
	(*stacka)->next = *stackb;
	*stackb = *stacka;
	*stacka = temp;
	if ((*stackb)->stk == 1)
		(*stackb)->stk = 2;
	else
		(*stackb)->stk = 1;
	return (1);
}

int	r_ab(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*stack) < 2)
		return (0);
	last = ft_stacklast(*stack);
	temp = (*stack)->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	return (1);
}

int	s_ab(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*tail;

	if (!*stk && !(*stk)->next)
		return (0);
	tail = (*stk)->next->next;
	temp = (*stk);
	*stk = (*stk)->next;
	(*stk)->next = temp;
	(*stk)->next->next = tail;
	return (1);
}

int	rr_ab(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*last2;

	if (ft_stacksize(*stack) < 2)
		return (0);
	temp = *stack;
	last = ft_stacklast(*stack);
	last2 = ft_iter_stop(*stack, last);
	last2->next = NULL;
	*stack = last;
	last->next = temp;
	return (1);
}
