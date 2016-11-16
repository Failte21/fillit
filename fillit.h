/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:16:58 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/16 10:50:07 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct		s_tetr
{
	int				coord[4];
	char			c;
	struct s_tetr	*next;
}					t_tetr;

int					read_file(char *buff, char *s);
t_tetr				*fill(char *s);
t_tetr				*tetr_new(int *array, char c);
t_tetr				*tetr_pushback(t_tetr *first, int *array, char c);
char				*create_grid(int min_rect);
int					place_tetr(char *s, t_tetr *tetr);
void				clean(char *s, t_tetr *tetr);
char				*resolve(char *s, t_tetr *tetr);
void				increase_coords(int min_rect, t_tetr *tetr);
int					get_min_rect(t_tetr *tetr);
void				adjust_coords(int min_rect, t_tetr *tetr);
int					all_check(char *s);
int					check_str(char *s, int i);
int					check_tetri(char *s, int i);
int					check_nb_piece(char *s, int i);
#endif
