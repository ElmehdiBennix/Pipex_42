/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:52:56 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/09 21:23:03 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_words(char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	**ft_free(char **str)
{
	char	*tab;
	int		i;

	i = 0;
	while (str[i])
	{
		tab = str[i];
		free(tab);
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

char	*malloc_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = malloc_word(s, c);
			if (tab[i] == NULL)
				return (ft_free(tab));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
} 
/*
int main(void)
{
	char **splitted;
	char  *mamsplitich = "hello       world        hhhhh      bennix      zaml";
	int i = 0;

	splitted = ft_split(mamsplitich, ' ');
	while(splitted[i])
	{
		printf("%s\n", splitted[i]);
		i++;
	}
	printf("%s",splitted[i]);
}
*/