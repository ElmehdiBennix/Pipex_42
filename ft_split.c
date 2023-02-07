/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:26 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/07 02:24:45 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char *str, char delimiter)
{
    char *p = strdup(str);
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
    p = strdup(str);
    while (*p)
    {
        while (*p == delimiter)
            p++;
        if (*p)
        {
            while (*p == '\0' && *p != delimiter)
            {
                i++;
                p++;
            }
            result[count] = strdup(p - i);
            count++;
            p++;
            i = 0;
        }
    }
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
