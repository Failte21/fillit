/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimos_mainupulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:34:48 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/16 17:40:15 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

t_tetr	*tetr_new(int	*array, char c)
{
	t_tetr	*new;
	int		i;

	i = 0;
	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	while (i < 4)
	{
		new->coord[i] = array[i];
		i++;
	}
	new->c = c;
	new->next = NULL;
	return (new);
}

t_tetr	*tetr_pushback(t_tetr *first, int *array, char c)
{
	t_tetr	*tmp;
	t_tetr	*new;

	new = NULL;
	if (!(new = tetr_new(array, c)))
		return (NULL);
	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_tetr	*insert_node(t_tetr *new, int *array, char c)
{
	if (!new)
	{
		if (!(new = tetr_new(array, c)))
			return (NULL);
	}
	else if (!(new = tetr_pushback(new, array, c)))
		return (NULL);
	return (new);
}
