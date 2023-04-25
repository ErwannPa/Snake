#include "initialisation.h"

void f_buffer(){ /* Permet de vider le buffer */
    int c;
    while ((c = getchar()) != EOF && c != '\n')
        ;
}


void plateau (int tab[N][N]){ /* Créer le plateau de jeu */
    int i, j;
    for (i = 0 ; i < Y ; i++ ){
        for (j = 0 ; j < X ; j++){
                tab[i][j]=0;
        }
    }
}

void contour_plateau (int tab[N][N]){ /* Créer les murs du plateau */
    int i, j;
    for (j=0,i=0;i<Y;i++){
         tab[i][j]=1;
    }
    for (j=X-1,i=0;i<Y;i++){
         tab[i][j]=1;
    }
    for (i=0,j=0;j<X;j++){
        tab[i][j]=1;
    }
    for (i=Y-1,j=0;j<X;j++){
        tab[i][j]=1;
    }
}

void contour_plateau_2 (int tab[N][N]){ /* Créer les murs du plateau */
    int i, j;
    for (j=0,i=0;i<Y;i++){
         tab[i][j]=1;
    }
    for (j=X-1,i=0;i<Y;i++){
         tab[i][j]=1;
    }
    for (i=0,j=0;j<X;j++){
        tab[i][j]=1;
    }
    for (i=Y-1,j=0;j<X;j++){
        tab[i][j]=1;
    }
    for(i=Y/2,j=3;j<X/2;j++){
        tab[i][j]=1;
    }
}

void aff_tab (int tab[N][N]){ /* Affiche le plateu de jeu */
    int i, j;
    printf("\n");
    for (i = 0; i < Y; i++){
        for (j = 0; j < X; j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}





coord random_spawn(){ /* Créer les coordonnées d'apparition du serpent */
    coord tete;
    tete.x=rand() %(X-2)+1;
    tete.y=rand() %(Y-2)+1;
    return tete;
}
int demande_action(){/* Récupère la direction ou la demande de pause demandée par l'utilisateur */
    char dem;
    printf("\nQue voulez vous faire jouer ou charger une partie ? (j : jouer | c : charger) ");
    dem=getchar();
    f_buffer();
    return dem;
}

int demande_direction(char dem){/* Récupère la direction ou la demande de pause demandée par l'utilisateur */
    MLV_Keyboard_button bouton;
    MLV_Event event = MLV_NONE;
    MLV_delay_according_to_frame_rate();
    event=MLV_get_event(&bouton,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    MLV_flush_event_queue();
    if (event==MLV_KEY){
        if ( bouton == MLV_KEYBOARD_z){
            return 'z';
        }
        if(bouton == MLV_KEYBOARD_q){
            return 'q';
        }
        if(bouton == MLV_KEYBOARD_s){
            return 's';
        }
        if(bouton == MLV_KEYBOARD_d){
            return 'd';
        }
        
        
        return dem;
    }
    return dem ;
}

int tete_vivante (int tab[N][N]){ /* Permet de savoir si la tête du serpent est présente dans le plateau  */
    int i, j;
    for (i = 0; i < Y; i++){
        for (j = 0; j < X; j++){
            if (tab[i][j]==3)
                return 1;
            }
    }
    return 0;
}