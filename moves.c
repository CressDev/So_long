/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:19:22 by cress             #+#    #+#             */
/*   Updated: 2025/08/18 11:19:30 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width)
		return (0);
	if (new_y < 0 || new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	collect_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectibles--;
	}
}

void	check_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectibles == 0)
			free_game1(game);
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (!is_valid_move(game, new_x, new_y))
		return ;
	collect_item(game, new_x, new_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
	check_exit(game, new_x, new_y);
	setup_map_frame_and_fill(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == ESC_KEY)
		free_game1(game);
	else if (keycode == W_KEY || keycode == UP_KEY)
		new_y--;
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		new_y++;
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		new_x--;
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		new_x++;
	if (new_x != game->player_x || new_y != game->player_y)
		move_player(game, new_x, new_y);
	return (0);
}