#include <iostream>
#include <string>

static int ROW = 10;
static int COLUMN = 10;

class Grid {
private:
	// Represents the view on the console
	char playerViewGrid[10][10];
	char aiViewGrid[10][10];
	
	// Represents where the ships are placed. 0 for empty. 1 for ship segment
	int playerMapGrid[10][10];
	int aiMapGrid[10][10];
	
	// Marker. If a ship segment is 1, then mark to true and indicate a hit.
	bool playerMarkGrid[10][10];
	bool aiMarkGrid[10][10];

	int aiHitCounter;
	bool detWinner;
public:
	Grid() {
		//initialzing the player and ai view board to '-'
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				playerViewGrid[i][j] = '-';
				aiViewGrid[i][j] = '-';
			}
		}
		//Initializing the player and ai map grid to 0
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				playerMapGrid[i][j] = 0;
				aiMapGrid[i][j] = 0;
			}
		}
		//Marking the player and AI grids to false
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				playerMarkGrid[i][j] = false;
				aiMarkGrid[i][j] = false;
			}
		}

		//initializing aiHitCounter
		aiHitCounter = 0;
		bool detWinner = false;
	}

	void printPlayerGrid() {
		std::cout << "Player Board\n";
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				std::cout << playerViewGrid[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	void printAIGrid() {
		std::cout << "Computer Board\n";
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				std::cout << aiViewGrid[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	void addShips() {
		//Adding ships to player view
		//Ship 1
		playerViewGrid[0][0] = 'o';
		playerViewGrid[0][1] = 'o';
		playerViewGrid[0][2] = 'o';
		playerViewGrid[0][3] = 'o';
		playerViewGrid[0][4] = 'o';

		//Ship 2
		playerViewGrid[9][0] = 'o';
		playerViewGrid[9][1] = 'o';
		playerViewGrid[9][2] = 'o';
		playerViewGrid[9][3] = 'o';

		//Ship 3
		playerViewGrid[5][3] = 'o';
		playerViewGrid[5][4] = 'o';
		playerViewGrid[5][5] = 'o';

		//Ship 4
		playerViewGrid[0][9] = 'o';
		playerViewGrid[1][9] = 'o';
		playerViewGrid[2][9] = 'o';


		//Marking ships as 1 to player map grid
		//Ship 1
		playerMapGrid[0][0] = 1;
		playerMapGrid[0][1] = 1;
		playerMapGrid[0][2] = 1;
		playerMapGrid[0][3] = 1;
		playerMapGrid[0][4] = 1;

		//Ship 2
		playerMapGrid[9][0] = 1;
		playerMapGrid[9][1] = 1;
		playerMapGrid[9][2] = 1;
		playerMapGrid[9][3] = 1;

		//Ship 3
		playerMapGrid[5][3] = 1;
		playerMapGrid[5][4] = 1;
		playerMapGrid[5][5] = 1;

		//Ship 4
		playerMapGrid[0][9] = 1;
		playerMapGrid[1][9] = 1;
		playerMapGrid[2][9] = 1;

		//Marking ships as 1 to AI grid
		//Ship 1
		aiMapGrid[0][0] = 1;
		aiMapGrid[0][1] = 1;
		aiMapGrid[0][2] = 1;
		aiMapGrid[0][3] = 1;
		aiMapGrid[0][4] = 1;

		//Ship 2
		aiMapGrid[9][0] = 1;
		aiMapGrid[9][1] = 1;
		aiMapGrid[9][2] = 1;
		aiMapGrid[9][3] = 1;

		//Ship 3
		aiMapGrid[5][3] = 1;
		aiMapGrid[5][4] = 1;
		aiMapGrid[5][5] = 1;

		//Ship 4
		aiMapGrid[0][9] = 1;
		aiMapGrid[1][9] = 1;
		aiMapGrid[2][9] = 1;
	}

	void playerMove(int x, int y) {
		if (aiMapGrid[x][y] == 1) {
			updateAIViewBoard(x, y, 'H');
			aiMarkGrid[x][y] = true;
			aiHitCounter++;
			if(aiHitCounter == 15){
				detWinner = true;
			}
		}
		else {
			updateAIViewBoard(x, y, 'M');
		}

	}

	void promptPlayer() {
		int xCoord;
		int yCoord;
		std::cout << "Enter ROW coordinate to fire: ";
		std::cin >> xCoord;
		std::cout << "Enter COLUMN coordinate to fire: ";
		std::cin >> yCoord;

		playerMove(xCoord, yCoord);
	}

	void updateAIViewBoard(int xCor, int yCor, char c) {
		aiViewGrid[xCor][yCor] = c;
	}
	
	bool getWinner(){
		return detWinner;
	}
	
};
