/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:28:52 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/15 16:49:12 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Fonction r2ccursive permettant de resoudre le problene
 */

#include "fillit.h"
#include "libft.h"

char	*resolve(char *s, t_tetr *tetr)
{
	int	i;

	i = 0;
	while (ft_strlen(&s[i]) >= (tetr->coord[3] % 100))
	{
		if (place_tetr(&s[i], tetr) == 1)
		{
			if (tetr->next == NULL)
				return (s);
			if (resolve(s, tetr->next) != NULL)
				return (s);
			else
				clean(&s[i], tetr);
		}
		i++;
	}
	return (NULL);
}
