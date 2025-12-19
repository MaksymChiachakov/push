/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:46:04 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:46:06 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/libftprintf.h"
# include <stdbool.h>

typedef struct s_stack
{
	int		*tab;
	int		bottom;
	int		top;
	int		size;
	int		count;
}			t_stack;

typedef struct s_args
{
	char	**av;
	bool	free_args;
}			t_args;

typedef enum e_rotations
{
	UP_UP,
	DOWN_DOWN,
	UP_DOWN,
	DOWN_UP,
}			t_rotations;

typedef struct s_map
{
	int		value;
	int		pos;
}			t_map;

void		free_args(t_args args);
int			nb_param(char **av);

void		free_stacks(t_stack *stack_a, t_stack *stack_b);
void		ft_put_error(t_stack *stack_a, t_stack *stack_b, t_args args);
bool		is_valid_int(char *str);
bool		is_in_stack(t_stack stack, int x);

void		stack_init(int cnt, t_args args, t_stack *a, t_stack *b);
void		print_stacks(t_stack a, t_stack b);
void		push(t_stack *stack, int x);
int			pop(t_stack *stack);
int			peek(t_stack *stack);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);

void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		ft_push_swap(t_stack a, t_stack b);
void		sort3(t_stack *stack_a);
int			*normalize(int *tab, int size);

int			get_index(t_stack stack, int value);
int			get_cost(t_stack a, t_stack b, int value, t_rotations *r);
void		greedy_sort(t_stack *a, t_stack *b);

int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			find_value(t_stack a, t_stack b, t_rotations *r_min);
void		rotate_ascending_order(t_stack *a);

void		rotate_up_up(t_stack *a, t_stack *b, int pos_t, int pos_v);
void		rotate_down_down(t_stack *a, t_stack *b, int pos_t, int pos_v);
void		rotate_up_down(t_stack *a, t_stack *b, int pos_t, int pos_v);
void		rotate_down_up(t_stack *a, t_stack *b, int pos_t, int pos_v);

#endif
