/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 13:52:56 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_mlx
{
	int		win;
	void	*mlx;
	void	*window;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*exit2;
	void	*coin;
}			t_mlx;

typedef struct s_parameters
{
	int		fd;
	int		moves;
	int		player_x;
	int		player_y;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		map_len;
	int		map_heigth;
	char	*map_path;
	char	*map_name;
	char	**map;
	char	**map_filled;
	t_mlx	*mlx;
}			t_params;

//------------------------------------------------------------------------------
//			PARSE MAP
//------------------------------------------------------------------------------
void	init(t_params *params);
void	check_fd(t_params *params);
void	error(char *message, t_params *params);
void	parse_map(t_params *params);
void	map_walls(t_params *params);
void	dump_map(t_params *params);
void	ber_check(t_params *params);
void	check_char_map(t_params *params);
void	count_lines_len_map(t_params *params);
void	char_counter(t_params *params);
void	flood_fill(t_params *params, int y, int x);
void	filled_map_checker(t_params *params);
void	dump_filled_map(t_params *params);
//------------------------------------------------------------------------------
//			INIT MLX
//------------------------------------------------------------------------------
void	init_mlx(t_params *params);
void	mlx_initializer(t_params *params);
void	window_draw(t_params *params);
void	image_selector(t_params *params, int x, int y);
void	image_selector2(t_params *params, int x, int y);
void	mlx_add_xpm(t_params *params);
int		key_tracker(int keypressed, t_params *params);
void	move(t_params *params, int i, int j);
//------------------------------------------------------------------------------
//			LEAKS CONTROL
//------------------------------------------------------------------------------
void	free_map(t_params *params);
int		red_cross(t_params *params);

#endif // SO_LONG_H