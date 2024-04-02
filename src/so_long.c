/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/04/02 13:39:05 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void dump_map(t_params *params)
{
	int	fd;
	char *result;
	result = NULL;
	int i;

	fd = open(params->map_path, O_RDONLY);
	while(1)
	{
		result = get_next_line(fd);
		if(!result)
			break ;
		params->map_heigth++;
	}
	params->map = malloc(sizeof(char*) * params->map_heigth);
	close(fd);
	fd = open(params->map_path, O_RDONLY);
	i=0;
	while(1)
	{
		printf("%s",params->map[i] = get_next_line(fd));
		if(!params->map[i])
			break ;
		i++;
	}
}

int main (int argc, char **argv)
{
	t_params *params;
	
	params = malloc(sizeof(t_params));
	params->map_path = ft_strdup(argv[1]);
	if(argc == 2)
	{
		printf("%s\n", params->map_path);
		dump_map(params);
	}
}