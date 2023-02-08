/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:26 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 10:04:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** ft_split(const char *str, char delimiter)
{
    char *p = ft_strdup(str);
    char **result;
    int count = 0;
    int i;

    while (*p) 
    {
        while (*p == delimiter)
            p++;
        if(*p)
        {
            while (*p != '\0' && *p != delimiter) 
                p++;
            count++;
        }
    } 
    result = (char **)malloc((count + 1) * sizeof(char *));

    i = 0;
    count = 0;
    p = ft_strdup(str);
    while (*p)
    {
        while (*p == delimiter)
            p++;
        if (*p)
        {
            while (*p && *p != delimiter)
            {
                i++;
                p++;
            }
            result[count] = p - i;
            *p = '\0';
            count++;
            p++;
            i=0;
        }
    }
    result[count] = NULL;
    return result;
}

int main() 
{
    char *str = ",,,hello,,world,f,oo,,bar,,,";
    char **res = ft_split(str,',');
    int i = 0;
    while(res[i])
    {
        printf("%s",res[i]);
        i++;
    }
    return 0;
}
