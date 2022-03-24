# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:02:33 by wding-ha          #+#    #+#              #
#    Updated: 2022/03/25 01:40:37 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= push_swap
B_NAME			= checker
#############################################################
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
#############################################################
INC				= -Iinclude -I$(LIBFT_DIR)
LIBFT_DIR		= libs/libft
LIB				= -L$(LIBFT_DIR) -lft
SRC_DIR			= src/push_swap/
CHK_DIR			= src/checker/
S_SRCS			= $(SRC_DIR)push_swap.c $(SRC_DIR)find_median.c $(SRC_DIR)small_case.c $(SRC_DIR)stack_shifter.c $(SRC_DIR)error.c\
				$(SRC_DIR)smart_rotate.c $(SRC_DIR)stack_function.c $(SRC_DIR)sort_function.c $(SRC_DIR)address_function.c\
				$(SRC_DIR)stack_build.c
B_SRCS			= $(CHK_DIR)checker.c $(SRC_DIR)find_median.c $(CHK_DIR)stack_command.c $(SRC_DIR)stack_function.c $(SRC_DIR)error.c\
				$(SRC_DIR)address_function.c  $(CHK_DIR)checker_util.c $(SRC_DIR)stack_shifter.c $(SRC_DIR)stack_build.c
OBJS			= $(S_SRCS:.c=.o)
B_OBJS			= $(B_SRCS:.c=.o)

all:			$(NAME) $(B_NAME)

$(NAME):		$(OBJS)
	@make re -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)
	
$(B_NAME):		$(B_OBJS)
	@make re -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(B_INC) -o $(B_NAME) $(B_MAIN) $(B_OBJS) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ -s
clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME) $(B_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean

.PHONY: all clean fclean re