#include "Grid.cpp"

int main() {
	
	Grid g;

	g.printPlayerGrid();
	std::cout << std::endl;
	g.printAIGrid();

	std::cout << "Adding ships...\n";
	g.addShips();
	g.printPlayerGrid();
	std::cout << std::endl;
	g.printAIGrid();

	while (g.getWinner() == false){
		g.promptPlayer();
		g.printAIGrid();
	}

	return 0;
}
