/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_funkcia.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleyshre <jleyshre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:17:20 by jleyshre          #+#    #+#             */
/*   Updated: 2019/10/30 14:46:19 by jleyshre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FUNKCIA_H
# define FILLIT_FUNKCIA_H

# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		tetris
{
	int				tetr[26];
	unsigned int	count;
}					t_tetr;

void	fillit_funkcia(int fd);
//int		main();
//int		displace(char *str, int sq, int tetr, int y);

#endif
