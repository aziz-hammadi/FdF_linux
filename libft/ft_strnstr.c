/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:03:56 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/14 11:30:57 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && to_find[j] && len > 0)
	{
		j = 0;
		if (to_find[j] != str[i])
		{
			i++;
			len --;
		}
		while (to_find[j] == str[i] && len > 0 && str[i])
		{
			j++;
			i++;
			len--;
		}
	}
	if (to_find[j] == '\0')
		return ((char *)str + (i - j));
	return (NULL);
}
