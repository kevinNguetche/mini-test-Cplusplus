#include "use.h"

// fonction de test d'unicite du numero du client
int isvalid(int nombre){
    int i=0;
    std::ifstream pass("numclient.txt", std::ios::in);
    if(!pass.fail()){
        while(!(pass.eof())){
            pass >> i;
            if(i==nombre) break;
        }
        if(pass.eof()) return 1;
        else return 0;
            
        }
    else {
        std::cout << "erreur d'ouverture du fichier !!!" << std::endl;
    }
    }

// fonction generant le numero du client 
std::string nbAleatoire(){
    static int qt = 10000;
    std::ifstream flux("numclient.txt",std::ios::in);
    int nbLignes = 0;
    while(flux.ignore(21474836, '\n')) 
    {
        nbLignes++;
    }
    if(nbLignes == qt) qt *= 2;
    flux.close();
    int n = 0;
    srand(time(0));
    do
    {
        n = rand() % qt ;
    }
    while(!isvalid(n));
    std::ofstream psw("numclient.txt",std::ios::app);
    psw << n << "\n";
    psw.close();
    std::ostringstream num;
    num << n;
    std::string number = num.str();
    return "cli"+number ;
    
}


/******************************Autour de l'Article ***********************************/


// fonction de test d'unicite du numero de la reference
int isvalid2(int nombre){
    int i=0;
    std::ifstream pass("numarticle.txt", std::ios::in);
    if(!pass.fail()){
        while(!(pass.eof())){
            pass >> i;
            if(i==nombre) break;
        }
        if(pass.eof()) return 1;
        else return 0;
            
        }
    else {
        std::cout << "erreur d'ouverture du fichier !!!" << std::endl;
    }
    }

// fonction generant la reference 
std::string nbAleatoire2(){
    static int qt = 10000;
    std::ifstream flux("numarticle.txt",std::ios::in);
    int nbLignes = 0;
    while(flux.ignore(21474836, '\n')) 
    {
        nbLignes++;
    }
    if(nbLignes == qt) qt *= 2;
    flux.close();
    int n = 0;
    srand(time(0));
    do
    {
        n = rand() % qt ;
    }
    while(!isvalid(n));
    std::ofstream psw("numarticle.txt",std::ios::app);
    psw << n << "\n";
    psw.close();
    std::ostringstream num;
    num << n;
    std::string number = num.str();
    return "art"+number ;
    
}



/***********************Autour de la commande **************************************/


// fonction de test d'unicite du numero du client
int isvalid3(int nombre){
    int i=0;
    std::ifstream pass("numcmd.txt", std::ios::in);
    if(!pass.fail()){
        while(!(pass.eof())){
            pass >> i;
            if(i==nombre) break;
        }
        if(pass.eof()) return 1;
        else return 0;
            
        }
    else {
        std::cout << "erreur d'ouverture du fichier !!!" << std::endl;
    }
    }

// fonction generant le numero du client 
std::string nbAleatoire3(){
    static int qt = 10000;
    std::ifstream flux("numcmd.txt",std::ios::in);
    int nbLignes = 0;
    while(flux.ignore(21474836, '\n')) 
    {
        nbLignes++;
    }
    if(nbLignes == qt) qt *= 2;
    flux.close();
    int n = 0;
    srand(time(0));
    do
    {
        n = rand() % qt ;
    }
    while(!isvalid(n));
    std::ofstream psw("numcmd.txt",std::ios::app);
    psw << n << "\n";
    psw.close();
    std::ostringstream num;
    num << n;
    std::string number = num.str();
    return "liv"+number ;
    
}

/**************************************** Comparaison ********************************/
/**
int compare(std::string str,std::vector<char> a){
    int i=0,r=0;
    if(str.size() == a.size()){
        for(int i=0;i< str.size();i++){
            if(str[i]==a[i]) r += 1;
        }
    }
    if(r == str.size()) return 1;
    else return 0;
}

 * */

