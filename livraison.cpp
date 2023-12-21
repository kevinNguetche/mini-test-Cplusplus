#include "livraison.h"



Livraison::Livraison()
: m_numCommande(" "), m_numClient(" "), m_qteLivre(30)  
{}

/***************************** Enregistrement de la livraison *********************************/

int Livraison::enregistreLivraison(std::string n, std::string p, int qte){
    m_numCommande = n;
    m_numClient = p;
    m_qteLivre = qte;
    std::ofstream enreg("livraison.txt",std::ios::out | std::ios::app);
    if(enreg.good()){
        enreg <<"*"<< m_numCommande <<" " << m_numClient << "@" << m_qteLivre  << "$" 
                << "\n";
             
        return 1;
    }
    else{
        std::cout << " Erreur d'ouverture en ecriture !!!" << std::endl;
        return 0;
    }
    
}




