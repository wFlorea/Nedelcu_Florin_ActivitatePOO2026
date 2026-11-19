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
		this->durate = new int[copy.nrMelodii];
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
	Playlist p1("Gym", 7, durate);
	Playlist p2 = p1;
	Playlist p3 = p2;
	p2.dubleaza();
	p1.afisare();
	p2.afisare();
	p3.afisare();
	cout << "Total playlisturi: " << Playlist::nrPlaylisturi;
	delete[] durate;
}


