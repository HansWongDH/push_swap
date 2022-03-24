/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:07:25 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/24 18:28:02 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_function(t_stack **stka, t_stack **stkb, char *str)
{
	if (!ft_strcmp(str, "ra"))
		r_com(stka);
	if (!ft_strcmp(str, "rb"))
		r_com(stkb);
	if (!ft_strcmp(str, "rr"))
	{
		r_com(stka);
		r_com(stkb);
	}
}

void	s_function(t_stack **stka, t_stack **stkb, char *str)
{
	if (!ft_strcmp(str, "sa"))
		s_com(stka);
	if (!ft_strcmp(str, "sb"))
		s_com(stkb);
	if (!ft_strcmp(str, "ss"))
	{
		s_com(stka);
		s_com(stkb);
	}
}

void	rrev_function(t_stack **stka, t_stack **stkb, char *str)
{
	if (!ft_strcmp(str, "rra"))
		rr_com(stka);
	if (!ft_strcmp(str, "rrb"))
		rr_com(stkb);
	if (!ft_strcmp(str, "rrr"))
	{
		rr_com(stka);
		rr_com(stkb);
	}
}
