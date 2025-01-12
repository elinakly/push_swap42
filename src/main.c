/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:55:42 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/09 14:20:07 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	// t_stuck	*stuck_a;
	// t_stuck *stuck_b;

	// stuck_a = NULL;
	// stuck_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 0);
	if (!validinput(argc, argv))
		return (0);
	return (0);
}