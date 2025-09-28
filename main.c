/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:20:37 by cress             #+#    #+#             */
/*   Updated: 2025/09/24 19:48:24 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_game	*init(char *map)
{
	t_game	*game;
	
	game = create_and_init_game();
	if (!game)
		free_game(game);
	if (!load_map(game, map))
		free_game(game);
	if (!setup_window_and_images(game))
		free_game(game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	game = init(argv[1]);
	if (!game)
		free_game(game);
	setup_map_frame_and_fill(game);
	mlx_hook(game->win_ptr, 2, 1L<<0, handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 1L<<17, handle_close, game);
	mlx_loop(game->mlx_ptr);
	free_game(game);
	return (0);
}
