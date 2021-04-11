#ifndef DEF_COMMANDE
#define DEF_COMMANDE

#include <string>

std::string const commandesF("Fichiers/commandes.txt");

class Commande
{
    public:
        Commande();
        Commande(long num, int numC, std::string et, long refA, long qte);
        ~Commande();
        void afficheCommande();
        void afficheCommandeLivree();

        //Accesseurs
        long get_numeroCmd();
        int get_numClient();
        std::string get_etat();
        long get_refArticle();
        long get_quantite();

        //Mutateurs
        void set_numeroCmd(long);
        void set_numClient(int);
        void set_etat(std::string);
        void set_refArticle(long);
        void set_quantite(long);

    private:
        long numeroCmd;
        int numClient;
        std::string etat;
        long refArticle;
        long quantite;
};

#endif // DEF_COMMANDE
