# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:02:33 by wding-ha          #+#    #+#              #
#    Updated: 2022/03/23 17:47:27 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
#############################################################
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
#############################################################
INC				= -Iinclude -I$(LIBFT_DIR)
LIBFT_DIR		= libs/libft
LIB				= -L$(LIBFT_DIR) -lft
SRC_DIR			= src/push_swap/
S_SRCS			= $(SRC_DIR)push_swap.c $(SRC_DIR)find_median.c $(SRC_DIR)small_case.c $(SRC_DIR)stack_shifter.c $(SRC_DIR)error.c\
				$(SRC_DIR)smart_rotate.c $(SRC_DIR)stack_function.c $(SRC_DIR)sort_function.c $(SRC_DIR)address_function.c


OBJS			= $(S_SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	make re -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean

.PHONY: all clean fclean re