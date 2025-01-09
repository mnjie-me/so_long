/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:25:21 by mnjie-me          #+#    #+#             */
/*   Updated: 2024/12/29 20:13:35 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long.h"
#include "libft.h"

static void	basic_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static int	ft_key(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == W)
		move(data, 'y', UP);
	else if (keycode == A)
		move(data, 'x', LEFT);
	else if (keycode == S)
		move(data, 'y', DOWN);
	else if (keycode == D)
		move(data, 'x', RIGHT);
	return (0);
}

static void	ft_render_next_frame(t_data *data)
{
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_close, data);
	mlx_hook(data->win, 02, 1L << 0, ft_key, data);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_data	data;

	if (argc != 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		!= (argv[1] + ft_strlen(argv[1]) - 4))
		basic_error("Error, write : ./so_long MAP.ber");
	check_columns(&data, argv);
	if (data.size_x == 0 || data.size_y <= (4 * IMG_H))
		basic_error("Map dimension error");
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		ft_perror("Malloc error");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			data.size_x, data.size_y, "./so_long");
	init_struct(&data, &map);
	parse_map(&data, argv);
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	return (0);
}
