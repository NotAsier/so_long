/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:58:00 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/01 18:39:46 by aarranz-         ###   ########.fr       */
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

void	mlx_initializer(t_params *params)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->win = 0;
	mlx->moves = 0;
	mlx->look_at = 0;
	mlx->wall = NULL;
	mlx->window = NULL;
	mlx->player = NULL;
	mlx->floor = NULL;
	mlx->mlx = NULL;
	mlx->exit = NULL;
	mlx->coin = NULL;
	params->mlx = mlx;
}

void	image_selector(t_params *params, int x, int y)
{
	if (params->map[y][x] == '1')
	{
		mlx_put_image_to_window(params->mlx->mlx, \
		params->mlx->window, \
		params->mlx->wall, x * 16, y * 16);
	}
	if (params->map[y][x] == 'C')
	{
		mlx_put_image_to_window(params->mlx->mlx, \
		params->mlx->window, \
		params->mlx->coin, x * 16, y * 16);
	}
	if (params->map[y][x] == 'P')
	{
		mlx_put_image_to_window(params->mlx->mlx, \
		params->mlx->window, \
		params->mlx->player, x * 16, y * 16);
	}
	image_selector2(params, x, y);
}

void	image_selector2(t_params *params, int x, int y)
{
	if (params->map[y][x] == 'E')
	{
		mlx_put_image_to_window(params->mlx->mlx, \
		params->mlx->window, \
		params->mlx->exit, x * 16, y * 16);
	}
	if (params->map[y][x] == 'K')
	{
		mlx_put_image_to_window(params->mlx->mlx, \
		params->mlx->window, \
		params->mlx->exit2, x * 16, y * 16);
	}
}

void	mlx_add_xpm(t_params *params)
{
	int	a;
	int	b;

	params->mlx->player = mlx_xpm_file_to_image(\
	params->mlx->mlx, "textures/player.xpm", &a, &b);
	params->mlx->wall = mlx_xpm_file_to_image(\
	params->mlx->mlx, "textures/wall.xpm", &a, &b);
	params->mlx->floor = mlx_xpm_file_to_image(\
	params->mlx->mlx, "textures/floor.xpm", &a, &b);
	params->mlx->coin = mlx_xpm_file_to_image(\
	params->mlx->mlx, "textures/coin.xpm", &a, &b);
	params->mlx->exit = mlx_xpm_file_to_image(\
	params->mlx->mlx, "textures/exit.xpm", &a, &b);
	params->mlx->exit2 = mlx_xpm_file_to_image(\
	params->mlx->mlx, "textures/exit2.xpm", &a, &b);
}

void	init_mlx(t_params *params)
{
	params->mlx->mlx = mlx_init();
	params->mlx->window = mlx_new_window(params->mlx->mlx, \
	(params->map_len + 1) * 16, params->map_heigth * 16, "so_long");
	mlx_add_xpm(params);
	window_draw(params);
	mlx_key_hook(params->mlx->window, key_tracker, params);
	mlx_loop(params->mlx->mlx);
}
