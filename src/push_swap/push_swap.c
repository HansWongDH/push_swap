/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:29:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 17:48:18 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_checkdup(t_stack *stack)
{
	t_stack	*stk1;
	t_stack	*stk2;

	stk1 = stack;
	while (stk1)
	{
		stk2 = stk1->next;
		while (stk2)
		{
			if (stk1->num == stk2->num)
				return (0);
			stk2 = stk2->next;
		}
		stk1 = stk1->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_add	*a;
	t_add	*b;
	int		i;

	i = 1;
	stacka = NULL;
	stackb = NULL;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (!ft_checkdigit(argv) || !ft_isover(argv))
			return (write(2, "error\n", 6));
		while (i < argc)
			stack_addback(&stacka, newstack(ft_atoi(argv[i++])));
	}
	if (!ft_checkdup(stacka))
		return (write(2, "error\n", 6));
	ft_add_front(&a, ft_new_add(NULL, ft_stacksize(stacka)));
	sort(&stacka, &stackb, &a, &b);
	free_stack(&stacka);
	free_add(&a);
	system("leaks push_swap");
	return (0);
}
