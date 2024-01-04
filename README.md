# Monoplan

Simplified spreadsheet made for the course of advanced C programmation at the University of Western Britany.

## Compilation and Execution
For compilation:
```bash
make
```
For execution:
```bash
Monoplan.exe
```

## Structure
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
### Module List
Composed of:
- liste.h
- liste.c
- testListe.c

Allow to create and manipulate a chained list of `void*`.

### Module Cell
Composed of:
- cellule.h
- cellule.c
- testCellule.c

Read a cell et calculate the value when it is a calculus.

### Module Graph
Composed of: 
- graphe.c
- graphe.h
- testGraphe.c

Evalue les cellules qui sont dépendantes les unes des autres.
Evauluate cells that are interdependent.

## Future work
Make an graphic inteface.
