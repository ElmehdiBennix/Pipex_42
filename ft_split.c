/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:26 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 10:50:16 by ebennix          ###   ########.fr       */
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

char** ft_split(const char *str, char c)
{
    char **res;
    char *tmp = ft_strdup(str);
    char *p = tmp;
    int i;
    int word = 0;

    while (*p) 
    {
        while (*p == c)
            p++;
        if(*p)
        {
            while (*p != '\0' && *p != c) 
                p++;
            word++;
        }
    } 
    res = (char **)malloc((word + 1) * sizeof(char *));
    //if() must add protection
    i = 0;
    word = 0;
    p = tmp;
    while (*p)
    {
        while (*p == c)
            p++;
        if (*p)
        {
            while (*p && *p != c)
            {
                i++;
                p++;
            }
            res[word] = p - i;
            *p = '\0';
            word++;
            p++;
            i=0;
        }
    }
    free(tmp);
    res[word] = NULL;
    return res;
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
