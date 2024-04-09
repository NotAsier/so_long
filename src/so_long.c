/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/09 13:07:36 by aarranz-         ###   ########.fr       */
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

void	parse_map(t_params *params)
{
	ber_check(params);
	dump_map(params);
	check_char_map(params);
	map_walls(params);
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
