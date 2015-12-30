#include <iostream>

enum SIGN  {SGN_CIRCLE, SGN_CROSS};
enum FIELD {FLD_EMPTY, FLD_CIRCLE, FLD_CROSS};
enum GAMESTATE {GS_NOTSTARTED,  GS_MOVE, GS_WON, GS_DRAW};

//rozpoczęcie gry
bool StartGry();

//wykonanie ruchu
bool Ruch(unsigned);

//rysowanie planszy
bool RysujPlansze();
