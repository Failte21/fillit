/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:46:17 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/16 17:48:51 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

t_tetr	*fill(char *s, char c, t_tetr *new)
{
	int		array[4];
	int		i;

	i = 0;
	fill_array(array, s, &i, c);
	if (!(new = insert_node(new, array, c)))
		return (NULL);
	if (s[i + 1] == '\n')
		if (!(fill(&s[i + 2], c + 1, new)))
			return (NULL);
	return (new);
}

void	fill_array(int *array, char *s, int *i, char c)
{
	int j;
	int k;

	j = -1;
	k = 0;
	while (*i < 19)
	{
		if (s[*i] == '#')
		{
			if (j < 0)
				j++;
			array[k++] = j;
		}
		if (s[*i] == '\n' && j >= 0)
			j += 100;
		if (j >= 0)
			j++;
		(*i)++;
	}
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

void	decrease_coords(t_tetr *tetr)
{
	t_tetr *tmp;

	tmp = tetr;
	while (tmp)
	{
		tmp->coord[1] -= tmp->coord[1] / 100;
		tmp->coord[2] -= tmp->coord[2] / 100;
		tmp->coord[3] -= tmp->coord[3] / 100;
		tmp = tmp->next;
	}
}

void	adjust_coords(t_tetr *tetr, int min_rect)
{
	while (min_rect > 4)
	{
		increase_coords(tetr);
		min_rect--;
	}
	while (min_rect < 4)
	{
		decrease_coords(tetr);
		min_rect++;
	}
}
