/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:08:50 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/24 20:06:26 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(t_stack **stka, t_stack **stkb, char **str)
{
	if (!ft_strcmp(*str, "sa") || !ft_strcmp(*str, "sb"))
		s_function(stka, stkb, *str);
	else if (!ft_strcmp(*str, "ss"))
		s_function(stka, stkb, *str);
	else if (!ft_strcmp(*str, "ra") || !ft_strcmp(*str, "rb"))
		rev_function(stka, stkb, *str);
	else if (!ft_strcmp(*str, "rr"))
		rev_function(stka, stkb, *str);
	else if (!ft_strcmp(*str, "rra") || !ft_strcmp(*str, "rrb"))
		rrev_function(stka, stkb, *str);
	else if (!ft_strcmp(*str, "rrr"))
		rrev_function(stka, stkb, *str);
	else if (!ft_strcmp(*str, "pa"))
		p_com(stkb, stka);
	else if (!ft_strcmp(*str, "pb"))
		p_com(stka, stkb);
	else
	{
		freestr(str);
		return (0);
	}
	freestr(str);
	return (1);
}

int	sorted_message(t_stack **stka, t_stack **stkb)
{
	if (!issorted(*stka) || *stkb)
		write(1, "KO\n", 4);
	else
		write(1, "OK\n", 4);
	return (error_message(stka, stkb, 1));
}

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;
	char	*str;
	int		i;

	i = 1;
	stka = NULL;
	stkb = NULL;
	if (argc <= 1)
		return (error_message(&stka, &stkb, 0));
	if (argc > 1)
	{
		if (!ft_checkdigit(argv) || !ft_isover(argv))
			return (error_message(&stka, &stkb, 0));
		while (i < argc)
			stack_addback(&stka, newstack(ft_atoi(argv[i++])));
	}
	if (!ft_checkdup(stka) || issorted(stka))
		return (error_message(&stka, &stkb, 0));
	while (get_next_line(0, &str) > 0)
	{
		if (!checker(&stka, &stkb, &str))
			return (error_message(&stka, &stkb, 0));
	}
	return (sorted_message(&stka, &stkb));
}
