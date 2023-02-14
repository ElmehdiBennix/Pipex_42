/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:45:39 by ebennix           #+#    #+#             */
/*   Updated: 2022/11/19 16:34:38 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char str, va_list arg)
{
	if (str == 'c')
		return (ft_printchar(va_arg(arg, int)));
	else if (str == 's')
		return (ft_printstr(va_arg(arg, char *)));
	else if (str == 'p')
	{
		write(1, "0x", 2);
		return (ft_printptr(va_arg(arg, unsigned long)) + 2);
	}
	else if (str == 'i' || str == 'd')
		return (ft_printnbr(va_arg(arg, int)));
	else if (str == 'u')
		return (ft_printunsigned(va_arg(arg, unsigned int)));
	else if (str == 'x')
		return (ft_lowhex(va_arg(arg, unsigned int)));
	else if (str == 'X')
		return (ft_caphex(va_arg(arg, unsigned int)));
	else if (str == '%')
		return (ft_printchar('%'));
	else
		return (ft_printchar(str));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		value;

	i = 0;
	value = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			value += check(str[i], arg);
		}
		else
			value += write (1, &str[i], 1);
			i++;
	}
	va_end(arg);
	return (value);
}
