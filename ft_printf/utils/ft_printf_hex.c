/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:51:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 19:03:40 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_lowhex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		i += ft_printchar(n + '0');
	else if (n >= 10 && n <= 15)
		i += ft_printchar(n + 'W');
	else
	{
		i += ft_lowhex(n / 16);
		i += ft_lowhex(n % 16);
	}
	return (i);
}

int	ft_caphex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		i += ft_printchar(n + '0');
	else if (n >= 10 && n <= 15)
		i += ft_printchar(n + '7');
	else
	{
		i += ft_caphex(n / 16);
		i += ft_caphex(n % 16);
	}
	return (i);
}
