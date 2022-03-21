/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:44:08 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/21 20:44:13 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stack	*ft_iter(t_stack *stk, int i)
{
	t_stack	*pos;

	pos = NULL;
	while (stk)
	{
		if (stk->num == i)
			pos = stk;
		stk = stk->next;
	}
	return (pos);
}

t_stack	*partition_a(t_stack **lsta, t_stack **lstb, t_add *info)
{
	t_stack	*tail;
	t_stack	*last;
	t_stack	*tailend;
	t_stack *pivotpos;
	int		pivot;
	int		i;


	last = info->tail;
	tailend = last->next;
	tail = NULL;
	i = 0;
	pivot = find_median(*lsta, last);
	while (info->len > 0)
	{
		if ((*lsta)->num < pivot)
		{
			p_ab(lsta, lstb);
			if (tail == NULL)
				tail = *lstb;
		}
		else
			i += r_ab(lsta);
		info->len--;
	}
	while (i-- > 0 && tailend)
	{
		if ((*lsta)->num == pivot)
		{
			p_ab(lsta, lstb);
			if (tail == NULL)
				tail = *lstb;
		}
		rr_ab(lsta);
	}
	return (tail);
}

t_stack	*partition_b(t_stack **lsta, t_stack **lstb, t_add *info)
{
	t_stack	*tail;
	t_stack	*last;
	t_stack	*tailend;
	int		pivot;
	int		i;

	last = info->tail;
	tailend = last->next;
	tail = NULL;
	i = 0;
	pivot = find_median(*lsta, last);
	while (info->len > 0)
	{
		if ((*lsta)->num > pivot)
		{
			p_ab(lsta, lstb);
			if (tail == NULL)
				tail = *lstb;
		}
		else if (*lsta != last)
			i += r_ab(lsta);
		info->len--;
	}
	while (i-- > 0 && tailend)
	{
		if ((*lsta)->num == pivot)
		{
			p_ab(lsta, lstb);
			if (tail == NULL)
				tail = *lstb;
		}
		rr_ab(lsta);
	}
	return (tail);
}

void	sorting(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	t_stack	*taila;
	t_stack	*tailb;

	if ((*stka)->stk == 1)
	{
		tailb = partition_a(stka, stkb, *a);
		ft_add_front(b, ft_new_add(tailb, ft_stacksize_n(tailb)));
		delete_add(a);
	}
	if ((*stka)->stk == 2)
	{
		taila = partition_b(stka, stkb, *b);
		ft_add_front(a, ft_new_add(taila, ft_stacksize_n(taila)));
		delete_add(b);
	}
}

void	sort(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	if (!*a && *stka)
		ft_add_front(a, ft_new_add(ft_stacklast(*stka), ft_stacksize(*stka));
	if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) > 3)
		sorting(stka, stkb, a, b);
	else if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) == 3)
		three_case_part(stka, (*a)->tail);
	else if (!issorted(*stka) && ft_stacksize_n(*stka, (*a)->tail) == 2)
		s_ab(stka);
	if (!*b && *stkb && issorted(*stka))
		ft_add_front(b, ft_new_add(ft_stacklast(*stkb), ft_stacksize(*stkb)));
	if (issorted(*stka) && *stkb)
	{
		if (issorted(*stkb))
			push_number(stkb, stka);
		else
			sorting(stkb, stka, a, b);
	}
	if (!issorted(*stka) || *stkb)
		sort(stka, stkb, a, b);
}
