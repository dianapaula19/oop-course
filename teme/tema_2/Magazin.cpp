#include <climits>
#include <iostream>
#include <cstring>
#include <vector>
#include "Magazin.h"
// Functii pentru clasa Produs

Produs::Produs() {

    aCantitate = 0;
    aCod = 0;
    aPretPerUnit = 0;
    aCost = aCantitate * aPretPerUnit;
    aUnit = "";

}
Produs::Produs(int cCantitate, int cCod, double cPretPerUnit, std::string cUnit) {

    aCantitate = cCantitate;
    aCod = cCod;
    aPretPerUnit = cPretPerUnit;
    aCost = aPretPerUnit * aCost;
    aUnit = cUnit;

}
Produs::Produs(const Produs& p){

    aCantitate = p.aCantitate;
    aPretPerUnit = p.aPretPerUnit;
    aCost = p.aCost;
    aUnit = p.aUnit;

}
Produs::~Produs() {
    std::cout << "Obiectul a fost sters" << std::endl;
}
Produs& Produs::operator = (const Produs& p) {

    if(this == &p) {
        return *this;
    }
    aPretPerUnit = p.aPretPerUnit;
    aCost = p.aCost;
    aUnit = p.aUnit;
    return *this;

}
Faina& Faina::operator = (const Faina& f) {

    if(this == &f) {
        return *this;
    }
    aCalitate = f.aCalitate;
    return *this;

}
Bere& Bere::operator = (const Bere& b) {

    if(this == &b) {
        return *this;
    }
    aBrand = b.aBrand;
    aTip = b.aTip;
    return *this;

}
VinVarsat& VinVarsat::operator = (const VinVarsat& v) {

    if(this == &v) {
        return *this;
    }
    aTip = v.aTip;
    return *this;

}
VinDeSoi& VinDeSoi::operator = (const VinDeSoi& v) {

    if(this == &v) {
        return *this;
    }
    aSoi = v.aSoi;
    aAn = v.aAn;
    aTara = v.aTara;
    return *this;

}
Cartofi& Cartofi::operator = (const Cartofi& c) {

    if(this == &c) {
        return *this;
    }
    aTip = c.aTip;
    return *this;

}
Jucarie& Jucarie::operator = (const Jucarie& j) {

    if(this == &j) {
        return *this;
    }
    aDenumire = j.aDenumire;
    return *this;

}
bool Varza::operator == (const Varza& v) {

    if(this->aPretPerUnit == v.aPretPerUnit) {
        return true;
    }
    return false;

}
bool Faina::operator == (const Faina& f) {

    if(this->aCalitate != f.aCalitate || this->aPretPerUnit != f.aPretPerUnit) {
        return false;
    }
    return true;

}
bool Bere::operator == (const Bere& b) {

    if(this->aBrand != b.aBrand || this->aTip != b.aTip || this->aPretPerUnit != b.aPretPerUnit) {
        return false;
    }
    return true;

}
bool VinVarsat::operator == (const VinVarsat& v) {

    if(this->aTip != v.aTip || this->aPretPerUnit != v.aPretPerUnit) {
        return false;
    }
    return true;
}
bool VinDeSoi::operator == (const VinDeSoi& v) {

    if(this->aSoi != v.aSoi || this->aAn != v.aAn || this->aTara != v.aTara || this->aPretPerUnit != v.aPretPerUnit) {
        return false;
    }
    return true;

}
bool Cartofi::operator == (const Cartofi& c) {

    if(this->aTip != c.aTip || this->aPretPerUnit != c.aPretPerUnit) {
        return false;
    }
    return true;

}
bool Jucarie::operator == (const Jucarie& j) {

    if(this->aDenumire == j.aDenumire) {
        return true;
    } else {
        return false;
    }

}
std::istream& operator >> (std::istream& in, Produs& p){

    p.Read();
    return in;

}
std::ostream& operator << (std::ostream& out, const Produs& p){

    p.Print();
    return out;

}
Magazin::Magazin() {
    aStoc = 0;
    aProduseVandute = 0;
    aTotal = 0;
}
Magazin::~Magazin() {
    stoc.clear();
}
void Magazin::AfisareOptiuni() {

    std::cout << "1-varza\n";
    std::cout << "2-faina\n";
    std::cout << "3-bere\n";
    std::cout << "4-vin de varsat\n";
    std::cout << "5-vin de soi\n";
    std::cout << "6-cartofi\n";
    std::cout << "7-jucarie\n";
    std::cout << "codul produsului: ";

}
int Magazin::GoodVinDeSoi(VinDeSoi& v_client, VinDeSoi& v_stoc) {

    if(v_client.getSoi() == "rosu sec" && v_stoc.getSoi() == "Cabernet Savignon") {
        return 1;
    }
    if(v_client.getSoi() == "rosu dulce" && v_stoc.getSoi() == "Merlot") {
        return 1;
    }
    if(v_client.getSoi() == "alb sec" && v_stoc.getSoi() == "Savignon Blanc") {
        return 1;
    }
    if(v_client.getSoi() == "alb dulce" && v_stoc.getSoi() == "Chardonnay") {
        return 1;
    }
    return 0;

}
void Magazin::ActualizareStoc() {
    // daca produsul adaugat se afla deja in stoc, trebuie sa fie adaugat un alt produs de acelasi tip
    int n;
    std::cout << "Cate produse adaugati in stoc? ";
    std::cin >> n;
    for(int i = aStoc; i < aStoc + n; ++i) {
        Magazin::AfisareOptiuni();
        int cod;
        std::cin >> cod;
        switch(cod) {
        case 1:{
            int ok = 0;
            Varza* v1 = new Varza();
            std::cin >> *(v1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 1) {
                Varza* v2 = dynamic_cast <Varza*> (stoc[j]);
                    if((*v1) == (*v2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati un produs identic\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*v1);
            }
            stoc.push_back(v1);
            break;
        }
        case 2:{
            int ok = 0;
            Faina* f1 = new Faina();
            std::cin >> *(f1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 2) {
                    Faina* f2 = dynamic_cast <Faina*> (stoc[j]);
                    if((*f1) == (*f2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati un produs identic\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*f1);
            }
            stoc.push_back(f1);
            break;
        }
        case 3:{
            int ok = 0;
            Bere* b1 = new Bere();
            std::cin >> *(b1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 3) {
                    Bere* b2 = dynamic_cast <Bere*> (stoc[j]);
                    if((*b1) == (*b2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati un produs identic\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*b1);
            }
            stoc.push_back(b1);
            break;
        }
        case 4:{
            int ok = 0;
            VinVarsat* v1 = new VinVarsat();
            std::cin >> *(v1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 4) {
                    VinVarsat* v2 = dynamic_cast <VinVarsat*> (stoc[j]);
                    if((*v1) == (*v2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati un produs identic\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*v1);
            }
            stoc.push_back(v1);
            break;
        }
        case 5:{
            int ok = 0;
            VinDeSoi* v1 = new VinDeSoi();
            std::cin >> *(v1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 5) {
                    VinDeSoi* v2 = dynamic_cast <VinDeSoi*> (stoc[j]);
                    if((*v1) == (*v2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati un produs identic\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*v1);
            }
            stoc.push_back(v1);
            break;
        }
        case 6:{
            int ok = 0;
            Cartofi* c1 = new Cartofi();
            std::cin >> *(c1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 6){
                Cartofi* c2 = dynamic_cast <Cartofi*> (stoc[j]);
                    if((*c1) == (*c2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati un produs identic\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*c1);
            }
            stoc.push_back(c1);
            break;
        }
        case 7:{
            int ok = 0;
            Jucarie* j1 = new Jucarie();
            std::cin >> *(j1);
            for(int j = aStoc; j < i; ++j) {
                if(stoc[j]->getCod() == 7) {
                    Jucarie* j2 = dynamic_cast <Jucarie*> (stoc[j]);
                    if((*j1) == (*j2)) {
                        ok = 1;
                        std::cout << "Nu puteti sa adaugati o jucarie cu aceeasi denumire\n";
                        break;
                    }
                }
            }
            if(ok == 1) {
                std::cout << "Adaugati alt produs: \n";
                std::cin >> (*j1);
            }
            stoc.push_back(j1);
            break;
        }
        }
        std::cout << "\n";
    }
    aStoc += n;
}
void Magazin::AfisareStoc() {

    std::cout << "Stocul curent\n";
    for(int i = 0; i < aStoc; ++i) {
        std::cout << (*stoc[i]) << "\n";
    }
}
void Magazin::ReadListaClient() {

    std::cout << "Cate elemente contine lista?\n";
    int n;
    double total = 0;
    std::vector <Produs*> lista;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        Magazin::AfisareOptiuni();
        int cod;
        std::cin >> cod;
        switch(cod) {
        case 1:{
            lista.push_back(new Varza());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        case 2:{
            lista.push_back(new Faina());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        case 3:{
            lista.push_back(new Bere());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        case 4:{
            lista.push_back(new VinVarsat());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        case 5:{
            lista.push_back(new VinDeSoi());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        case 6:{
            lista.push_back(new Cartofi());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        case 7:{
            lista.push_back(new Jucarie());
            lista[i]->ReadClient();
            this->CautProdus((*lista[i]), lista[i]->getCod(), 1);
            total += lista[i]->getCost();
            break;
        }
        }
        std::cout << "\n";
    }
    /*  daca un element din lista de mai jos are pretul 0 inseamna ca a fost o gasit produsul cerut de client,
        ceea ce inseamna ca produsul nu va fi adaugata la produse vandute
    */
    std::cout << "Lista dumneavoastra este:\n";
    for(int i = 0; i < n; ++i) {
        std::cout << *(lista[i]) << "\n";
    }
    std::cout << "Totalul dumneavoastra este: " << total << "\n\n";
    if(total == 0) {
        for(int i = 0; i < n; ++i) {
            this->CautProdus((*lista[i]), lista[i]->getCod(), 2);
        }
        return;
    } else {
        std::string optiune;
        std::cout << "Vreti sa cumparati produsele?\n";
        std::cin >> optiune;
        if(optiune == "nu") {
            for(int i = 0; i < n; ++i) {
                this->CautProdus((*lista[i]), lista[i]->getCod(), 2);
            }
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(lista[i]->getPretPerUnit() != 0) {
                ++aProduseVandute;
            }
        }
    }
    aTotal += total;
}
void Magazin::CautProdus(Produs& p, int cod, int op) {
    // op = 2 -> clientul a ales sa nu cumpere produsele
    double min_pret = INT_MAX;
    int index = 0;
        for(int i = 0; i < aStoc; ++i) {
            switch(cod) {
                case 1: {
                    if(stoc[i]->getCod() == cod) {
                        if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                        min_pret = stoc[i]->getPretPerUnit();
                        index = i;
                        }
                    }
                    break;
                }
                case 2: {
                    Faina* f1 = dynamic_cast <Faina*> (stoc[i]);
                    Faina& f2 = dynamic_cast <Faina&> (p);
                    if(stoc[i]->getCod() == cod) {
                        if(f2.getCalitate() == "" || f2.getCalitate() == f1->getCalitate()) {
                            if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                                min_pret = stoc[i]->getPretPerUnit();
                                index = i;
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    Bere* b1 = dynamic_cast <Bere*> (stoc[i]);
                    Bere& b2 = dynamic_cast <Bere&> (p);
                    if(stoc[i]->getCod() == cod) {
                        if((b2.getBrand() == "" || b2.getBrand() == b1->getBrand()) && (b2.getTip() == "" || b2.getTip() == b1->getTip())) {
                            if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                                min_pret = stoc[i]->getPretPerUnit();
                                index = i;
                            }
                        }
                    }
                    break;
                }
                case 4: {
                    VinVarsat* v1 = dynamic_cast <VinVarsat*> (stoc[i]);
                    VinVarsat& v2 = dynamic_cast <VinVarsat&> (p);
                    if(stoc[i]->getCod() == cod) {
                        if((v2.getTip() == "" || v2.getTip() == v1->getTip())) {
                            if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                                min_pret = stoc[i]->getPretPerUnit();
                                index = i;
                            }
                        }
                    }
                    break;
                }
                case 5: {
                    VinDeSoi* v1 = dynamic_cast <VinDeSoi*> (stoc[i]);
                    VinDeSoi& v2 = dynamic_cast <VinDeSoi&> (p);
                    if(stoc[i]->getCod() == cod) {
                        if((v2.getSoi() == "" || Magazin::GoodVinDeSoi(v2, *v1)) && (v2.getAn() == 0 || v2.getAn() == v1->getAn()) && (v2.getTara() == "" || v2.getTara() == v1->getTara())) {
                            if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                                min_pret = stoc[i]->getPretPerUnit();
                                index = i;
                            }
                        }
                    }
                    break;
                }
                case 6: {
                    Cartofi* c1 = dynamic_cast <Cartofi*> (stoc[i]);
                    Cartofi& c2 = dynamic_cast <Cartofi&> (p);
                    if(stoc[i]->getCod() == cod) {
                        if((c2.getTip() == "" || c2.getTip() == c1->getTip())) {
                            if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                                min_pret = stoc[i]->getPretPerUnit();
                                index = i;
                            }
                        }
                    }
                    break;
                }
                case 7: {
                    Jucarie* j1 = dynamic_cast <Jucarie*> (stoc[i]);
                    Jucarie& j2 = dynamic_cast <Jucarie&> (p);
                    if(stoc[i]->getCod() == cod) {
                        if((j2.getDenumire() == "" || j2.getDenumire() == j1->getDenumire())) {
                            if(min_pret > stoc[i]->getPretPerUnit() && stoc[i]->getCantitate() >= p.getCantitate()) {
                                min_pret = stoc[i]->getPretPerUnit();
                                index = i;
                            }
                        }
                    }
                    break;
                }
            }
        }
        if(min_pret != INT_MAX) {
            switch(cod) {
                case 2: {
                    Faina* f1 = dynamic_cast <Faina*> (stoc[index]);
                    Faina& f2 = dynamic_cast <Faina&> (p);
                    f2 = *f1;
                    break;
                }
                case 3: {
                    Bere* b1 = dynamic_cast <Bere*> (stoc[index]);
                    Bere& b2 = dynamic_cast <Bere&> (p);
                    b2 = *b1;
                    break;
                }
                case 4: {
                    VinVarsat* v1 = dynamic_cast <VinVarsat*> (stoc[index]);
                    VinVarsat& v2 = dynamic_cast <VinVarsat&> (p);
                    v2 = *v1;
                    break;
                }
                case 5: {
                    VinDeSoi* v1 = dynamic_cast <VinDeSoi*> (stoc[index]);
                    VinDeSoi& v2 = dynamic_cast <VinDeSoi&> (p);
                    v2 = *v1;
                    break;
                }
                case 6: {
                    Cartofi* c1 = dynamic_cast <Cartofi*> (stoc[index]);
                    Cartofi& c2 = dynamic_cast <Cartofi&> (p);
                    c2 = *c1;
                    break;
                }
                case 7: {
                    Jucarie* j1 = dynamic_cast <Jucarie*> (stoc[index]);
                    Jucarie& j2 = dynamic_cast <Jucarie&> (p);
                    j2 = *j1;
                    break;

                }
            }
        p.setPretPerUnit(min_pret);
        p.setCost(p.getPretPerUnit() * p.getCantitate());
        if(op == 1) {
            int cantitate = stoc[index]->getCantitate();
            stoc[index]->setCantitate(cantitate - p.getCantitate());
            stoc[index]->setCost(stoc[index]->getCantitate() * stoc[index]->getPretPerUnit());
        } else {
            int cantitate = stoc[index]->getCantitate();
            stoc[index]->setCantitate(cantitate + p.getCantitate());
            stoc[index]->setCost(stoc[index]->getCantitate() * stoc[index]->getPretPerUnit());
        }
        }
}
void Magazin::ZiDeLucru() {

    int n;
    std::cout << "Numarul de clienti este: ";
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        this->ReadListaClient();
    }
}
