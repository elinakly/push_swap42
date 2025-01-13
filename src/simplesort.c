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

t_stuck	*min(t_stuck **stuck_a)
{
	t_stuck	*min_node;
	t_stuck	*current;

	current = *stuck_a;
	min_node = current;

	while (current)
	{
		if (current->node < min_node->node)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	sort_3(t_stuck **stuck_a)
{
	// print_stuck(*stuck_a);
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
		printf("list is empty\n");
}

void	sort_4(t_stuck **stuck_a, t_stuck **stuck_b)
{
	t_stuck	*minimum;

	printf("NAstuck_a _sort4\n");
	print_stuck(*stuck_a);
	printf("NAstuck_b _sort4\n");
	print_stuck(*stuck_b);
	minimum = min(stuck_a);
	printf("min is %d\n", minimum->node);
	ft_lstadd_front1(stuck_a, minimum);

	printf("terstuck_a _sort4\n");
	// print_stuck(*stuck_a);
	printf("terstuck_b _sort4\n");
	print_stuck(*stuck_b);

	pa(stuck_a, stuck_b);

	printf("yesstuck_a _sort4\n");
	print_stuck(*stuck_a);
	printf("yesstuck_b _sort4\n");
	print_stuck(*stuck_b);


	sort_3(stuck_a); //aint work
	pb(stuck_b, stuck_a);
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
