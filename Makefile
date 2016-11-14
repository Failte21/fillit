FLAGS =	-Wall -Werror -Wextra

SRCS =	main.c \
		fill.c \
		read_file.c \
		tetr_manipulation.c \
		create_grid.c \
		place_tetr.c \
		resolve.c \
		get_min_rect.c \
		check_tetri.c \
		libft.a

OBJS =	main.o \
		fill.o \
		read_file.o \
		tetr_manipulation.o \
		create_grid.o \
		resolve.o \
		place_tetr.o \
		get_min_rect.o \
		check_tetri.o

NAME =	fillit

all: $(NAME)

$(NAME):
	gcc $(FlAGS) $(SRCS) -o $(NAME)

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
