/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:08:50 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 21:14:26 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_function(t_stack **stka, t_stack **stkb, char *str)
{
	if (ft_strcmp(str, "ra\n"))
		r_ab(stka);
	if (ft_strcmp(str, "rb\n"))
		r_ab(stka);
	if (ft_strcmp(str, "rr\n"))
	{
		r_ab(stka);
		r_ab(stkb);
	}
}

void	s_function(t_stack **stka, t_stack **stkb, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		s_ab(stka);
	if (ft_strcmp(str, "sb\n"))
		s_ab(stka);
	if (ft_strcmp(str, "ss\n"))
	{
		s_ab(stka);
		s_ab(stkb);
	}
}

void	rrev_function(t_stack **stka, t_stack **stkb, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		rr_ab(stka);
	if (ft_strcmp(str, "rra\n"))
		rr_ab(stka);
	if (ft_strcmp(str, "rrr\n"))
	{
		rr_ab(stka);
		rr_ab(stkb);
	}
}

int	checker(t_stack **stka, t_stack **stkb, char *str)
{
	if (ft_strcmp(str, "sa\n") || ft_strcmp(str, "sb\n") || ft_strcmp(str, "ss\n"))
		s_function(stka, stkb, str);
	else if (ft_strcmp(str, "ra\n") || ft_strcmp(str, "rb\n"))
		rev_function(stka, stkb, str);
	else if (ft_strcmp(str, "rr\n"))
		rev_function(stka, stkb, str);
	else if (ft_strcmp(str, "rra\n") || ft_strcmp(str, "rrb\n"))
		rrev_function(stka, stkb, str);
	else if (ft_strcmp(str, "rrr\n"))
		rrev_function(stka, stkb, str);
	else if (ft_strcmp(str, "sa\n"))
		s_ab(stka);
	else if (ft_strcmp(str, "sb\n"))
		s_ab(stkb);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	*str;
	char	buf[1000];
	int		i;
	int		fd;

	i = 1;
	stacka = NULL;
	stackb = NULL;
	str = "haha";
	fd = 1;
	if (argc > 1)
	{
		if (!ft_checkdigit(argv) || !ft_isover(argv) || argc <= 2)
			return (write(2, "Error\n", 7));
		while (i < argc)
			stack_addback(&stacka, newstack(ft_atoi(argv[i++])));
	}
	if (!ft_checkdup(stacka))
		return (write(2, "Error\n", 7));
	while (fd)
		fd = read(0, buf, 20);
	while (get_next_line(fd, &str))
	{
		if (!checker(&stacka, &stackb, str))
		{
			free_stack(&stacka);
			free_stack(&stackb);
			return (0);
		}
	}
	if (!issorted(stacka))
		return (write(2, "not sorted\n", 7));
	else
		return (write(1, "Genius\n", 8));
}
