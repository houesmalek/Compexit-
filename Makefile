CC=gcc

# Les différents répertoires contenant respectivement les fichiers : sources *.c, headers *.h, objets *.o, l'exécutable
SRCDIR=src
HEADDIR=headers
LIBDIR=obj
BINDIR=bin

# Les différentes options de compilations
CFLAGS= -g -pedantic-errors -lpthread -Wextra -Wshadow -Werror -std=c99 -lm
#-I../..
# Les éventuelles bibliothèques pour le linkage
GLLIBS =

# L'exécutable
BIN=main_graph

# Où trouver les différents sources *.c qu'il faudra compiler pour créer les objets correspondants
SRC= $(wildcard $(SRCDIR)/*.c)
OBJ= $(SRC:$(SRCDIR)/%.c=$(LIBDIR)/%.o)

all: $(BIN)

#Création de l'exécutable
$(BIN) : %: $(OBJ)
			$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS) $(GLLIBS)

# Création des différents *.o à partir des *.c
$(LIBDIR)/%.o: $(SRCDIR)/%.c $(HEADDIR)/%.h
			   $(CC) -o $@ -c $< $(CFLAGS)

# Nettoyage des objets => Tout sera recompiler
clean:
	rm $(LIBDIR)/*

# Nettoyage complet => clean + effacement du l'exécutable
cleanall :: clean
		    rm $(BINDIR)/*
