/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:48:07 by mnaji             #+#    #+#             */
/*   Updated: 2019/04/29 11:41:10 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_assign2(int *variable, int valeur)
{
	*variable = valeur;
	return (*variable);
}

static int	strchr_line(char **stock, char **line)
{
	char			*tmp_stock;
	int				i;

	i = 0;
	tmp_stock = *stock;
	while (tmp_stock[i] != '\n')
		if (tmp_stock[i++] == '\0')
			return (0);
	tmp_stock[i] = '\0';
	*line = ft_strdup(*stock);
	if (!*line)
		return (-1);
	*stock = ft_strdup_free(*stock, &tmp_stock[i] + 1);
	if (!*stock)
		return (-1);
	return (1);
}

int	ft_init_stock(char *buff, char **stock)
{
	if (*stock)
	{
		*stock = ft_strjoin_free(*stock, *stock, buff);
		if (!*stock)
			return (-1);
	}
	if (!*stock)
	{			
		*stock = ft_strdup(buff);
		if (!*stock)
			return (-1);
	}
	return (0);
}

static int	read_file(int fd, char **stock, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	int				eol;

	while ((ptr_assign2(&ret, read(fd, buff, BUFF_SIZE))) > 0)
	{
		buff[ret] = '\0';
		if (ft_init_stock(buff, stock) == -1)
			return (-1);
		eol = strchr_line(stock, line);
		if (eol == 1)
			break ;
		if (eol == -1)
			return (-1);
	}
	if (ret <= 0)
		return (ret);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char		*stock[BUFF_SIZE];
	int				eof;

	if (!line || fd < 0 || fd > BUFF_SIZE || (read(fd, stock[fd], 0) != 0)
		|| BUFF_SIZE <= 0)
		return (-1);
	if (stock[fd])
	{
		eof = strchr_line(&stock[fd], line);
		if (eof == -1)
			return (-1);
		else if (eof != 0)
			return (1);
	}
	eof = read_file(fd, &stock[fd], line);
	if (eof != 0 || stock[fd] == NULL || stock[fd][0] == '\0')
		return (eof);
	*line = stock[fd];
	stock[fd] = NULL;
	return (1);
}
