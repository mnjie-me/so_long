/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:20:31 by mnjie-me          #+#    #+#             */
/*   Updated: 2024/12/29 19:26:08 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	test_map(int e, int p, t_data *data)
{
	if (e < 1)
		ft_end(data, 2, "Map error : No exit");
	if (data->map->money < 1)
		ft_end(data, 2, "Map error : No coin");
	if (p != 1)
		ft_end(data, 2, "Map error : Invalid number of player spawn");
}

void	check_map(t_data *data)
{
	int	x;
	int	y;
	int	element[2];

	y = 0;
	element[0] = 0;
	element[1] = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[y][x] == 'C')
				data->map->money++;
			if (data->map->map[y][x] == 'E')
				element[0]++;
			if (data->map->map[y][x] == 'P')
				element[1]++;
			if (ft_cmp(data->map->map[y][x], "CEP01") == 1)
				ft_end(data, 2, "Error, invalid letter");
			x++;
		}
		y++;
	}
	test_map(element[0], element[1], data);
}

void	check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[0][x] != '1')
				ft_end(data, 2, "Border error");
			else if (data->map->map[y][0] != '1')
				ft_end(data, 2, "Border error");
			else if (data->map->map[(data->size_y / IMG_H) - 1][x] != '1')
				ft_end(data, 2, "Border error");
			else if (data->map->map[y][(data->size_x / IMG_W) - 1] != '1')
				ft_end(data, 2, "Border error");
			x++;
		}
		y++;
	}
}

void	parse_map(t_data *data, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_end(data, 0, "Open map error");
	data->map = malloc(sizeof(t_map));
	data->map->map = malloc((data->size_y + 1) * sizeof(char *));
	if (!data->map || !data->map->map)
		ft_end(data, 0, "Malloc error");
	while (1)
	{
		data->map->map[i] = get_next_line(fd);
		if (!data->map->map[i])
			break ;
		data->map->map[i][(data->size_x / IMG_W)] = '\0';
		i++;
	}
	check_map(data);
	check_borders(data);
	close(fd);
}
