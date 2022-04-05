/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:28:22 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/05 12:27:59 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_build(int argc, char **argv, t_stack **stka, t_stack **stkb)
{
	char	**hold;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		hold = ft_split(argv[i++], ' ');
		j = 0;
		while (hold[j])
		{
			if (!ft_checkdigit(hold[j]) || !ft_isover(hold[j]))
			{
				free(hold);
				return (error_message(stka, stkb, 0));
			}
			stack_addback(stka, newstack(ft_atoi(hold[j])));
			free(hold[j]);
			j++;
		}
		free(hold);
	}
	return (1);
}

t_stack	*ft_iter_stop(t_stack *stk, t_stack *last)
{
	while (stk)
	{
		if (stk->next == last)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}
