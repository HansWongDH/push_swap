/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:32:35 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 05:36:35 by wding-ha         ###   ########.fr       */
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

/*void	insertion_sort(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	t_stack	*lowest;
	int		i;

	while ((*a)->len > 3)
	{
		lowest = find_lowest(*stka, (*a)->tail);
		if ((*stka)->next == lowest)
			s_ab(stka);
		else if (*stka != lowest)
			i = r_ab(stka);	
		if (*stka == lowest)
		{
			(*a)->len -= p_ab(stka, stkb);
			while (i-- > 0)
				rr_ab(stka);
		}
	}
}*/

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
		rr_ab(stk);
	if ((*stk)->num > (*stk)->next->num && (*stk)->stk == 1)
		s_ab(stk);
	if ((*stk)->num < (*stk)->next->num && (*stk)->stk == 2)
		s_ab(stk);
}

void	three_case_part(t_stack **stk, t_stack *last)
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
	while (i-- > 0)
		rr_ab(stk);
	if ((*stk)->num > (*stk)->next->num)
		s_ab(stk);
}
