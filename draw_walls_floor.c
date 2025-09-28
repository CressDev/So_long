/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_walls_floor.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cress <cress@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/07/23 12:22:59 by cress			 #+#	#+#			 */
/*   Updated: 2025/08/07 23:17:40 by cress			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	put_image_at_position(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_collectible(t_game *game, int x, int y)
{
	put_image_at_position(game, game->floor_img, x, y);
	put_image_at_position(game, game->collectible_img, x, y);
}

void	draw_all_collectibles(t_game *game)
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
				draw_collectible(game, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
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
			if (game->map[y][x] == '1')
				put_image_at_position(game, game->wall_img, x, y);
			else
				put_image_at_position(game, game->floor_img, x, y);
			x++;
		}
		y++;
	}
}

void	setup_map_frame_and_fill(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
	draw_game_elements(game);
}

