# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:42:42 by leobarbo          #+#    #+#              #
#    Updated: 2023/12/07 15:08:20 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!MANDATORY-------------------------------------------------------------------------------------------------------------------------------------------------------

NAME := libftprintf.a

PATH_INCLUDE = ./includes/

PATH_UTILS = ./utils/

PATH_SRC = ./src/

CFLAGS = -Wall -Werror -Wextra -g3

AR := ar -rcs

RM := rm -rf

SRCS = ft_printf.c

UTILS = ft_putchar.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putnbr_unsg.c \
		ft_putpointer.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_utoa.c \
		ft_itoa.c \
		ft_calloc.c \
		ft_memset.c \
		ft_print_arg.c \
		ft_puthash.c \
		ft_putsign.c \

OBJS := $(SRCS:.c=.o)
OBJS_UTILS := $(UTILS:.c=.o)


.DEFAULT_GOAL := all

.PHONY: all clean fclean re bonus

$(NAME): $(OBJS) $(OBJS_UTILS)
	@$(AR) $@ $^

all: $(NAME)

%.o:$(PATH_SRC)%.c
	@echo "Compilando $<"
	@$(CC) $(CFLAGS) -I $(PATH_SRC) -c $< -o $@

%.o: $(PATH_UTILS)%.c
	@echo "Compilando $<"
	@$(CC) $(CFLAGS) -I $(PATH_SRC) -I $(PATH_UTILS) -c $< -o $@

clean: 
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

#!BONUS-------------------------------------------------------------------------------------------------------------------------------------------------------

PATH_BONUS = ./bonus/

PATH_INCLUDE_BONUS = ./bonus/includes_bonus/

PATH_UTILS_BONUS = ./bonus/utils_bonus/

PATH_SRC_BONUS = ./bonus/src_bonus/

SRCS_BONUS = ft_printf_bonus.c

UTILS_BONUS = ft_putchar_bonus.c \
			  ft_puthex_bonus.c \
			  ft_putnbr_bonus.c \
			  ft_putnbr_unsg_bonus.c \
			  ft_putpointer_bonus.c \
			  ft_putstr_bonus.c \
			  ft_strlen_bonus.c \
			  ft_strrchr_bonus.c \
			  ft_utoa_bonus.c \
			  ft_itoa_bonus.c \
			  ft_calloc_bonus.c \
			  ft_memset_bonus.c \
			  ft_print_arg_bonus.c \
			  ft_puthash_bonus.c \
			  ft_putsign_bonus.c \

%.o:$(PATH_SRC_BONUS)%.c
	@echo "Compilando $<"
	@$(CC) $(CFLAGS) -I $(PATH_SRC_BONUS) -c $< -o $@

%.o: $(PATH_UTILS_BONUS)%.c
	@echo "Compilando $<"
	@$(CC) $(CFLAGS) -I $(PATH_SRC_BONUS) -I $(PATH_UTILS_BONUS) -c $< -o $@

OBJS_BONUS := $(SRCS_BONUS:.c=.o)
OBJS_UTILS_BONUS := $(UTILS_BONUS:.c=.o)

bonus : $(OBJS_BONUS) $(OBJS_UTILS_BONUS)
		@$(AR) $(NAME) $(OBJS_BONUS) $(OBJS_UTILS_BONUS)
