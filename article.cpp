#include "article.h"



Article::Article()
: m_ref(" "),m_lib(" "),m_pu(1500),m_qteStock(30),m_seuil(4)  
{}

/***************************** Enregistrement de l'article *********************************/

int Article::enregistreArticle(std::string n, int p, int qte, int seuil){
    m_ref = nbAleatoire2(); 
    m_lib = n;
    m_pu = p;
    m_qteStock = qte;
    m_seuil = seuil;
    std::ofstream enreg("article.txt",std::ios::out | std::ios::app);
    if(enreg.good()){
        enreg <<"*"<< m_ref <<" " << m_lib << "&" << m_pu << "@" 
              << m_qteStock << "$" << m_seuil << "!" << "\n" ;
        return 1;
    }
    else{
        std::cout << " Erreur d'ouverture en ecriture !!!" << std::endl;
        return 0;
    }
    
}


