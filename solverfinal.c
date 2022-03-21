/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverfinal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:33:21 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 00:39:58 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	partition_a(t_stack **stka, t_stack **stkb, t_add **a)
{
	t_stack	*tail;
	t_stack	*last;
	int		i;
	int		len;
	int		pivot;

	last = (*a)->tail;
	len = (*a)->len;
	pivot = find_median(*stka, last);
	i = 0;
	tail = NULL;
	while (len > 0)
	{
		if ((*stka)->num < pivot)
			p_ab(stka, stkb);
		else if (*stka != last)
			i = r_ab(stka);
		len--;
	}
	(*a)->len = i;
	while (i-- > 0)
		rr_ab(stka);

}