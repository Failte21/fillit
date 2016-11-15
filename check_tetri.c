/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:51:54 by becorbel          #+#    #+#             */
/*   Updated: 2016/11/15 16:05:15 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

int	ft_split_fct(char *s, int *i, int *j)
{
	while (s[*i] != '\n')
	{
		if (s[*i] != '.' && s[*i] != '#')
			return (0);
		(*i)++;
		(*j)++;
	}
	return (1);
}

int	check_str(char *s, int i)
{
	int	j;
	int	n;

	n = 0;
	while (s[i])
	{
		j = 0;
		if (!(ft_split_fct(s, &i, &j)))
			return (0);
		n++;
		if (j != 4)
			return (0);
		if (n == 4)
		{
			if (s[i + 1] != '\n' && s[i + 1] != '\0')
				return (0);
			if (s[i + 1] == '\n')
				if((check_str(s, i + 2)) == 1)
					return (1);
			if (s[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (1);
}

int	check_tetri(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] != '\n' && s[i + 1] != '\n' && s[i])
		{
			if (s[i] == '#' && s[i + 1] != '#' && s[i + 5] != '#')
				return (0);
			i++;
		}
		i += 2;
	}
	return (1);
}
