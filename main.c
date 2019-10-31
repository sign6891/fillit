/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleyshre <jleyshre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:42:39 by jleyshre          #+#    #+#             */
/*   Updated: 2019/10/28 14:39:09 by jleyshre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_funkcia.h"
#include <stdio.h>

int		main()
{
	int		y;
	char	*str;
	int		sq;
	int		tetr;
	int j;

	sq = 5;
	y = 9;
	tetr = 34952;

	str = (char*)malloc(sizeof(char) * (sq * sq));

	j = displace(str, sq, tetr, y);
	printf("%d\n", j);
	return (0);
}
