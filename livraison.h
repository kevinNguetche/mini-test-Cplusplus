#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <iostream>
#include <string>
#include <fstream>



class Livraison
{
    public:
        Livraison();
    int enregistreLivraison(std::string, std::string, int);

    private: 
    std::string m_numCommande; // Le numéro de la commande
    std::string m_numClient; // Le numéro du client
    int m_qteLivre; // La quantité à livrer de l'article

};


#endif /* LIVRAISON_H */

