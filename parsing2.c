/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:19:14 by cress             #+#    #+#             */
/*   Updated: 2025/09/24 20:36:06 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	find_player_position(char **map, int *player_x, int *player_y)
{
	int	y;
	int	x;

	*player_x = -1;
	*player_y = -1;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	count_collectibles(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_flood_fill(char **map_copy, int x, int y, int *collectibles_found, int *exit_found)
{
	if (!map_copy || !map_copy[y] || !map_copy[y][x])
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'X')
		return ;
	if (map_copy[y][x] == 'C')
		(*collectibles_found)++;
	if (map_copy[y][x] == 'E')
		*exit_found = 1;
	map_copy[y][x] = 'X';
	ft_flood_fill(map_copy, x + 1, y, collectibles_found, exit_found);
	ft_flood_fill(map_copy, x - 1, y, collectibles_found, exit_found);
	ft_flood_fill(map_copy, x, y + 1, collectibles_found, exit_found);
	ft_flood_fill(map_copy, x, y - 1, collectibles_found, exit_found);
}

char	**create_map_copy(char **original)
{
	char	**copy;
	int		height;
	int		i;

	height = ft_count(original);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

int	validate_path(char **map)
{
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		total_collectibles;
	int		collectibles_found;
	int		exit_found;

	find_player_position(map, &player_x, &player_y);
	if (player_x == -1 || player_y == -1)
		return (0);
	total_collectibles = count_collectibles(map);
	map_copy = create_map_copy(map);
	if (!map_copy)
		return (0);
	collectibles_found = 0;
	exit_found = 0;
	ft_flood_fill(map_copy, player_x, player_y, &collectibles_found, &exit_found);
	free_map(map_copy);
	if (collectibles_found != total_collectibles || !exit_found)
	{
		ft_printf("Error: no hay camino válido\n");
		return (0);
	}
	return (1);
}