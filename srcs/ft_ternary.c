/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:17:04 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/11 19:00:32 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_ternry(int condition, double a, double b)
{
	if (condition == 1)
		return (a);
	return (b);
}

int	ft_int_ternry(int condition, int a, int b)
{
	if (condition == 1)
		return (a);
	return (b);
}
