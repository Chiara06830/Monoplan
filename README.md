# Monoplan

Tableur simplifié réaliser dans le cadre du module de programmation C avancé. (L3 II, Université de Bretagne Occidentale)

## Compilation et Exécution
Pour compiler il faut faire la commande `make` a la base de l'arboressence.
Et pour éxécuter il faut éxecuter `Monoplan.exe`.

## Arboressence
```
 Monoplan :
├── include
│   ├── cellule.h
│   ├── graphe.h
│   ├── liste.h
│   ├── stack.h
│   └── test.h
├── obj
├── src
│   ├── cellule.c
│   ├── graphe.c
│   ├── liste.c
│   ├── stack.c
│   ├── testCellule.c
│   ├── testGraphe.c
│   ├── testListe.c
│   ├── testStack.c
│   └── main.c
└── makefile
```


## Modules
### Module Liste
Composé de :
- liste.h
- liste.c
- testListe.c

Permet de créer et manipulé une liste chainé de void *.

### Module Cellules
Composé de  :
- cellule.h
- cellule.c
- testCellule.c

Lit le contenu d'une cellule et effectue le calcul quand s'en est un.

### Modules Graphe
Composé de : 
- graphe.c
- graphe.h
- testGraphe.c

Evalue les cellules qui sont dépendantes les unes des autres.