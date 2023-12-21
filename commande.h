#ifndef COMMANDE_H
#define COMMANDE_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include "use.h"



enum etat {livre,en_cours};
class Cmd {
private:
    std::string m_numCmd, m_numClient, m_ref;
    etat m_etat ;
    int m_qtecmd ;
    
public :
    Cmd();
    int enregistreCmd(std::string, std::string,  int m_qte, etat);

};




#endif /* COMMANDE_H */

