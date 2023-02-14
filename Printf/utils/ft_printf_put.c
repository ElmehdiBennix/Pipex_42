/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:14:29 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 19:03:46 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printstr(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (ft_printstr("(null)"));
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_printunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n < 10)
	{
		i += ft_printchar(n + '0');
	}
	else
	{
		i += ft_printunsigned(n / 10);
		i += ft_printunsigned(n % 10);
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_printstr("-2147483648");
	}
	else if (n >= 0 && n < 10)
	{
		i += ft_printchar(n + '0');
	}
	else
	{
		if (n < 0)
		{
			i += ft_printchar('-');
			i += ft_printnbr(n * (-1));
		}
		else
		{
			i += ft_printnbr(n / 10);
			i += ft_printnbr(n % 10);
		}
	}
	return (i);
}
