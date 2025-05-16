/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 20:50:22 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 14:10:51 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#include <MLX42.h>
#include <libft.h>

#define WIDTH 800
#define HEIGHT 600

// Function to call when an event happens.
typedef void (*event_func)(mlx_key_data_t keydata, void *param);

// Struct for the main game state
typedef struct s_game
{
	mlx_t *mlx; // Pointer to the mlx instance
	event_func *event_handlers;

} t_game;

void key_input(mlx_key_data_t keydata, void *param);
// Add or remove event handlers
void add_event_handler(t_game *data, keys_t key, void (*func)(mlx_key_data_t, void *));
void remove_event_handler(t_game *data, keys_t key);
void close_window(mlx_key_data_t keydata, void *param);
void wo(mlx_key_data_t keydata, void *param);

#endif