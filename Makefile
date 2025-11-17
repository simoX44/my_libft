# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: mmouis <marvin@42.fr>                        +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2025/10/13 18:35:05 by mmouis              #+#    #+#             #
#   Updated: 2025/10/13 18:35:05 by mmouis             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  ft_putnbr_fd.c get_next_line_bonus.c ft_printf.c ft_putstr.c ft_putnbr.c ft_print_hex.c ft_print_char.c\
	  ft_print_unsig.c ft_print_pointer.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c ft_lstsize.c
NAME = libft.a

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(BONUS_OBJ)
	ar rcs $@ $(OBJ) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY:$(OBJ) $(BONUS_OBJ)
.PHONY: all clean fclean re bonus
