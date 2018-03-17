##
## Makefile for lem-in in /home/lecler_k//Semestre_2/Progelem/lem-in
## 
## Made by brice leclercq
## Login   <lecler_k@epitech.net>
## 
## Started on  Thu Apr 25 14:16:46 2013 brice leclercq
## Last update Tue Oct 22 14:40:34 2013 Alexis Santini
##

NAME	=	lem_in

SRC	=	src/main.c		\
		src/my_str_to_word_tab.c\
		src/aff_tab.c		\
		src/free_tab.c		\
		src/init_rooms.c	\
		src/my_put_in_room.c	\
		src/clear_map.c		\
		src/error.c		\
		src/check_doubles.c	\
		src/complete_rooms.c	\
		src/is.c		\
		src/xerror.c		\
		src/push_ant.c

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc

RM	=	@rm -f

CPPFLAGS=	-I include/ -g

CFLAGS	=	-W -Wall -Werror -pedantic -ansi

NEUTRE	=	\e[0;m

ROUGE	=	\e[0;31m

all:		$(OBJ)
#		@(echo -e "\n\n\t$(ROUGE)ATTENTION: compilation du programme en cours... (âmes sensibles s'abstenir)$(NEUTRE)\n" ; sleep 3 ; xloadimage -quiet .king_kong.gif)
		$(CC) $(OBJ) -o $(NAME)
		@(echo -e "$(ROUGE)DONE$(NEUTRE)")

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

love:
		@echo "... not war"

coffee:
		@echo "         {"
		@echo "      {   }"
		@echo "       }_{ __{"
		@echo "    .-{   }   }-."
		@echo "   (   }     {   )"
		@echo "   |'-.._____..-'|"
		@echo "   |             ;--."
		@echo "   |            (__  \\"
		@echo "   |             | )  )"
		@echo "   |    I <3     |/  /"
		@echo "   |     NY      /  /"
		@echo "   |            (  /"
		@echo "   \             y'"
		@echo "    '-.._____..-'"

pikachu:
		@echo "  :::,"
		@echo "  '::::'._"
		@echo "    '.    '.                        __.,,."
		@echo "      '.    '.                _..-'''':::"
		@echo "        \     \,.--\"\"\"\"--.,-''      _:'"
		@echo "    /\   \  .               .    .-'"
		@echo "   /  \   \                   ':'"
		@echo "  /    \  :                     :"
		@echo " /      \:                       :"
		@echo " \       :                       :"
		@echo "  \      :      ,--,        ,--,  :"
		@echo "   \    :      |(_):|      |(_):| :"
		@echo "    \   :     __'--'   __   '--'_  :"
		@echo "     \  :    /  \      \/      / \ :"
		@echo "      \  :  (    )             \_/ :"
		@echo "   .-'' . :  \__/   '--''--'      :"
		@echo "   \  . .-:'.                   .:"
		@echo "    \' :| :  '-.__      ___...-' :"
		@echo "     \::|:        ''''''          '."
		@echo "   .,:::':  :                       '."
		@echo "    \::\:   :                         '._"
		@echo "     \::    :     /             '-._     '."
		@echo "      \:    :    /              .   :-._ :-'"
		@echo "       :    :   /               :   :  ''"
		@echo "       :   .'   )'.             :   :"
		@echo "        :  :  .'   '.          :   :"
		@echo "         : '..'      :      _.' _.:"
		@echo "          '._        :..---'\'''  _)"
		@echo "             '':---''_)      '-'-'"
		@echo "                '-'-'  PIKACHU!"
