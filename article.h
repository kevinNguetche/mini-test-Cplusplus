#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include "use.h"

class Article {
private :
    std::string m_ref, m_lib;
    int m_pu, m_qteStock, m_seuil;
public:
    Article();
    int enregistreArticle(std::string, int, int, int);
            
    
};


#endif /* ARTICLE_H */

