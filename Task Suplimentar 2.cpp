#include <iostream>

using namespace std;

class Stralucirea {
public:
	static string autor;
	const int id;
	string editura;
	int nrPg;
	string* culoareCoperta;
	int anPublicare;

	//Constructor implicit
	Stralucirea() :id(0)
	{
		this->editura = "Corint";
		this->nrPg = 600;
		this->culoareCoperta = new string("albastru");
		this->anPublicare = 2000;
	}
		//Constructori cu parametrii
		Stralucirea(string edit, int Pg, string Culoare, int An) :id(1){
		this->editura = edit;
		this->nrPg = Pg;
		this->culoareCoperta = new string(Culoare);
		this->anPublicare = An; }

		//Constructor de copiere 
		Stralucirea(const Stralucirea& s) :id(2){
			this->editura = s.editura;
			this->nrPg = s.nrPg;
			this->culoareCoperta = new string(*s.culoareCoperta);
			this->anPublicare = s.anPublicare;
		}

		//Functie statica
		static void AfiseazaAutor() {

			cout << "Autorul cartii este: " << autor << endl;

		}

		//Functia de afisare
		void AfiseazaCarte() {
			cout << "Cartea Stralucirea, are id: " << id << ", autorul este: " << autor << ", editura este " << editura << ", numarul de pagini este " << nrPg <<
				", culoarea copertii este " << *culoareCoperta << "si anul publicarii este " << anPublicare << endl;
		}

		//Destructor
		~Stralucirea() {
			delete culoareCoperta;
		}

};
	string Stralucirea::autor = "Stephen King";

	class It {
	public:
		static string autor;
		const int id;
		string editura;
		int nrPg;
		string* culoareCoperta;
		int anPublicare;

		//constructor implicit
		It() :id(3) {
			this->editura = "Delfin";
			this->nrPg = 340;
			this->culoareCoperta = new string("Rosu");
			this->anPublicare = 2012;
		}

		//constructor cu parametrii
		It(string edit, int pg, string culoare, int an) : id(4) {
			this->editura = edit;
			this->nrPg = pg;
			this->culoareCoperta = new string (culoare);
			this->anPublicare = an;

		}

		//constructor de copiere
		It(It& s) :id(5) {
			this->editura = s.editura;
			this->nrPg = s.nrPg;
			this->culoareCoperta = s.culoareCoperta;
			this->anPublicare = s.anPublicare;
		}

		//functie statica
		static void AfisareAutor() {
			cout << autor << endl;
		}

		//functie de afisare
		void AfisareCarte() {
			cout << "Cartea It, cu id " << id << " scrisa de " << autor << " are nr de pagini " << nrPg << " culoarea copertii este " <<
				*culoareCoperta << " si a fost publicata in anul " << anPublicare;


		}

		//destructor
		~It() {
			delete culoareCoperta;
		}

	};
//initiem static
	string It::autor = "Stephen King";


	class Apocalipsa {
	private:
		
		const int id;
		string editura;
		int nrPg;
		string* culoareCoperta;
		int anPublicare;


	public:
		static string autor;
		// Constructor implicit
		Apocalipsa() : id(6) {
			this->editura = "Gogo";
			this->nrPg = 450;
			this->culoareCoperta = new string("Mov");
			this->anPublicare = 2015;
		}

		// Constructor cu parametrii
		Apocalipsa(string e, int pg, string culoare, int an) : id(7) {
			this->editura = e;
			this->nrPg = pg;
			this->culoareCoperta = new string(culoare);
			this->anPublicare = an;
		}

		// Constructor de copiere
		Apocalipsa(const Apocalipsa& a) : id(8) {
			this->editura = a.editura;
			this->nrPg = a.nrPg;
			this->culoareCoperta = new string(*a.culoareCoperta);
			this->anPublicare = a.anPublicare;
		}

		// Funcție statică
		static void AfisareAutor() {
			cout << "Autor: " << autor << endl;
		}

		// Funcție de afișare
		void AfisareCarte() const {
			cout << "Cartea Apocalipsa, cu id " << id << ", scrisa de " << autor
				<< ", are " << nrPg << " pagini, culoarea copertii este "
				<< *culoareCoperta << " si a fost publicata in anul " << anPublicare << endl;
		}

		// Destructor
		~Apocalipsa() {
			delete culoareCoperta;
		}
	};

	// Inițializare membru static
	string Apocalipsa::autor = "Stephen King";



	int main() {
		//obiecte Stralucirea
		Stralucirea s1;
		Stralucirea s2("Elefant", 450, "negru", 2008);
		Stralucirea s3(s2);

		s1.AfiseazaCarte(); 
		cout << endl;
		s2.AfiseazaCarte(); cout << endl;
		s3.AfiseazaCarte(); cout << endl;

		Stralucirea::AfiseazaAutor();


		//obiecte It
		It i1;
		It i2("Frontier", 290, "roz", 2045);
		It i3(i2);

		i1.AfisareCarte(); cout << endl;
		i2.AfisareCarte(); cout << endl;
		i3.AfisareCarte(); cout << endl;

		It::AfisareAutor();

		//obiecte Apocalipsa
		Apocalipsa a1;
		Apocalipsa a2("Gigi", 234, "galben", 2014);
		Apocalipsa a3(a2);

		a1.AfisareCarte();
		a2.AfisareCarte();
		a3.AfisareCarte();

		It::AfisareAutor();

		

		return 0;
	}




