#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Cinema {
private:
	const int id;
	string nume;
	int nrFilme;
	int* durate;
public:
	static int nrCinematografe;
	static int totalFilme;
	Cinema() : id(++nrCinematografe) {
		this->nume = "Cinema nou";
		this->nrFilme = 0;
		this->durate = nullptr;
		totalFilme += nrFilme;
	}
	Cinema(string nume, int nrFilme, int* durate) : id(++nrCinematografe) {
		this->nume = nume;
		this->nrFilme = nrFilme;
		this->durate = new int[nrFilme];
		for (int i = 0; i < nrFilme; i++) {
			this->durate[i] = durate[i];
		}
		totalFilme += nrFilme;
	}
	Cinema(const Cinema& copie) : id(++nrCinematografe) {
		this->nume = copie.nume;
		this->nrFilme = copie.nrFilme;
		if (copie.durate != nullptr) {
			this->durate = new int[copie.nrFilme];
			for (int i = 0; i < copie.nrFilme; i++) {
				this->durate[i] = copie.durate[i];
			}
		}
		else {
			this->durate = nullptr;
		}
		totalFilme += copie.nrFilme;
	}
	void afisare() {
		cout << endl << "ID: " << this->id << " | Cinema: " << this->nume << " | Durate: " << endl;
		for (int i = 0; i < nrFilme; i++) {
			cout << durate[i] << " | ";
		}
	}
	float durataMedie() {
		float suma = 0;
		if (nrFilme > 0) {
			for (int i = 0; i < nrFilme; i++) {
				suma += durate[i];
			}
			return suma / nrFilme;
		}
		else {
			return 0;
		}
		
	}
	int celMaiLungFilm() {
		int maxim = 0;
		if (nrFilme > 0) {
			for (int i = 0; i < nrFilme; i++) {
				if (durate[i] > maxim) {
					maxim = durate[i];
				}
			}
			return maxim;
		}
		return 0;
	}
	void adaugaFilm(int durata) {
		int* durateNoi = new int[nrFilme + 1];
		for (int i = 0; i < nrFilme; i++) {
			durateNoi[i] = durate[i];
		}
		durateNoi[nrFilme] = durata;
		delete[] durate;
		durate = durateNoi;
		nrFilme++;
		totalFilme++;
	}
	~Cinema() {
		delete[] durate;
	}
	
};

int Cinema::totalFilme = 0;
int Cinema::nrCinematografe = 0;

int main() {
	int* durateCity = new int[3] {120, 95, 104};
	Cinema c1;
	Cinema c2("Cinema City", 3, durateCity);
	c1.afisare();
	cout << "Durata medie: " << c1.durataMedie();
	cout << " | Cel mai lung film: " << c1.celMaiLungFilm();
	c1.adaugaFilm(90);
	c1.afisare();
	cout << " | Durata Medie: " << c1.durataMedie();
	cout << " | Cel mai lung film: " << c1.celMaiLungFilm();
	c2.afisare();
	cout << "Durata medie: " << c2.durataMedie();
	cout << " | Cel mai lung film: " << c2.celMaiLungFilm();
	c2.adaugaFilm(120);
	c2.afisare();
	cout << " | Durata Medie: " << c2.durataMedie();
	cout << " | Cel mai lung film: " << c2.celMaiLungFilm();
	Cinema c3 = c2;
	c3.afisare();
	cout << endl << "Total movies: " << Cinema::totalFilme;
	c3.adaugaFilm(180);
	c3.afisare();
	cout << endl << "Total movies: " << Cinema::totalFilme;

	delete[] durateCity;
}


