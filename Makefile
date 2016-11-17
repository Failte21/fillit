FLAGS =	-Wall -Werror -Wextra

SRCS =	main.c \
		fill.c \
		read_file.c \
		tetr_manipulation.c \
		create_grid.c \
		resolve.c \
		get_min_rect.c \
		check_tetri.c \
		libft_functions.c \

OBJS =	main.o \
		fill.o \
		read_file.o \
		tetr_manipulation.o \
		create_grid.o \
		resolve.o \
		check_tetri.o \
		libft_functions.o \
		get_min_rect.o \

NAME =	fillit

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FlAGS) $(SRCS) -o $(NAME)

$(OBJS):
	gcc $(FlAGS) -c $(SRCS)

.PHONY: clean fclean

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
