#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "initialisation.h"

void sauvegarder (FILE* fichier,int taille, coord pomme,coord serpent[XY]);

int gestion_pause ();

int charger_partie (FILE* fichier, coord *pomme,coord serpent[XY]);

#endif /* _SAUVEGARDE_H_ */