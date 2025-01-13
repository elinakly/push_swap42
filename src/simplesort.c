/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:07:06 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/12 21:25:43 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stuck *min(t_stuck **stuck_a)
{
	t_stuck *min_node;
	t_stuck *current;

	current = *stuck_a;
	min_node = current;

	while (current)
	{
		if(current->node < min_node->node)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	sort_3(t_stuck **stuck_a)
{
	if ((*stuck_a)->node > (*stuck_a)->next->node)
		sa(stuck_a);
	if ((*stuck_a)->node > (*stuck_a)->next->next->node)
		rra(stuck_a);
	else if ((*stuck_a)->node < (*stuck_a)->next->next->node)
		ra(stuck_a);
}

void	sort_4(t_stuck **stuck_a)
{
	t_stuck min;

	min = min(stuck_a);
	
}

void	simplesort(t_stuck **stuck_a, t_stuck **stuck_b)
{
	if (ft_lstsize1(stuck_a) == 2)
		sa(stuck_a);
	if (ft_lstsize1(stuck_a) == 3)
		sort_3(stuck_a);
	if (ft_lstsize1(stuck_a) == 4)
		sort_4(stuck_a, stuck_b);
	// if (ft_lstsize1 == 5)
}
