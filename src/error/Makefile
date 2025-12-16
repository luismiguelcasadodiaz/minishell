# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 18:16:38 by luicasad          #+#    #+#              #
#    Updated: 2024/06/25 19:52:20 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#MAKEFLAGS += rR
# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
MYCOLOR		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
BLACK		=	\033[0;99m
ORANGE		=	\033[38;5;209m
BROWN		=	\033[38;2;184;143;29m
DARK_GRAY	=	\033[38;5;234m
MID_GRAY	=	\033[38;5;245m
DARK_GREEN	=	\033[38;2;75;179;82m
DARK_YELLOW	=	\033[38;5;143m

MYCOLOR		=$(RED)
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #
NAME		= libfterror.a
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
#OBJDIR		= ../../obj/
INCDIR		= ../../inc/
LIBDIR		= ../../lib/
OBJDIR		= 
#INCDIR		=
#LIBDIR		=
vpath %.a $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC			=	cc
CFLAGS		=	-g -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
HEADS		=	-I$(INCDIR)
# From 4.4.3 The Function wildcard gnu make manual....
# Althought wildcard exparnds automaticaly in rules
# I use the wildcard function to expand wildcards in variables. 
# SRCS = $(wildcard *.c)
#
# This technique is forbidden according to 42 Norm point III.11
#
# So I must explicitly enumerate files for the project.

HEADER	=	ft_error.h
SRCS	=	ft_error_str.c \
			ft_error_decode_e.c \
			ft_error_exit.c \
			ft_error_print.c \
			my_perror.c \
			ft_errorf.c \
			ft_write_c.c \
			ft_write_dec.c \
			ft_write_hex_cap.c \
			ft_write_hex_low.c \
			ft_write_int.c \
			ft_write_int_base.c \
			ft_write_ptr.c \
			ft_write_str.c \
			ft_write_uns.c \
			ft_write_uns_base.c

# Generate a list of object files by replacing .c with .o
#
# I did this approach
#
#OBJS = $(patsubst %.c, %.o, $(SRCS))
#BONUS_OBJS = $(patsubst %.c, %.o, $(BONUS_SRCS))
#
#But Dina Zhuzhleva suggested me this aproach to avoid suspicious usage of wild cards.
#
_OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(_OBJS))

# The default goal is the first target of the first rule in the first makefile.
# This is the reason for writtting this rule the first one


all: $(NAME)

#includes all dependencies files.
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
include $(SRCS:.c=.d)

# Vous devez utiliser la commande ar pour créer votre bibliothèque
# NOTE rcs:
# - r  means that if the library already exists, replace the old files within the library with your new files. 
# - c means create the library if it did not exist. 
# - s can be seen to mean 'sort' (create a sorted index of) the library, so that it will be indexed and faster to access the functions in the library.
#   Therefore, rcs can be seen to mean replace, create, sort

$(NAME): $(OBJS) 
	@echo "$(MYCOLOR)$(NAME) ========== GATHERING ALL OBJECTS ====================$(DEF_COLOR)"
	ar rcs $(LIBDIR)$(NAME) $?


# For each c file create its object file.
#$(OBJS): $(SRCS) 
%.o: %.c Makefile 
	@echo "$(MYCOLOR)$(NAME) ========== COMPILING ALL OBJECTS ====================$(DEF_COLOR)"
	$(CC) $(CFLAGS)  -c $< -o $@ $(HEADS)

#for each c file create its dependency file 
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

# removes all generated object files
clean:
	@echo "$(MYCOLOR)$(NAME) ========== REMOVING ALL OBJECTS =====================$(DEF_COLOR)"
	rm -f $(OBJS)
	rm -f *.d

# removes target file and all generated object files
fclean: clean
	@echo "$(MYCOLOR)$(NAME) ========== REMOVING TARGET ==========================$(DEF_COLOR)"
	rm -f $(LIBDIR)$(NAME) # rebuild all after removing all
re: fclean all
	@echo "$(MYCOLOR)$(NAME) ================ REBUILDING =========================$(DEF_COLOR)"

norma:
	@echo "$(MYCOLOR)$(NAME) ============== CHECKING NORME =======================$(DEF_COLOR)"
	norminette $(SRCS)
	norminette $(INCDIR)$(HEADER)
.PHONY: all clean fclean re

