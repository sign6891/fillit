/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleyshre <jleyshre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:39 by jleyshre          #+#    #+#             */
/*   Updated: 2019/10/30 15:59:00 by jleyshre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_funkcia.h"
#include <unistd.h>
#include <stdio.h>

int                displace(char *str, int sq, int tetr, int y)
{
    int     i;
    int     j;
    int        b;
    j = y + 1;
    while (str[j] != '0' && j < sq * sq)
        j++;
    i = 15;
    while (!(tetr & (1 << i)))
        i--;
    b = i++;
    while (i--)
        if (tetr & (1 << i))
        {
            if (j + b - i + (sq - 4) * (3 - i / 4) >= sq * sq)
                return (-2);
            else if ((j + b - i + (sq - 4) * (3 - i / 4))/sq - j / sq != 3 - i / 4)
            {
                j++;
                i = b + 1;
            }
        }
    return (j);
}

int		block_size(int count)
{
	int	sq;

	sq = 1;
	count = count * 4;
	while (sq * sq < count)
		sq++;
	return (sq);
}

char            *abc(int tetr, char c, int sq, int y)
{
    int     i;
    int     j;
    static char    *str;
    int        b;
    j = 0;
    i = 15;
    if (y == -1 && !str)
    {
        str = ft_memalloc(sq * sq);
        str = ft_memset(str, '0', sq * sq);
    }
    while (!(tetr & (1 << i)))
        i--;
    b = i++;
    while (i-- > 2 && y > -1)
        if (j != 4 && tetr & (1 << i) && *(str + (b - i) + (3 - i / 4) * (sq - 4) + y) == '0')
            j++;
    i = 16;
    if (j == 4 && y >= 0)
        while (i-- > 2 && y != -1)
            if (tetr & (1 << i))
                *(str + (b - i) + (3 - i / 4) * (sq - 4) + y) = c;
    if (j != 4 && y >= -1)
    {
        y = displace(str, sq, tetr, y);
        abc(tetr, c, sq, y);
    }
    if (y == -2)
        free(str);
    return (str);
}

t_tetr			norm(char *str)
{
	int			i;
	static int	count;
	t_tetr		tetr;

	tetr.tetr[count] = 0;
	i = 16;
	while (i--)
	{
		if (*str++ == '.')
			tetr.tetr[count] &= ~(1 << i);
		else
			tetr.tetr[count] |= (1 << i);
	}
	printf("%d\n", tetr.tetr[count]);
	while (tetr.tetr[count] < 4096)
        tetr.tetr[count] <<= 4;
    while (!(tetr.tetr[count] & 34952))
        tetr.tetr[count] <<= 1;
    printf("%d\n", tetr.tetr[count]);
	tetr.count = ++count;
	return(tetr);
}

int            valid(char str[4][4])
{
    int i;
    int j;
    int count;
    i = -1;
    count = 0;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            if (str[i][j] == '.')
                continue;
            if (str[i][j] != '#')
            {
                printf("чпок2");
                exit (1);
            }
            count++;
            if (((i + 1 < 4 && str[i + 1][j] != '#') || (i + 1 >= 4)) &&
                ((j + 1 < 4 && str[i][j + 1] != '#') || (j + 1 >= 4)) &&
                count != 4)
            {
                printf("чпок1");
                exit (1);
            }
            while (j + 1 < 4 && str[i][j + 1] == '#' && count++)
                j++;
        }
    }
    return(count);
}

//Чтение из файла
t_tetr		fillit_read(char *fname, int fd)
{
	char	str[4][4];
	char	c;
	int		i;
	t_tetr	tetrimino;

	c = '2';
	while (c != '\0')
	{
		i = -1;
		while (i++ < 3)
		{
			read(fd, str[i], 4);
			read(fd, &c, 1);
			if (c != '\n')
			{
				printf("чпок3");
				exit (1);
			}
			c = '\0';
		printf("%c%c%c%c\n", str[i][0], str[i][1], str[i][2], str[i][3]);
		}
		read(fd, &c, 1);
		if ((c != '\n' && c != '\0') || valid(str) != 4)
			{
				printf("чпок4");
				exit (1);
			}
		tetrimino = norm((char *)str);
	}
	return(tetrimino);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_tetr	tetrimino;
	char	c;
	int y;
	int sq;
	int	i;
	char *str;

	if (argc > 2)
		write(1, "Error, extra arguments\n", 23);
	if (argc < 2)
		write(1, "Error, add argument\n", 20);

	fd = open(argv[1], O_RDONLY);
	tetrimino = fillit_read(argv[1], fd);

	sq = block_size(tetrimino.count);
	while (1)
	{
		y = -1;
		c = 'A';
		i = -1;
		while (++i < tetrimino.count)
		{
			printf("%s \n", abc(tetrimino.tetr[i], c, sq, y));
			c++;
			y = 0;
		}
		if (!str)
			sq++;
		else
		exit (1);
	}
	close(fd);
	return (0);
}
