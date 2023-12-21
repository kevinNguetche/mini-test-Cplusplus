#include "commande.h"



Cmd::Cmd()
: m_numCmd(" "), m_numClient(" "), m_ref(" "), m_etat(en_cours), m_qtecmd(20)  
{}

/***************************** Enregistrement de la commande ***************************/

int Cmd::enregistreCmd(std::string n, std::string p,  int qte, etat et){    
    m_numCmd = nbAleatoire3(); 
    m_numClient = n;
    m_ref = p;
    m_etat = et;
    m_qtecmd = qte;
    std::ofstream enreg("cmd.txt",std::ios::out | std::ios::app);
    if(enreg.good()){
        enreg <<"*"<< m_numCmd <<" " << m_numClient << "&" << m_ref << "@" 
              << m_etat << "$" << m_qtecmd << "!" << "\n" ;
        return 1;
    }
    else{
        std::cout << " Erreur d'ouverture en ecriture !!!" << std::endl;
        return 0;
    }
    
}


