/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:19:09 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/22 03:10:47 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_median(t_stack *stack, int size)
{
	int	*arr;
	int	i;
	int	median;

	if (!stack)
		return (0);
	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i] = stack->num;
		stack = stack->next;
		i++;
	}
	bubble_sort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

int	issorted(t_stack *stk)
{
	t_stack	*lst;

	lst = stk;
	while (lst && lst->next)
	{
		if (lst->stk == 1 && lst->num > lst->next->num)
			return (0);
		if (lst->stk == 2 && lst->num < lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	issortedtail(t_stack *lst, int len)
{
	while (len > 0 && lst && lst->next)
	{
		if (lst->stk == 1 && lst->num > lst->next->num)
			return (0);
		if (lst->stk == 2 && lst->num < lst->next->num)
			return (0);
		len--;
		lst = lst->next;
	}
	return (1);
}

