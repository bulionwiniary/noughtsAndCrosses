#include "game.h"


int main(int argc, char** argv)
{
	extern GAMESTATE stanGry;
	unsigned ruch;

	if(StartGry() == 1){
		std::cout << "Coś poszło nie tak ze startem \n";
	}
	
//	if(stanGry == GS_MOVE)
//		std::cout << "jest ok\n";
	RysujPlansze();
	
	while(stanGry == GS_MOVE){
		std::cout << "Gdzie chcesz postawić swój znak? ";
		std::cin >> ruch;
		if(Ruch(ruch) == 1){
			std::cout << "Na tym polu już coś jest. Spróbuj jeszcze raz!\n"; //funkcja Ruch() sprawdza czy jest coś na polu ruch, jeśli tak to wyświetli komunikat

		}
		if(ruch < 1 || ruch > 9){
/* prosta obsługa błędów - poza zakresem*/
			std::cout << "Wybrałeś zły numer, spróbuj jeszcze raz!\n";	
		continue;		
		}
		//potem go rysuje i sprawdza czy koniec gry
		if(RysujPlansze()){
			StartGry();
			RysujPlansze();
		}
	}
	std::cout << "Dziekuje za mila gre!\n";
	return 0;
}
