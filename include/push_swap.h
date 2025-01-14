/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:57:01 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/13 21:51:02 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stuck
{
	int				node;
	int				index;
	struct s_stuck	*next;
}t_stuck;

int     validinput(int argc, char **argv);
int     ifsorted(t_stuck *stuck_a);
int     ft_lstsize1(t_stuck **stuck_a);
t_stuck *ft_lstnew1(int content);
void    ft_lstadd_back1(t_stuck **stuck_a, t_stuck *new);
void    simplesort(t_stuck **stuck_a, t_stuck **stuck_b);
void	sa(t_stuck **stack_a);
void	rra(t_stuck **stack_a);
void	ra(t_stuck **stack_a);
void	pb(t_stuck **stack_b, t_stuck **stack_a);
void	pa(t_stuck **stack_a, t_stuck **stack_b);
void    print_stuck(t_stuck *stuck_a);
int     argv_index(t_stuck *stuck_a);
t_stuck	*min(t_stuck **stuck_a);
void	free_argv(int argc, char **args);
void	del_node(t_stuck **stuck);
#endif