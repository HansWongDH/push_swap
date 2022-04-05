/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:47:49 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/06 01:40:49 by wding-ha         ###   ########.fr       */
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

int	ft_checkdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	return (1);
}

int	ft_isover(char *str)
{
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

void	free_stack(t_stack **stka, t_stack **stkb)
{
	t_stack	*temp;

	while (*stka)
	{
		temp = (*stka)->next;
		free(*stka);
		*stka = temp;
	}
	while (*stkb)
	{
		temp = (*stkb)->next;
		free(*stkb);
		*stkb = temp;
	}
}

int	error_message(t_stack **stka, t_stack **stkb, int i)
{
	if (*stka || *stkb)
		free_stack(stka, stkb);
	if (i == 0)
		write(2, "Error\n", 6);
	exit(0);
}
