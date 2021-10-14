/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:29:49 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 19:01:07 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	c_bis;

	str = (unsigned char *)b;
	c_bis = (unsigned char)c;
	while (len != 0)
	{
		*str++ = c_bis;
		--len;
	}
	return (b);
}
