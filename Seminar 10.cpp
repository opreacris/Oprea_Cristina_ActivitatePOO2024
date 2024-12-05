#include<iostream>
#include<fstream>
using namespace std;

class Masina {
private:
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2024), nrRoti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}
	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;
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
		for (int i = 0; i < m.nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}
	Masina operator=(const Masina& m) {
		if (this != &m) {
			this->nrRoti = m.nrRoti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[m.nrRoti];
			for (int i = 0; i < m.nrRoti; i++) {
				this->producatori[i] = m.producatori[i];
			}
		}
		return *this;
	}


	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}

	Masina operator+(const Masina& m) const {
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	Masina operator+=(Masina m) {
		this->pret = this->pret + m.pret;
		return *this;
	}

	Masina operator+=(float adaosPret) {
		this->pret += adaosPret;
		return *this;
	}

	Masina operator+(float adaosPret)const {
		Masina temp = *this;
		temp.pret += adaosPret;
		return temp;
	}

	friend Masina operator+(float adaosPret, Masina m) {
		Masina temp = m;
		temp.pret += adaosPret;
		return temp;
	}
	explicit operator float()
	{
		return calculeazaPretTotal();
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			throw "Indexul este in afara limitelor.";
		}
	}
	explicit operator int()
	{
		return this->nrRoti;
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
	string* getProducatori() {
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			return "NU a fost gasit.";
		}
	}

	int getNrRoti() {
		return this->nrRoti;
	}
	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << ": ";
		if (this->producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + (this->pret * (Masina::TVA / 100.0f));
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}

	bool operator<(Masina m) {
		return this->pret < m.pret;
	}

	void scriereFisierBinar(fstream& fisier) { /// SEMINAR 10
		fisier.write((char*)&nrRoti, sizeof(nrRoti));
		for (int i = 0; i < nrRoti; i++) {
			int lungime = producatori[i].length();
			fisier.write((char*)&lungime, sizeof(lungime));
			fisier.write((char*)(producatori[i].c_str()), lungime * sizeof(char));
		}
		int lungime = marca.length();
		fisier.write((char*)(marca.c_str()), lungime * sizeof(char));
		fisier.write((char*)&pret, sizeof(pret));

	}

	void citesteFisierBinar(fstream& fisier) { /// SEMINAR 10
		fisier.read((char*)&nrRoti, sizeof(nrRoti));
		for (int i = 0; i < nrRoti; i++) {
			int lungime = 0;
			fisier.read((char*)&lungime, sizeof(lungime));
			fisier.read((char*)(producatori[i].c_str()), lungime * sizeof(char));
		}
		int lungime = 0;
		fisier.read((char*)(marca.c_str()), lungime * sizeof(char));
		fisier.read((char*)&pret, sizeof(pret));
	}

	friend istream& operator>>(istream& input, Masina& m) {
		cout << "Introduceti marca:";
		input >> m.marca;
		cout << "Nr roti:";
		input >> m.nrRoti;
		if (m.producatori != NULL) {
			delete[]m.producatori;
		}
		if (m.nrRoti > 0) {
			m.producatori = new string[m.nrRoti];
			cout << "Producatori:";
			for (int i = 0; i < m.nrRoti; i++) {
				input >> m.producatori[i];
			}
		}
		else {
			m.producatori = NULL;
		}
		cout << "Pret:";
		input >> m.pret;
		return input;
	}

	friend ostream& operator<<(ostream& output, Masina m);

	friend ofstream& operator<<(ofstream& output, Masina m) { /// SEminar 10
		output << m.marca << endl;
		output << m.nrRoti << ": ";
		if (m.producatori != NULL) {
			for (int i = 0; i < m.nrRoti; i++) {
				output << m.producatori[i] << ", ";
			}
		}
		output << endl;
		output << m.pret << endl;
		output << m.anFabricatie << endl;
		return output;
	}
};

int Masina::TVA = 19;

ostream& operator<<(ostream& output, Masina m) {
	output << "Marca:" << m.marca << endl;
	output << "Nr roti:" << m.nrRoti << ": ";
	if (m.producatori != NULL) {
		for (int i = 0; i < m.nrRoti; i++) {
			output << m.producatori[i] << ", ";
		}
	}
	output << endl;
	output << "Pret:" << m.pret << endl;
	output << "TVA:" << m.TVA << endl;
	output << "An fabricatie:" << m.anFabricatie << endl;
	return output;
}






int main() {
	/// SEM. 10


	/*ifstream fisier2("fisier.txt", ios::in);
	Masina m;
	Masina m2;
	fisier2 >> m;
	fisier2 >> m2;
	cout << m << endl;
	cout << m2 << endl;
	fisier2.close();*/

	/*int nr_Roti = 4;
	string* prod = new string[nr_Roti];
	prod[0] = "michelin";
	prod[1] = "pirelli";
	prod[2] = "hankook";
	prod[3] = "bridgestone";
	Masina masina(nr_Roti, "dacia", 5000.0f, 2020);
	masina.setNrRoti(nr_Roti, prod);

	fstream fisierBinar("fisierBinar.txt", ios::binary | ios::out);

	masina.scriereFisierBinar(fisierBinar);
	fisierBinar.close();*/

	fstream fisierBinar1("fisierBinar1.txt", ios::binary | ios::in);
	Masina masina1(4, "abc", 2000, 2024);
	masina1.citesteFisierBinar(fisierBinar1);
	cout << masina1;
	fisierBinar1.close();




}