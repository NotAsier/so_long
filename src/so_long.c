/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/03/26 17:27:06 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int map_len(char *fd)
{
	size_t	i;

	i = 0;
	while (fd[i] != '\n')
	{
		i++;
	}
	return (i);
}

static int map_height(char *fd)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (fd[i])
	{	
		if (fd[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int main (int argc, char **argv)
{
	int	fd;
	char *result;
	t_params *params;
	
	params = malloc(sizeof(t_params));
	result = NULL;
	
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		while(result)
		{
			result = get_next_line(fd);
			params->map_heigth++;
		}
		printf("%i", params->map_len);
		printf("%i", params->map_heigth);
	}	
	return (0);
}