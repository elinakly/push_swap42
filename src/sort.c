/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:55:05 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/13 22:03:35 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ifsorted(t_stuck *stuck_a)
{
	t_stuck	*temp;

	if ((!stuck_a))
		return (0);
	temp = stuck_a;
	while ((temp)->next)
	{
		if (temp->node > temp->next->node)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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

void	free_argv(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
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
