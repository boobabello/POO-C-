#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include "Article.h"
#include "Commande.h"
#include "fonctions.h"

using namespace std;

int main()
{
    cout << "*****MINI PROJET DE POO 2018-2019*****\n";

    menu: afficherMenu();

    vector<Client> tabClients;
    int nbLignesClient = compterLignesFichier(clientsF);
    ifstream clientFlux(clientsF.c_str());
    do
    {
        int numC;
        string nomC, prenomC, dateC;
        char genreC;
        Client clientCharge;
        clientFlux >> numC >> nomC >> prenomC >> dateC >> genreC;
        clientCharge.set_numero(numC);
        clientCharge.set_nom(nomC);
        clientCharge.set_prenom(prenomC);
        clientCharge.set_date(dateC);
        clientCharge.set_genre(genreC);
        tabClients.push_back(clientCharge);
        nbLignesClient--;
    }while(nbLignesClient);
    clientFlux.close();

    vector<Article> tabArticles;
    int nbLignesArticle = compterLignesFichier(articlesF);
    ifstream articleFlux(articlesF.c_str());
    do
    {
        long referenceA;
        string libelleA;
        long prixUA, quantiteSA;
        int seuilCA;
        Article articleCharge;
        articleFlux >> referenceA >> libelleA >> prixUA >> quantiteSA >> seuilCA;
        articleCharge.set_referenceA(referenceA);
        articleCharge.set_libelle(libelleA);
        articleCharge.set_PrixU(prixUA);
        articleCharge.set_quantiteS(quantiteSA);
        articleCharge.set_seuilC(seuilCA);
        tabArticles.push_back(articleCharge);
        nbLignesArticle--;
    }while(nbLignesArticle);
    articleFlux.close();


    vector<Commande> tabCommandes;
    int nbLignesCommandes = compterLignesFichier(commandesF);
    ifstream commandeFlux(commandesF.c_str());
    do
    {
        long numCmd;
        int numCl;
        string etatC;
        long refA, qteC;
        Commande commandeCharge;
        commandeFlux >> numCmd >> numCl >> etatC >> refA >> qteC;
        commandeCharge.set_numeroCmd(numCmd);
        commandeCharge.set_numClient(numCl);
        commandeCharge.set_etat(etatC);
        commandeCharge.set_refArticle(refA);
        commandeCharge.set_quantite(qteC);
        tabCommandes.push_back(commandeCharge);
        nbLignesCommandes--;
    }while(nbLignesCommandes);
    commandeFlux.close();


    int choix=0;
    do
    {
        cout << "\nVeuillez saisir le numero correspondant a l'operation que vous souhaitez effectuer : " ;
        cin >> choix;
        if(choix<1 || choix>21)
            cout << "Attention!!! Votre choix doit etre compris entre 1 et 21\n";
    }while(choix<1 || choix>21);

    switch (choix)
    {
        case 1:
            {
                cout << "Pour enregistrer un client, saisissez ses informations completes\n";
                int num; string nom, prnom, date; char genre;
                bool existe;
                do
                {
                    cout << "Numero : "; cin >> num;
                    existe = existeClient(tabClients, num);
                    if(existe)
                        cout << "Il existe deja un client enregistre au meme numero!!!\nUtilisez un autre numero svp.\n";
                    else
                    {
                        cout << "Nom : "; cin >> nom;
                        cout << "Prenom : "; cin >> prnom;
                        cout << "Date de naissance(jj/mm/aaaa) : "; cin >> date;
                        cout << "Genre(M/F) : "; cin >> genre;
                        Client newClient(num, nom, prnom, date, genre);
                        enregistrerClient(newClient);
                        cout << "Client enregistre avec succes!\n";
                    }
                }while(existe);
            }break;

        case 2:
            {
                int num;
                bool existe;
                do
                {
                    cout << "Pour rechercher un client, saisissez son numero : "; cin >> num;
                    existe = existeClient(tabClients, num);
                    if(existe)
                    {
                        Client client;
                        cout << "Client trouve!\n";
                        client = rechercherClient(tabClients, num);
                        client.afficheClient();
                    }
                    else
                        cout << "Il n'existe pas un client enregistre a numero!!!\nUtilisez un autre numero svp.\n";
                }while(!existe);
            }break;

        case 3:
            {
                int num; string nom, prnom, date; char genre;
                bool existe;
                do
                {
                    cout << "Saisissez le numero du client que vous souhaitez modifier : "; cin >> num;
                    existe = existeClient(tabClients, num);
                    if(existe)
                    {
                        Client client;
                        client = rechercherClient(tabClients, num);
                        cout << "Vous voulez modifier le client ci-dessous\n";
                        client.afficheClient();
                        cout << "Entrez les nouvelles informations du client\n";
                        cout << "Nom : "; cin >> nom;
                        cout << "Prenom : "; cin >> prnom;
                        cout << "Date de naissance(jj/mm/aaaa) : "; cin >> date;
                        cout << "Genre(M/F) : "; cin >> genre;
                        supprimerClient(tabClients, num);
                        Client newClient(num, nom, prnom, date, genre);
                        enregistrerClient(newClient);
                        cout << "Client modifie avec succes!\n";
                    }
                    else
                        cout << "Il n'existe pas un client enregistre a numero!!!\nUtilisez un autre numero svp.\n";
                }while(!existe);
            }break;

        case 4:
            {
                int num;
                bool existe;
                do
                {
                    cout << "Saisissez le numero du client que vous souhaitez supprimer : "; cin >> num;
                    existe = existeClient(tabClients, num);
                    if(existe)
                    {
                        supprimerClient(tabClients, num);
                        cout << "Client supprime avec succes!\n";
                    }
                    else
                        cout << "Il n'existe pas un client enregistre a numero!!!\nUtilisez un autre numero svp.\n";
                }while(!existe);
            }break;

        case 5:
            {
                cout << "Pour enregistrer un article, saisissez ses carateristiques\n";
                long refe, prix, qte, seuil;
                string libelle;
                bool existe;
                do
                {
                    cout << "Reference : " ; cin >> refe;
                    existe = existeArticle(tabArticles, refe);
                    if(existe)
                        cout << "Il existe deja un article enregistre avec la meme reference!!!\nUtilisez un autre numero de reference svp.\n";
                    else
                    {
                        cout << "Libelle : " ; cin >> libelle;
                        cout << "Prix Unitaire : " ; cin >> prix;
                        cout << "Quantite en stock : " ; cin >> qte;
                        cout << "Seuil critique : " ; cin >> seuil;
                        Article newArticle(refe, libelle, prix, qte, seuil);
                        enregistrerArticle(newArticle);
                        cout << "Article enregistre avec succes!\n";
                    }
                }while(existe);
            }break;

        case 6:
            {
                long refe;
                bool existe;
                do
                {
                    cout << "Pour rechercher un article, saisissez sa reference : "; cin >> refe;
                    existe = existeArticle(tabArticles, refe);
                    if(existe)
                    {
                        Article article;
                        cout << "Article trouve!\n";
                        article = rechercherArticle(tabArticles, refe);
                        article.afficheArticle();
                    }
                    else
                        cout << "Il n'existe pas un article enregistre avec numero de reference!!!\nUtilisez une autre reference svp.\n";
                }while(!existe);
            }break;

        case 7:
            {
                long refe, prix, qte, seuil;
                string libelle;
                bool existe;
                do
                {
                    cout << "Saisissez le numero de reference de l'article que vous souhaitez modifier : "; cin >> refe;
                    existe = existeArticle(tabArticles, refe);
                    if(existe)
                    {
                        Article article;
                        article = rechercherArticle(tabArticles, refe);
                        cout << "Vous voulez modifier l'article ci-dessous\n";
                        article.afficheArticle();
                        cout << "Entrez les nouvelles informations sur l'article\n";
                        cout << "Libelle : " ; cin >> libelle;
                        cout << "Prix Unitaire : " ; cin >> prix;
                        cout << "Quantite en stock : " ; cin >> qte;
                        cout << "Seuil critique : " ; cin >> seuil;
                        supprimerArticle(tabArticles, refe);
                        Article newArticle(refe, libelle, prix, qte, seuil);
                        enregistrerArticle(newArticle);
                        cout << "Article modifie avec succes!\n";
                    }
                    else
                        cout << "Il n'existe pas un article enregistre avec numero de reference!!!\nUtilisez une autre reference svp.\n";
                }while(!existe);
            }break;

        case 8:
            {
                long refe;
                bool existe;
                do
                {
                    cout << "Pour supprimer un article, saisissez sa reference : "; cin >> refe;
                    existe = existeArticle(tabArticles, refe);
                    if(existe)
                    {
                        supprimerArticle(tabArticles, refe);
                        cout << "Article supprime avec succes!\n";
                    }
                    else
                        cout << "Il n'existe pas un article enregistre avec numero de reference!!!\nUtilisez une autre reference svp.\n";
                }while(!existe);
            }break;

        case 9:
            {
                cout << "Pour enregistrer une commande, saisissez :\n";
                int numClient;
                long numCmd, refArt, qteCmd;
                string etat;
                bool existe;
                do
                {
                    cout << "Numero commande : "; cin >> numCmd;
                    existe = existeCommande(tabCommandes, numCmd);
                    if(existe)
                        cout << "Il existe deja une commande enregistre avec meme numero!!!\nUtilisez un autre numero de commande svp.\n";
                    else
                        {
                            cout << "Numero client : "; cin >> numClient;
                            cout << "Reference article : "; cin >> refArt;
                            cout << "Quantite commande : "; cin >> qteCmd;
                            etat=etatLivraisonCmd(tabArticles, refArt, qteCmd);
                            Commande newCommande(numCmd, numClient, etat, refArt, qteCmd);
                            enregistrerCommande(newCommande);
                            cout << "Commande enregistree avec succes!\n";
                            if(etat == "Livre")
                            {
                                Article article;
                                article = rechercherArticle(tabArticles, refArt);
                                supprimerArticle(tabArticles, refArt);
                                article.set_quantiteS(article.get_quantiteS() - qteCmd);
                                enregistrerArticle(article);
                            }
                        }
                }while(existe);
            }break;

        case 10:
            {
                long numCmd;
                bool existe;
                do
                {
                    cout << "Pour rechercher une commande, saisissez son numero : "; cin >> numCmd;
                    existe = existeCommande(tabCommandes, numCmd);
                    if(existe)
                    {
                        Commande commande;
                        cout << "Commande trouve!\n";
                        commande = rechercherCommande(tabCommandes, numCmd);
                        commande.afficheCommande();
                    }
                    else
                        cout << "Il n'existe pas de commande enregistre avec numero!!!\nUtilisez un autre numero de commande svp.\n";
                }while(!existe);
            }break;

        case 11:
            {
                int numClient;
                long numCmd, refArt, qteCmd;
                string etat;
                bool existe;
                do
                {
                    cout << "Saisissez le numero de la commande que vous souhaitez modifier : "; cin >> numCmd;
                    existe = existeCommande(tabCommandes, numCmd);
                    if(existe)
                    {
                        Commande commande;
                        commande = rechercherCommande(tabCommandes, numCmd);
                        cout << "Vous voulez modifier la commande ci-dessous\n";
                        commande.afficheCommande();
                        cout << "Entrez les nouvelles informations sur la commande\n";;
                        cout << "Numero client : "; cin >> numClient;
                        cout << "Reference article : "; cin >> refArt;
                        cout << "Quantite commande : "; cin >> qteCmd;
                        etat=etatLivraisonCmd(tabArticles, refArt, qteCmd);
                        supprimerCommande(tabCommandes, numCmd);
                        Commande newCommande(numCmd, numClient, etat, refArt, qteCmd);
                        enregistrerCommande(newCommande);
                        cout << "Commande modifiee avec succes!\n";
                    }
                    else
                        cout << "Il n'existe pas une commande enregistre avec numero!!!\nUtilisez un autre numero de commande svp.\n";
                }while(!existe);
            }break;

        case 12:
            {
                long numCmd;
                bool existe;
                do
                {
                    cout << "Pour supprimer une commande, saisissez son numero : "; cin >> numCmd;
                    existe = existeCommande(tabCommandes, numCmd);
                    if(existe)
                    {
                        Commande commande = rechercherCommande(tabCommandes, numCmd);
                        supprimerCommande(tabCommandes, numCmd);
                        cout << "Commande supprimee avec succes!\n";
                        if(commande.get_etat() == "Livre")
                        {
                            Article article;
                            article = rechercherArticle(tabArticles, commande.get_refArticle());
                            supprimerArticle(tabArticles, commande.get_refArticle());
                            article.set_quantiteS(article.get_quantiteS() + commande.get_quantite());
                            enregistrerArticle(article);
                        }
                    }
                    else
                        cout << "Il n'existe pas une commande enregistre avec numero!!!\nUtilisez un autre numero de commande svp.\n";
                }while(!existe);
            }break;

        case 13:
            {
                cout << "La liste des livraisons effectuees :\n";
                afficherLivraisons(tabCommandes);
            }break;

        case 14:
            {
                int numClient;
                cout << "Pour donner la liste des articles achetés par un client, entrez le numero du client : "; cin >> numClient;
                cout << "La liste des articles acheter par ce client est :\n";
                listerArticlesClient(tabCommandes, tabArticles, numClient);
            }break;

        case 15:
            {
                long numRefA;
                cout << "Pour donner la liste des clients d’un article, entrez le numero de reference de l'article : "; cin >> numRefA;
                cout << "La liste des clients de cet article est :\n";
                listerClientArticles(tabCommandes, tabClients, numRefA);
            }break;

        case 16:
            {
                int numClient;
                cout << "Pour donner la liste des commandes en cours d’un client, entrez le numero du client : "; cin >> numClient;
                cout << "La liste des commandes en cours de ce client est :\n";
                listerCommandesClient_EnCours(tabCommandes, numClient);
            }break;

        case 17:
            {
                long numRefA;
                cout << "Pour faire des statistiques sur les ventes d’un article, entrez le numero de reference de l'article : "; cin >> numRefA;
                faireStatsArticle(tabCommandes, numRefA);
            }break;

        case 18:
            {
                cout << "La liste des articles et leurs prix unitaires :\n";
                afficherArticlePU(tabArticles);
            }break;

        case 19:
            {
                cout << "La liste des articles à ravitailler :\n";
                afficherArticleARavitaller(tabArticles);
            }break;

        case 20:
            {
                long capital;
                capital = calculerCapital_XL(tabArticles, tabCommandes);
                cout << "Capital de XL = " << capital << " FCFA\n";
            }break;

        case 21:
            {
                cout << "Les noms des meilleurs clients par articles sont :\n\n";
                cout << "RefA\tNom du meilleur client\n";
                meilleurClientArticles(tabCommandes, tabClients);
            }break;

    }


    char retour;
    bool bonChoix=true;
    do
    {
        cout << "\n\nVoulez-vous retourner au menu principal?(O:Oui/N:Non) : "; cin >> retour;
        if(retour=='O')
            goto menu;
        else if(retour=='N')
            cout << "\nMerci!!!\n";
        else
        {
            cout << "\nVotre choix n\'est pas correct!!!\n";
            bonChoix=false;
        }
        cout << "\n\n";
    }while(!bonChoix);


    return 0;
}
