/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:38:55 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/11 16:00:51 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	box_color(t_fdf *fdf, int x, int y, int color)
{
	int		xt;
	int		yt;

	yt = y;
	while (yt < y + 20)
	{
		xt = x;
		while (xt < x + 20)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xt, yt, color);
			xt++;
		}
		yt++;
	}
}

static void	print_arrow_down(void *mlx_ptr, void *win_ptr, double x, int y)
{
	double	x1;
	int		y1;

	x1 = x + 8;
	y1 = y + 4;
	while (x <= x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y, 0xffffff);
		x = x + 0.5;
		x1 = x1 - 0.5;
		y1++;
	}
}

static void	print_arrow_up(void *mlx_ptr, void *win_ptr, double x, int y)
{
	double	x1;
	int		y1;

	x1 = x + 8;
	y1 = y + 4;
	while (x <= x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y1, 0xffffff);
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xffffff);
		x = x + 0.5;
		x1 = x1 - 0.5;
		y1--;
	}
}

static void	print_usage(void *mlx_ptr, void *win_ptr, int mapc, double proj)
{
	print_arrow_up(mlx_ptr, win_ptr, 692, 75);
	mlx_string_put(mlx_ptr, win_ptr, 691, 77, 0xffffff, "!");
	mlx_string_put(mlx_ptr, win_ptr, 540, 87, 0xffffff, "Move Map :   <- ->");
	mlx_string_put(mlx_ptr, win_ptr, 691, 97, 0xffffff, "!");
	print_arrow_down(mlx_ptr, win_ptr, 692, 119);
	mlx_string_put(mlx_ptr, win_ptr, 150, 45, mapc, "  Color Map : Space");
	if (proj == 0.05)
		mlx_string_put(mlx_ptr, win_ptr, 150, 70, 0xffffff, \
						" Isometric : Enter");
	else
		mlx_string_put(mlx_ptr, win_ptr, 150, 70, 0xffffff, \
						"  Parallel : Enter");
	mlx_string_put(mlx_ptr, win_ptr, 150, 105, 0xffffff, "  Zoom : scroll in");
	mlx_string_put(mlx_ptr, win_ptr, 150, 125, 0xffffff, \
					"Zoom out : scroll out");
	mlx_string_put(mlx_ptr, win_ptr, 940, 45, 0xffffff, " Quit : ESC");
	mlx_string_put(mlx_ptr, win_ptr, 940, 70, 0xffffff, " Reset : DEL");
	mlx_string_put(mlx_ptr, win_ptr, 940, 105, 0xffffff, " Grow up : +");
	mlx_string_put(mlx_ptr, win_ptr, 940, 125, 0xffffff, "Grow down : -");
}

void	header(t_usage *usage, t_fdf *fdf)
{
	move_title(fdf);
	usage->color_map = fdf->map.img.color.blue + \
		fdf->map.img.color.green * 256 + fdf->map.img.color.red * 65536;
	usage->img.img_ptr = mlx_new_image(fdf->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT - IMG_HEIGHT);
	usage->img.data = mlx_get_data_addr(usage->img.img_ptr, &usage->img.bpp, \
		&usage->img.size_line, &usage->img.endian);
	background_color(&usage->img, WIN_HEIGHT - IMG_HEIGHT, \
		usage->backg_color, usage->op_color);
	background_color(&usage->img, 35, 0xcccccc, 127);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
		usage->img.img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, usage->img.img_ptr);
	print_usage(fdf->mlx_ptr, fdf->win_ptr, usage->color_map, \
		fdf->map.projection);
	box_color(fdf, 1250, 42, 0xaa0000);
	box_color(fdf, 1250, 72, 0x00aa00);
	box_color(fdf, 1250, 102, 0x0000aa);
	box_color(fdf, 1250, 132, 0x555555);
}
