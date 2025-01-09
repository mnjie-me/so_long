/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:54:56 by mnjie-me          #+#    #+#             */
/*   Updated: 2025/01/09 16:09:42 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rows(int fd, int x)
{
	int		count;
	char	*lines;

	count = 1;
	while (1)
	{
		lines = get_next_line(fd);
		if (!lines)
			break ;
		if ((lines[ft_strlen(lines) - 1] == '\n'
				&& (int)ft_strlen(lines) != x + 1)
			|| (lines[ft_strlen(lines) - 1] != '\n'
				&& (int)ft_strlen(lines) != x))
		{
			free(lines);
			ft_printf("Map dimensions error");
			exit(EXIT_FAILURE);
		}
		else
		{
			free(lines);
			count++;
		}
	}
	return (count);
}

void	check_columns(t_data *data, char **argv)
{
	int		fd;
	int		read_bytes;
	char	buffer[2];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror("Could not open map");
	read_bytes = read(fd, buffer, 1);
	buffer[0] = '\0';
	data->size_x = 0;
	while (read_bytes == 1 && buffer[0] != '\n')
	{
		data->size_x += 1;
		read_bytes = read(fd, buffer, 1);
		buffer[read_bytes] = '\0';
	}
	data->size_y = check_rows(fd, data->size_x);
	data->size_x *= IMG_W;
	data->size_y *= IMG_H;
	close(fd);
}

static void	enviroment_textures(t_data *data)
{
	int	width;
	int	hight;

	data->img->right = mlx_xpm_file_to_image(data->mlx,
			"textures/treeright.xpm", &width, &hight);
	data->img->left = mlx_xpm_file_to_image(data->mlx,
			"textures/treeleft.xpm", &width, &hight);
	data->img->top = mlx_xpm_file_to_image(data->mlx,
			"textures/treetop.xpm", &width, &hight);
	data->img->bottom = mlx_xpm_file_to_image(data->mlx,
			"textures/treebottom.xpm", &width, &hight);
	data->img->trcorner = mlx_xpm_file_to_image(data->mlx,
			"textures/treetr.xpm", &width, &hight);
	data->img->tlcorner = mlx_xpm_file_to_image(data->mlx,
			"textures/treetl.xpm", &width, &hight);
	data->img->brcorner = mlx_xpm_file_to_image(data->mlx,
			"textures/treebr.xpm", &width, &hight);
	data->img->blcorner = mlx_xpm_file_to_image(data->mlx,
			"textures/treebl.xpm", &width, &hight);
}

static void	item_textures(t_data *data)
{
	int	width;
	int	hight;

	data->img->monster = mlx_xpm_file_to_image(data->mlx,
			"textures/monsterxpm", &width, &hight);
	data->map->home = mlx_xpm_file_to_image(data->mlx,
			"textures/home.xpm", &width, &hight);
	data->map->shrooms = mlx_xpm_file_to_image(data->mlx,
			"textures/shrooms.xpm", &width, &hight);
	data->map->fire = mlx_xpm_file_to_image(data->mlx,
			"textures/fire.xpm", &width, &hight);
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &width, &hight);
	enviroment_textures(data);
}

void	init_struct(t_data *data, t_map *map)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		mlx_destroy_display(data->mlx);
		ft_perror("Could not save image");
	}
	data->map = map;
	data->img = img;
	data->count = 0;
	data->collect = 0;
	data->map->shrooms = 0;
	item_textures(data);
}
