/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shifter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:01 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 04:48:24 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_ab(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;
	char	c;

	if (!*stacka)
		return (0);
	temp = (*stacka)->next;
	(*stacka)->next = *stackb;
	*stackb = *stacka;
	*stacka = temp;
	if ((*stackb)->stk == 1)
	{
		c = 'b';
		(*stackb)->stk = 2;
	}
	else
	{
		c = 'a';
		(*stackb)->stk = 1;
	}
	printf("p%c\n", c);
	return (1);
}

int	r_ab(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	char	c;

	if ((*stack)->stk == 1)
		c = 'a';
	else
		c = 'b';
	if (ft_stacksize(*stack) < 2)
		return (0);
	last = ft_stacklast(*stack);
	temp = (*stack)->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	printf("r%c\n", c);
	return (1);
}

int	s_ab(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*tail;
	char	c;

	if ((*stk)->stk == 1)
		c = 'a';
	else
		c = 'b';
	tail = (*stk)->next->next;
	temp = (*stk);
	*stk = (*stk)->next;
	(*stk)->next = temp;
	(*stk)->next->next = tail;
	printf("s%c\n", c);
}

int	rr_ab(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*last2;
	char	c;

	if (ft_stacksize(*stack) < 2)
		return (0);
	if ((*stack)->stk == 1)
		c = 'a';
	else
		c = 'b';
	temp = *stack;
	last = ft_stacklast(*stack);
	last2 = ft_iter_stop(*stack, last);
	last2->next = NULL;
	*stack = last;
	last->next = temp;
	printf("rr%c\n", c);
	return (1);
}