#ifndef _SERPENT_H_
#define _SERPENT_H_

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "initialisation.h"
#include "sauvegarde.h"

int creer_serpent (coord serpent[X*Y], coord pos );
int deplacer (coord serpent[X*Y], char dem,int taille);
void place_serpent (coord serpent[X*Y], int tab[N][N], int taille);
void place_serpent_pomme (coord serpent[X*Y], int tab[N][N], int taille, coord pomme);
int aggrandi_serpent (coord serpent[X*Y], coord pomme,int taille);
void aff_serpent (coord serpent[X*Y],int taille);


#endif /* _SERPENT_H_ */