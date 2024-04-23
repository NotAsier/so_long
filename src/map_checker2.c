/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:55:57 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/23 15:46:51 by aarranz-         ###   ########.fr       */
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
		error("map char counter not valid");
}

void	flood_fill(t_params *params, int y, int x)
{
	params->map_filled = params->map;
	if (params->map_filled[y][x] == '1')
		return ;
	params->map_filled[y][x] = '1';
	flood_fill(params, y - 1, x);
	flood_fill(params, y + 1, x);
	flood_fill(params, y, x + 1);
	flood_fill(params, y, x - 1);
}
