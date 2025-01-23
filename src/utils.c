/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:55:05 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/20 16:29:15 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_index(t_stuck *stuck_a)
{
	t_stuck	*tmp;
	int		i;

	i = 0;
	tmp = stuck_a;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

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

t_stuck	*max(t_stuck **stuck_a)
{
	t_stuck	*tmp;
	t_stuck	*max;

	tmp = *stuck_a;
	max = tmp;
	while (tmp)
	{
		if (tmp->node > max->node)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	free_argv(int argc, char **args)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	del_node(t_stuck **stuck)
{
	t_stuck	*tmp;

	while ((*stuck)->next)
	{
		tmp = *stuck;
		*stuck = (*stuck)->next;
		free(tmp);
	}
	free(*stuck);
}
