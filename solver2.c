/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:25:18 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 02:27:45 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap2.h"

void	printlist(t_stack *list)
{
		while (list)
	{
		printf("Linked list %d :%d \n", list->stk, list->num);
		list = list->next;
	}
	printf("--------------------\n");
}

void	push_number(t_stack **lsta, t_stack **lstb)
{
	while (*lsta)
	{
		p_ab(lsta, lstb);
	}
}

t_stack	*partition_a(t_stack **stka, t_stack **stkb, t_add **a)
{
	t_stack	*tail;
	t_stack	*last;
	int		i;
	int		len;
	int		pivot;

	last = ft_iter_stop(*stka, (*a)->tail);
	len = (*a)->len;
	pivot = find_median(*stka, len);
	i = 0;
	if (*stkb)
		tail = *stkb;
	else
		tail = NULL;
	while (len > 0)
	{
		if ((*stka)->num < pivot)
			(*a)->len -= p_ab(stka, stkb);
		else if (*stka != last)
			i += r_ab(stka);
		len--;
	}
	while (i-- > 0 && (*a)->tail)
		rr_ab(stka);
	return (tail);
}

t_stack	*partition_b(t_stack **stka, t_stack **stkb, t_add **a)
{
	t_stack	*tail;
	t_stack	*last;
	int		i;
	int		len;
	int		pivot;

	last = ft_iter_stop(*stka, (*a)->tail);
	len = (*a)->len;
	pivot = find_median(*stka, len);
	i = 0;
	if (*stkb)
		tail = *stkb;
	else
		tail = NULL;
	while (len > 0)
	{
		if ((*stka)->num >= pivot)
			(*a)->len -= p_ab(stka, stkb);
		else if (*stka != last)
			i += r_ab(stka);
		len--;
	}
	while (i-- > 0 && (*a)->tail)
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
		if ((*a)->len == 0)
			delete_add(a);
		ft_add_front(b, ft_new_add(tailb, ft_stacksize_n(*stkb, tailb)));
	}
	if ((*stka)->stk == 2)
	{
		taila = partition_b(stka, stkb, b);
		if ((*b)->len == 0)
			delete_add(b);
		ft_add_front(a, ft_new_add(taila, ft_stacksize_n(*stkb, taila)));
	}
}

void	sort(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) > 3)
		sorting(stka, stkb, a, b);
	else if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) == 3)
		three_case_part(stka, (*a)->tail);
	else if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) == 2)
		s_ab(stka);
	if (issorted(*stka) && *stkb)
	{
		//if (!issorted(*stkb))
			sorting(stkb, stka, a, b);
	//	else if (!issorted(*stkb) && (*b)->len == 2)
		//	s_ab(stkb);
		//else
		//	push_number(stkb, stka);
	//	else if ((*b)->len == 2)
	//		s_ab(stkb);
	}
	if (!issorted(*stka) || *stkb)
		sort(stka, stkb, a, b);
}
