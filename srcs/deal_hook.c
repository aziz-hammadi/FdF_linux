/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:06:05 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/11 16:04:00 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	anim_initialise_map(t_map *map)
{
	if (map->initialise_map == 0)
	{
		if (map->zoom < map->anim_zoom)
		{
			map->mult_z += 0.1;
			map->zoom += map->anim_zoom / 35;
		}
		else
			map->initialise_map = 1;
		map->mult_zoom = map->mult_z / map->zoom;
	}
}

static void	color_img(t_img *img, int x, int y)
{
	int		i;

	i = (x * 4) + (y * WIN_WIDTH * 4);
	img->data[i] = img->color.red;
	img->data[i + 1] = img->color.green;
	img->data[i + 2] = img->color.blue;
	img->data[i + 3] = img->color.op;
}

static void	draw_line(t_draw pt, t_img *img)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	vect;

	x = pt.x1;
	y = pt.y1;
	vect = (double)sqrt((pow(pt.x2 - pt.x1, 2)) + (pow(pt.y2 - pt.y1, 2)));
	dx = (pt.x2 - pt.x1) / vect;
	dy = (pt.y2 - pt.y1) / vect;
	while (vect > 0)
	{
		if ((x > 0 && y > 0) && (x < IMG_WIDTH && y < IMG_HEIGHT))
			color_img(img, x, y);
		x = x + dx;
		y = y + dy;
		vect--;
	}
}

static void	draw_top(t_map *map, int x, int y)
{
	t_draw	pt;

	pt.xt = x - map->width / 2;
	pt.yt = y - map->height / 2;
	pt.x1 = 0.5 * (pt.xt - pt.yt) * map->zoom + (IMG_WIDTH / 2) + map->x;
	pt.y1 = map->projection * (pt.xt + pt.yt) * map->zoom - map->z[y][x] * \
			map->mult_z + (IMG_HEIGHT / 2) + map->y;
	if (map->width > x + 1)
	{
		pt.x2 = 0.5 * ((pt.xt + 1) - pt.yt) * map->zoom + (IMG_WIDTH / 2) \
				+ map->x;
		pt.y2 = map->projection * ((pt.xt + 1) + pt.yt) * \
		map->zoom - map->z[y][x + 1] * map->mult_z + (IMG_HEIGHT / 2) + map->y;
		draw_line(pt, &map->img);
	}
	if (map->height > y + 1)
	{
		pt.x2 = 0.5 * (pt.xt - (pt.yt + 1)) * map->zoom + \
				(IMG_WIDTH / 2) + map->x;
		pt.y2 = map->projection * (pt.xt + (pt.yt + 1)) * map->zoom - \
		map->z[y + 1][x] * map->mult_z + (IMG_HEIGHT / 2) + map->y;
		draw_line(pt, &map->img);
	}
}

int	deal_hook(t_fdf *fdf)
{
	int			x;
	int			y;

	y = -1;
	if (fdf->map.initialise_map == 0)
		anim_initialise_map(&fdf->map);
	fdf->map.img.img_ptr = mlx_new_image(fdf->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	fdf->map.img.data = mlx_get_data_addr(fdf->map.img.img_ptr, \
			&fdf->map.img.bpp, &fdf->map.img.size_line, &fdf->map.img.endian);
	header(&fdf->usage, fdf);
	while (++y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
			draw_top(&fdf->map, x, y);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->map.img.img_ptr, \
							0, WIN_HEIGHT - IMG_HEIGHT);
	mlx_destroy_image(fdf->mlx_ptr, fdf->map.img.img_ptr);
	return (0);
}
