/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:48:42 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:48:44 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putarg(va_list ap, char c);
int	ft_putint(int n);
int	ft_putstr(char *str);
int	ft_intlen(unsigned long int n, unsigned long int base_len);
int	ft_putunsigned(unsigned long int n, char *base);
int	ft_putptr(void *ptr);

#endif
