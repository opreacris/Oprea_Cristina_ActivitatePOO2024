#include <iostream>
using namespace std;

class Stralucirea {
private:
    static string autor;
    const int id;
    string editura;
    int nrPg;
    string* culoareCoperta;
    int anPublicare;

public:
    // Constructor implicit
    Stralucirea() : id(0) {
        this->editura = "Corint";
        this->nrPg = 600;
        this->culoareCoperta = new string("albastru");
        this->anPublicare = 2000;
    }

    // Constructor cu parametrii
    Stralucirea(string edit, int Pg, string Culoare, int An) : id(1) {
        this->editura = edit;
        this->nrPg = Pg;
        this->culoareCoperta = new string(Culoare);
        this->anPublicare = An;
    }

    // Constructor de copiere
    Stralucirea(const Stralucirea& s) : id(2) {
        this->editura = s.editura;
        this->nrPg = s.nrPg;
        this->culoareCoperta = new string(*s.culoareCoperta);
        this->anPublicare = s.anPublicare;
    }

    // Destructor
    ~Stralucirea() {
        delete culoareCoperta;
    }

    // Getteri ?i setteri
    string getEditura() const { return editura; }
    void setEditura(const string& edit) { editura = edit; }

    int getNrPagini() const { return nrPg; }
    void setNrPagini(int pagini) { nrPg = pagini; }

    string getCuloareCoperta() const { return *culoareCoperta; }
    void setCuloareCoperta(const string& culoare) {
        *culoareCoperta = culoare;
    }

    int getAnPublicare() const { return anPublicare; }
    void setAnPublicare(int an) { anPublicare = an; }

    static string getAutor() { return autor; }
    static void setAutor(const string& aut) { autor = aut; }

    // Func?ia de afi?are
    void AfiseazaCarte() const {
        cout << "Cartea Stralucirea, are id: " << id << ", autorul este: " << autor
            << ", editura este " << editura << ", numarul de pagini este " << nrPg
            << ", culoarea copertii este " << *culoareCoperta
            << " si anul publicarii este " << anPublicare << endl;
    }

    friend void ProcesareStralucirea(Stralucirea& s);
};

string Stralucirea::autor = "Stephen King";

class It {
private:
    static string autor;
    const int id;
    string editura;
    int nrPg;
    string* culoareCoperta;
    int anPublicare;

public:
    // Constructor implicit
    It() : id(3) {
        this->editura = "Delfin";
        this->nrPg = 340;
        this->culoareCoperta = new string("Rosu");
        this->anPublicare = 2012;
    }

    // Constructor cu parametrii
    It(string edit, int pg, string culoare, int an) : id(4) {
        this->editura = edit;
        this->nrPg = pg;
        this->culoareCoperta = new string(culoare);
        this->anPublicare = an;
    }

    // Constructor de copiere
    It(const It& s) : id(5) {
        this->editura = s.editura;
        this->nrPg = s.nrPg;
        this->culoareCoperta = new string(*s.culoareCoperta);
        this->anPublicare = s.anPublicare;
    }

    // Destructor
    ~It() {
        delete culoareCoperta;
    }

    // Getteri ?i setteri
    string getEditura() const { return editura; }
    void setEditura(const string& edit) { editura = edit; }

    int getNrPagini() const { return nrPg; }
    void setNrPagini(int pagini) { nrPg = pagini; }

    string getCuloareCoperta() const { return *culoareCoperta; }
    void setCuloareCoperta(const string& culoare) {
        *culoareCoperta = culoare;
    }

    int getAnPublicare() const { return anPublicare; }
    void setAnPublicare(int an) { anPublicare = an; }

    static string getAutor() { return autor; }
    static void setAutor(const string& aut) { autor = aut; }

    // Func?ia de afi?are
    void AfisareCarte() const {
        cout << "Cartea It, cu id " << id << " scrisa de " << autor
            << " are nr de pagini " << nrPg << ", culoarea copertii este "
            << *culoareCoperta << " si a fost publicata in anul " << anPublicare << endl;
    }

    friend void ProcesareIt(It& i);
};

string It::autor = "Stephen King";

class Apocalipsa {
private:
    static string autor;
    const int id;
    string editura;
    int nrPg;
    string* culoareCoperta;
    int anPublicare;

public:
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

    // Destructor
    ~Apocalipsa() {
        delete culoareCoperta;
    }

    // Getteri ?i setteri
    string getEditura() const { return editura; }
    void setEditura(const string& e) { editura = e; }

    int getNrPagini() const { return nrPg; }
    void setNrPagini(int pg) { nrPg = pg; }

    string getCuloareCoperta() const { return *culoareCoperta; }
    void setCuloareCoperta(const string& culoare) {
        *culoareCoperta = culoare;
    }

    int getAnPublicare() const { return anPublicare; }
    void setAnPublicare(int an) { anPublicare = an; }

    static string getAutor() { return autor; }
    static void setAutor(const string& a) { autor = a; }

    void AfisareCarte() const {
        cout << "Cartea Apocalipsa, cu id " << id << ", scrisa de " << autor
            << ", are " << nrPg << " pagini, culoarea copertii este "
            << *culoareCoperta << " si a fost publicata in anul " << anPublicare << endl;
    }

    friend void ProcesareApocalipsa(Apocalipsa& a);
};

string Apocalipsa::autor = "Stephen King";

// Func?ii globale prietene
void ProcesareStralucirea(Stralucirea& s) {
    cout << "Procesare pentru cartea Stralucirea: " << endl;
    s.setNrPagini(s.getNrPagini() + 100);
    cout << "Num?rul de pagini a fost m?rit la: " << s.getNrPagini() << endl;
}

void ProcesareIt(It& i) {
    cout << "Procesare pentru cartea It: " << endl;
    i.setCuloareCoperta("Verde");
    cout << "Culoarea copertii a fost schimbat? în: " << i.getCuloareCoperta() << endl;
}

void ProcesareApocalipsa(Apocalipsa& a) {
    a.setEditura("Editura Speciala");
}

int main() {
    // Testare Stralucirea
    Stralucirea s1;
    s1.AfiseazaCarte();
    ProcesareStralucirea(s1);
    s1.AfiseazaCarte();

    // Testare It
    It i1;
    i1.AfisareCarte();
    ProcesareIt(i1);
    i1.AfisareCarte();

    // Testare getter-i
    cout << "Autor Stralucirea: " << Stralucirea::getAutor() << endl;
    cout << "Autor It: " << It::getAutor() << endl;

    return 0;
}
