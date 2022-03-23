/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:30:00 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/23 20:37:38 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	int				num;
	int				stk;
	struct s_stack	*next;
}	t_stack;

int		r_ab(t_stack **stack);
int		p_ab(t_stack **stacka, t_stack **stackb);
int		rr_ab(t_stack **stack);
int		s_ab(t_stack **stk);
int		ft_checkdigit(char **str);
int		ft_isover(char **str);
int		ft_checkdup(t_stack *stack);
int		issorted(t_stack *stk);
void	free_stack(t_stack **stack);
t_stack	*newstack(int n);
void	stack_addback(t_stack **stk, t_stack *new);
int		ft_stacksize(t_stack *stk);
t_stack	*ft_stacklast(t_stack *stk);
t_stack	*ft_iter_stop(t_stack *stk, t_stack *last);

#endif