/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:26:45 by aarranz-          #+#    #+#             */
/*   Updated: 2024/03/20 16:11:55 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include "../libft/libft.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

//get_next_line.c
char	*ft_read(char *s, int fd);
char	*change_the_static(char *s);
char	*get_line(char *res);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
