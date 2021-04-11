#include <iostream>
#include <string>
#include "Commande.h"

using namespace std;

Commande::Commande()
{

}

Commande::Commande(long num, int numC, string et, long refA, long qte) : numeroCmd(num), numClient(numC), etat(et), refArticle(refA), quantite(qte)
{

}

Commande::~Commande()
{

}

void Commande::afficheCommande()
{
    cout << "Numero Commande : " << numeroCmd << endl;
    cout << "Numero client : " << numClient << endl;
    cout << "Etat : " << etat << endl;
    cout << "Reference article : " << refArticle << endl;
    cout << "Quantite : " << quantite << endl;
    cout << endl;
}

void Commande::afficheCommandeLivree()
{
    cout << "Numero Commande : " << numeroCmd << endl;
    cout << "Quantite : " << quantite << endl;
    cout << "Numero client : " << numClient << endl;
    cout << endl;
}



long Commande::get_numeroCmd()
{
    return numeroCmd;
}

int Commande::get_numClient()
{
    return numClient;
}

string Commande::get_etat()
{
    return etat;
}

long Commande::get_refArticle()
{
    return refArticle;
}

long Commande::get_quantite()
{
    return quantite;
}



void Commande::set_numeroCmd(long numC)
{
    this->numeroCmd = numC;
}

void Commande::set_numClient(int numCl)
{
    this->numClient = numCl;
}

void Commande::set_etat(string etatC)
{
    this->etat = etatC;
}

void Commande::set_refArticle(long refA)
{
    this->refArticle = refA;
}

void Commande::set_quantite(long qteC)
{
    this->quantite = qteC;
}
