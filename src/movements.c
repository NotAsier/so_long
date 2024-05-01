/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:35:39 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/01 18:43:15 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function for moving the player down or up
void	move(t_params *params, int i, int j)
{
	if (params->map[params->player_y + i][params->player_x + j] != '1')
	{
		if (params->map[params->player_y + i][params->player_x + j] == 'C')
			params->coin_count--;
		if (params->map[params->player_y + i][params->player_x + j] != 'E')
		{
			if (params->map[params->player_y][params->player_x] != 'K')
				params->map[params->player_y][params->player_x] = '0';
			else
			{
				if (params->mlx->win == 1)
					exit(0);
				params->map[params->player_y][params->player_x] = 'E';
			}
			params->player_y += i;
			params->player_x += j;
			params->map[params->player_y][params->player_x] = 'P';
		}
		else
		{
			params->map[params->player_y][params->player_x] = '0';
			params->player_y += i;
			params->player_x += j;
			params->map[params->player_y][params->player_x] = 'K';
		}
	}
}

//function for moving the player side
/*void	move_side(t_params *params, int i)
{
	if (params->map[params->player_y][params->player_x + i] != '1')
	{
		if (params->map[params->player_y][params->player_x + i] == 'C')
			params->coin_count--;
		params->map[params->player_y][params->player_x] = '0';
		params->player_x += i;
		params->map[params->player_y][params->player_x] = 'P';
	}
}*/

int	key_tracker(int keypressed, t_params *params)
{
	if (keypressed == 53)
		exit(0);
	if (keypressed == 13)
		move(params, -1, 0);
	if (keypressed == 1)
		move(params, 1, 0);
	if (keypressed == 0)
		move(params, 0, -1);
	if (keypressed == 2)
		move(params, 0, 1);
	window_draw(params);
	if (params->coin_count == 0)
		params->mlx->win = 1;
	return (keypressed);
}
