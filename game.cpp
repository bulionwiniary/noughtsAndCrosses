#include "game.h"

GAMESTATE stanGry = GS_NOTSTARTED;
static SIGN stan = SGN_CIRCLE;
static std::string nazwaGracza1;//grajacy kolkiem
static std::string nazwaGracza2;//grajacy krzyzykiem
static FIELD plansza[3][3];
static int licznikGry;


//rozpoczęcie gry
bool StartGry()
{
	if(stanGry != GS_NOTSTARTED)
		return 1;

	std::cout<< "Witaj w grze \"Kolko i Krzyzyk\" autorstwa Mateusza Krawczyka\n";
	std::cout<< "Jak się nazywasz? (kolko)  ";
	std::cin >> nazwaGracza1;
	std::cout<< "\nJak nazywa sie twoj przeciwnik? (krzyzyk)  ";
	std::cin >> nazwaGracza2;	
	stanGry = GS_MOVE;

//zerowanie planszy
	for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++)
				plansza[i][j] = FLD_EMPTY;
	}
	licznikGry = 0;

	return 0;
}

//wykonanie ruchu
bool Ruch(unsigned ruch)
{
	int i,j,k;
	j=(ruch-1)%3;
	i=(ruch-j)/3;

	if( plansza[i][j]!= FLD_EMPTY )
		return 1;
//ustawianie 
	plansza[i][j]= (stan == SGN_CIRCLE) ? FLD_CIRCLE : FLD_CROSS;
	stan = (stan == SGN_CIRCLE) ? SGN_CROSS : SGN_CIRCLE;

	int sprawdzacz_cross, sprawdzacz_circle;

	licznikGry++;
	//pętla poniżej sprawdza, czy nie ma 3 znaków w PIONIE (warunek wystarczający wygranej)

	for(int k = 0; k <3; k++){
		sprawdzacz_cross = 0;
		sprawdzacz_circle = 0;
		for( int m=0; m <3; m++){
			if(plansza[k][m] == FLD_CIRCLE)
				sprawdzacz_circle++;
			else if(plansza[k][m] == FLD_CROSS)
				sprawdzacz_cross++;
		}
		if(sprawdzacz_cross==3 || sprawdzacz_circle == 3){
			stanGry = GS_WON;
			return 0;
		}
	}

	//pętla poniżej sprawdza, czy nie ma 3 znaków w POZIOMIE(warunek wystarczający wygranej)
	for(k = 0; k <3; k++){
		sprawdzacz_cross = 0;
		sprawdzacz_circle = 0;
		for( int m=0; m <3; m++){
			if(plansza[m][k] == FLD_CIRCLE)
				sprawdzacz_circle++;
			else if(plansza[m][k] == FLD_CROSS)
				sprawdzacz_cross++;
		}
		if(sprawdzacz_cross== 3 || sprawdzacz_circle == 3){
			stanGry = GS_WON;
			return 0;
		}
	}
	sprawdzacz_cross = 0;
	sprawdzacz_circle = 0;
	//sprawdzanie backslasha (\)
	for(k = 0; k<3; k++){
		if(plansza[k][k] == FLD_CIRCLE)
			sprawdzacz_circle++;
		else if(plansza[k][k] == FLD_CROSS)
			sprawdzacz_cross++;
		if(sprawdzacz_cross== 3 || sprawdzacz_circle == 3){
			stanGry = GS_WON;
			return 0;
		}
	}
	sprawdzacz_cross = 0;
	sprawdzacz_circle = 0;
	//sprawdzanie slasha (/)
	for(k = 0; k<3; k++){
		if(plansza[2-k][k] == FLD_CIRCLE)
			sprawdzacz_circle++;
		else if(plansza[2-k][k] == FLD_CROSS)
			sprawdzacz_cross++;
		if(sprawdzacz_cross== 3 || sprawdzacz_circle == 3){
			stanGry = GS_WON;
			return 0;
		}
	}

	if(licznikGry == 9)
		stanGry = GS_DRAW;
	
	return 0;		
}

//rysowanie planszy
bool RysujPlansze()
{
	if(stanGry == GS_MOVE){
		std::cout<<"-----------------------------------------\n";
		if (stan == SGN_CIRCLE)
			std::cout<<nazwaGracza1<<" - to twoj ruch!";
		else
			std::cout<<nazwaGracza2<<" - to twoj ruch!";
	
		for(int i = 0; i<3; i++){
			std::cout<<"\n\t";
			for(int j = 0; j<3; j++){
				if(plansza[i][j] == FLD_EMPTY){
					std::cout<<(i*3)+j+1<<" ";
				}else if(plansza[i][j] == FLD_CIRCLE){
					std::cout<<"O ";
				}else if(plansza[i][j] == FLD_CROSS){
					std::cout<<"X ";
				}
			}
	
		}
		std::cout<<"\n-----------------------------------------\n";
		return 0;

	}else if(stanGry == GS_WON){//obsługa wygrania

		for(int i = 0; i<3; i++){
			std::cout<<"\n\t";
			for(int j = 0; j<3; j++){
				if(plansza[i][j] == FLD_EMPTY){
					std::cout<<(i*3)+j+1<<" ";
				}else if(plansza[i][j] == FLD_CIRCLE){
					std::cout<<"O ";
				}else if(plansza[i][j] == FLD_CROSS){
					std::cout<<"X ";
				}
			}
		}
		std::string newGame;
		std::cout << "\nBrawo " <<((stan == SGN_CROSS) ? nazwaGracza1 : nazwaGracza2) << " - wygrałeś życie i tą grę!!!\n";
		std::cout << "Gramy jeszcze raz? (t/n)\n";
		std::cin >> newGame;

		while(!(newGame == "t" || newGame == "n")){
			std::cout << "Wpisz t (tak) lub n (nie)\n";
			std::cin >> newGame;
		}	
		if(newGame == "t")
			return 1;
		else
			return 0;
			
	}else if(stanGry == GS_DRAW){//obsługa remisu

		for(int i = 0; i<3; i++){
			std::cout<<"\n\t";
			for(int j = 0; j<3; j++){
				if(plansza[i][j] == FLD_EMPTY){
					std::cout<<(i*3)+j+1<<" ";
				}else if(plansza[i][j] == FLD_CIRCLE){
					std::cout<<"O ";
				}else if(plansza[i][j] == FLD_CROSS){
					std::cout<<"X ";
				}
			}		
		}
		std::string newGame;
		std::cout << "\nOgłaszam remis\n";
		std::cout << "Gramy jeszcze raz? (t/n)\n";
		std::cin >> newGame;

		while(!(newGame == "t" || newGame == "n")){
			std::cout << "Wpisz t (tak) lub n (nie)\n";
			std::cin >> newGame;
		}	
		if(newGame == "t")
			return 1;
		else
			return 0;
			
	}
	
}
