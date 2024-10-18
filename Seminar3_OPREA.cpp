#include <iostream>

using namespace std;


// constant,  CONSTRUCTOR , static, clasa

class Masina {   // delcaram clasa
public:
	int nrRoti;
	string marca;
	float pret;
	static int TVA;               //atribut static apartine clasei
  	const int anFabricatie;        //atribut static apartine obiectului

	Masina():anFabricatie(2024), nrRoti(4){
		this->marca = "Dacia";
		this->pret = 5000;
	}
	
	Masina(int _nrRoti, string marca, float pret, int an):anFabricatie(an) {    // pt ca anfabricate e const nu poate sa fie in stanga egalului

		this->nrRoti = _nrRoti;
		this->marca = marca;      //primul atribut, al doilea parametru
		this->pret = pret;
		

	}


	void afisare() {
		cout << endl;  
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << endl;
		cout << "Pret:" << this->pret <<endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An Fabricatie:" << this->anFabricatie<< endl;
	
	}

	float CalculeazaPretTotal() {   // acesta este un constructor
		return this->pret + (this->pret * (Masina::TVA / 100.0f));   // am facut 100 float in loc sa punem (float) in paranteza cu masina

		
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}

	}
	

	static float caculeazaPretTotalVector(int nrMasini,Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].CalculeazaPretTotal();
		}
		return pretTotal;

	}


};

int Masina::TVA = 19;

int main() {

	Masina m1;

	m1.afisare();

	Masina m2(4, "Audi", 7000, 2020);
	m2.afisare();

	Masina::modificaTVA(21);   // pentru static se apeleaza cu Masina::

	Masina* pointer = new Masina(6, "Volvo", 20000, 2022);
	pointer->afisare();
	
	cout << "Pret total:" << pointer->CalculeazaPretTotal()<<endl;

	//declar vector
	int nrMasini = 3;
	Masina* vector;
	vector = new Masina[nrMasini];   // construct fara parametrii = constructor implicit

	for (int i = 0; i < nrMasini; i++) {
		//(*(vector+i).afisare();
		vector[i].afisare();

	}

	//-> - dereferentiere +accesare
	//[] - index face deplasare + dereferentiere
	// . - accesare

	// o functie care sa apeleze pretul total tuturor masinilor din vecto   ( APLICATIE )
	cout << "Pret total flota:" << Masina::caculeazaPretTotalVector(nrMasini, vector) << endl;
	
	return 1000;
}