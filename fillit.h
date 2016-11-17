/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:16:58 by lsimon            #+#    #+#             */
/*   Updated: 2016/11/17 11:06:19 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 4098

typedef struct		s_tetr
{
	int				coord[4];
	char			c;
	struct s_tetr	*next;
}					t_tetr;

int					read_file(char *buff, char *s);
t_tetr				*fill(char *s, char c, t_tetr *new);
t_tetr				*tetr_new(int *array, char c);
t_tetr				*tetr_pushback(t_tetr *first, int *array, char c);
t_tetr				*insert_node(t_tetr *new, int *array, char c);
char				*create_grid(int min_rect);
char				*resolve(char *s, t_tetr *tetr);
int					get_min_rect(t_tetr *tetr);
void				adjust_coords(t_tetr *tetr, int iter);
void				increase_coords(t_tetr *tetr);
int					all_check(char *s);
int					ft_strlen(const char *str);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
int					ft_sqrt(int nb);

#endif
