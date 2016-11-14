/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:41:56 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/14 15:10:49 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	get_min_rect(t_tetr *tetr)
{
	t_tetr *tmp;
	int		result;

	tmp = tetr;
	result = 0;
	while (tmp)
	{
		result += 4;
		tmp = tmp->next;
	}
	while (ft_sqrt(result) == 0)
		result++;
	return (ft_sqrt(result));
}
