#ifndef _TYPES_H_
#define _TYPES_H_

#define N 50
#define Y 20
#define X 30
#define XY 300

/**********PARTIE MLV***********/
#define X_BOITE 375          
#define X_INTERBOITE 150
#define Y_BOITE 120
#define Y_INTERBOITE 140
#define C 35

/*******************************/

struct coordonnees {
  int x;
  int y;
};
typedef struct coordonnees coord ;

#endif /* _TYPES_H_ */