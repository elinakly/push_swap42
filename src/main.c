/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:55:42 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/12 19:05:14 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	init_stuck(int argc, char **argv, t_stuck **stuck_a)
{
	int		i;
	char	**args;
	t_stuck	*new;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (ft_printf("split faild\n"), 0);
	}
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		new = ft_lstnew1(ft_atoi(args[i]));
		if (!new)
			return (ft_printf("problem with the init stuck\n"), 0);
		ft_lstadd_back1(stuck_a, new);
		i++;
	}
	t_stuck *tmp = *stuck_a;  // print the list
	while (tmp)
	{
		ft_printf("%d\n", tmp->node);
		tmp = tmp->next;
	}
	return (1);
}

void sort(t_stuck **stuck_a, t_stuck **stuck_b)
{
	if (ft_lstsize1(stuck_a) <= 5)
		simplesort(stuck_a, stuck_b);
	(void)stuck_b;
		
	// else
		// radix(stuck_a, stuck_b);
}

int	main(int argc, char *argv[])
{
	t_stuck	*stuck_a;
	t_stuck	*stuck_b;

	stuck_a = NULL;
	stuck_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 0);
	if (!validinput(argc, argv))
		return (0);
	init_stuck(argc, argv, &stuck_a);
	
	if (!ifsorted(stuck_a))
		ft_printf("non sorted\n");
	else
	{
		ft_printf("already sorted\n");
		return (0);
	}
	sort(&stuck_a, &stuck_b);
	return (0);
}
