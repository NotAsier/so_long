/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:35:39 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 14:05:10 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_draw(t_params *params)
{
	int	x;
	int	y;

	y = 0;
	while (params->map[y])
	{
		x = 0;
		while (params->map[y][x])
		{
			mlx_put_image_to_window(params->mlx->mlx, \
			params->mlx->window, \
			params->mlx->floor, x * 16, y * 16);
			image_selector(params, x, y);
			x++;
		}
		y++;
	}
}

void	print_moves(t_params *params)
{
	params->moves++;
	ft_putnbr_fd(params->moves, 1);
	write(1, "\n", 1);
}

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
				params->map[params->player_y][params->player_x] = 'E';
			params->player_y += i;
			params->player_x += j;
			params->map[params->player_y][params->player_x] = 'P';
		}
		else
		{
			if (params->mlx->win == 1)
				exit(0);
			params->map[params->player_y][params->player_x] = '0';
			params->player_y += i;
			params->player_x += j;
			params->map[params->player_y][params->player_x] = 'K';
		}
		print_moves(params);
	}
}

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
