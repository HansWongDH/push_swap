/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:32:35 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/05 13:01:06 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_highest(t_stack *stk, t_stack *last)
{
	t_stack	*highest;

	highest = stk;
	while (stk && stk != last)
	{
		if (highest->num < stk->num)
			highest = stk;
		stk = stk->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack *stk, t_stack *last)
{
	t_stack	*lowest;

	lowest = stk;
	while (stk && stk != last)
	{
		if (lowest->num > stk->num)
			lowest = stk;
		stk = stk->next;
	}
	return (lowest);
}

int	check_three_case(t_stack **stk, t_stack *last)
{
	t_stack	*mid;
	t_stack	*tail;
	int		i;

	mid = (*stk)->next;
	tail = find_highest(*stk, last);
	i = 0;
	if (!(*stk)->next)
		return (0);
	if (*stk == tail || mid == tail)
		i = 1;
	return (i);
}

void	three_case(t_stack **stk, t_stack *last)
{
	t_stack	*mid;
	t_stack	*tail;

	if (!(*stk)->next)
		return ;
	mid = (*stk)->next;
	if ((*stk)->stk == 1)
		tail = find_highest(*stk, last);
	else
		tail = find_lowest(*stk, last);
	if (*stk == tail)
		r_ab(stk);
	else if (mid == tail)
		rr_ab(stk, 0);
	if ((*stk)->num > (*stk)->next->num && (*stk)->stk == 1)
		s_ab(stk);
	if ((*stk)->num < (*stk)->next->num && (*stk)->stk == 2)
		s_ab(stk);
}

void	three_case_p(t_stack **stk, t_stack **stkb, t_stack *last, t_add **b)
{
	t_stack	*mid;
	t_stack	*tail;
	int		i;

	i = 0;
	if (!(*stk)->next)
		return ;
	if (!last)
	{
		three_case(stk, last);
		return ;
	}
	mid = (*stk)->next;
	tail = find_highest(*stk, last);
	if (*stk == tail)
		s_ab(stk);
	if (mid == tail)
	{
		i += r_ab(stk);
		s_ab(stk);
	}
	if (i > 0)
		rrr_or_rra(stk, stkb, b);
	if ((*stk)->num > (*stk)->next->num)
		s_ab(stk);
}
