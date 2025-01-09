/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:15:18 by mnjie-me          #+#    #+#             */
/*   Updated: 2025/01/07 20:50:38 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	shrooms_exit(t_data *data)
{
	if (data->map->map[data->m_y][data->m_x] == 'C')
	{
		++data->collect;
		data->map->map[data->m_y][data->m_x] = '0';
	}
	if (data->map->map[data->m_y][data->m_x] == 'E')
		ft_end(data, 1, NULL);
}

static void	move_monster(t_data *data, char p, int dir)
{
	if (p == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->m_down, (data->m_x * IMG_W), (data->m_y * IMG_H));
	else if (p == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->m_up, (data->m_x * IMG_W), (data->m_y * IMG_H));
	else if (p == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->m_left, (data->m_x * IMG_W), (data->m_y * IMG_H));
	else if (p == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->m_right, (data->m_x * IMG_W), (data->m_y * IMG_H));
	data->count++;
	ft_printf("%d meters done so far !\n", data->count);
	shrooms_exit(data);
}

static void	all_done(t_data *data, char p, int dir)
{
	if (p == 'y' && data->map->map[data->m_y + dir][data->m_x] == 'E'
		&& data->collect == data->map->money)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->m_y * IMG_H), (data->m_x * IMG_W));
		data->m_y += dir;
		move_monster(data, p, dir);
	}
	else if (p == 'x' && data->map->map[data->m_y][data->m_x + dir] == 'E'
		&& data->collect == data->map->money)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->m_y * IMG_H), (data->m_x * IMG_W));
		data->m_x *= dir;
		move_monster(data, p, dir);
	}
}

void	move(t_data *data, char p, int dir)
{
	if (p == 'y' && data->map->map[data->m_y + dir][data->m_x] != '1' &&
		data->map->map[data->m_y + dir][data->m_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->m_y * IMG_H), (data->m_x * IMG_W));
		data->m_y += dir;
		move_monster(data, p, dir);
	}
	else if (p == 'x' && data->map->map[data->m_y][data->m_x + dir] != '1' &&
		data->map->map[data->m_y][data->m_x + dir] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->m_y * IMG_H), (data->m_x * IMG_W));
		data->m_x += dir;
		move_monster(data, p, dir);
	}
	else
		all_done(data, p, dir);
}
