/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/03/20 16:09:57 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main (int argc, char **argv)
{
	int	fd;
	
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%s", get_next_line(fd));
	}
	return (0);
}