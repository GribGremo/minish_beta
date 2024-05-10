# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 11:39:02 by sylabbe           #+#    #+#              #
#    Updated: 2024/05/10 15:56:02 by sylabbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address

# Définir le répertoire des sources mandatory
SRC_MDT_DIR = mdt/srcs

# Définir le répertoire des objets mandatory
DEST_MDT_DIR = mdt/obj


# Ajouter le chemin au début de chaque fichier source
SRC =	$(addprefix $(SRC_MDT_DIR)/, minishell.c \
										env.c \
										expand.c \
										lst_char.c \
										lst_env.c \
										lst_word.c \
										create_lst_char.c \
										create_lst_word.c \
										debug.c)


# Générer les noms d'objets en remplaçant l'extension .c par .o dans le répertoire obj
OBJECTS = $(SRC:$(SRC_MDT_DIR)/%.c=$(DEST_MDT_DIR)/%.o)

CC = cc

RM = rm -f

all: $(NAME)


$(NAME): $(OBJECTS)
	@${MAKE} -C ./Libft
	@echo "\033[0;32mLIBFT COMPILED\033[0m"
	@${CC} ${CFLAGS} $(OBJECTS) ./Libft/libft.a -o $(NAME) -lreadline
	@echo "\033[0;32mMANDATORY COMPILED\033[0m"


# Générer les fichiers objets
$(DEST_MDT_DIR)/%.o: $(SRC_MDT_DIR)/%.c | obj
	@$(CC) $(CFLAGS) -c $< -o $@ -g


# Créer le répertoire obj s'il n'existe pas
obj:
	@mkdir -p $(DEST_MDT_DIR)

clean:
	@${MAKE} -C ./Libft fclean
	@$(RM) -r $(DEST_MDT_DIR) 
	@echo "\033[0;33mCLEAN OBJECTS\033[0m"

fclean: clean
	@$(RM) $(NAME) 
	@echo "\033[0;33mCLEAN EXEC\033[0m"

#re: fclean all

re:
	@${MAKE} fclean all;

MAKEFLAGS         += --no-print-directory

.PHONY: all clean fclean re bonus

