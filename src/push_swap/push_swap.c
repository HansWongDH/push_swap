/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:29:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 20:19:40 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!ft_checkdigit(argv) || !ft_isover(argv) || argc <= 2)
			return (write(2, "Error\n", 7));
		while (i < argc)
			stack_addback(&stacka, newstack(ft_atoi(argv[i++])));
	}
	if (!ft_checkdup(stacka))
		return (write(2, "Error\n", 7));
	ft_add_front(&a, ft_new_add(NULL, ft_stacksize(stacka)));
	sort(&stacka, &stackb, &a, &b);
	free_stack(&stacka);
	free_add(&a);
	return (0);
}
