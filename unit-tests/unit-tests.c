/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit-tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:21:21 by cocummin          #+#    #+#             */
/*   Updated: 2018/12/07 12:39:43 by cocummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../get_next_line.c"

int main()
{
    int fd;

    fd = open("firstTest", O_RDONLY);
    printf("file descriptor is %i\n", fd);

    fd = open("firstTest", O_RDONLY);
    printf("file descriptor now is %i\n", fd);

    char line[100];

    get_next_line(fd, &line);
    if (ft_strcmp(line,  "First test is awesome\0") != 0)
        printf("first Test failed\n");
    else
        printf("First test - OK\n");

    get_next_line(fd, &line);
    if (ft_strcmp(line,  "It really is\0") != 0)
        printf("second Test failed\n");
    else
        printf("Second test - OK\n");

    get_next_line(fd, &line);
    if (ft_strcmp(line,  "If you don't see this line\0") != 0)
        printf("third Test failed\n");
    else
        printf("Third test - OK\n");

    get_next_line(fd, &line);
    if (ft_strcmp(line,  "It sucks\0") != 0)
        printf("fourth Test failed\n");
    else
        printf("Fourth terst - OK")
    close(fd);
    return (0);

}