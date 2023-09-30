/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:07:05 by otawatanabe       #+#    #+#             */
/*   Updated: 2023/09/30 12:15:26 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	print_16(unsigned long u, int c)
{
	char	s[16];
	int		i;
	int		j;

	i = 16;
	while (u && i--)
	{
		s[i] = "0123456789abcdef"[u % 16];
		u /= 16;
	}
	if (i == 16)
		s[--i] = '0';
	if (c == 'p')
		return (write(1, "0x", 2) + write(1, s + i, 16 - i));
	if (c == 'X')
	{
		j = i;
		while (j++ < 16)
			s[j - 1] = ft_toupper(s[j - 1]);
	}
	return (write(1, s + i, 16 - i));
}

ssize_t	putnbr_count(long n)
{
	long	i;
	char	c;
	ssize_t	r;

	i = n;
	r = 0;
	if (n < 0)
	{
		r += write(1, "-", 1);
		i = -i;
	}
	if (i > 9)
		r += putnbr_count(i / 10);
	c = '0' + i % 10;
	return (r + write(1, &c, 1));
}

long	check_specifier(va_list *ap, char c)
{
	char	*s;

	if (c == '%')
		return (write(1, &c, 1));
	else if (c == 'c')
	{
		c = va_arg(*ap, int);
		return (write(1, &c, 1));
	}
	else if (c == 's')
	{
		s = va_arg(*ap, char *);
		if (s)
			return (write(1, s, ft_strlen(s)));
		return (write(1, "(null)", 6));
	}
	else if (c == 'p')
		return (print_16(va_arg(*ap, unsigned long), c));
	else if (c == 'x' || c == 'X')
		return (print_16(va_arg(*ap, unsigned int), c));
	else if (c == 'd' || c == 'i')
		return (putnbr_count(va_arg(*ap, int)));
	else if (c == 'u')
		return (putnbr_count(va_arg(*ap, unsigned int)));
	return (LONG_MIN);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*s;
	long	r;

	va_start(ap, fmt);
	s = (char *) fmt;
	r = 0;
	while (r >= 0 && *s != 0)
	{
		fmt = ft_strchr(s, '%');
		if (fmt == NULL)
		{
			r += write(1, s, ft_strlen(s));
			break ;
		}
		r += write(1, s, fmt - s);
		r += check_specifier(&ap, *(fmt + 1));
		s = (char *)fmt + 2;
	}
	va_end(ap);
	if (r > INT_MAX || r < 0)
		return (-1);
	return ((int)r);
}
