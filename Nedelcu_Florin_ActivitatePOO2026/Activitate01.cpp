#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Playlist {
private:
	const int id;
	string nume;
	int nrMelodii;
	int* durate;
public:
	static int nrPlaylisturi;
	Playlist(string nume, int nrMelodii, int* durate) : id(++nrPlaylisturi) {
		this->nume = nume;
		this->nrMelodii = nrMelodii;
		this->durate = new int[nrMelodii];
		for (int i = 0; i < nrMelodii; i++) {
			this->durate[i] = durate[i];
		}
	}
	Playlist(const Playlist& copy) : id(++nrPlaylisturi) {
		this->nume = copy.nume;
		this->nrMelodii = copy.nrMelodii;
		if (copy.durate != nullptr) {
			this->durate = new int[copy.nrMelodii];
			for (int i = 0; i < copy.nrMelodii; i++) {
				this->durate[i] = copy.durate[i];
			}
		}
		else {
			this->durate = nullptr;
		}
	}
	void operator=(const Playlist& copie) {
		this->nume = copie.nume;
		this->nrMelodii = copie.nrMelodii;
		if (this->durate != nullptr) {
			delete[] this->durate;
			this->durate = nullptr;
		}
		if (copie.durate != nullptr) {
			this->durate = new int[copie.nrMelodii];
			for (int i = 0; i < copie.nrMelodii; i++) {
				this->durate[i] = copie.durate[i];
			}
		}
	}
	void dubleaza() {
		for (int i = 0; i < nrMelodii; i++) {
			this->durate[i] *= 2;
		}
	}
	void afisare() {
		cout << "ID: " << this->id << " | Name: " << this->nume << " | Durate: " << endl;
		for (int i = 0; i < nrMelodii; i++) {
			cout << this->durate[i] << " | ";
		}
		cout << endl;
	}

	~Playlist() {
		cout << endl << "~Playlist ID: " << this->id << " Deleted!";
		delete[] durate;
	}
};

int Playlist::nrPlaylisturi;

int main() {
	int* durate = new int[7] {3, 4, 3, 2, 2, 4, 7};
	int* durate2 = new int[2] {5, 6};
	Playlist p1("Gym", 7, durate);
	Playlist p3("Chill", 2, durate2);   
	p3.afisare();                        
	p3 = p1;                               
	p3.afisare();                        
	delete[] durate;
	delete[] durate2;
}


