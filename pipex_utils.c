/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:18 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/09 23:16:27 by ebennix          ###   ########.fr       */
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j]
				&& i + j < len)
					j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// char *pars(char **env)
// {
// 	int i = 0 ;

// 	char * path ;
// 	while(env[i] != '\0' && path == NULL)
// 	{
// 		path = ft_strnstr(env[i],"PATH=",5); // can use ft_strlen("PATH=") in the 3 parameter for lazy work but since its fixed i could just put 5
// 		i++;
// 	}
// 	return(path);
// }

// int main (int ac ,char **av,char **env)
// {
// 	char * pathfr = pars(env);
	
// 	printf("%s",pathfr);
// }