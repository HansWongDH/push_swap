# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:02:33 by wding-ha          #+#    #+#              #
#    Updated: 2022/03/22 19:52:12 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			= ./src/push_swap
LIBS			= ./libs/libftprintf.a
S_SRCS			= $(wildcard $(SRC_DIR)/*.c)
OBJS			= $(S_SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LIBFT			= -make -C libs
NAME			= pushswap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(LIBFT)
				$(CC) -o $@ $< $(LIBS)
				
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) -c $(CFLAGS) $< -o $@
clean:			
				$(RM) $(OBJS)
				make -C libs clean