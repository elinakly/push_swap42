/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:02:26 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/13 20:55:58 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize1(t_stuck *stuck_a)
{
	int		i;
	t_stuck	*tmp;

	i = 0;
	tmp = stuck_a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	ft_printf("size of the list is %d\n", i);
	return (i);
}

t_stuck	*ft_lstnew1(int content)
{
	t_stuck	*node;

	node = (t_stuck *)malloc(sizeof(t_stuck));
	if (!node)
		return (NULL);
	node->node = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back1(t_stuck **stuck_a, t_stuck *new)
{
	t_stuck	*tmp;

	if (!new)
		return ;
	if (!*stuck_a)
	{
		*stuck_a = new;
		return ;
	}
	tmp = *stuck_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
