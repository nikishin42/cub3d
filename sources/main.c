#include "../include/parse.h"

void	init_cube(t_cube *cube)
{
	t_player	*hero;
	t_coords	*coords;
	t_texture	*texs;
	t_keys		*keys;
	t_img		*img;

	hero = malloc(sizeof(t_player));
	coords = malloc(sizeof(t_coords));
	texs = malloc(sizeof(t_texture) * 4);
	keys = malloc(sizeof(t_keys));
	img = malloc(sizeof(t_img));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "cube3d");
	cube->hero = hero;
	cube->coords = coords;
	cube->texs = texs;
	cube->key = keys;
	cube->img = img;
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
		free(cube->texs);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
}

void	init_cube_2(t_cube *cube, t_elements *elem)
{
	cube->src = elem;
	cube->hero->direction = cube->src->dir;
	cube->hero->x = cube->src->vec.x;
	cube->hero->y = cube->src->vec.y;
	cube->src->map[cube->hero->y][cube->hero->x] = '0';
	init_texture(cube, &cube->texs[0], cube->src->EA);
	init_texture(cube, &cube->texs[1], cube->src->WE);
	init_texture(cube, &cube->texs[2], cube->src->NO);
	init_texture(cube, &cube->texs[3], cube->src->SO);
}

int	main(int ac, char **av)
{
	t_elements *elem;
	t_cube cube;

	elem = parse(ac, av);
	init_cube(&cube);
	init_cube_2(&cube, elem);
	graphic(&cube);
	return (0);
}
