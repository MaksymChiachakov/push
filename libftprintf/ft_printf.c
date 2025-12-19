/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:49:17 by mchiacha          #+#    #+#             */
/*   Updated: 2025/12/19 12:49:20 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;

	if (!str)
		return (-1);
	va_start(ap, str);
	cnt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (!*(str + 1))
				return (-1);
			cnt += ft_putarg(ap, *(++str));
		}
		else
		{
			write(1, str, 1);
			cnt++;
		}
		str++;
	}
	va_end(ap);
	return (cnt);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a = -2147483648;
	char str[] = "hello";
	char c = 'A';
	unsigned int u = 42;

	ft_printf("         int : %d, ", a);
	printf("%d\n", a);
	ft_printf("      string : %s, ", str);
	printf("%s\n", str);
	ft_printf("        char : %c, ", c);
	printf("%c\n", c);
	ft_printf("    unsigned : %u, ", u);
	printf("%u\n", u);
	ft_printf("  hexa lower : %x, ", u);
	printf("%x\n", u);
	ft_printf("  hexa upper : %X, ", u);
	printf("%X\n", u);
	ft_printf("     pointer : %p, ", str);
	printf("%p\n", str);
	ft_printf(" null string : %s, ", (char *)NULL);
	printf("%s\n", (char *)NULL);
	ft_printf("null pointer : %p, ", NULL);
	printf("%p\n", NULL);
	
	// int cnt;
	// ft_printf("\ntest str = NULL\n");
	// cnt = ft_printf(NULL);
	// ft_printf("res = %d\n", cnt);
	// cnt = printf(NULL);
	// ft_printf("res = %d\n", cnt);
	// cnt = ft_printf("test printf %w");
	// ft_printf("\nres = %d\n", cnt);
	// cnt = printf("test printf %w");
	// printf("\nres = %d\n", cnt);
	// cnt = ft_printf("test printf %");
	// ft_printf("\nres = %d\n", cnt);
	// cnt = printf("test printf %");
	// printf("\nres = %d\n", cnt);
	// ft_printf("%p\n", -1);
	// printf("%p\n", -1);
	// return (0);

	return (0);
}
*/
