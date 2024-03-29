/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:59:31 by hyeopark          #+#    #+#             */
/*   Updated: 2021/06/19 17:03:17 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(t_stack *s)
{
	int		max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

void		sort_3(t_stacks *stacks)
{
	int		max;

	max = ft_max(stacks->a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->data == max)
			ra(&stacks->a, 1);
		if (stacks->a->next->data == max)
			rra(&stacks->a, 1);
		if (stacks->a->data > stacks->a->next->data)
			sa(stacks->a, 1);
	}
}

void		sort_5(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->a->data == stacks->min || stacks->a->data == stacks->max)
			pb(stacks, 1);
		else
			ra(&stacks->a, 1);
	}
	sort_3(stacks);
	pa(stacks, 1);
	pa(stacks, 1);
	if (stacks->a->data == stacks->max)
	{
		ra(&stacks->a, 1);
	}
	else
	{
		sa(stacks->a, 1);
		ra(&stacks->a, 1);
	}
}
