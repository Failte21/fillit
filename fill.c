/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:46:17 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/15 17:09:56 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

t_tetr	*fill(char *s)
{
	t_tetr	*new;
	int		array[4];
	int		j;
	char	c;
	int		k;

	c = 'A';
	j = -1;
	k = 0;
	new = NULL;
	while (*s++)
	{
		if (*s == '\n' && *(s + 1) == '\n')
		{
			if (!new)
			{
				if (!(new = tetr_new(array, c)))
					return (NULL);
			}
			else
			{
				if (!(tetr_pushback(new, array, c)))
					return (NULL);
			}
			c++; 
			j = -1;
			k = 0;
		}
		if (*s == '\n' && j >= 0)
			j += 100;
		if (*s == '#')
		{
			if (j < 0)
				j++;
			array[k++] = j;
		}
		if (j >= 0)
			j++;
	}
	if (!new)
	{
		if (!(new = tetr_new(array, c)))
			return (NULL);
	}
	else
	{
		if (!(tetr_pushback(new, array, c)))
			return (NULL);
	}
	return (new);
}

void	increase_coords(t_tetr *tetr)
{
	t_tetr *tmp;

	tmp = tetr;
	while (tmp)
	{
		tmp->coord[1] += tmp->coord[1] / 100;
		tmp->coord[2] += tmp->coord[2] / 100;
		tmp->coord[3] += tmp->coord[3] / 100;
		tmp = tmp->next;
	}
}

t_tetr	*fill_2(char *s)
{
	t_tetr *new;
	int		array[4];
	char	c;

	if (*s == '\0')
	{
		if (!new)
		{
			if (!(new = tetr_new(array, c)))
				return (NULL);
		}
		else
			if (!(new = tetr_pushback(new, array, c)))
				return (NULL);
	}
	return (new);
}
