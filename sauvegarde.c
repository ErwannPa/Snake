#include"sauvegarde.h"


void sauvegarder (FILE *fichier,int taille, coord pomme,coord serpent[XY]){ 
    int k;

    fprintf(fichier,"%d\t",taille);
    fprintf(fichier,"%d\t%d\n",pomme.x,pomme.y);

    for (k=0;k<taille;k++){
        fprintf(fichier,"%d\t%d\n",serpent[k].x,serpent[k].y);
    }
}


int gestion_pause (){
    char pause_dem;    
    printf("Votre jeu est en pause que voulez-vous faire ? (s : sauvegarder / autre lettre pour continuer) ");
    pause_dem=getchar();
    f_buffer();
    
    if (pause_dem=='s')
        return 0;
    return 1;
}
    


int charger_partie (FILE *fichier,coord * pomme,coord serpent[XY]){
    int k,taille;
    if (fscanf(fichier,"%d\t%d\t%d",&taille,&pomme->x,&pomme->y)==3){  
        for (k=0;k<taille;k++){
            if (fscanf(fichier,"%d\t%d",&serpent[k].x,&serpent[k].y)!=2){
                k=taille;
                taille = -1;
            }
        }
    }
    printf("les coord pomme x:%d y : %d\n",pomme->x, pomme->y);
    return taille;
}