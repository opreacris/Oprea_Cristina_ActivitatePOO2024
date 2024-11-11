#include<iostream>

using namespace std;

class Masina {
private:
	int nrRoti;
	string marca;
	float pret;
	static int TVA; /// static = nu apartine obiectului, poate fi apelat in mod general. adica tva-ul este acelasi pt toate obiectele.
	const int anFabricatie;
	string* producatori;
public:
	Masina() :anFabricatie(2024), nrRoti(4) { /// este mai eficient daca initializam valori de aici (pentru const trebuie initializate aici, sus)
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}

	Masina(int nrRoti, string marca, float pret, int an) :anFabricatie(an) { /// folosim  '' (_nrRoti) pentru a face distinctia intre atribut si parametru
		this->nrRoti = nrRoti;
		this->marca = marca;
		this->pret = pret;
		/// nu putem face anFabricatie cu "this" pt ca e const
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++) {
			this->producatori[i] = "Michelin";
		}
	}

	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrRoti];
		for (int i = 0; i < nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}

	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}

	string getMarca() {
		return this->marca;
	}

	void setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	string* getProducatori() { /// fac eu deplasarea ca sa aflu pozitia producatorului
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			return "Nu a fost gasit";
		}
	}

	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL)
				delete[]this->producatori;
		}
		this->producatori = new string[nrRoti];
		for (int i = 0; i < nrRoti; i++) {
			this->producatori[i] = producatori[i];
		}
	}



	void afisare() {
		cout << "Marca: " << this->marca << endl;
		cout << "Nr roti: " << this->nrRoti << ": ";
		if (this->producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "An Fabricatie: " << this->anFabricatie << endl << endl;
	}


};

int Masina::TVA = 19; /// asa se face initializarea atributului static


int main() {

	Masina m;
	cout << m.getMarca() << endl;

	m.setMarca("Audi");
	cout << m.getMarca() << endl << endl;

	m.afisare();

	Masina m2(4, "BMW", 45000, 2021);
	m2.afisare();

	cout << m2.getProducatori()[1] << endl; /// folosim [] pentru a dereferentia si deplasa

	cout << m2.getProducator(3);

	/// m2.setNrRoti(6,new string[6]{"Michelin","Continental","Bridgestone","Pirelli","Hancook","POO"}); 
	/// cout << m2.getProducator(4);

	Masina m3(m2);
	Masina m4 = m2;
	cout << m4.getProducator(2);


	return 0;
}