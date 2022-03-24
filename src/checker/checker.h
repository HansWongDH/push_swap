/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:30:00 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/24 18:26:45 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "../push_swap/push_swap.h"
# include <unistd.h>
# include <stdlib.h>

int		r_com(t_stack **stack);
int		p_com(t_stack **stacka, t_stack **stackb);
int		rr_com(t_stack **stack);
int		s_com(t_stack **stk);
void	rrev_function(t_stack **stka, t_stack **stkb, char *str);
void	s_function(t_stack **stka, t_stack **stkb, char *str);
void	rev_function(t_stack **stka, t_stack **stkb, char *str);

#endif