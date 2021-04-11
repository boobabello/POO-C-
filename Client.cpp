#include <iostream>
#include <string>
#include "Client.h"

using namespace std;

Client::Client()
{

}

Client::Client(int num, string nm, string prnm, string dte, char gre) : numero(num), nom(nm), prenom(prnm), date(dte), genre(gre)
{

}

Client::~Client()
{

}

void Client::afficheClient()
{
    cout << "Nunero : " << numero << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prenom : " << prenom << endl;
    cout << "Date de naissance : " << date << endl;
    cout << "Genre : " << genre << endl;
    cout << endl;
}

void Client::afficheNomClient()
{
    cout << nom;
}



int Client::get_numero()
{
    return numero;
}
string Client::get_nom()
{
    return nom;
}
string Client::get_prenom()
{
    return prenom;
}
string Client::get_date()
{
    return date;
}
char Client::get_genre()
{
    return genre;
}



void Client::set_numero(int num)
{
    this->numero = num;
}

void Client::set_nom(string nomC)
{
    this->nom = nomC;
}

void Client::set_prenom(string prenomC)
{
    this->prenom = prenomC;
}

void Client::set_date(string dateC)
{
    this->date = dateC;
}

void Client::set_genre(char genreC)
{
    this->genre = genreC;
}
