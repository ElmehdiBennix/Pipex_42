/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:51:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 20:44:18 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hex(unsigned int n, char flag)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		i += ft_printchar(n + '0');
	else if (n >= 10 && n <= 15)
	{
		if (flag == 'x')
			i += ft_printchar(n + 'W');
		else
			i += ft_printchar(n + '7');
	}
	else
	{
		i += ft_hex(n / 16, flag);
		i += ft_hex(n % 16, flag);
	}
	return (i);
}
