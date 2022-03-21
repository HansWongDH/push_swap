/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:32:35 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 04:14:00 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_highest(t_stack *lst, t_stack *last)
{
	t_stack	*highest;

	highest = lst;
	while (lst && lst != last)
	{
		if (highest->num < lst->num)
			highest = lst;
		lst = lst->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack *lst, t_stack *last)
{
	t_stack	*lowest;

	lowest = lst;
	while (lst && lst != last)
	{
		if (lowest->num > lst->num)
			lowest = lst;
		lst = lst->next;
	}
	return (lowest);
}

void	three_case(t_stack **lst, t_stack *last)
{
	t_stack	*mid;
	t_stack	*tail;

	if (!(*lst)->next)
		return ;
	mid = (*lst)->next;
	if ((*lst)->stk == 1)
		tail = find_highest(*lst, last);
	else
		tail = find_lowest(*lst, last);
	if (*lst == tail)
		r_ab(lst);
	else if (mid == tail)
		rr_ab(lst);
	if ((*lst)->num > (*lst)->next->num && (*lst)->stk == 1)
		s_ab(lst);
	if ((*lst)->num < (*lst)->next->num && (*lst)->stk == 2)
		s_ab(lst);
}

void	three_case_part(t_stack **lst, t_stack *last)
{
	t_stack	*mid;
	t_stack	*tail;
	int		i;

	
	i = 0;
	if (!(*lst)->next)
		return ;
	if (!last)
	{
		three_case(lst, last);
		return ;
	}
	mid = (*lst)->next;
	if ((*lst)->stk == 1)
		tail = find_highest(*lst, last);
	else
		tail = find_lowest(*lst, last);
	if (*lst == tail)
		s_ab(lst);
	if (mid == tail)
	{
		i += r_ab(lst);
		s_ab(lst);
	}
	while (i-- > 0)
		rr_ab(lst);
	if ((*lst)->num > (*lst)->next->num && (*lst)->stk == 1)
		s_ab(lst);
	else if ((*lst)->num < (*lst)->next->num && (*lst)->stk == 2)
		s_ab(lst);
}