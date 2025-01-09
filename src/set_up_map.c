/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:05:01 by mnjie-me          #+#    #+#             */
/*   Updated: 2025/01/09 16:00:11 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_monster(t_data *data)
{
	data->m_x = data->map->x;
	data->m_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->monster,
		data->m_x * IMG_W, data->m_y * IMG_H);
}

void	place_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	set_up_map(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'P')
		place_monster(data);
	else if (data->map->map[y][x] == '1')
		place_corners(data);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->map->shrooms,
			x * IMG_W, y * IMG_H);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->map->home,
			x * IMG_W, y * IMG_H);
}

void	create_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	place_background(data);
	while (data->map->y < ((data->size_y) / IMG_H))
	{
		set_up_map(data, data->map->x, data->map->y);
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
