/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 23:56:21 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 20:48:22 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		i2;
	char	temp;

	i = 0;
	i2 = ft_strlen(str) - 1;
	while (i < i2)
	{
		temp = str[i];
		str[i] = str[i2];
		str[i2] = temp;
		i++;
		i2--;
	}
	return (str);
}
