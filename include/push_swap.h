/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:57:01 by eklymova          #+#    #+#             */
/*   Updated: 2025/01/12 21:23:28 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stuck
{
    int     node;
    int     index;
    struct s_stuck  *next;
}t_stuck;

int     validinput(int argc, char **argv);
int     ifsorted(t_stuck *stuck_a);
int     ft_lstsize1(t_stuck **stuck_a);
t_stuck *ft_lstnew1(int content);
void	ft_lstadd_back1(t_stuck **stuck_a, t_stuck *new);
void     simplesort(t_stuck **stuck_a, t_stuck **stuck_b);
void	sa(t_stuck **stack_a);
// void	sb(t_stuck **stack_b);
void	rra(t_stuck **stack_a);
void	ra(t_stuck **stack_a);
void	ft_lstadd_front1(t_stuck **stuck_a, t_stuck *new);
void	pb(t_stuck **stack_b, t_stuck **stack_a);
void	pa(t_stuck **stack_a, t_stuck **stack_b);
void    print_stuck(t_stuck *stuck_a);
#endif