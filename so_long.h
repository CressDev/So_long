/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:30:00 by cress             #+#    #+#             */
/*   Updated: 2025/09/24 20:30:24 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <signal.h>

# define TILE_SIZE 32
# define ESC_KEY    65307
# define W_KEY      119
# define A_KEY      97
# define S_KEY      115
# define D_KEY      100
# define UP_KEY     65362
# define DOWN_KEY   65364
# define LEFT_KEY   65361
# define RIGHT_KEY  65363

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}	t_game;

t_game	*create_and_init_game(void);
void	put_image_at_position(t_game *game, void *img, int x, int y);
void	setup_map_frame_and_fill(t_game *game);
void	draw_map(t_game *game);
void	*load_single_image(t_game *game, char *path);
void	free_game(t_game *game);
void	free_game1(t_game *game);
void	destroy_images(t_game *game);
int		init_game(t_game *game);
int		load_map(t_game *game, char *map);
int		validate_map(t_game *game);
int		load_images(t_game *game);
int		setup_window_and_images(t_game *game);
void	draw_player(t_game *game);
void	draw_exit(t_game *game, int x, int y);
void	draw_collectible(t_game *game, int x, int y);
void	draw_all_collectibles(t_game *game);
void	find_and_draw_exit(t_game *game);
void	find_and_set_player_position(t_game *game);
void	draw_game_elements(t_game *game);
char	**create_test_map(void);
void	free_map(char **map);
int		setup_test_map(t_game *game);
int		count_lines_map(char *map);
char	**copy_map(char *map, int height);
int		load_map_from_file(t_game *game, char *filename);
int		parsing(char **map);
int		validate_path(char **map);
int		is_valid_move(t_game *game, int new_x, int new_y);
void	collect_item(t_game *game, int x, int y);
void	check_exit(t_game *game, int x, int y);
void	move_player(t_game *game, int new_x, int new_y);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);

#endif
