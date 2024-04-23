/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/23 15:53:29 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit (1);
}

void	prueba_fill(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (params->map_filled[i])
	{
		j = 0;
		while (j <= params->map_len)
		{
			printf("%i", params->map_filled[i][j]);
			j++;
		}
		i++;
	}
}

void	parse_map(t_params *params)
{
	ber_check(params);
	dump_map(params);
	check_char_map(params);
	map_walls(params);
	count_lines_len_map(params);
	char_counter(params);
	flood_fill(params, params->player_y, params->player_x);
	prueba_fill(params);
}

int	main(int argc, char **argv)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	params->map_path = ft_strdup(argv[1]);
	if (argc == 2)
	{
		parse_map(params);
	}
	return (0);
}
