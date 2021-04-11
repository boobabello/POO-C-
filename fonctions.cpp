#include <iostream>
#include <string>
#include <vector>
#include "fonctions.h"


using namespace std;

void afficherMenu()
{
    cout << "\n\nMENU PRINCIPAL\n\n";
    cout << "1-Enregistrer client" << endl;
    cout << "2-Rechercher client" << endl;
    cout << "3-Modifier client" << endl;
    cout << "4-Supprimer client" << endl;
    cout << "5-Enregistrer article" << endl;
    cout << "6-Rechercher article" << endl;
    cout << "7-Modifier article" << endl;
    cout << "8-Supprimer article" << endl;
    cout << "9-Enregistrer commande" << endl;
    cout << "10-Rechercher commande" << endl;
    cout << "11-Modifier commande" << endl;
    cout << "12-Supprimer commande" << endl;
    cout << "13-Afficher la liste des livraisons effectuees" << endl;
    cout << "14-Donner la liste des articles achetes par un client" << endl;
    cout << "15-Donner la liste des clients d’un article" << endl;
    cout << "16-Donner la liste des commandes d’un client en cours" << endl;
    cout << "17-Faire des statistiques sur les ventes d’un article : quantite vendue, nombre de commandes" << endl;
    cout << "18-Afficher les articles et leurs prix unitaires" << endl;
    cout << "19-Afficher les articles à ravitailler" << endl;
    cout << "20-Calculer le capital de XL" << endl;
    cout << "21-Donner le nom du meilleur client par articles" << endl;
}

int compterLignesFichier(string const nom)
{
    int nbLignes=0;
    string lignes;
    ifstream fichierFlux(nom.c_str());
    while(getline(fichierFlux, lignes))
        nbLignes++;
    return nbLignes;
    fichierFlux.close();
}

bool existeClient(vector<Client> tab, int num)
{
    int i;
    int const taille=tab.size();
    bool trouve=false;

    for(i=0; i<taille; i++)
        if(num == tab[i].get_numero())
            trouve=true;

    return trouve;
}

bool existeArticle(vector<Article> tab, long refe)
{
    int i;
    int const taille=tab.size();
    bool trouve=false;

    for(i=0; i<taille; i++)
        if(refe == tab[i].get_referenceA())
            trouve=true;

    return trouve;
}

bool existeCommande(vector<Commande> tab, long numCmd)
{
    int i;
    int const taille=tab.size();
    bool trouve=false;

    for(i=0; i<taille; i++)
        if(numCmd == tab[i].get_numeroCmd())
            trouve=true;

    return trouve;
}

void enregistrerClient(Client client)
{
    ofstream clientsFlux(clientsF.c_str(), ios::app);
    if(clientsFlux)
    {
        clientsFlux << client.get_numero();
        clientsFlux << "\t";
        clientsFlux << client.get_nom();
        clientsFlux << "\t";
        clientsFlux << client.get_prenom();
        clientsFlux << "\t";
        clientsFlux << client.get_date();
        clientsFlux << "\t";
        clientsFlux << client.get_genre();
        clientsFlux << endl;
    }
    clientsFlux.close();
}

void enregistrerArticle(Article article)
{
    ofstream articlesFlux(articlesF.c_str(), ios::app);
    if(articlesFlux)
    {
        articlesFlux << article.get_referenceA();
        articlesFlux << "\t";
        articlesFlux << article.get_libelle();
        articlesFlux << "\t";
        articlesFlux << article.get_PrixU();
        articlesFlux << "\t";
        articlesFlux << article.get_quantiteS();
        articlesFlux << "\t";
        articlesFlux << article.get_seuilC();
        articlesFlux << endl;
    }
    articlesFlux.close();
}

string etatLivraisonCmd(vector<Article> tab, long refArt, long qteCmd)
{
    int i;
    int const taille=tab.size();
    string etat("En_cours");

    for(i=0; i<taille; i++)
        if(refArt == tab[i].get_referenceA())
            if(qteCmd <= tab[i].get_quantiteS())
                etat="Livre";

    return etat;
}

void enregistrerCommande(Commande commande)
{
    ofstream commandesFlux(commandesF.c_str(), ios::app);
    if(commandesFlux)
    {
        commandesFlux << commande.get_numeroCmd();
        commandesFlux << "\t";
        commandesFlux << commande.get_numClient();
        commandesFlux << "\t";
        commandesFlux << commande.get_etat();
        commandesFlux << "\t";
        commandesFlux << commande.get_refArticle();
        commandesFlux << "\t";
        commandesFlux << commande.get_quantite();
        commandesFlux << endl;
    }
    commandesFlux.close();
}

Client rechercherClient(vector<Client> tab, int num)
{
    int i;
    int const taille=tab.size();
    Client client;
    for(i=0; i<taille; i++)
    {
        if(num == tab[i].get_numero())
        {
            client.set_numero(num);
            client.set_nom(tab[i].get_nom());
            client.set_prenom(tab[i].get_prenom());
            client.set_date(tab[i].get_date());
            client.set_genre(tab[i].get_genre());
        }
    }

    return client;
}

Article rechercherArticle(vector<Article> tab, long refe)
{
    int i;
    int const taille=tab.size();
    Article article;
    for(i=0; i<taille; i++)
    {
        if(refe == tab[i].get_referenceA())
        {
            article.set_referenceA(refe);
            article.set_libelle(tab[i].get_libelle());
            article.set_PrixU(tab[i].get_PrixU());
            article.set_quantiteS(tab[i].get_quantiteS());
            article.set_seuilC(tab[i].get_seuilC());
        }
    }

    return article;
}

Commande rechercherCommande(vector<Commande> tab, long numCmd)
{
    int i;
    int const taille=tab.size();
    Commande commande;

    for(i=0; i<taille; i++)
    {
        if(numCmd == tab[i].get_numeroCmd())
        {
            commande.set_numeroCmd(numCmd);
            commande.set_numClient(tab[i].get_numClient());
            commande.set_etat(tab[i].get_etat());
            commande.set_refArticle(tab[i].get_refArticle());
            commande.set_quantite(tab[i].get_quantite());
        }
    }

    return commande;
}


void supprimerClient(vector<Client> tab, int num)
{
    int i;
    int const taille=tab.size();

    ofstream clientFlux(clientsF.c_str());
    if(clientFlux)
    {
        for(i=0; i<taille; i++)
        {
            if(num != tab[i].get_numero())
            {
                enregistrerClient(tab[i]);
            }
        }
    }
}

void supprimerArticle(vector<Article> tab, long refe)
{
    int i;
    int const taille=tab.size();

    ofstream articleFlux(articlesF.c_str());
    if(articleFlux)
    {
        for(i=0; i<taille; i++)
        {
            if(refe != tab[i].get_referenceA())
            {
                enregistrerArticle(tab[i]);
            }
        }
    }
}

void supprimerCommande(vector<Commande> tab, long numCmd)
{
    int i;
    int const taille=tab.size();

    ofstream commandeFlux(commandesF.c_str());
    if(commandeFlux)
    {
        for(i=0; i<taille; i++)
        {
            if(numCmd != tab[i].get_numeroCmd())
            {
                enregistrerCommande(tab[i]);
            }
        }
    }
}

void afficherLivraisons(vector<Commande> tab)
{
    int i;
    int const taille=tab.size();

    for(i=0; i<taille; i++)
    {
        if(tab[i].get_etat() == "Livre")
        {
            tab[i].afficheCommandeLivree();
        }
    }
}

void listerArticlesClient(vector<Commande> tabCmd, vector<Article> tabArt, int numClient)
{
    int i, j;
    int const tailleCmd=tabCmd.size(), tailleArt=tabArt.size();

    for(i=0; i<tailleCmd; i++)
    {
        if(tabCmd[i].get_numClient() == numClient)
        {
            for(j=0; j<tailleArt; j++)
                if(tabArt[j].get_referenceA() == tabCmd[i].get_refArticle())
                    tabArt[j].afficheArticle();
        }
    }
}

void listerClientArticles(vector<Commande> tabCmd, vector<Client> tabCl, long refArticle)
{
    int i, j;
    int const tailleCmd=tabCmd.size(), tailleCl=tabCl.size();

    for(i=0; i<tailleCmd; i++)
    {
        if(tabCmd[i].get_refArticle() == refArticle)
        {
            for(j=0; j<tailleCl; j++)
                if(tabCl[j].get_numero() == tabCmd[i].get_numClient())
                    tabCl[j].afficheClient();
        }
    }
}

void listerCommandesClient_EnCours(vector<Commande> tab, int numClient)
{
    int i;
    int const taille=tab.size();

    for(i=0; i<taille; i++)
    {
        if(tab[i].get_numClient()==numClient && tab[i].get_etat()=="En_cours")
            tab[i].afficheCommande();
    }
}

void faireStatsArticle(vector<Commande> tab, long refArticle)
{
    int i;
    int const taille=tab.size();
    long qteV=0, nbCmd=0;

    for(i=0; i<taille; i++)
    {
        if(tab[i].get_refArticle() == refArticle)
        {
            if(tab[i].get_etat() == "Livre")
                qteV += tab[i].get_quantite();
            nbCmd += tab[i].get_quantite();
        }
    }
    cout << "Quantite vendue : " << qteV << endl;
    cout << "Nombre de commandes : " << nbCmd << endl;
}

void afficherArticlePU(vector<Article> tab)
{
    int i;
    int const taille=tab.size();

    cout << "RefA\tPrixU\n";
    for(i=0; i<taille; i++)
        cout << tab[i].get_referenceA() << "\t" << tab[i].get_PrixU() << endl;
}

void afficherArticleARavitaller(vector<Article> tab)
{
    int i;
    int const taille=tab.size();

    for(i=0; i<taille; i++)
    {
        if(tab[i].get_quantiteS() <= tab[i].get_seuilC())
            tab[i].afficheArticle();
    }
}

long calculerCapital_XL(vector<Article> tabArt, vector<Commande> tabCmd)
{
    int i, j;
    int const tailleCmd=tabCmd.size(), tailleArt=tabArt.size();
    long capital_XL, prixArtEnStock=0, prixArtAchete=0;

    for(i=0; i<tailleCmd; i++)
    {
        if(tabCmd[i].get_etat() == "Livre")
        {
            for(j=0; j<tailleArt; j++)
            {
                if(tabCmd[i].get_refArticle() == tabArt[j].get_referenceA())
                    prixArtAchete += (tabCmd[i].get_quantite()*tabArt[j].get_PrixU());
            }
        }
    }
    for(i=0; i<tailleArt; i++)
        prixArtEnStock += (tabArt[i].get_PrixU()*tabArt[i].get_quantiteS());

    capital_XL = prixArtAchete+prixArtEnStock;

    return capital_XL;
}

void meilleurClientArticles(vector<Commande> tabCmd, vector<Client> tabCl)
{
    int i, j;
    int const tailleCmd=tabCmd.size(), tailleCl=tabCl.size();
    int numMCl;
    long qteCmd=0;

    for(i=0; i<tailleCmd; i++)
    {
        for(j=i+1; j<tailleCmd; j++)
        {
            if(tabCmd[i].get_refArticle() == tabCmd[j].get_refArticle())
            {
                if(tabCmd[i].get_quantite() < tabCmd[j].get_quantite())
                    tabCmd[i].set_quantite(0);
                else
                    tabCmd[j].set_quantite(0);
            }
        }
    }

    for(i=0; i<tailleCmd; i++)
    {
        if(tabCmd[i].get_quantite())
        {
            cout << tabCmd[i].get_refArticle() << "\t";
            for(j=0; j<tailleCl; j++)
            {
                if(tabCmd[i].get_numClient() == tabCl[j].get_numero())
                    tabCl[j].afficheNomClient();
            }
            cout << endl;
        }
    }
}

