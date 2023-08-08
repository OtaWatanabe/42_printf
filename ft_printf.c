/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:07:05 by otawatanabe       #+#    #+#             */
/*   Updated: 2023/08/08 03:29:14 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char * fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt != '%')
            write(1, fmt, 1);
        else
        {
            
        }
    }
        
}