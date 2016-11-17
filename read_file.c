/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:43:46 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/17 11:06:50 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include <stdlib.h>

int		read_file(char *buff, char *s)
{
	int	r;
	int	f;

	if (!(f = open(s, O_RDONLY)))
		return (0);
	while ((r = read(f, buff, BUFF_SIZE)))
		buff[r] = '\0';
	return (1);
}
