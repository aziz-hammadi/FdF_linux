/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:01:06 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 17:52:41 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	random_color(t_color *color)
{
	color->red = (rand() % 127);
	color->green = (rand() % 127);
	color->blue = (rand() % 127);
}

static void	deal_key2(int key, t_fdf *fdf)
{
	if ((key == 61 || key == 65451) && (fdf->map.mult_z < 100))
	{
		fdf->map.mult_z += 0.5;
		fdf->map.mult_zoom = fdf->map.mult_z / fdf->map.zoom;
	}
	else if ((key == 45 || key == 65453) && (fdf->map.mult_z > -100))
	{
		fdf->map.mult_zoom = fdf->map.mult_z / fdf->map.zoom;
		fdf->map.mult_z -= 0.5;
	}
	else if (key == 65293)
	{
		if (fdf->map.projection == 0.25)
			fdf->map.projection = 0.05;
		else
			fdf->map.projection = 0.25;
	}
}

static void	deal_mouse2(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 1 && x > 690 && x < 700 && y > 100 && y < 135)
		fdf->map.y += 10;
	else if (mouse == 1 && x > 668 && x < 692 && y > 88 && y < 105)
		fdf->map.x -= 10;
	else if (mouse == 1 && x > 700 && x < 724 && y > 88 && y < 105)
		fdf->map.x += 10;
	else if (mouse == 1 && x > 940 && x < 1060 && y > 40 && y < 65)
	{
		free_z(fdf->map.z, fdf->map.height);
		exit(0);
	}
	else if (mouse == 1 && x > 940 && x < 1065 && y > 65 && y < 70)
		initialise_fdf(fdf);
	else if (mouse == 1 && x > 940 && x < 1070 && y > 100 && y < 120)
		deal_key2(61, fdf);
	else if (mouse == 1 && x > 940 && x < 1075 && y > 120 && y < 145)
		deal_key2(45, fdf);
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 42 && y <= 67)
		fdf->usage.backg_color = 0xaa0000;
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 72 && y <= 97)
		fdf->usage.backg_color = 0x00aa00;
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 102 && y <= 127)
		fdf->usage.backg_color = 0x0000aa;
	else if (mouse == 1 && x >= 1250 && x <= 1275 && y >= 132 && y <= 157)
		fdf->usage.backg_color = 0x555555;
}

int	deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	if (mouse == 4 || (mouse == 1 && x > 150 && x < 340 && y > 100 && y < 120))
	{
		fdf->map.mult_z += fdf->map.mult_zoom * fdf->map.anim_zoom / 20;
		fdf->map.zoom += fdf->map.anim_zoom / 20;
	}
	else if (((mouse == 5 || (mouse == 1 && x > 150 && x < 362 && y > 120 \
	&& y < 145)) && fabs(fdf->map.mult_z) - fabs(fdf->map.mult_zoom) >= 0 \
	&& fdf->map.zoom > 0))
	{
		fdf->map.zoom -= fdf->map.anim_zoom / 35;
		fdf->map.mult_z -= fdf->map.mult_zoom * fdf->map.anim_zoom / 35;
	}
	else if (mouse == 1 && x < fdf->x_title + \
	(int)(ft_strlen(fdf->title) * 10) && x > fdf->x_title && y < 40 && y > 5)
		fdf->title_color = ft_int_ternry(fdf->title_color == 0, 1, 0);
	else if (mouse == 1 && x > 150 && x < 340 && y > 40 && y < 65)
		random_color(&fdf->map.img.color);
	else if (mouse == 1 && x > 150 && x < 340 && y > 65 && y < 95)
		fdf->map.projection = ft_ternry(fdf->map.projection == 0.25, 0.5, 0.25);
	else if (mouse == 1 && x > 690 && x < 700 && y > 70 && y < 97)
		fdf->map.y -= 10;
	else
		deal_mouse2(mouse, x, y, fdf);
	return (0);
}

int	deal_key(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		free_z(fdf->map.z, fdf->map.height);
		exit(0);
	}
	else if (key == 65288)
		initialise_fdf(fdf);
	else if (key == 32)
		random_color(&fdf->map.img.color);
	else if (key == 65362)
		fdf->map.y -= 10;
	else if (key == 65364)
		fdf->map.y += 10;
	else if (key == 65361)
		fdf->map.x -= 10;
	else if (key == 65363)
		fdf->map.x += 10;
	else
		deal_key2(key, fdf);
	return (0);
}
