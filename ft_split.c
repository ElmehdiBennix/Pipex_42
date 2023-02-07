/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:26 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/07 01:51:14 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char *str, char delimiter)
{
    char *p, *temp_str;
    char **result;
    int count = 0;
    int i;
    
    temp_str = strdup(str);
    p = temp_str;
    
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

    strcpy(temp_str, str);
    p = temp_str;

    i = 0;
    count = 0;
    
    while (*p) 
    {
        if (*p == delimiter)
        {
            result[count] = p - i;
            *p = '\0';
            count++;
            p++;
            i = 0;
        }
        else
        {
            i++;
            p++;
        }
    }
    result[count] = p - i;
    count++;
    result[count] = NULL;
    return result;
}

int main() {
  char **tokens;
  char *string = ",,,,,,,,hello,,,,world,f,,,,,oo,,bar,,,,,,,";
  char delimiter = ',';

  tokens = split(string, delimiter);

  for (int i = 0; tokens[i]; i++) {
    printf("%s\n", tokens[i]);
  }
  free(tokens);

  return 0;
}
