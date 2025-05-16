/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 20:50:22 by dritsema      #+#    #+#                 */
/*   Updated: 2025/05/16 18:20:27 by dritsema      ########   odam.nl         */
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

typedef struct s_input_state
{
	bool move_up;
	bool move_down;
	bool move_left;
	bool move_right;
} t_input_state;

// Struct for the main game state
typedef struct s_game
{
	mlx_t *mlx; // Pointer to the mlx instance
	event_func *event_handlers;
	mlx_image_t *image;
	t_input_state input_state;

} t_game;

void key_input(mlx_key_data_t keydata, void *param);
// Add or remove event handlers
void add_event_handler(t_game *data, keys_t key, void (*func)(mlx_key_data_t, void *));
void remove_event_handler(t_game *data, keys_t key);
void close_window(mlx_key_data_t keydata, void *param);
void move_up(mlx_key_data_t keydata, void *param);
void move_down(mlx_key_data_t keydata, void *param);
void move_left(mlx_key_data_t keydata, void *param);
void move_right(mlx_key_data_t keydata, void *param);

#endif