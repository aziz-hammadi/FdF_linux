/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:41:43 by mnaji             #+#    #+#             */
/*   Updated: 2021/10/12 20:30:05 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0 || s1 == 0 || s2 == 0)
		return (1);
	while (s1[i] == s2[i])
	{
		if ((i + 1 >= n) || (s1[i] == '\0' && s1[i] == s2[i]))
			return (1);
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
