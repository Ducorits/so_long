/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 15:49:25 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 20:16:22 by dritsema      ########   odam.nl         */
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

void update_state(void *param)
{
	t_game *data = param;

	if (data->input_state.move_up)
		data->image->instances[0].y -= 5;
	if (data->input_state.move_down)
		data->image->instances[0].y += 5;
	if (data->input_state.move_left)
		data->image->instances[0].x -= 5;
	if (data->input_state.move_right)
		data->image->instances[0].x += 5;
}

void ft_randomize(void *param)
{
	t_game *data = param;

	for (uint32_t i = 0; i < data->image->width; ++i)
	{
		for (uint32_t y = 0; y < data->image->height; ++y)
		{
			uint32_t color = ft_pixel(
					rand() % 0xFF, // R
					rand() % 0xFF, // G
					rand() % 0xFF, // B
					rand() % 0xFF	 // A
			);
			mlx_put_pixel(data->image, i, y, color);
		}
	}
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
	data->image = mlx_new_image(data->mlx, 100, 100);

	mlx_image_to_window(data->mlx, data->image, 0, 0);

	data->input_state.move_up = 0;
	data->input_state.move_down = 0;
	data->input_state.move_left = 0;
	data->input_state.move_right = 0;

	mlx_key_hook(data->mlx, key_input, data);
	mlx_loop_hook(data->mlx, ft_randomize, data);
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