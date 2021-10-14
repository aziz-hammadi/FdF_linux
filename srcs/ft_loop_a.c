/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:21:57 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/13 00:30:17 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ptr_assign(int *variable, int valeur)
{
	*variable = valeur;
	return (*variable);
}

int	**ft_mllc(int ***mapz, int a)
{
	*mapz = ((int **)malloc(sizeof(int *) * a));
	return (*mapz);
}

int	*ft_mllc_2(int **mapz, int a)
{
	*mapz = (int *)malloc(sizeof(int) * a);
	return (*mapz);
}

int	what_buff(char buff)
{
	if (!ft_isdigit(buff))
		if ((buff < 'a' || buff > 'f'))
			if ((buff < 'A' || buff > 'F'))
				if (buff != ' ' && buff != '-' && buff != '+')
					if (buff != 'x' && buff != 'X')
						return (1);
	return (0);
}
