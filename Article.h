#ifndef DEF_ARTICLE
#define DEF_ARTICLE

#include <string>

std::string const articlesF("Fichiers/articles.txt");

class Article
{
    public:
        Article();
        Article(long refe, std::string lib, long pu, long qs, int sc);
        ~Article();
        void afficheArticle();

        //Accesseurs
        long get_referenceA();
        std::string get_libelle();
        long get_PrixU();
        long get_quantiteS();
        int get_seuilC();

        //Mutateurs
        void set_referenceA(long);
        void set_libelle(std::string);
        void set_PrixU(long);
        void set_quantiteS(long);
        void set_seuilC(int);

    private:
        long referenceA;
        std::string libelle;
        long prixU;
        long quantiteS;
        int seuilC;
};

#endif // DEF_ARTICLE
