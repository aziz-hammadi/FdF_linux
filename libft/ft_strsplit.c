/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:52 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/13 14:05:53 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_c_w(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			i++;
			if (str[i] == c || str[i] == '\0')
				word++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_counter_letter(char const *str, int i, char c)
{
	int	letter;

	letter = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		letter++;
		i++;
	}
	return (letter);
}

char const	*ft_init(int *i, int *word, char const *str)
{
	*i = 0;
	*word = 0;
	if (!str)
		return (NULL);
	return (str);
}

char	**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		word;
	int		letter;

	str = ft_init(&i, &word, str);
	tab = (char **)malloc(sizeof(char *) * (ft_c_w(str, c) + 2));
	if (tab == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		letter = ft_counter_letter(str, i, c);
		if (letter > 0)
		{
			tab[word] = ft_strnew(letter);
			ft_strncpy(tab[word], str + i, letter);
			++word;
			i += letter;
		}
		else
			++i;
	}
	tab[word] = NULL;
	return (tab);
}
