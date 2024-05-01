/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/30 13:15:35 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_params *params)
{
	params->fd = 0;
	params->player_x = 0;
	params->player_y = 0;
	params->player_count = 0;
	params->coin_count = 0;
	params->exit_count = 0;
	params->map_len = 0;
	params->map_heigth = 0;
	params->mlx = NULL;
	params->map_path = NULL;
	params->map_name = NULL;
	params->map = NULL;
	params->map_filled = NULL;
}

void	check_fd(t_params *params)
{
	char	*res;

	res = NULL;
	params->fd = open(params->map_path, O_RDONLY);
	res = get_next_line(params->fd);
	if (!res || ft_strlen(res) < 6 || res[0] == '\n')
	{
		close(params->fd);
		error("file can't open");
	}
	free(res);
	close(params->fd);
}

void	error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit (1);
}

void	parse_map(t_params *params)
{
	check_fd(params);
	ber_check(params);
	dump_map(params);
	check_char_map(params);
	map_walls(params);
	count_lines_len_map(params);
	char_counter(params);
	dump_filled_map(params);
	flood_fill(params, params->player_y, params->player_x);
	filled_map_checker(params);
	printf("okia\n");
}

int	main(int argc, char **argv)
{
	t_params	*params;

	if (argc != 2)
		return (-1);
	params = malloc(sizeof(t_params));
	init(params);
	params->map_path = ft_strdup(argv[1]);
	parse_map(params);
	mlx_initializer(params);
	init_mlx(params);
	return (0);
}
