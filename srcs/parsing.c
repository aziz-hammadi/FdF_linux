/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:45:16 by ahammad           #+#    #+#             */
/*   Updated: 2021/10/12 17:48:36 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_file(char *file)
{
	int		fd;
	int		ret;
	char	buff;
	int		file_height;

	if (ptr_assign(&fd, open(file, O_RDONLY)) < 0)
		return (-1);
	file_height = 1;
	while (ptr_assign(&ret, read(fd, &buff, 1)) != 0)
	{
		if (ret == -1 || what_buff(buff))
		{
			if (buff != '\n')
			{
				close(fd);
				return (-1);
			}
			file_height++;
		}
	}
	if (close(fd) == -1)
		return (-1);
	return (file_height);
}

static int	banck_point(t_map *map, char **split)
{
	int		i;

	i = 0;
	while (i < map->width)
	{
		if (ft_isnbr_int(split[i]) == 1)
			map->z[map->height][i] = ft_atoi(split[i]);
		else if (ft_ishexa_int(split[i]) == 1)
			map->z[map->height][i] = ft_atoi_base(&split[i][2], 16);
		else
		{
			free(map->z[map->height]);
			return (-1);
		}
		if (precision_print(map->z[map->height][i]) > map->precision_print)
			map->precision_print = precision_print(map->z[map->height][i]);
		i++;
	}
	return (0);
}

static int	check_line(char *line, t_map *map)
{
	char	**split;
	int		split_size;

	split = ft_strsplit(line, ' ');
	free(line);
	split_size = 0;
	while (split[split_size] != NULL)
		split_size++;
	if (map->width == 0)
		map->width = split_size;
	if (split_size != map->width || split_size == 0)
		return (free_split(split, split_size));
	if (!(ft_mllc_2(&map->z[map->height], map->width)))
		return (free_split(split, split_size));
	if (banck_point(map, split) == -1)
		return (free_split(split, split_size));
	free_split(split, split_size);
	return (0);
}

static int	check_map(char *file, t_map *map, int file_height)
{
	char	*line;
	int		fd;
	int		ret;

	if (ptr_assign(&fd, open(file, O_RDONLY)) < 0)
		return (-1);
	if (!(ft_mllc(&map->z, file_height)))
		return (-1);
	while (ptr_assign(&ret, get_next_line(fd, &line)) == 1)
	{
		if (*line == '\0')
			break ;
		if (check_line(line, map) == -1)
			return (close(fd));
		map->height++;
	}
	if (ret == 1)
		free(line);
	if (ret == -1)
		return (close(fd));
	while (ptr_assign(&ret, read(fd, line, 1)) != 0)
		if (ret == -1 || line[0] != '\n')
			return (close(fd));
	close(fd);
	return (1);
}

int	parsing(char *file, t_map *map)
{
	int		file_height;

	file_height = check_file(file);
	if (file_height == -1)
		return (-1);
	if (check_map(file, map, file_height) != 1)
		return (free_z(map->z, map->height));
	return (0);
}
