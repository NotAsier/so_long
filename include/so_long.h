/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/08 17:09:17 by aarranz-         ###   ########.fr       */
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
	char	*map_path;
	char	*map_name;
	int		map_len;
	int		map_heigth;
	char	**map;
	char	**map_phill;
}			t_params;

void	error(char *message);
void	parse_map(t_params *params);
void	map_walls(t_params *params);
void	dump_map(t_params *params);
void	ber_check(t_params *params);
void	check_char_map(t_params *params);

#endif // SO_LONG_H