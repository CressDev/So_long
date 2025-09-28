/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:18:51 by cress             #+#    #+#             */
/*   Updated: 2025/08/18 11:18:53 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	put_image_at_position(game, game->floor_img, game->player_x, game->player_y);
	put_image_at_position(game, game->player_img, game->player_x, game->player_y);
}

void	draw_exit(t_game *game, int x, int y)
{
	put_image_at_position(game, game->floor_img, x, y);
	put_image_at_position(game, game->exit_img, x, y);
}

void	find_and_draw_exit(t_game *game)
{
	int	y;
	int	x;

	if (!game->map)
		return ;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E')
			{
				draw_exit(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_and_set_player_position(t_game *game)
{
	int	y;
	int	x;

	if (!game->map)
		return ;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			else if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}

			x++;
		}
		y++;
	}
}

void	draw_game_elements(t_game *game)
{
	find_and_draw_exit(game);
	draw_all_collectibles(game);
	draw_player(game);
}