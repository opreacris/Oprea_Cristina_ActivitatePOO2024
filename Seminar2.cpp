#include <iostream>

using namespace std;

struct Tara {
	char* denumire;
	int nrLocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisarePointerLaTara() {

}

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrLocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areIesireLaMare ? "DA" : "NU") << endl;

	/*
	if (pt->areIesireLaMare) {
		cout << "DA" << endl;
	}
	else {
		cout < "NU" << endl;
	}
	*/
}

Tara* citirePointerLaTara() {
	Tara* p = new Tara();

	cout << "Denumire:";
	char buffer[100];
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);
	
	cout << "Capitala:";
	cin >> p->denumire;

	cout << "Numar locuitori:";
	cin >> p->nrLocuitori;

	cout << "Are iesire la mare> (0-NU, 1-DA)";
	cin >> p->areIesireLaMare;

	//char aux;
	//if(aux=='Y' || 'y')

	return p;
}


int main(){
	Tara tara;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nrLocuitori = 200;

	afisarePointerLaTara(pTara);

	/*Tara* p2Tara = citirePointerLaTara();
	afisarePointerLaTara(p2Tara);
	*/

	Tara* vector;
	vector = new Tara[2];
	
	int nrPointeri = 2;
	//vector de pointeri
	Tara** pointeri;
	pointeri = new Tara * [2];
	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointerLaTara();
	}
	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		afisarePointerLaTara(pointeri[i]);
	}


}

//Shallow copy pTara->denumire = "Romania";