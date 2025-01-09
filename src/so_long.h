/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnjie-me <mnjie-me@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:23:28 by mnjie-me          #+#    #+#             */
/*   Updated: 2025/01/09 16:42:36 by mnjie-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "stdio.h"
# include "libft.h"
# include <limits.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "mlx.h"

# define IMG_W 80
# define IMG_H 80
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*m_left;
	void	*m_right;
	void	*m_down;
	void	*m_up;
	void	*background;
	void	*left;
	void	*top;
	void	*bottom;
	void	*right;
	void	*trcorner;
	void	*tlcorner;
	void	*brcorner;
	void	*blcorner;
}				t_img;

typedef struct s_map
{
	char	**map;
	void	*home;
	void	*shrooms;
	void	*fire;
	int		y;
	int		x; // coordenadas de los elementos en el mapa
	int		money;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x; // ancho del mapa
	int		size_y; // alto del mapa
	int		m_x;
	int		m_y;
	int		count;
	int		collect;
	t_map	*map;
	t_img	*img;
}				t_data;

void		move(t_data *data, char p, int dir);
void		ft_perror(char *str);
int			ft_end(t_data *data, int win, char *str);
int			ft_close(t_data *data);
void		place_sides(t_data *data);
void		place_corners(t_data *data);
void		check_columns(t_data *data, char **argv);
void		init_struct(t_data *data, t_map *map);
void		check_borders(t_data *data);
void		check_borders(t_data *data);
void		parse_map(t_data *data, char **argv);
void		place_monster(t_data *data);
void		place_background(t_data *data);
void		set_up_map(t_data *data, int x, int y);
void		create_map(t_data *data);
int			on_destroy(t_data *data);
int			on_keypress(int keysym, t_data *data);
void		load_textures(t_data *data);

#endif