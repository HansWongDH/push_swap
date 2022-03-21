/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:29:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 04:49:29 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	split_a(t_stack **stka, t_stack **stkb, t_add **a, t_add **b)
{
	t_stack	*tailb;

	if (!issorted(*stka) && ft_stacksize(*stka) > 3)
	{
		tailb = partition_a2(stka, stkb, ft_stacklast(*stka));
		ft_add_front(b, ft_new_add(tailb, ft_stacksize_n(*stkb, tailb)));
		split_a(stka, stkb, a, b);
	}
}
*/

void	printtest(t_stack **stka, t_add *a)
{
	t_stack	*last;

	last = a->tail;
	while (*stka != last)
	{
		printf("Linked list a : %d \n", (*stka)->num);
		*stka = (*stka)->next;
	}
}
int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_add	*a;
	t_add	*b;
	int		i;
	int		size;

	i = 1;
	size = 0;
	stacka = NULL;
	stackb = NULL;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			stack_addback(&stacka, newstack(atoi(argv[i])));
			i++;
		}
	}
	ft_add_front(&a, ft_new_add(NULL, ft_stacksize(stacka)));
	//split_a(&stacka, &stackb, &a, &b);
	sort(&stacka, &stackb, &a, &b);
	//printtest(&stacka, a);
/*	while (stacka)
	{
		printf("Linked list a :%d \n", stacka->num);
		stacka = stacka->next;
	}
	printf("-------------------\n");
	while (stackb)
	{
		printf("Linked list b :%d \n", stackb->num);
		stackb = stackb->next;
	}*/
}
