/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:01:13 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/17 11:08:57 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	if (nb > 2147483647 || nb < -214748348)
		return (0);
	if (nb == 1)
		return (nb);
	while (sqrt < nb)
	{
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
