/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:28:52 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/16 17:18:35 by tfarrugi         ###   ########.fr       */
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
	//ft_putendl(s);
	//ft_putchar('\n');
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
			if (coord_match(tetr->coord, tetr->next->coord) == 1)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}

int		coord_match(int *a1, int *a2)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (a1[i] != a2[i])
			return (0);
		i++;
	}
	return (1);
}

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
