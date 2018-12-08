/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocummin <cocummin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:22:39 by cocummin          #+#    #+#             */
/*   Updated: 2018/12/08 21:10:48 by cocummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <printf.h>

int get_next_line(const int fd, char **line)
{
    static char	*c[4864];
	char		buffer[BUFF_SIZE + 1];
	char		*tempo;
	long		number_of_bytes;
	int			endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(c[fd], '\n') && (number_of_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		tempo = c[fd];
		buffer[number_of_bytes] = '\0';
		c[fd] = ft_strjoin(c[fd], buffer);
		ft_strdel(&tempo);
	}
	if (number_of_bytes == -1 || !*(tempo = c[fd]))
		return (number_of_bytes == -1 ? -1 : 0);
	if ((endl = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));

	ft_strdel(&tempo);
	return (!(!c[fd] && !ft_strlen(*line)));
}
