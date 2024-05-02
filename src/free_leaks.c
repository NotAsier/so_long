/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:56:58 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 14:16:14 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_params *params)
{
	if (params->mlx->window)
		mlx_destroy_window(params->mlx->mlx, params->mlx->window);
	if (params->mlx->wall)
		mlx_destroy_image(params->mlx->mlx, params->mlx->wall);
	if (params->mlx->floor)
		mlx_destroy_image(params->mlx->mlx, params->mlx->floor);
	if (params->mlx->player)
		mlx_destroy_image(params->mlx->mlx, params->mlx->player);
	if (params->mlx->coin)
		mlx_destroy_image(params->mlx->mlx, params->mlx->coin);
	if (params->mlx->exit)
		mlx_destroy_image(params->mlx->mlx, params->mlx->exit);
	if (params->mlx->exit2)
		mlx_destroy_image(params->mlx->mlx, params->mlx->exit2);
}

void	free_splited(char **splited)
{
	int	i;

	i = -1;
	while (splited && splited[++i])
		free(splited[i]);
	free(splited);
}

int	red_cross(t_params *params)
{
	free_map(params);
	exit(0);
	return (0);
}

void	free_map(t_params *params)
{
	free(params->mlx);
	free(params->map_path);
	free(params->map_name);
	free_splited(params->map);
	free_splited(params->map_filled);
}

void	win(t_params *params)
{
	write(1, "YOU WIN!", 8);
	free_map(params);
	free_mlx(params);
	exit(0);
}
