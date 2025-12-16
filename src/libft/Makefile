# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 18:16:38 by luicasad          #+#    #+#              #
#    Updated: 2024/06/25 19:52:11 by luicasad         ###   ########.fr        #
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
BLUE		=	\033[0;94m
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
MY_COLOR	= $(BLUE)
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #
NAME		= libft.a
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
CC		=	cc
CFLAGS		=  -g -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
HEADS		=	-I$(INCDIR)
# From 4.4.3 The Function wildcard gnu make manual....
# Althought wildcard exparnds automaticaly in rules
# I use the wildcard function to expand wildcards in variables. 
# SRCS = $(wildcard *.c)
#
# This technique is forbidden according to 42 Norm point III.11
#
# So I must explicitly enumerate files for the project.

HEADER	=	libft.h
SRCS	=	ft_isalnum.c \
      	ft_isalpha.c \
      	ft_isascii.c \
      	ft_isdigit.c \
      	ft_isprint.c \
      	ft_strlen.c \
      	ft_memset.c \
      	ft_bzero.c \
      	ft_memcpy.c \
      	ft_memmove.c \
      	ft_memchr.c \
      	ft_memcmp.c \
      	ft_strlcpy.c \
      	ft_strlcat.c \
      	ft_strchr.c \
      	ft_strrchr.c \
      	ft_tolower.c \
      	ft_toupper.c \
      	ft_strtoupper.c \
		ft_atoi.c \
		ft_atol.c \
      	ft_strtrim.c \
      	ft_strncmp.c \
      	ft_calloc.c \
      	ft_strdup.c \
      	ft_strnstr.c \
      	ft_substr.c \
      	ft_strjoin.c \
      	ft_strjoin_int.c \
		ft_split_mem.c \
      	ft_split.c \
		ft_split_pipex.c \
      	ft_itoa.c \
      	ft_putchar_fd.c \
      	ft_putbits_fd.c \
      	ft_putstr_fd.c \
      	ft_putendl_fd.c \
      	ft_putnbr_fd.c \
      	ft_strmapi.c \
      	ft_striteri.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_msb.c \
		ft_bit.c

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
	@echo "$(MY_COLOR)LIBFT ========== GATHERING ALL OBJECTS ====================$(DEF_COLOR)"
	ar rcs $(LIBDIR)$(NAME) $?


# For each c file create its object file.
#$(OBJS): $(SRCS) 
%.o: %.c Makefile 
	@echo "$(MY_COLOR)LIBFT ========== COMPILING ALL OBJECTS ====================$(DEF_COLOR)"
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
	@echo "$(MY_COLOR)LIBFT ========== REMOVING ALL OBJECTS =====================$(DEF_COLOR)"
	rm -f $(OBJS)
	rm -f *.d

# removes target file and all generated object files
fclean: clean
	@echo "$(MY_COLOR)LIBFT ========== REMOVING TARGET ==========================$(DEF_COLOR)"
	rm -f $(LIBDIR)$(NAME) # rebuild all after removing all
re: fclean all
	@echo "$(MY_COLOR)LIBFT ================ REBUILDING =========================$(DEF_COLOR)"

norma:
	@echo "$(MY_COLOR)LIBFT ============== CHECKING NORME =======================$(DEF_COLOR)"
	norminette $(SRCS)
.PHONY: all clean fclean re

