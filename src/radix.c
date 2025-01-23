/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:50:21 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/15 22:21:34 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(int *array, t_stuck *current)
{
	int	i;

	i = 0;
	while (current)
	{
		array[i++] = current->node;
		current = current->next;
	}
}

static void	buble_sorted_values(t_stuck *stack, int *sorted_values, int size)
{
	int		j;
	int		k;
	int		temp_val;

	j = 0;
	fill_array(sorted_values, stack);
	while (j < size - 1)
	{
		k = j + 1;
		while (k < size)
		{
			if (sorted_values[j] > sorted_values[k])
			{
				temp_val = sorted_values[j];
				sorted_values[j] = sorted_values[k];
				sorted_values[k] = temp_val;
			}
			k++;
		}
		j++;
	}
}

static void	assign_index(t_stuck *stack, int size)
{
	t_stuck	*current;
	int		*sorted_values;
	int		j;

	current = stack;
	sorted_values = malloc(size * sizeof(int));
	if (!sorted_values)
		return ;
	buble_sorted_values(stack, sorted_values, size);
	current = stack;
	while (current)
	{
		j = 0;
		while (j < size)
		{
			if (current->node == sorted_values[j])
			{
				current->index = j + 1;
				break ;
			}
			j++;
		}
		current = current->next;
	}
	free(sorted_values);
}

static void	radix_sort(int max_bits, t_stuck **stack_a,
		t_stuck **stack_b, int size)
{
	int	bit;
	int	i;

	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		bit++;
	}
}

void	radix(t_stuck **stack_a, t_stuck **stack_b)
{
	int	size;
	int	max_bits;

	size = ft_lstsize1(*stack_a);
	assign_index(*stack_a, size);
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	radix_sort(max_bits, stack_a, stack_b, size);
}
