# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 08:35:36 by leobarbo          #+#    #+#              #
#    Updated: 2024/01/16 13:27:18 by leobarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libft.a

SRCS := ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_split.c\

OBJS := $(SRCS:.c=.o)

CC := cc

CFLAGS := -Wall -Wextra -Werror

AR := ar -rcs

RM := rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -g3
	@$(AR) $(NAME) $@
	@printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
