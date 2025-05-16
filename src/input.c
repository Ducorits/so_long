/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 21:44:54 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 14:15:20 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <base.h>

void add_event_handler(t_game *data, keys_t key, void (*func)(mlx_key_data_t, void *))
{
	data->event_handlers[key] = func;
}

void remove_event_handler(t_game *data, keys_t key)
{
	data->event_handlers[key] = NULL;
}

// mlx key hook is called for all key presses. So I made a jump table to quickly jump to the correct handler for a specific key input. This way we skip if trees! Whoop whoop!
void key_input(mlx_key_data_t keydata, void *param)
{
	t_game *data = param;

	if (data->event_handlers[keydata.key])
		data->event_handlers[keydata.key](keydata, param);
}