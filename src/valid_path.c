#include "so_long.h"

void check_exit_accessibility(char **map, t_point size, t_point exit)
{
    if (map[exit.y][exit.x] != 'F')
    {
        printf("Error: la salida no es accesible.\n");
        exit(1);
    }
}

void	fill(char **tab, t_point size, t_point current, char to_fill)
{
	if ((current.y < 0x0) || (current.x < 0x0) || (current.y >= size.y)
		|| (current.x >= size.x) || tab[current.y][current.x] != to_fill)
		return ;
	tab[current.y][current.x] = 'F';
	fill(tab, size, (t_point){current.x - 0x1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x + 0x1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x, current.y - 0x1}, to_fill);
	fill(tab, size, (t_point){current.x, current.y + 0x1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void valid_path(char **map, int x, int y)
{
	t_point size = {data->size_x / IMG_W, data->size_y / IMG_H};
	t_point start = {x, y};
    flood_fill(map, size, start);

    int y;
    int x;

    // Recorremos el mapa para verificar puntos no accesibles
	y = 0;
    while (y < data->size_y)
    {
        x = 0;
        while (x < data->size_x)
        {
            if ((data-> map->map[y][x] == '0' || data-> map->map[y][x] == 'C') && 
				data-> map->map[y][x] != 'F')
            {
                // Si encontramos un '0' o 'C' no accesible, mostramos el error
                write(1, "Map no accesible.\n", 54);
                exit(1);
            }
            x++;
        }
        y++;
    }
	check_exit_accessibility(**map, t_point size, t_point exit)
}
