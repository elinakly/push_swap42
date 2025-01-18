/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:07:06 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/13 18:02:05 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stuck **stuck_a)
{
	if (stuck_a && *stuck_a && (*stuck_a)->next)
	{
		if ((*stuck_a)->node > (*stuck_a)->next->node)
			sa(stuck_a);
		if ((*stuck_a)->node > (*stuck_a)->next->next->node)
			rra(stuck_a);
		else if ((*stuck_a)->node < (*stuck_a)->next->next->node)
			ra(stuck_a);
	}
	else
		ft_printf("list is empty\n");
}

void	index3(t_stuck **stuck_a, t_stuck **stuck_b)
{
	rra(stuck_a);
	rra(stuck_a);
	pb(stuck_a, stuck_b);
}

void	sort_4(t_stuck **stuck_a, t_stuck **stuck_b)
{
	t_stuck	*minimum;

	minimum = min(stuck_a);
	argv_index(*stuck_a);
	printf("Minimum index: %d\n", minimum->index);
	if (minimum->index == 0)
		pb(stuck_a, stuck_b);
	else if (minimum->index == 1)
	{
		ra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (minimum->index == 2)
	{
		rra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (minimum->index == 3)
		index3(stuck_a, stuck_b);
	sort_3(stuck_a);
	pa(stuck_b, stuck_a);
}

void	sort_5(t_stuck **stuck_a, t_stuck **stuck_b)
{
	t_stuck	*minimum;

	minimum = min(stuck_a);
	argv_index(*stuck_a);
	if (minimum->index == 0)
		pb(stuck_a, stuck_b);
	else if (minimum->index == 1)
	{
		ra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (minimum->index == 2)
	{
		rra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (minimum->index == 3)
		index3(stuck_a, stuck_b);
	else if (minimum->index == 4)
	{
		ra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	sort_4(stuck_a, stuck_b);
	pa(stuck_b, stuck_a);
}

void	simplesort(t_stuck **stuck_a, t_stuck **stuck_b)
{
	if (ft_lstsize1(*stuck_a) == 2)
		sa(stuck_a);
	if (ft_lstsize1(*stuck_a) == 3)
		sort_3(stuck_a);
	if (ft_lstsize1(*stuck_a) == 4)
		sort_4(stuck_a, stuck_b);
	if (ft_lstsize1(*stuck_a) == 5)
		sort_5(stuck_a, stuck_b);
}
