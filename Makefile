# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:44:12 by olrudenk          #+#    #+#              #
#    Updated: 2019/02/13 12:03:24 by olrudenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_OBJ = ./libft/*.o

SRC = ft_assembly.c \
	  ft_auxiliary.c \
	  ft_auxiliary_2.c \
	  ft_basic_functions.c \
	  ft_color_output.c \
	  ft_invalid_case.c \
	  ft_major_parsing.c \
	  ft_minor_parsing.c \
	  ft_printf.c \
	  ft_type_b.c \
	  ft_type_b_auxiliary.c \
	  ft_type_c.c \
	  ft_type_d.c \
	  ft_type_d_auxiliary.c \
	  ft_type_f.c \
	  ft_type_f_auxiliary.c \
	  ft_type_f_auxiliary_2.c \
	  ft_type_o.c \
	  ft_type_o_auxiliary.c \
	  ft_type_p.c \
	  ft_type_p_auxiliary.c \
	  ft_type_s.c \
	  ft_type_s_auxiliary.c \
	  ft_type_u.c \
	  ft_type_u_auxiliary.c \
	  ft_type_x.c \
	  ft_type_x_auxiliary.c \
	  ft_type_r.c \
	  ft_type_r_auxiliary.c \
	  ft_valid_case.c

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(LIBFT_OBJ) $(OBJ)
	@echo "\033[33mCreating libftprintf.a...\033[0m"
	@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	@echo "\033[32mlibftprintf.a has successfully created!\033[0m"
	@echo "\033[35mPS: for ft_cprintf usage do like that [\033[0mft_cprintf(\"+usage\");\033[35m]\033[0m"

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(LIBFT_OBJ):
	@echo "\033[33mCreating object libft files...\033[0m"
	@make -C $(LIBFT_DIR)
	@echo "\033[32mObject libft files have created!\033[0m"

clean:
	@echo "\033[33mDeleting all object files...\033[0m"
	@make clean -C ./libft
	@rm -f *.o
	@echo "\033[32mAll object files have deleted!\033[0m"

fclean: clean
	@echo "\033[33mDeleting libft.a and libfprintf.a ...\033[0m"
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\033[32mLibft.a and libftprintf.a have deleted!\033[0m"

re: fclean all
