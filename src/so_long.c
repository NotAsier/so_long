/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/04 15:47:30 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	params->map = malloc(sizeof(char *) * params->map_heigth);
	close(fd);
	fd = open(params->map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		printf("%s", params->map[i] = get_next_line(fd));
		if (!params->map[i])
			break ;
		i++;
	}
}

void	error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit (1);
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

void	parse_map(t_params *params)
{
	ber_check(params);
	dump_map(params);
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
