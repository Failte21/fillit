/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:51:54 by becorbel          #+#    #+#             */
/*   Updated: 2016/11/16 12:39:09 by lsimon           ###   ########.fr       */
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
				if ((check_str(s, i + 2)) == 1)
					return (1);
			if (s[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (1);
}

int	check_tetri(char *s, int i)
{
	while (s[i])
	{
		while (s[i] != '\n' && s[i + 1] != '\n' && s[i])
		{
			if ((s[i] != '#') || ((s[i] == '#') && ((s[i + 1] == '#')
							|| (i > 0 && (s[i - 1] == '#'))
							|| (s[i + 5] == '#')
							|| (i > 6 && (s[i - 5] == '#')))))
				i++;
			else
				return (0);
		}
		if (check_tetri(s, i + 2) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_nb_piece(char *s)
{
	int	j;
	int i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (i < 19)
		{
			if (s[i] == '#')
				j++;
			i++;
		}
		//ft_putnbr(j);
		//ft_putchar('\n');
		if (j == 4)
		{
			//ft_putendl("OK");
			if (s[i + 1] == '\n')
				if (check_nb_piece(&s[i + 2]) == 1)
					return (1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_check(char *s)
{
	int i;

	i = 0;
	if (!(check_str(s, i)))
	{
		ft_putendl("checkstr");
		return (0);
	}
	if (!(check_nb_piece(s)))
	{
		ft_putendl("checknb");
		return (0);
	}
	if (!(check_tetri(s, i)))
	{
		ft_putendl("checktetri");
		return (0);
	}
	return (1);
}
