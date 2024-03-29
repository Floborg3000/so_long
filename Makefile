NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBMLX = ./lib/MLX42

HEADERS = -I ./include -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
LGPATH = libmlx42.a -Iinclude -lglfw -L"/Users/fcornill/.brew/opt/glfw/lib"
SRCS = $(shell find ./src -iname "*.c")
OBJS = ${SRC:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

%.o: %.c 
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx