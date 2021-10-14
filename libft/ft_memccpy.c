/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:40:23 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 18:55:38 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d_dest;
	unsigned char	*s_src;
	unsigned char	c_bis;
	size_t			cursor;

	d_dest = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	c_bis = (unsigned char)c;
	cursor = 0;
	while (cursor < n)
	{
		d_dest[cursor] = s_src[cursor];
		if (d_dest[cursor] == c_bis)
		{
			return (d_dest + cursor + 1);
		}
		cursor++;
	}
	return (NULL);
}
