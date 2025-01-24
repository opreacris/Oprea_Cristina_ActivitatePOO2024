#include <iostream>
#include <vector>
#include <string>
using namespace std;


//structura in care declar atributele
struct Bloc {

	string strada;
	int nrBloc;
	int nrScari;	
	int nrAp;
	int anConstruire;

};

//functia de afisare
void afisareBloc(Bloc* b) {

	cout << "Blocul de pe strada " << b->strada << " cu numarul " << b->nrBloc << " are " << b->nrScari <<
		" scari " << " ,un numar total de " << b->nrAp << " apartamente" << " , si a fost construit in anul " << b->anConstruire<<endl;
}
	
//functia de citire
Bloc* citesteBloc() {
	auto* bloc=new Bloc;
	cout << "Introduceti numele strazii: ";
	cin.ignore();
	getline (cin,bloc->strada);
	
	cout << "Introduceti numarul blocului: ";
	cin >> bloc->nrBloc;

	cout << "Introduceti numarul de scari: ";
	cin >> bloc->nrScari;

	cout << "Introduceti numarul de apartamente: ";
	cin >> bloc->nrAp;

	cout << "Introduceti anul in care a fost construit: ";
	cin >> bloc->anConstruire;

	return bloc;
}



int main() {

	




	//vector cu 10 blocuri

	vector<Bloc*> blocuri(10);

	for (int i = 0; i < 10; i++) {
		cout << "Citire date pentru blocul " << i + 1 << ":\n";
		blocuri[i] = citesteBloc(); // Atribuim direct elementului din vector


	}



	cout << "\nInforma?iile despre blocurile introduse:\n";
	for (int i = 0; i < 10; i++) {
		afisareBloc(blocuri[i]);
	}




	return 0;
}