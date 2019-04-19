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

	for (int i = 0; i < 10; i++) {
		g.promptPlayer();
		g.printAIGrid();
	}



	system("PAUSE");
	return 0;
}