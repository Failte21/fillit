/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:36:08 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/15 16:42:11 by lsimon           ###   ########.fr       */
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
	if (!(tetr = fill(buff)))
		return (1);
	//min_rect = get_min_rect(tetr);
	min_rect = 4;
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
