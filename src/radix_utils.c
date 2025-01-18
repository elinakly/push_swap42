#include "push_swap.h"

int	find_min(t_stuck *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->node < min)
			min = stack->node;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stuck *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->node > max)
			max = stack->node;
		stack = stack->next;
	}
	return (max);
}