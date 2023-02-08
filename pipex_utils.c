/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:18 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 15:37:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t ft_strlen(const char *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1)+ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0' && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i < len)
			str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

// char** ft_split(const char *str, char c)
// {
//     char **res;
//     char *tmp = ft_strdup(str);
//     char *p = tmp;
//     int i;
//     int word = 0;

//     while (*p) 
//     {
//         while (*p == c)
//             p++;
//         if(*p)
//         {
//             while (*p != '\0' && *p != c) 
//                 p++;
//             word++;
//         }
//     } 
//     res = (char **)malloc((word + 1) * sizeof(char *));
//     //if() must add protection
//     i = 0;
//     word = 0;
//     p = tmp;
//     while (*p)
//     {
//         while (*p == c)
//             p++;
//         if (*p)
//         {
//             while (*p && *p != c)
//             {
//                 i++;
//                 p++;
//             }
//             res[word] = p - i;
//             *p = '\0';
//             word++;
//             p++;
//             i=0;
//         }
//     }
//     free(tmp);
//     res[word] = NULL;
//     return res;
// }
