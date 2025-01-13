/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:28:00 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/12 21:22:13 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	sa(t_stuck **stack_a)
{
	int	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->node;
	(*stack_a)->node = (*stack_a)->next->node;
	(*stack_a)->next->node = tmp;
	ft_printf("sa\n");
}

void	ra(t_stuck **stack_a)
{
	t_stuck	*tmp;
	t_stuck	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	ft_printf("ra\n");
}

void	rra(t_stuck **stack_a)
{
	t_stuck	*tmp;
	t_stuck	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

void pa ()
void pb ()