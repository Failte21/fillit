/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:41:20 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/14 07:19:20 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *create_grid(int min_rect)
{
	char	*s;
	int		i;

	i = 1;
	if(!(s = (char *)malloc(sizeof(char) *
		(min_rect * (min_rect + 1) + 1))))
		return (NULL);
	while (i < (min_rect) * (min_rect + 1))
	{
		if (i % (min_rect + 1) == 0)
			s[i - 1] = '\n';
		else
			s[i - 1] = '.';
		i++;
	}
	s[i - 1] = '\0';
	return (s);
}
