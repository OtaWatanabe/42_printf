/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:07:05 by otawatanabe       #+#    #+#             */
/*   Updated: 2023/08/27 05:11:03 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char * print_16(unsigned int u)
{
	char s[9];
	size_t i;

	i = 8;
	while (i--) 
	{
		s[i] = "0123456789ABCDEF"[u % 16];
		u /= 16;
	}
	s[8] = 0;
	return (s);
}

va_list check_specifier(va_list ap, char c)
{
	if (c == '%')
		ft_putchar_fd(c, 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(ap, char), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p' || c == 'x')
		ft_putstr_fd(print_16(va_arg(ap, unsigned int)), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_putstr_fd(va_arg(ap, unsigned int), 1);
	else if (c == 'X');
		ft_putstr_fd(ft_toupper(print_16(va_arg(ap, unsigned int))), 1);
	return (ap);
}

int ft_printf(const char * fmt, ...)
{
    va_list	ap;
    char	*s;

    va_start(ap, fmt);
	s = fmt;
    while (fmt)
    {
		if (*fmt != '%')
		{
			fmt = ft_strchr(fmt, '%');
			if (fmt == NULL)
				write(1, s, ft_strlen(fmt));
			write(1, s, fmt - s);
		}
        else if (*(++fmt) == '%')
			ft_putchar_fd(*fmt++, 1);
		else
			ap = check_specifier(ap, *fmt);
		s = ++fmt;
	}
}
