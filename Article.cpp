#include <iostream>
#include <string>
#include "Article.h"

using namespace std;


Article::Article()
{

}

Article::Article(long refe, string lib, long pu, long qs, int sc) : referenceA(refe), libelle(lib), prixU(pu), quantiteS(qs), seuilC(sc)
{

}

Article::~Article()
{

}

void Article::afficheArticle()
{
    cout << "Reference : " << referenceA << endl;
    cout << "Libelle : " << libelle << endl;
    cout << "Prix unitaire : " << prixU << endl;
    cout << "Quantite en stock : " << quantiteS << endl;
    cout << "Seuil critique : " << seuilC << endl;
    cout << endl;
}



long Article::get_referenceA()
{
    return referenceA;
}

string Article::get_libelle()
{
    return libelle;
}

long Article::get_PrixU()
{
    return prixU;
}

long Article::get_quantiteS()
{
    return quantiteS;
}

int Article::get_seuilC()
{
    return seuilC;
}



void Article::set_referenceA(long refe)
{
    this->referenceA = refe;
}

void Article::set_libelle(string lib)
{
    this->libelle = lib;
}

void Article::set_PrixU(long pu)
{
    this->prixU = pu;
}

void Article::set_quantiteS(long qs)
{
    this->quantiteS = qs;
}

void Article::set_seuilC(int sc)
{
    this->seuilC = sc;
}
