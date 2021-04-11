#ifndef DEF_FONCTIONS
#define DEF_FONCTIONS

#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Article.h"
#include "Commande.h"

void afficherMenu();
int compterLignesFichier(std::string const);
bool existeClient(std::vector<Client>, int);
bool existeArticle(std::vector<Article>, long);
bool existeCommande(std::vector<Commande>, long);
void enregistrerClient(Client);
void enregistrerArticle(Article);
std::string etatLivraisonCmd(std::vector<Article>, long, long);
void enregistrerCommande(Commande);
Client rechercherClient(std::vector<Client>, int);
Article rechercherArticle(std::vector<Article>, long);
Commande rechercherCommande(std::vector<Commande>, long);
void supprimerClient(std::vector<Client>, int);
void supprimerArticle(std::vector<Article>, long);
void supprimerCommande(std::vector<Commande>, long);
void afficherLivraisons(std::vector<Commande>);
void listerArticlesClient(std::vector<Commande>, std::vector<Article>, int);
void listerClientArticles(std::vector<Commande>, std::vector<Client>, long);
void listerCommandesClient_EnCours(std::vector<Commande>, int);
void faireStatsArticle(std::vector<Commande>, long);
void afficherArticlePU(std::vector<Article>);
void afficherArticleARavitaller(std::vector<Article>);
long calculerCapital_XL(std::vector<Article>, std::vector<Commande>);
void meilleurClientArticles(std::vector<Commande>, std::vector<Client>);


#endif // DEF_FONCTIONS
