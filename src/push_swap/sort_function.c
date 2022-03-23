/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:25:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 18:23:15 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_number(t_stack **stka, t_stack **stkb, t_add **info)
{
	while ((*info)->len > 0)
	{
		p_ab(stka, stkb);
		(*info)->len--;
	}
	delete_add(info);
}

t_stack	*partition_a(t_stack **stka, t_stack **stkb, t_add **a)
{
	t_stack	*tail;
	int		i;
	int		pivot;

	pivot = find_median(*stka, (*a)->len);
	tail = *stkb;
	i = rotation(stka, stkb, a, pivot);
	while (i-- > 0 && (*a)->tail)
	{
		if ((*stka)->num == pivot && (*a)->len > 3)
			(*a)->len -= p_ab(stka, stkb);
		rr_ab(stka);
	}
	return (tail);
}

t_stack	*partition_b(t_stack **stka, t_stack **stkb, t_add **b)
{
	t_stack	*tail;
	t_stack	*last;
	int		i;
	int		len;
	int		pivot;

	last = ft_iter_stop(*stka, (*b)->tail);
	len = (*b)->len;
	pivot = find_median(*stka, len);
	i = 0;
	tail = *stkb;
	while (len-- > 0)
	{
		if ((*stka)->num >= pivot)
			(*b)->len -= p_ab(stka, stkb);
		else if (!(*b)->tail)
			rot_b(stka, pivot, *b);
		else if (*stka != last)
			i += r_ab(stka);
	}
	while (i-- > 0 && (*b)->tail)
		rr_ab(stka);
	return (tail);
}

void	sorting(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	t_stack	*taila;
	t_stack	*tailb;

	taila = NULL;
	tailb = NULL;
	if ((*stka)->stk == 1)
	{
		tailb = partition_a(stka, stkb, a);
		if (*a && (*a)->len == 0)
			delete_add(a);
		ft_add_front(b, ft_new_add(tailb, ft_stacksize_n(*stkb, tailb)));
	}
	if ((*stka)->stk == 2)
	{
		taila = partition_b(stka, stkb, b);
		if (*b && (*b)->len == 0)
			delete_add(b);
		ft_add_front(a, ft_new_add(taila, ft_stacksize_n(*stkb, taila)));
	}
}

void	sort(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	if (!issorted(*stka))
	{
		if ((*a)->len > 3)
			sorting(stka, stkb, a, b);
		else if ((*a)->len == 3)
			three_case_part(stka, (*a)->tail);
		else if ((*a)->len == 2)
			s_ab(stka);
	}
	if (issorted(*stka) && *stkb)
	{
		if (!issorted(*stkb) && (*b)->len > 2)
			sorting(stkb, stka, a, b);
		else if (!issortedtail(*stkb, 2) && (*b)->len == 2)
			s_ab(stkb);
		else
			push_number(stkb, stka, b);
	}
	if (!issorted(*stka) || *stkb)
		sort(stka, stkb, a, b);
	if (issorted(*stka) && !*stkb)
		return ;
}
