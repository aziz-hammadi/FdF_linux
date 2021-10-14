/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:47:45 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/11 18:02:13 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	putnbr_precision(int nbr, int prec)
{
	int		i;

	i = 0;
	ft_putnbr(nbr);
	while (i++ < prec - precision_print(nbr))
		ft_putchar(' ');
}

static void	print_map(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.precision_print == 0)
				putnbr_precision(map.z[y][x], 1);
			else if (map.precision_print == 1)
				putnbr_precision(map.z[y][x], 2);
			else if (map.precision_print == 2)
				putnbr_precision(map.z[y][x], 3);
			else if (map.precision_print == 3)
				putnbr_precision(map.z[y][x], 4);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

static char	*stock_title(char *argv)
{
	char	*title;
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '/')
			title = &argv[i + 1];
		i++;
	}
	return (title);
}

void	initialise_fdf(t_fdf *fdf)
{
	fdf->map.initialise_map = 0;
	fdf->map.x = 0;
	fdf->map.y = 0;
	fdf->map.mult_z = 0;
	fdf->map.zoom = 0;
	if (fdf->map.width > fdf->map.height)
		fdf->map.anim_zoom = IMG_WIDTH / fdf->map.width;
	else
		fdf->map.anim_zoom = IMG_HEIGHT / fdf->map.height;
	fdf->map.projection = 0.25;
	fdf->x_title = WIN_WIDTH / 2;
	fdf->title_color = 0;
	fdf->map.img.color.red = 127;
	fdf->map.img.color.green = 127;
	fdf->map.img.color.blue = 127;
	fdf->map.img.color.op = 0;
	fdf->usage.backg_color = 0x555555;
	fdf->usage.op_color = 127;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(fdf));
	if (argc != 2)
		ft_putstr("usage : ./fdf file\n");
	else if (parsing(argv[1], &fdf.map) == -1)
		ft_putstr("error\n");
	else
	{
		if (fdf.map.width * fdf.map.height < 1000 && \
			fdf.map.precision_print < 4)
			print_map(fdf.map);
		initialise_fdf(&fdf);
		fdf.title = stock_title(argv[1]);
		fdf.mlx_ptr = mlx_init();
		fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_WIDTH, \
									WIN_HEIGHT, fdf.title);
		mlx_hook(fdf.win_ptr, 2, 3, deal_key, &fdf);
		mlx_mouse_hook(fdf.win_ptr, deal_mouse, &fdf);
		mlx_loop_hook(fdf.mlx_ptr, deal_hook, &fdf);
		mlx_loop(fdf.mlx_ptr);
	}
	return (0);
}
