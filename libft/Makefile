# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 22:56:07 by qmebble           #+#    #+#              #
#    Updated: 2019/08/31 06:03:47 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_FOLDER = Src/main_functions/
SRC_LIBFT =		$(LIBFT_FOLDER)*.c

GET_NEXT_LINE_FOLDER = Src/get_next_line/
SRC_GET_NEXT_LINE = $(GET_NEXT_LINE_FOLDER)*.c

FT_PRINTF_FOLDER = Src/ft_printf_functions/
SRC_FT_PRINTF = $(FT_PRINTF_FOLDER)HighestFunctions/*.c \
				$(FT_PRINTF_FOLDER)HighestFunctions/Parsing/*.c \
				$(FT_PRINTF_FOLDER)Char/*.c \
				$(FT_PRINTF_FOLDER)String/*.c \
				$(FT_PRINTF_FOLDER)Pointer/*.c \
				$(FT_PRINTF_FOLDER)OxX/*.c \
				$(FT_PRINTF_FOLDER)DI/*.c \
				$(FT_PRINTF_FOLDER)Unsigned/*.c \
				$(FT_PRINTF_FOLDER)Float/*.c

OBJ_DIR = obj
HEADERS_FOLDER = Headers/
NAME = libft.a
INCLUDE =	$(HEADERS_FOLDER)libft.h \
			$(HEADERS_FOLDER)ft_printf.h \
			$(HEADERS_FOLDER)get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: compile_libft compile_get_next_line compile_ft_printf ran_lib

compile_libft:
	@echo Compiling libft ...
	@gcc $(FLAGS) -c $(SRC_LIBFT) -I $(INCLUDE)

compile_get_next_line:
	@echo Compilint get_next_line ...
	@gcc $(FLAGS) -c $(SRC_GET_NEXT_LINE) $(INCLUDE)

compile_ft_printf:
	@echo Compiling ft_printf ...
	@gcc $(FLAGS) -c $(SRC_FT_PRINTF) $(INCLUDE)

ran_lib:
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)/
	@ar rc $(NAME) $(OBJ_DIR)/*.o
	@ranlib $(NAME)
	@mv $(NAME) ../$(NAME)

clean:
	@rm -rf $(OBJ_DIR) *SYMDEF* $(HEADERS_FOLDER)*.gch

fclean: clean
	@rm -rf ../$(NAME)

re: fclean all
