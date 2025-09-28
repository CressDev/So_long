/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:19:07 by cress             #+#    #+#             */
/*   Updated: 2025/08/18 11:19:08 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_characters(char **map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_elements(char **map)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;
	int	y;
	int	x;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_count++;
			else if (map[y][x] == 'E')
				exit_count++;
			else if (map[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1 || exit_count != 1 || collectible_count < 1)
		return (0);
	return (1);
}

int	validate_rectangular(char **map)
{
	int	width;
	int	current_width;
	int	y;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (width < 3)
		return (0);
	y = 1;
	while (map[y])
	{
		current_width = ft_strlen(map[y]);
		if (current_width != width)
			return (0);
		y++;
	}
	return (1);
}

int	validate_walls(char **map)
{
	int	height;
	int	width;
	int	y;
	int	x;

	if (!map || !map[0])
		return (0);
	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1) 
				&& map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	parsing(char **map)
{
	if (!map)
		return (0);
	if (!validate_characters(map))
		return (0);
	if (!validate_rectangular(map))
		return (0);
	if (!validate_walls(map))
		return (0);
	if (!validate_elements(map))
		return (0);
	if (!validate_path(map))
		return (0);
	return (1);
}