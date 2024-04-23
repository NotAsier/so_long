/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/23 15:46:59 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_parameters
{
	int		player_x;
	int		player_y;
	int		player_count;
	int		coin_count;
	int		exit_count;
	char	*map_path;
	char	*map_name;
	int		map_len;
	int		map_heigth;
	char	**map;
	char	**map_filled;
}			t_params;

void	error(char *message);
void	parse_map(t_params *params);
void	map_walls(t_params *params);
void	dump_map(t_params *params);
void	ber_check(t_params *params);
void	check_char_map(t_params *params);
void	count_lines_len_map(t_params *params);
void	char_counter(t_params *params);
void	flood_fill(t_params *params, int y, int x);

#endif // SO_LONG_H