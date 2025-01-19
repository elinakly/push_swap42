/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:55:42 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/18 21:58:03 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	init_stuck(int argc, char **args, t_stuck **stuck_a)
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
			return (ft_printf("problem with the init stuck\n"), 0);
		ft_lstadd_back1(stuck_a, new);
		i++;
	}
	return (1);
}

void	print_stuck(t_stuck *stuck_a)
{
	t_stuck	*tmp;

	tmp = stuck_a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->node);
		tmp = tmp->next;
	}
}

void	sort(t_stuck **stuck_a, t_stuck **stuck_b)
{
	if (ft_lstsize1(*stuck_a) <= 5)
		simplesort(stuck_a, stuck_b);
	else
		radix(stuck_a, stuck_b);
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
		return (0);
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
