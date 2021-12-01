#include "../main.h"

int	key_press(int key, t_data *data)
{
	if (key == 13)
		data->key_w = 1;
	else if (key == 1)
		data->key_s = 1;
	else if (key == 2)
		data->key_d = 1;
	else if (key == 0)
		data->key_a = 1;
	else if (key == 123)
		data->key_arrow_l = 1;
	else if (key == 124)
		data->key_arrow_r = 1;
	if (key == 53)
		closer(data);
	return (key);
}

int	key_release(int key, t_data *data)
{
	if (key == 13)
		data->key_w = -1;
	else if (key == 1)
		data->key_s = -1;
	else if (key == 2)
		data->key_d = -1;
	else if (key == 0)
		data->key_a = -1;
	else if (key == 123)
		data->key_arrow_l = -1;
	else if (key == 124)
		data->key_arrow_r = -1;
	return (key);
}
