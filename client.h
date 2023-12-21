#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <iomanip>
#include "use.h"


 enum genre {M,F};
class Client {
private:
    std::string m_numClient, m_nom, m_prenom, m_date_naissance ;
    genre m_genre ;
    
public :
    Client();
    int enregistreClient(std::string, std::string, std::string,genre);
    int rechercheClient(std::string);
    int recherche2Client(std::string);
    int suppClient(std::string);
    void afficheClient(std::string,int);
    int modifClient(int,std::string,std::string,std::string,std::string,genre);
    
};

    



#endif /* CLIENT_H */

