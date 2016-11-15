/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:36:08 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/15 20:34:08 by becorbel         ###   ########.fr       */
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
	if (!(check_str(buff, 0)))
		return (1);
	if (!(check_nb_piece(buff, 0)))
	{
		printf("KO");
		return (1);
	}
	//if (!(check_tetri(buff)))
	//	return (1);
	printf("OK");
	/*if (!(tetr = fill(buff)))
		return (1);
	//min_rect = get_min_rect(tetr);
	min_rect = 4;
	ft_putnbr(min_rect);
	ft_putchar('\n');
	//adjust_coords(min_rect, tetr);
	while (s == NULL)
	{
		free(s);
		s = NULL;
		if (!(s = create_grid(min_rect)))
			return (1);
		s = resolve(s, tetr);
		increase_coords(min_rect, tetr);
		min_rect++;
	}
	ft_putendl(s);*/
	return (0);
}
