/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:43:07 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 18:56:30 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_s;

	s_s = (unsigned char *)s;
	while (n != 0)
	{
		if (*s_s == (unsigned char)c)
			return (s_s);
		s_s++;
		n--;
	}
	return (NULL);
}
