#ifndef DEF_CLIENT
#define DEF_CLIENT

#include <string>

std::string const clientsF("Fichiers/clients.txt");

class Client
{
    public:
        Client();
        Client(int num, std::string nm, std::string prnm, std::string dte, char gre);
        ~Client();
        void afficheClient();
        void afficheNomClient();

        //Accesseurs
        int get_numero();
        std::string get_nom();
        std::string get_prenom();
        std::string get_date();
        char get_genre();

        //mutateur
        void set_numero(int);
        void set_nom(std::string);
        void set_prenom(std::string);
        void set_date(std::string);
        void set_genre(char);

    private:
        int numero;
        std::string nom;
        std::string prenom;
        std::string date;
        char genre;

};

#endif // DEF_CLIENT
