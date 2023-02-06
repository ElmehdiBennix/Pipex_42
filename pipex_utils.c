/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:18 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/07 00:34:42 by ebennix          ###   ########.fr       */
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

// char** ft_split(char *s, char c) {
//     char **str;
//     int word = 0;
//     int i = 0, j = 0;
    
//     while (s[i] != '\0')
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i] != '\0')
// 		{
// 			while (s[i] != '\0' && s[i] != c)
// 				i++;
// 			word++;
// 		}
// 	}
//     str = (char **)malloc((word + 1) * sizeof(char *));
    
//     i = 0;
//     j = 0;
    
//     while (s[i] < word)
//     {
        
//     }
//     // while (*s) 
//     // {
//     //     if (*s == c) 
//     //     {
//     //         str[word] = s - i;
//     //         *s = '\0';
//     //         word++;
//     //         s++;
//     //         i = 0;
//     //     } 
//     //     else 
//     //     {
//     //         i++;
//     //         s++;
//     //     }
//     // }
//     // str[word] = s - i;
//     word++;
//     str[word] = NULL;   
//     return str;
// }
// int main ()
// {
//     int i =0;
//     char* str = "PATH=/Users/ebennix/goinfre/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Applications/Visual Studio Code.app/Contents/Resources/app/bin";
//     char** res = ft_split(str,':');
//     while(1)
//     {
//         printf("%s\n",res[i]);
//         i++;
//         if (res[i]== NULL)
//             break;
//     }
//     printf("\n%s",str);
// }
// int main()
// {
//     char *str = "this is me";
//     int len = ft_strlen(str);
//     char *new_str = str; // Offset the pointer to start at "is me"
//     printf("%s\n", new_str + 1);
//     printf("%d\n", len);
//     return 0;
// }