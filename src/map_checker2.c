/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:55:57 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 13:54:46 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_counter(t_params *params)
{
	int	i;
	int	j;

	i = -1;
	while (params->map[++i])
	{
		j = -1;
		while (++j <= params->map_len)
		{
			if (params->map[i][j] == 'P')
			{
				params->player_count++;
				params->player_x = j;
				params->player_y = i;
			}
			if (params->map[i][j] == 'C')
				params->coin_count++;
			if (params->map[i][j] == 'E')
				params->exit_count++;
		}
	}
	if (params->player_count != 1
		|| params->exit_count != 1
		|| params->coin_count < 1)
		error("map char counter not valid", params);
}

void	dump_filled_map(t_params *params)
{
	int	i;

	i = 0;
	params->map_filled = malloc(sizeof(char *) * params->map_heigth + 1);
	while (params->map[i])
	{
		params->map_filled[i] = ft_strdup(params->map[i]);
		i++;
	}
	params->map_filled[i] = NULL;
}

void	filled_map_checker(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (params->map_filled[i])
	{
		j = 0;
		while (j <= params->map_len)
		{
			if (params->map_filled[i][j] != '0'
				&& params->map_filled[i][j] != '1')
				error("map is not playable", params);
			j++;
		}
		i++;
	}
}

void	flood_fill(t_params *params, int y, int x)
{
	if (params->map_filled[y][x] == '1')
		return ;
	params->map_filled[y][x] = '1';
	flood_fill(params, y - 1, x);
	flood_fill(params, y + 1, x);
	flood_fill(params, y, x + 1);
	flood_fill(params, y, x - 1);
}
