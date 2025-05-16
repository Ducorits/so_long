/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 15:49:25 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 14:15:21 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <base.h>

// So for the hook prototype mlx works with a void * param.
// This is a pointer that YOU yes YOU can typecast to it's correct type. (Or assigg in our marvelous example)
// The reason it works like this is so that YOU yes YOU can decide what to give to a function.
// In this example code I will give the t_game called data to the hook.

void loop_func(void *param)
{
	t_game *data;
	data = param;
	// Now here we can do all the looping and updating and everything in our nice linear manner.
	(void)data;
}

// Add hooks for any and all things.
void add_hooks(t_game *data)
{
	mlx_key_hook(data->mlx, key_input, data);
	mlx_loop_hook(data->mlx, loop_func, (void *)data); // Example of a nice loop hook whoop whoop.
	add_event_handler(data, MLX_KEY_ESCAPE, close_window);
}

// Main entrypoint for program.
int main(int argc, char **argv)
{

	(void)argc;
	(void)argv;
	t_game data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "Name Goes here", true);
	if (!data.mlx)
		return (0);
	data.event_handlers = ft_calloc(400, sizeof(event_func)); // Allocate in one big go so we never have to realocate. Use calloc so it's null terminated.

	add_hooks(&data);

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free(data.event_handlers);

	return (0);
}