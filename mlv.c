#include "mlv.h"

void fond_ecran(){
    int i,j;
    int coordonnee_x[3];
    int coordonnee_y[3];
    for (i=0;i<48;i++){
        if (i%2==0)
            MLV_draw_filled_rectangle( 0, i*25, 1200, 25, MLV_COLOR_PEACH_PUFF );
        else
            MLV_draw_filled_rectangle( 0, i*25, 1200, 25, MLV_COLOR_BISQUE);
    }
    for (j=0;j<18;j++){
        for (i=0;i<48;i++){
            coordonnee_x[0]=i*25;
            coordonnee_x[1]=i*25+25;
            coordonnee_x[2]=i*25+12.5;
            coordonnee_y[0]=j*50;
            coordonnee_y[1]=j*50;
            coordonnee_y[2]=j*50+25;
            MLV_draw_filled_polygon (coordonnee_x,coordonnee_y,3,MLV_COLOR_BISQUE);
        }
        for (i=0;i<48;i++){
            coordonnee_x[0]=i*25;
            coordonnee_x[1]=i*25+12.5;
            coordonnee_x[2]=i*25+25;
            coordonnee_y[0]=j*50+50;
            coordonnee_y[1]=j*50+25;
            coordonnee_y[2]=j*50+50;
            MLV_draw_filled_polygon (coordonnee_x,coordonnee_y,3,MLV_COLOR_PEACH_PUFF);
        }
    }
}

int menu_mlv (){
    int x=0,y=0, taille_interligne=10;
    MLV_Font* font=MLV_load_font("MilkyBoba.ttf",25);
    MLV_Font* font_titre=MLV_load_font("HugeParty.ttf",170);
    fond_ecran();

    MLV_draw_text_with_font(
        385,50,
        "SNAKE",
        font_titre,
        MLV_COLOR_SADDLEBROWN
        );
    
    MLV_draw_text_box_with_font(
        X_INTERBOITE,Y_INTERBOITE*2,
        X_BOITE,Y_BOITE,
        "Jouer",
        font,
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_draw_text_box_with_font(
        X_INTERBOITE*2+X_BOITE,Y_INTERBOITE*2,
        X_BOITE,Y_BOITE,
        "Charger",
        font,
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_draw_text_box_with_font(
        X_INTERBOITE,Y_INTERBOITE*3+Y_BOITE,
        X_BOITE,Y_BOITE,
        "Meilleurs scores",
        font,
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_draw_text_box_with_font(
        X_INTERBOITE*2+X_BOITE,Y_INTERBOITE*3+Y_BOITE,
        X_BOITE,Y_BOITE,
        "Bonus",
        font,
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_actualise_window();

    

    while(1==1){
        MLV_wait_mouse(&x, &y);
        
        if (x>=X_INTERBOITE && x<=X_INTERBOITE+X_BOITE && y>=Y_INTERBOITE*2 && y<=Y_INTERBOITE*2+Y_BOITE)
            return 1;
        
        if (x>=X_INTERBOITE*2+X_BOITE && x<=X_INTERBOITE*2+X_BOITE*2 && y>=Y_INTERBOITE*2 && y<=Y_INTERBOITE*2+Y_BOITE)
            return 2;
            
        if (x>=X_INTERBOITE && x<=X_INTERBOITE+X_BOITE && y>=Y_INTERBOITE*3+Y_BOITE && y<=Y_INTERBOITE*3+Y_BOITE+Y_BOITE*2)
            return 3;
        
        if (x>=X_INTERBOITE*2+X_BOITE && x<=X_INTERBOITE*2+X_BOITE*2 && y>=Y_INTERBOITE*3+Y_BOITE && y<=Y_INTERBOITE*3+Y_BOITE+Y_BOITE*2)
            return 4;
    }
}

void couleur_case_mlv (int pos_x, int pos_y, int couleur){
    if (couleur==0)
        MLV_draw_filled_rectangle( pos_x,pos_y, C, C, MLV_COLOR_BLACK );
    if (couleur==1)
        MLV_draw_filled_rectangle( pos_x,pos_y, C, C, MLV_COLOR_WHITE );
    if (couleur==2)
        MLV_draw_filled_rectangle( pos_x,pos_y, C, C, MLV_COLOR_LIME_GREEN );
    if (couleur==3)
        MLV_draw_filled_rectangle( pos_x,pos_y, C, C, MLV_COLOR_FOREST_GREEN );
    if (couleur==4)
        MLV_draw_filled_rectangle( pos_x,pos_y, C, C, MLV_COLOR_RED );
}
void score_mlv (int taille){
    MLV_Font* font=MLV_load_font("MilkyBoba.ttf",25);
    
    MLV_draw_text_with_font(
        800,20,
        "Score : %d",
        font,
        MLV_COLOR_BLACK,
        taille-1
        );
}

void aff_plateau_mlv (int tab[N][N],int taille){
    MLV_Font* font_titre=MLV_load_font("HugeParty.ttf",150);
    int i,j;
    fond_ecran();
    
    MLV_draw_text_with_font(
        100,-21,
        "SNAKE",
        font_titre,
        MLV_COLOR_SADDLEBROWN
        );
    score_mlv(taille);
    for (i = 0; i < Y; i++){
        for (j = 0; j < X; j++){
            couleur_case_mlv (75+j*C,100+i*C,tab[i][j]);
        }
    }
    MLV_actualise_window();
}


int chargement_partie_mlv(){
    int x,y,taille_interligne=10;
    fond_ecran();

    MLV_draw_text_box(
        205,250,
        280,150,
        "Partie 1",
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_draw_text_box(
        715,250,
        280,150,
        "Partie 2",
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_draw_text_box(
        460,525,
        280,150,
        "Partie 3",
        taille_interligne,
        MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_CHOCOLATE,
        MLV_TEXT_LEFT,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    MLV_actualise_window();    

    while(1==1){
        MLV_wait_mouse(&x, &y);
        
        if (x>=205 && x<=485 && y>=250 && y<=400)
            return 1;
        
        if (x>=715 && x<=995 && y>=250 && y<=400)
            return 2;
            
        if (x>=460 && x<=740 && y>=525 && y<=675)
            return 3;
        
    }
}


