/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:20:29 by cress             #+#    #+#             */
/*   Updated: 2025/08/21 17:26:43 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
}

void	free_game(t_game *game)
{
	write (1, "Error\n", 6);
	if (!game)
		return ;
	if (game->mlx_ptr)
	{
		destroy_images(game);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	free(game);
	exit(1);
}

int	setup_window_and_images(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_width, window_height, "So_long");
	if (!game->win_ptr)
		return (0);
	if (!load_images(game))
		return (0);
	return (1);
}

int	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->player_img = NULL;
	game->collectible_img = NULL;
	game->exit_img = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->moves = 0;
	return (1);
}

t_game	*create_and_init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game);
		return (NULL);
	}
	return (game);
}
