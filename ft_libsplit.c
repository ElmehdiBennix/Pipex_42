/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:26 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 21:10:54 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t ft_strlen(const char *str)
{
    size_t i = 0;
    
    if(str == NULL || str[i] == '\0') {
        return 0 ;
    }else{
        while (str[i] != '\0')
            i++;
        return i ;
    }
}

static char *ft_strdup(const char *s)
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

// static char *splitdup(const char *s, int dex)
// {
//     size_t i = 0;
//     char *str;
    
//     str=(char *)malloc((ft_strlen(s)+1)*sizeof(char));
//     if (!str)
//         return NULL;
//     while (s[i] && i < dex)
//     {
//         str[i]=s[i];
//         i++;
//     }
//     str[i]='\0';
//     return str;
// }

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
    if (!res)
		return (NULL);
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
            res[word] = p - i;  // or // res[word] = splitdup(p - i , i);
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

// int main() 
// {
//     char *str1 ;
//     str1 = ",,,hello,,world,and,fellow,,cowboyz,,,";
//     char *str ;
//     str = "     hello   world and  fellow    cowboyz      ";
//     char **res = ft_split(str,',');
//     char **res2 = ft_split(str,' ');
//     int i = 0;
//     while(res[i])
//     {
//         printf("%s\n",res[i]);
//         i++;
//     }
//     printf("%s\n",res[i]);
//     i = 0;
//     while(res2[i])
//     {
//         printf("%s\n",res2[i]);
//         i++;
//     }
//     printf("%s\n",res2[i]);
// }
