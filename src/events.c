/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 13:40:34 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 20:16:15 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Events go here.
// We abstract away the specific key being pressed. Key action and modifier still needs to be checked. (May change this in the future)

void close_window(mlx_key_data_t keydata, void *param)
{
	t_game *data;
	data = param;

	if (keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void move_up(mlx_key_data_t keydata, void *param)
{
	t_game *data = param;

	if (keydata.action == MLX_PRESS)
		data->input_state.move_up = true;
	if (keydata.action == MLX_RELEASE)
		data->input_state.move_up = false;
}

void move_down(mlx_key_data_t keydata, void *param)
{
	t_game *data = param;

	if (keydata.action == MLX_PRESS)
		data->input_state.move_down = true;
	if (keydata.action == MLX_RELEASE)
		data->input_state.move_down = false;
}

void move_left(mlx_key_data_t keydata, void *param)
{
	t_game *data = param;

	if (keydata.action == MLX_PRESS)
		data->input_state.move_left = true;
	if (keydata.action == MLX_RELEASE)
		data->input_state.move_left = false;
}

void move_right(mlx_key_data_t keydata, void *param)
{
	t_game *data = param;

	if (keydata.action == MLX_PRESS)
		data->input_state.move_right = true;
	if (keydata.action == MLX_RELEASE)
		data->input_state.move_right = false;
}