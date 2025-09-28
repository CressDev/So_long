/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:18:31 by cress             #+#    #+#             */
/*   Updated: 2025/08/18 11:18:34 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game1(t_game *game)
{
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
int	handle_close(t_game *game)
{
	free_game1(game);
	return (0);
}