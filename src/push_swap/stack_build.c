/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:28:22 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/06 01:35:42 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free2d(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s[i]);
		free(s);
	}
}

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
				free2d(hold);
				return (error_message(stka, stkb, 0));
			}
			stack_addback(stka, newstack(ft_atoi(hold[j])));
			j++;
		}
		free2d(hold);
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
