#include <cstring>
#include <iostream>
using namespace std;



int main() {

	char* nume = new char[strlen("Florea")];
	strcpy(nume, "Florea");
	cout << endl << "Numele este: " << nume;
	delete[] nume;

	return 0;
}