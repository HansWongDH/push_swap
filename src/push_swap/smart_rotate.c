/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:11:59 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 16:17:23 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_a(t_stack **stk, int pivot, t_add *a)
{
	t_stack	*chk;
	int		i;

	if (a->tail)
		return (0);
	i = 0;
	chk = *stk;
	while (chk && chk->num >= pivot)
	{
		i++;
		chk = chk->next;
	}
	if (i == a->len)
		return (0);
	if (i < a->len / 2)
	{
		while ((*stk)->num >= pivot)
			r_ab(stk);
	}
	else
		while ((*stk)->num >= pivot)
			rr_ab(stk);
	return (1);
}

int	rot_b(t_stack **stk, int pivot, t_add *b)
{
	t_stack	*chk;
	int		i;

	if (b->tail)
		return (0);
	i = 0;
	chk = *stk;
	while (chk && chk->num < pivot)
	{
		i++;
		chk = chk->next;
	}
	if (i == b->len)
		return (0);
	if (i < b->len / 2)
	{
		while ((*stk)->num < pivot)
			r_ab(stk);
	}
	else
		while ((*stk)->num < pivot)
			rr_ab(stk);
	return (1);
}

int	rotation(t_stack **stka, t_stack **stkb, t_add **a, int pivot)
{
	int		len;
	int		i;
	t_stack	*last;

	last = ft_iter_stop(*stka, (*a)->tail);
	len = (*a)->len;
	i = 0;
	while (len-- > 0 && (*a)->len > 3)
	{
		if ((*stka)->num < pivot)
			(*a)->len -= p_ab(stka, stkb);
		else if (!(*a)->tail)
			rot_a(stka, pivot, *a);
		else if (*stka != last)
			i += r_ab(stka);
	}
	return (i);
}
