/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:12:10 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/23 15:54:42 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_walls(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	params->map_len = ft_strlen(params->map[i]) - 2;
	while (params->map[i])
	{
		if (params->map[i][0] != '1'
		|| params->map[i][params->map_len] != '1')
			error("map side walls not valid");
		i++;
		while (j < params->map_len)
		{
			if (params->map[0][j] != '1'
			|| params->map[params->map_heigth - 1][j] != '1')
				error("map top or floor walls not valid");
			j++;
		}
	}
}

void	dump_map(t_params *params)
{
	int		fd;
	char	*result;
	int		i;

	result = NULL;
	fd = open(params->map_path, O_RDONLY);
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		params->map_heigth++;
	}
	params->map = malloc(sizeof(char *) * params->map_heigth + 1);
	close(fd);
	fd = open(params->map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		params->map[i] = get_next_line(fd);
		if (!params->map[i])
			break ;
		i++;
	}
}

void	ber_check(t_params *params)
{
	params->map_name = ft_strdup(ft_strrchr(params->map_path, '/') + 1);
	if ((ft_strlen(params->map_name) <= 4)
		|| ((params->map_name[ft_strlen(params->map_name) - 1] != 'r')
			|| (params->map_name[ft_strlen(params->map_name) - 2] != 'e')
			|| (params->map_name[ft_strlen(params->map_name) - 3] != 'b')
			|| (params->map_name[ft_strlen(params->map_name) - 4] != '.')))
		error("map extension not valid");
}

void	check_char_map(t_params *params)
{
	int	row;
	int	col;

	row = 0;
	while (row < params->map_heigth)
	{
		col = 0;
//		printf("%d, \t %s", row, params->map[row]);
		while (params->map[row][col])
		{
			if (params->map[row][col] != '1'
			&& params->map[row][col] != '0'
			&& params->map[row][col] != 'P'
			&& params->map[row][col] != 'C'
			&& params->map[row][col] != 'E'
			&& params->map[row][col] != '\n')
				error("characters in map are invalid");
			col++;
		}
		row++;
	}
}

void	count_lines_len_map(t_params *params)
{
	int	i;

	i = 0;
	while (params->map[i])
	{
		if ((params->map[i][params->map_len] != '1')
			|| (params->map[i][params->map_len + 1] != '\n'
			&& params->map[i][params->map_len + 1] != '\0'))
			error("map char count in lines not valid");
		i++;
	}
}
