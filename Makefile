# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #
NAME 			= minishell
BONUS 			= bonus
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
SRCDIR_MINIS		= ./src/minis/
SRCDIR_BONUS		= ./src/bonus/
SRCDIR_PRINT		= ./src/ftpri/
SRCDIR_LIBFT		= ./src/libft/
SRCDIR_ERROR		= ./src/error/
SRCDIR_READL		= /usr/include/readline
#BUILD_DIR = $(shell grep -m1 BUILD_DIR $(SRCDIR_READL)Makefile | sed -e 's/BUILD_DIR = //g')

OBJDIR 			= ./obj/
INCDIR 			= ./inc/
LIBDIR			= ./lib/
REQUIRED_DIRS	= $(OBJDIR) $(INCDIR) $(LIBDIR)
vpath %.a $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= cc
CC 				= clang


WRNFL			= -Wall -Wextra -Werror -fsanitize=address
#WRNFL			= -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer

DBGFL			= -g3
CFLGS			= $(DBGFL) $(WRNFL) -c 
HEADS			= -I$(INCDIR) -I$(SRCDIR_READL) -I/usr/include
LFLGS 			= 
LFLGS 			= -fsanitize=address

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #
NAMELIBPRINTF 		= libftprintf.a
PATH_PRINT			= $(addprefix $(SRCDIR_PRINT), $(NAMELIBPRINTF))
LOADLIBPRINTF 		= ftprintf

NAMELIBFT 		= libft.a
PATH_LIBFT 		= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
LOADLIBFT 		= ft

NAMELIBERROR 		= libfterror.a
PATH_ERROR 		= $(addprefix $(SRCDIR_ERROR), $(NAMELIBERROR))
LOADLIBERROR 		= fterror

MYLIBS			= $(NAMELIBPRINTF) $(NAMELIBFT) $(NAMELIBERROR) 
LLIBS 			= -L$(LIBDIR) -l$(LOADLIBPRINTF) -l$(LOADLIBFT) -l$(LOADLIBERROR) -lreadline -lhistory -lncurses
$(info PRINT paths  $(PATH_PRINT))
$(info LIBT paths   $(PATH_LIBFT))
$(info ERROR paths  $(PATH_ERROR))
# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #

HEADER		=	minishell.h
SRCS_MINIS	= 	main.c\
			init.c\
			utils.c\
			free.c\
			signals.c\
			utils2.c\
			utils3.c\
			utils4.c\
			tokenizer.c\
			tokenizer_utils.c\
			ecmd_struct.c\
			expansor.c\
			expansor_here.c\
			expansor_here2.c\
			expansor_utils.c\
			executor.c\
			executor_command.c\
			executor_close.c\
			executor_struct.c\
			executor_utils.c\
			parser.c\
			parser_lexic.c\
			parser_utils.c\
			parser_utils2.c\
			builtin_selector.c\
			builtin_cd.c\
			builtin_echo.c\
			builtin_env.c\
			builtin_exit.c\
			builtin_export.c\
			builtin_pwd.c\
			builtin_unset.c\
			builtin_checker.c\
			utils_lists.c\
			utils_lists2.c\
			utils_lists3.c\
			utils_lists4.c\
			utils_env.c\
			utils_export.c\
			utils_export2.c\
			utils_file.c\
			utils_file2.c\
			utils_file3.c\
			utils_checks.c\
			utils_checks2.c\
			utils_checks3.c\
			utils_redir.c\
			utils_redir2.c\
			utils_redir3.c


FILE_MINIS = $(addprefix $(SRCDIR_MINIS), $(SRCS_MINIS))

OBJS_MINIS = $(addprefix $(OBJDIR), $(SRCS_MINIS:.c=.o))

DEPE_MINIS = $(addprefix $(OBJDIR), $(SRCS_MINIS:.c=.d))

$(info source files $(SRCS_MINIS))
$(info source paths $(FILE_MINIS))
$(info object patha $(OBJS_MINIS))
$(info depend patha $(DEPE_MINIS))

# ============================================================================ #
#                                 RULES                                        #
# ============================================================================ #
all: makedirs makelibs $(NAME)
#	bash -c "sudo sysctl vm.mmap_rnd_bits=28"
# includes all dependencies files.
# READ GNU make  manual 4.14 Generating Prerequisites Automatically.
-include $(DEPE_MINIS)

# .......................... directories creation ............................ #
#makedirs:
#	@mkdir -p $(REQUIRED_DIRS)
 makedirs:
 	$(shell for d in $(REQUIRED_DIRS); \
  				do \
  					[ -d $$d ] || mkdir -p $$d; \
  				done)

# .......................... library construction ............................ #
makelibs: $(MYLIBS) 

#$(NAMELIBFT): makelibft #$(LIBDIR)$(NAMELIBFT)
#$(NAMELIBPRINTF): makelibftprintf #$(LIBDIR)$(NAMELIBPRINTF)
#$(NAMELIBERROR): makeliberror #$(LIBDIR)$(NAMELIBERROR)

$(NAMELIBFT): makelibft 
	sleep 1
$(NAMELIBPRINTF): makelibftprintf
	sleep 1
$(NAMELIBERROR): makeliberror
	sleep 1
-lft:makelibft
-lftprintf:makelibftprintf
-lfterror:makeliberror


makelibft: 
	$(MAKE) -C $(SRCDIR_LIBFT) &> /dev/null

makelibftprintf:
	$(MAKE) -C $(SRCDIR_PRINT) &> /dev/null

makeliberror:
	$(MAKE) -C $(SRCDIR_ERROR) &> /dev/null
	
# ....................... dependencies construction .......................... #
#for each c file create its dependency file 
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$
# .......................... targets construction ............................ #
$(NAME): Makefile  $(OBJS_MINIS) -l$(LOADLIBFT) -l$(LOADLIBPRINTF) -l$(LOADLIBERROR)
	@echo "$(GREEN)========== GATHERING Minishell OBJECTS =============$(DEF_COLOR)"
	$(CC) -v $(LFLGS) $(OBJS_MINIS) -o $@ $(LLIBS)

# .......................... objects construction ............................ #
$(OBJDIR)%.o: $(SRCDIR_MINIS)%.c $(INCDIR)$(HEADER)
	@echo "$(GREEN)========== COMPILING Minishell FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)
 


.PHONY: clean
clean:
	@echo "========== Cleaning minishell objects =============="
	rm -f $(OBJS_MINIS)
	@echo "========== Cleaning prinf_f objects ================"
	$(MAKE) -C $(SRCDIR_PRINT)  clean
	@echo "========== Cleaning libft  objects ================="
	$(MAKE) -C $(SRCDIR_LIBFT)  clean
	@echo "========== Cleaning error  objects ================="
	$(MAKE) -C $(SRCDIR_ERROR)  clean
	@echo "========== Cleaning libraries *.a =================="
	rm -f $(LIBDIR)*

.PHONY: fclean
fclean : clean
	@echo "========== Cleaning executable minishell ==========="
	rm -f $(NAME)
	@echo "======= Cleaning prinf_f objects and library ======="
	$(MAKE) -C $(SRCDIR_PRINT)  fclean
	@echo "======= Cleaning libft   objectsand library ========"
	$(MAKE) -C $(SRCDIR_LIBFT)  fclean
	@echo "======= Cleaning error   objectsand library ========"
	$(MAKE) -C $(SRCDIR_ERROR)  fclean

.PHONY: re
re: fclean all
	@echo "========== Rebuilding minishell ===================="

.PHONY: bonus_clean
bonus_clean:
	@echo "========== Cleaning nimishell bonus objects ================"
	rm -f $(OBJS_CHECK)

.PHONY: bonus_fclean
bonus_fclean: bonus_clean
	@echo "========== Cleaning executable minishell bonus ============="
	rm -f $(BONUS)
norma:
	$(MAKE) -C $(SRCDIR_PRINT)  norma
	$(MAKE) -C $(SRCDIR_LIBFT)  norma
	$(MAKE) -C $(SRCDIR_ERROR)  norma

	@echo "$(GREEN)========== CHECKING NORME $(NAME) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_MINIS) 
	@echo "$(MAGENTA)========== CHECKING NORME $(BONUS) ==============$(DEF_COLOR)"
	norminette $(INCDIR)
run:
	valgrind -s --tool=memcheck --leak-check=full --track-origins=yes --track-fds=yes --trace-children=yes ./$(NAME)
bonusrun:
	valgrind -s --tool=memcheck --leak-check=full --track-origins=yes --track-fds=yes --trace-children=yes ./$(BONUS) $(VAR)
bonusrung:
	valgrind --tool=massif --stacks=yes ./$(BONUS)
