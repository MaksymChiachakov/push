/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andelalo <andelalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:45:40 by andelalo          #+#    #+#             */
/*   Updated: 2025/12/17 15:56:10 by andelalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../push_swap.h"

void	ft_checker(t_stack *a, t_stack *b);

void	pa_check(t_stack *a, t_stack *b);
void	pb_check(t_stack *a, t_stack *b);

void	ra_check(t_stack *a);
void	rb_check(t_stack *b);
void	rr_check(t_stack *a, t_stack *b);

void	rra_check(t_stack *a);
void	rrb_check(t_stack *b);
void	rrr_check(t_stack *a, t_stack *b);

void	sa_check(t_stack *a);
void	sb_check(t_stack *b);
void	ss_check(t_stack *a, t_stack *b);

#endif