/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:26 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 10:35:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s)
{
    size_t i = 0;
    char *str;
    
    str=(char *)malloc((ft_strlen(s)+1)*sizeof(char));
    if (!str)
        return NULL;
    while (s[i])
    {
        str[i]=s[i];
        i++;
    }
    str[i]='\0';
    return str;
}

char** ft_split(const char *str, char delimiter)
{
    char *tmp = ft_strdup(str);
    char *p = tmp;
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
    //if() must add protection
    i = 0;
    count = 0;
    p = tmp;
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
    free(tmp);
    result[count] = NULL;
    return result;
}

int main() 
{
    char *str = ",,,hello,,world,and,fellow,,cowboyz,,,";
    char **res = ft_split(str,',');
    int i = 0;
    while(res[i])
    {
        printf("%s\n",res[i]);
        i++;
    }
    printf("%s",res[i++]);
    while (1){
        // leaks check 
        // fixed
    }
}
