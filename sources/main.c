#include "../include/parse.h"
// #include "parse.h"

void	init_map(t_cube *cube)
{
	char **map;
	int x = 0;
	int y = 0;

	map = malloc(sizeof(char *) * 6);
	while (x < 5)
		map[x++] = malloc(sizeof(char) * 6);
	x = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (x == 0 || x == 4 || y == 0 || y == 4)
				map[y][x] = '1';
			else
				map[y][x] = '0';
			// if 	
			x++;
		}
		map[y][x] = 0;
		y++;
	}
	// map[2][3] = 'N';
	map[y] = NULL;
	y = 0;
	while (map[y])
		printf("%s\n", map[y++]);

	cube->src->map = map;
}

void	init_cube(t_cube *cube)
{
	// t_elements	*src;
	t_player	*hero;
	t_coords	*coords;
	t_texture	*texs;
	t_keys		*keys;
	t_img		*img;

	// src = malloc(sizeof(t_elements));
	hero = malloc(sizeof(t_player));
	coords = malloc(sizeof(t_coords));
	texs = malloc(sizeof(t_texture) * 4);
	keys = malloc(sizeof(t_keys));
	img = malloc(sizeof(t_img));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "cube3d");
	// cube->src = src;
	cube->hero = hero;
	cube->coords = coords;
	cube->texs = texs;
	cube->key = keys;
	cube->img = img;
	// img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	// img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	// init_map(cube);
	// cube->hero->direction = 'E';
	// cube->hero->x = 2;
	// cube->hero->y = 2;
	cube->key->w = 0;
	cube->key->a = 0;
	cube->key->s = 0;
	cube->key->d = 0;
	cube->key->left = 0;
	cube->key->right = 0;
	cube->key->esc = 0;
}

void	init_texture(t_cube *cube, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cube->mlx, path, &tex->size.x,
			&tex->size.y);
	if (!tex->img)
	{
		free(cube->texs);
		// terminate("Error: Image doesn't exist");
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
}

void	init_cube_2(t_cube *cube, t_elements *elem)
{
	cube->src = elem;
	int y = 0;
	cube->hero->direction = cube->src->dir;
	cube->hero->x = cube->src->vec.x;
	cube->hero->y = cube->src->vec.y;
	printf("x = %d, y = %d\n", cube->hero->x, cube->hero->y);
	while (cube->src->map[y])
		printf("%s\n", cube->src->map[y++]);
	cube->src->map[cube->hero->y][cube->hero->x] = '0';
	init_texture(cube, &cube->texs[0], cube->src->EA);
	init_texture(cube, &cube->texs[1], cube->src->WE);
	init_texture(cube, &cube->texs[2], cube->src->NO);
	init_texture(cube, &cube->texs[3], cube->src->SO);
	// exit(0);

}

int	main(int ac, char **av)
{
	t_elements *elem;
	t_cube cube;


	// исправить заполнение цвета пола и потолка
	// по направлению игрока выставлять дир
	// заинитить текстуры
	elem = parse(ac, av);
	init_cube(&cube);
	init_cube_2(&cube, elem);
	graphic(&cube);
	return (0);
}
