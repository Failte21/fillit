/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:04:37 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/15 16:28:08 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		place_tetr(char *s, t_tetr *tetr)
{
	char	i;

	i = 0;
	if (*s == '.' && *(s + tetr->coord[1] % 100) == '.' &&
			*(s + tetr->coord[2] % 100) == '.' && 
			*(s + tetr->coord[3] % 100) == '.')
	{
		while (i < 4)
		{
			*(s + tetr->coord[i] % 100) = tetr->c;
			i++;
		}
		return (1);
	}
	return (0);
}

void	clean(char *s, t_tetr *tetr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		*(s + tetr->coord[i] % 100) = '.';
		i++;
	}
}
