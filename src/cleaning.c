/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:35:40 by mnjie-me          #+#    #+#             */
/*   Updated: 2025/01/07 20:27:12 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_SUCCESS);
}

static void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->background);
	mlx_destroy_image(data->mlx, data->img->m_down);
	mlx_destroy_image(data->mlx, data->img->m_left);
	mlx_destroy_image(data->mlx, data->img->m_right);
	mlx_destroy_image(data->mlx, data->img->m_up);
	mlx_destroy_image(data->mlx, data->map->shrooms);
	mlx_destroy_image(data->mlx, data->map->fire);
	mlx_destroy_image(data->mlx, data->map->home);
}

int	ft_end(t_data *data, int win, char *str)
{
	ft_destroy_img(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img);
	clear_map(data->map->map);
	if (win == 1)
	{
		ft_printf("Steps: %d\n Coins: %d\n", data->count, data->collect);
		exit(EXIT_SUCCESS);
	}
	else if (win == 2)
	{
		ft_printf("%s\n", str);
		exit(EXIT_SUCCESS);
	}
	else
		ft_perror(str);
	return (0);
}

int	ft_close(t_data *data)
{
	ft_end(data, 2, "Leaving already?");
	return (0);
}
