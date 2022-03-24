/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:29:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/24 18:29:47 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;
	t_add	*a;
	t_add	*b;
	int		i;

	i = 1;
	stka = NULL;
	stkb = NULL;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (!ft_checkdigit(argv) || !ft_isover(argv) || argc <= 2)
			return (error_message(&stka, &stkb, 0));
		while (i < argc)
			stack_addback(&stka, newstack(ft_atoi(argv[i++])));
	}
	if (!ft_checkdup(stka))
		return (error_message(&stka, &stkb, 0));
	ft_add_front(&a, ft_new_add(NULL, ft_stacksize(stka)));
	sort(&stka, &stkb, &a, &b);
	free_add(&a, &b);
	return (error_message(&stka, &stkb, 1));
}
