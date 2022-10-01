SRCSSERVEUR = ./SERVEUR/serveur.c

SRCSCLIENT = ./CLIENT/client.c

OBJSSERVEUR = $(SRCSSERVEUR:%.c=%.o)

OBJSCLIENT = $(SRCSCLIENT:%.c=%.o)

CC   = gcc -g3 -Wall -Wextra -Werror

NAMES = serveur

NAMEC = client

HEADSERVEUR = SERVEUR/serveur.h

HEADCLIENT = CLIENT/client.h

all: $(NAMES) $(NAMEC)

$(NAMES): $(OBJSSERVEUR) $(HEADSERVEUR)
	make -C ./Libft
	$(CC) $(SRCSSERVEUR) ./Libft/libft.a -o $@

$(NAMEC): $(OBJSCLIENT) $(HEADCLIENT)
	make -C ./Libft
	$(CC) $(SRCSCLIENT) ./Libft/libft.a -o $@

clean:
	make -C ./Libft clean
	rm -f $(OBJSSERVEUR)
	rm -f $(OBJSCLIENT)

fclean: clean
	rm -f ./Libft/libft.a
	rm -f $(NAMES)
	rm -f $(NAMEC)

re: fclean
	make all
	

.PHONY: all bonus clean fclean re
