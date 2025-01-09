/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:23:32 by mnjie-me          #+#    #+#             */
/*   Updated: 2025/01/09 15:56:48 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_sides(t_data *data)
{
	if (data->map->y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->top,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->left,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->right,
			(data->map->x * IMG_W), (data->map->y / IMG_H - 1));
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	place_corners(t_data *data)
{
	if ((data->size_y / IMG_H) == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bottom, data->map->x * IMG_W, data->map->y * IMG_H);
	else if (data->map->y == (data->size_y / IMG_H) - 1
		&& data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->brcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 1 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->blcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0 && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->trcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->tlcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else
		place_sides(data);
}
