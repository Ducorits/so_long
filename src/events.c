/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 13:40:34 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 14:15:18 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <base.h>

// Events go here.
// We abstract away the specific key being pressed. Key action and modifier still needs to be checked. (May change this in the future)

void close_window(mlx_key_data_t keydata, void *param)
{
	t_game *data;
	data = param;

	if (keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}