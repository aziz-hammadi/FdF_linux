/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:41:07 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 20:24:21 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}