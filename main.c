/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:36:08 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/16 16:50:28 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	buff[BUFF_SIZE];
	t_tetr	*tetr;
	char	*s;
	int		min_rect;

	s = NULL;
	if (argc != 2)
		return (1);
	if (!(read_file(buff, argv[1])))
		return (1);
	if (all_check(buff) == 0)
	{
		ft_putendl("error");
		return (1);
	}
	if (!(tetr = fill(buff, 'A', tetr)))
		return (1);
	//for (int i =0; i < 4; i++)
	//	ft_putnbr(tetr->coord[i]);
	//min_rect = 4;
	min_rect = get_min_rect(tetr);
	adjust_coords(tetr, min_rect - 4);
	while (s == NULL)
	{
		free(s);
		if (!(s = create_grid(min_rect)))
			return (1);
		s = resolve(s, tetr);
		min_rect++;
		increase_coords(tetr);
	}
	ft_putendl(s);
	return (0);
}
