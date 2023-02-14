/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:36:07 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 16:36:08 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;

	write (1, "output", 10);
	str = calloc(sizeof(char), 1000);
	read (0, str, 1000);
	write (1, str, 1000);
	free (str);
}
