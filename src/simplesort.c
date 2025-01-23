/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:07:06 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/20 16:29:05 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stuck **stuck_a)
{
	t_stuck	*maximum;

	maximum = max(stuck_a);
	if (!ifsorted(*stuck_a))
	{
		if (*stuck_a == maximum)
			ra(stuck_a);
		if ((*stuck_a)->next == maximum)
			rra(stuck_a);
		if ((*stuck_a)->node > (*stuck_a)->next->node)
			sa(stuck_a);
	}
}

static void	sort_4(t_stuck **stuck_a, t_stuck **stuck_b)
{
	t_stuck	*minimum;

	minimum = min(stuck_a);
	argv_index(*stuck_a);
	if (minimum->index == 0)
		pb(stuck_a, stuck_b);
	else if (minimum->index == 1)
	{
		sa(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (minimum->index == 2)
	{
		rra(stuck_a);
		rra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (minimum->index == 3)
	{
		rra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	sort_3(stuck_a);
	pa(stuck_b, stuck_a);
}

static void	index5(t_stuck **stuck_a, t_stuck **stuck_b, int index)
{
	if (index == 3)
	{
		rra(stuck_a);
		rra(stuck_a);
		pb(stuck_a, stuck_b);
	}
	else if (index == 2)
	{
		ra(stuck_a);
		sa(stuck_a);
		pb(stuck_a, stuck_b);
	}
}

static void	sort_5(t_stuck **stuck_a, t_stuck **stuck_b)
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
		index5(stuck_a, stuck_b, 2);
	else if (minimum->index == 3)
		index5(stuck_a, stuck_b, 3);
	else if (minimum->index == 4)
	{
		rra(stuck_a);
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
