/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 15:49:25 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 23:45:28 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// So for the hook prototype mlx works with a void * param.
// This is a pointer that YOU yes YOU can typecast to it's correct type. (Or assigg in our marvelous example)
// The reason it works like this is so that YOU yes YOU can decide what to give to a function.
// In this example code I will give the t_game called data to the hook.

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void draw_grid(t_game *data)
{
	int x = 0;
	int y = 0;
	int px = 0;
	int py = 0;

	int im_width = data->image->width;
	int im_height = data->image->height;

	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			px = ((WIDTH / 2) + (x * im_width / 2)) - (im_width / 2 * 10 / 2) - (y * im_width / 2);
			py = ((HEIGHT / 2) + (y * (im_height / 4))) - ((im_height / 4) * 10 / 2) + (x * (im_height / 4));
			mlx_put_pixel(data->background, px, py, 0xffffff);
			mlx_image_to_window(data->mlx, data->image, px, py);
			y++;
		}
		x++;
	}
}

void update_state(void *param)
{
	t_game *data = param;

	if (data->input_state.move_up)
		data->image->instances[100].y -= 5;
	if (data->input_state.move_down)
		data->image->instances[100].y += 5;
	if (data->input_state.move_left)
		data->image->instances[100].x -= 5;
	if (data->input_state.move_right)
		data->image->instances[100].x += 5;
}

// Add hooks, event handlers and initialize data.
int game_init(t_game *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Name Goes here", true);
	if (!data->mlx)
		return (0);
	data->event_handlers = ft_calloc(400, sizeof(event_func)); // Allocate in one big go so we never have to realocate. Use calloc so it's null terminated.
	if (!data->event_handlers)
	{
		mlx_terminate(data->mlx);
		return (0);
	}

	data->texture = mlx_load_png("./assets/dirt_block.png");

	data->image = mlx_texture_to_image(data->mlx, data->texture);

	data->background = mlx_new_image(data->mlx, WIDTH, HEIGHT);

	mlx_image_to_window(data->mlx, data->background, 0, 0);

	data->input_state.move_up = 0;
	data->input_state.move_down = 0;
	data->input_state.move_left = 0;
	data->input_state.move_right = 0;

	draw_grid(data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);

	mlx_key_hook(data->mlx, key_input, data);
	mlx_loop_hook(data->mlx, update_state, data);
	add_event_handler(data, MLX_KEY_ESCAPE, close_window);
	add_event_handler(data, MLX_KEY_W, move_up);
	add_event_handler(data, MLX_KEY_S, move_down);
	add_event_handler(data, MLX_KEY_A, move_left);
	add_event_handler(data, MLX_KEY_D, move_right);
	return (1);
}

// Main entrypoint for program.
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game data;

	if (!game_init(&data))
		return (0);

	mlx_loop(data.mlx);

	mlx_terminate(data.mlx);
	free(data.event_handlers);

	return (0);
}