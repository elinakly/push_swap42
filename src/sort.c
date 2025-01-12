/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:55:05 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/12 16:29:06 by eklymova         ###   ########.fr       */
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
