/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:47:49 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 20:11:06 by wding-ha         ###   ########.fr       */
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

int	ft_checkdigit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isover(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atol(str[i]) > 2147483647 || ft_atol(str[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_add(t_add **add)
{
	while (*add)
	{
		delete_add(add);
	}
}
