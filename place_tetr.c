/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:04:37 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/14 17:50:31 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		place_tetr(char *s, t_tetr *tetr)
{
	int	i;

	i = 0;
	if (*s == '.' && *(s + tetr->coord[1]) == '.' && 
			*(s + tetr->coord[2]) == '.' && *(s + tetr->coord[3]) == '.')
	{
		while (i < 4)
		{
			*(s + tetr->coord[i]) = tetr->c;
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
		*(s + tetr->coord[i]) = '.';
		i++;
	}
}
