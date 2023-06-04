//  Pedro Henrique Rodrigues Salzani / RA: 12325789.

//  Bruno Piffer Stephan / RA: 12325417.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale.h>

using namespace std;

//FUNCTION THAT RETURN A SHUFFLE ARRAY WITH 4 NUMBERS (1 TO 4) 
int* random() {
	setlocale(LC_ALL, "Portuguese");
	static int arr[4];
	int pos;

	pos = (1 + rand() % 4);
	arr[0] = pos;

	for (int i = 1; i < 4; i++)
	{
		pos = (1 + rand() % 4);
		if (pos == arr[i - 1]) {
			i--;
		}
		else if (pos == arr[i - 2]) {
			i--;
		}
		else if (pos == arr[i - 3]) {
			i--;
		}
		else {
			arr[i] = pos;
		}
	}

	return arr;
}

int main(){
	//THE BOARD WITH NUMBERS AND THE BOARD THAT IS SHOWED
	int board[2][4];
	string emptyBoard[2][4];

	//TIMER
	int timer = 0;

	//ARRAYS THAT WILL RECEIVE THE RANDOM()
	int* arr1;
	int* arr2;

	//RAND INICIALIZATION
	unsigned seed = time(0);
	srand(seed);
	
	//COL AND LINE FOR THE PLAYS
	int line1, line2;
	int col1, col2;
	
	//FILLING THE BOARD WITH THE NUMBERS
	arr1 = random();
	for(int i=0; i<4; i++){
		board[0][i] = arr1[i];
	}

	arr2 = random();
	for(int i=0; i<4; i++){
		board[1][i] = arr2[i];	
	}

	//FILLING THE BOARD THAT WILL BE SHOWED WITH X
	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			emptyBoard[i][j] = "X";
		}
	}

	//GAME
	
	while(true){
		//TIME TO SHOW THE BOARD
		timer++;
		if(timer < 50){
			cout << "MEMORIZE ENQUANTO HÁ TEMPO" << endl;
			for(int i=0; i<2; i++){
				for(int j=0; j<4; j++){
					cout << board[i][j] << " ";
				}
				cout << endl;		
			}
			system("cls");
		}else{
			
		//MAIN BOARD
		cout << "  1 2 3 4" << endl;
		for(int i=0; i<2; i++){
			cout << i + 1 << " ";
			for(int j=0; j<4; j++){
				cout << emptyBoard[i][j] << " ";
			}
			
			cout << endl;
		}
		
		//PLAYS
		cout << "Digite a coluna da primeira jogada: \n";
		cin >> col1;
		
		cout << "Digite a linha da primeira jogada: \n";
		cin >> line1;
		
		cout << "Digite a coluna da segunda jogada: \n";
		cin >> col2;
		
		cout << "Digite a linha da segunda jogada: \n";
		cin >> line2;
		
		//VERIFY IF THE PLAYS ARE THE SAME
		if(col1 == col2 && line1 == line2){
			cout << "\nJogadas iguais, jogue novamente \n" << endl; 
		}else{
			//VERIFY IF THE PLAY IS CORRECT AND FILL WITH O
			if(board[line1-1][col1-1] == board[line2-1][col2-1]){
				emptyBoard[line1-1][col1-1] = "O";
				emptyBoard[line2-1][col2-1] = "O";	
				system("cls");
			}else{
				cout << "\nJogada errada pae tamo junto \n" << endl; 
			}	
		}
	}
		//VERIFY WITH THE BOARD IN COMPLETELY FILLED
		if(emptyBoard[0][0] == "O" && emptyBoard[0][1] == "O" &&emptyBoard[0][2] == "O" &&emptyBoard[0][3] == "O" &&
		emptyBoard[1][0] == "O" &&emptyBoard[1][1] == "O" &&emptyBoard[1][2] == "O" &&emptyBoard[1][3] == "O"){
			cout << "VOCÊ GANHOU";
			break;
		}
	}
}

