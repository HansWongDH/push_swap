/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:29:27 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/25 00:36:29 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;
	t_add	*a;
	t_add	*b;

	stka = NULL;
	stkb = NULL;
	a = NULL;
	b = NULL;
	if (argc > 1)
		stack_build(argc, argv, &stka, &stkb);
	if (!ft_checkdup(stka))
		return (error_message(&stka, &stkb, 0));
	ft_add_front(&a, ft_new_add(NULL, ft_stacksize(stka)));
	sort(&stka, &stkb, &a, &b);
	free_add(&a, &b);
	return (error_message(&stka, &stkb, 1));
}
