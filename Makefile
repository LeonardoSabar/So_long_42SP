NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(PRINTF)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find src -iname "*.c")		# Mudar isso depois
OBJS	:= ${SRCS:src/%.c=obj/%.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C ${LIBFT} all

printf:
	@make -C ${PRINTF} all

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
#	@rm -rf $(LIBMLX)/build
#	@make -C ${LIBFT} clean
#	@make -C ${PRINTF} clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, printf
