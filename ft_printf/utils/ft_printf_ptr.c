/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:56:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 19:03:43 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		i += ft_printchar(n + '0');
	else if (n >= 10 && n <= 15)
		i += ft_printchar(n + 'W');
	else
	{
		i += ft_printptr(n / 16);
		i += ft_printptr(n % 16);
	}
	return (i);
}
