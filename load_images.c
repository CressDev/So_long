/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:20:16 by cress             #+#    #+#             */
/*   Updated: 2025/09/24 20:35:01 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_map(char *map)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

char	**copy_map(char *map, int height)
{
	int		fd;
	char	*line;
	char	**temp_map;
	int		i;

	i = 0;
	temp_map = malloc(sizeof(char*) * (height + 1));
	if (!temp_map)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL && i < height)
	{
		temp_map[i++] = line;
		line = get_next_line(fd);
	}
	temp_map[i] = NULL;
	close(fd);
	return (temp_map);
}

int	load_map(t_game *game, char *map)
{
	char	**temp_map;
	int		height;
	
	height = count_lines_map(map);
	temp_map = copy_map(map, height);
	if (!parsing(temp_map))
		free_game(game);
	game->map = temp_map;
	game->map_height = height;
	game->map_width = ft_strlen(temp_map[0]);
	find_and_set_player_position(game);
	game->moves = 0;
	return (1);
}

void	*load_single_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!img)
		return (NULL);
	return (img);
}

int	load_images(t_game *game)
{
	game->wall_img = load_single_image(game, "textures/wall.xpm");
	if (!game->wall_img)
		return (0);
	game->floor_img = load_single_image(game, "textures/floor.xpm");
	if (!game->floor_img)
		return (0);
	game->player_img = load_single_image(game, "textures/player.xpm");
	if (!game->player_img)
		return (0);
	game->collectible_img = load_single_image(game, "textures/collectible.xpm");
	if (!game->collectible_img)
		return (0);
	game->exit_img = load_single_image(game, "textures/exit.xpm");
	if (!game->exit_img)
		return (0);
	return (1);
}
