#include<iostream>

using namespace std;

struct CoordonateGPS {

	int latitudine;
	int longitudine;
	float altitudine;
	string locatie;

};


// tip returt , nume  , ( [ parametrii ] ) {
// Corpul functiei
//    }


void afisarecoordonateGPS(CoordonateGPS l) {

	cout << "Latitudine:" << l.latitudine << endl;
	cout << "Longitudine:" << l.longitudine << endl;
	cout << "Altitudine:" << l.altitudine << endl;
	cout << "Locatie:" << l.locatie << endl;

}

void modificaAltitudine(CoordonateGPS *l, float nouaAltitudine) {

	l->altitudine = nouaAltitudine;  // ->= ( deferentiere + accesare)
}

void modificaAltitudineRef(CoordonateGPS& l, float nouaAltitudine) {

	l.altitudine = nouaAltitudine;

}

CoordonateGPS initializareCoordonate(int latitudine, int longitudine, float altitudine, string locatie) {
	CoordonateGPS l;
	l.latitudine = latitudine;
	l.longitudine = longitudine;
	l.altitudine = altitudine;
	l.locatie = locatie;
	return l;
}

int main() {

	CoordonateGPS l;    //locatie
	l.latitudine = 46;
	l.longitudine = 22;
	l.altitudine = 1010;
	l.locatie = "Predeal";

	afisarecoordonateGPS(l);

	CoordonateGPS l2;
	cout << "Introduceti latitudinea:\n";
	cin >> l2.latitudine;

	cout << "Introduceti longitudine:\n";
	cin >> l2.longitudine;

	cout << "Introduceti altitudine:\n";
	cin >> l2.altitudine;

	cout << "Introduceti locatie:\n";
	cin >> l2.locatie;

	afisarecoordonateGPS(l2);

	modificaAltitudine(&l2, -20);
	
	modificaAltitudineRef(l2, 3000);

	afisarecoordonateGPS(l2);


	return 0;

}



// diferenta "a" ( /0 ) sir de caractere/ ocupa 2 octeti  ,   'a' ascii/retinut cu un nr / un sg octet