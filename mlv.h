#ifndef _MLV_H_
#define _MLV_H_

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "types.h"

int menu_mlv ();
void couleur_case_mlv (int pos_x, int pos_y, int couleur);
void score_mlv (int taille);

void aff_plateau_mlv (int tab[N][N],int taille);
int chargement_partie_mlv();
void fond_ecran();


#endif /* _MLV_H_ */