/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:55:42 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/20 17:02:30 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stuck(int argc, char **args, t_stuck **stuck_a)
{
	int		i;
	t_stuck	*new;

	i = 1;
	if (argc == 2)
		i = 0;
	while (args[i])
	{
		new = ft_lstnew1(ft_atoi(args[i]));
		if (!new)
			return (0);
		ft_lstadd_back1(stuck_a, new);
		i++;
	}
	return (1);
}

static void	sort(t_stuck **stuck_a, t_stuck **stuck_b)
{
	if (ft_lstsize1(*stuck_a) <= 5)
		simplesort(stuck_a, stuck_b);
	else
		radix(stuck_a, stuck_b);
}

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

int	main(int argc, char *argv[])
{
	t_stuck	*stuck_a;
	t_stuck	*stuck_b;
	char	**args;

	args = argv;
	stuck_a = NULL;
	stuck_b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && (!argv[1][0] || !ft_strncmp(argv[1], " ", 2)))
		return (write(2, "Error\n", 6), 0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (free(argv), write(2, "Error\n", 6), 0);
	}
	if (!validinput(argc, args))
		return (free_argv(argc, args), write(2, "Error\n", 6), 0);
	init_stuck(argc, args, &stuck_a);
	if (ifsorted(stuck_a))
		return (free_argv(argc, args), del_node(&stuck_a), 0);
	sort(&stuck_a, &stuck_b);
	return (free_argv(argc, args), del_node(&stuck_a), 0);
}
