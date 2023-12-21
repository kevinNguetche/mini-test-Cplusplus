#include "client.h"


Client::Client()
: m_numClient(""), m_nom(""), m_prenom(""), m_date_naissance(""), m_genre(M) 
{}

/***************************** Enregistrement du client *********************************/

int Client::enregistreClient(std::string n, std::string p, std::string date,genre sexe){
    m_numClient = nbAleatoire(); 
    m_nom = n;
    m_prenom = p;
    m_date_naissance = date;
    m_genre = sexe;
    std::ofstream enreg("client.txt",std::ios::out | std::ios::app);
    if(enreg.good()){
        enreg <<"*"<< m_numClient <<" " << m_nom << "&" << m_prenom << "@" 
              << m_date_naissance << "$" << m_genre << "!" << "\n" ;
        return 1;
    }
    else{
        std::cout << " Erreur d'ouverture en ecriture !!!" << std::endl;
        return 0;
    }
    
}

/********************************** Recherche client***********************************/

// grace au numero
int Client::rechercheClient(std::string num){
    std:: string ligne;
    m_numClient = num ;
    int i = 0, j=0,r=0,cmp=0;
    std::ifstream enreg("client.txt",std::ios::in);
    if(enreg.good()){
        while(std::getline(enreg,ligne)){
            std::vector<char> temp;
            cmp++;
            i = 0;
            r = 0;
            j = 0;
            while(ligne[i] != '*') i++;
                j = i+1;
                while(ligne[j] != ' '){
                    temp.push_back(ligne[j]);
                    j++;
                }
                
                if(m_numClient.size() == temp.size()){
                        for(int i=0;i< m_numClient.size();i++){
                            if(m_numClient[i]==temp[i]) r += 1;
                        }
                    if(r==m_numClient.size()) break;   
                }
        }
        
        if(r == m_numClient.size()) return cmp;
        else return 0;
       
    }
    else{
        std::cout << " Erreur d'ouverture en ecriture !!!" << std::endl;
    }
}

//nom
int Client::recherche2Client(std::string nom){
    std:: string ligne;
    m_nom = nom ;
    int i = 0, j=0,r=0,cmp=0;
    std::ifstream enreg("client.txt",std::ios::in);
    if(enreg.good()){
        while(std::getline(enreg,ligne)){
            std::vector<char> temp;
            cmp++;
            i = 0;
            r = 0;
            j = 0;
            while(ligne[i] != ' ') i++;
                j = i+1;
                while(ligne[j] != '&'){
                    temp.push_back(ligne[j]);
                    j++;
                }
                
                if(m_nom.size() == temp.size()){
                        for(int i=0;i< m_nom.size();i++){
                            if(m_nom[i]==temp[i]) r += 1;
                        }
                    if(r==m_nom.size()) break;   
                }
        }
        
        if(r == m_nom.size()) return cmp;
        else return 0;
       
    }
    else{
        std::cout << " Erreur d'ouverture en ecriture !!!" << std::endl;
    }
}


/*************************** Suppression du client ****************************/

int Client::suppClient(std::string id){
    m_numClient = id;
    std::string ligne;
    int n=0,cmp=0;
    n = rechercheClient(id);
    std::ifstream oldFile("client.txt");
    std::ofstream newFile("temp.txt");
    if(!newFile.fail()){
        if(!oldFile.fail()){
            cmp = 0;
            while(std::getline(oldFile,ligne)){
                cmp++;
                if(cmp==n) continue;
                newFile << ligne <<'\n';
            }
        }
        else{
            std::cout << "Echec d'ouverture du fichier client\n";
        }
    }
    else{
            std::cout << "Echec d'ouverture du fichier temporaire\n";
    }
    remove("client.txt");
    rename("temp.txt","client.txt");
    return n;
}


/****************************** Modification du client *********************************/

//FONCTION D'AFFICHAGE DU CLIENT
void Client::afficheClient(std::string id,int x){
    
    std::string ligne;
    int cmp=0,i=0,i1=0,j1=0,i2=0,j2=0,i3=0,j3=0,i4=0,j4=0;
    m_numClient = id;

    std::ifstream file("client.txt");
    if(file.good()){
        while(getline(file,ligne)){
            
            std::vector<char> temp1;
            cmp++;
            i1 = 0;
            j1 = 0;
            std::vector<char> temp2;
            
            i2 = 0;
            j2 = 0;
            std::vector<char> temp3;
          
            i3 = 0;
            j3 = 0;
            std::vector<char> temp4;
     
            i4 = 0;
            j4 = 0;

            if(cmp == x){

                //nom
                while(ligne[i1] != ' ') i1++;
                j1 = i1+1;
                while(ligne[j1] != '&'){
                        temp1.push_back(ligne[j1]);
                        j1++;
                    }
                for(i = 0;i<temp1.size();i++){
           
                    m_nom += temp1[i];
                }
                
                
                //prenom

                while(ligne[i2] != '&') i2++;
                j2 = i2+1;
                while(ligne[j2] != '@'){
                        temp2.push_back(ligne[j2]);
                        j2++;
                    }
                for(i = 0;i<temp2.size();i++){
                    m_prenom += temp2[i];
                }
                //std::cout << m_prenom <<"\n";
                //date naissance

                while(ligne[i3] != '@') i3++;
                j3 = i3+1;
                while(ligne[j3] != '$'){
                        temp3.push_back(ligne[j3]);
                        j3++;
                    }
                for(i = 0;i<temp3.size();i++){
                    m_date_naissance += temp3[i];
                }

                //genre

                while(ligne[i4] != '&') i4++;
                j4 = i4+1;
                while(ligne[j4] != '!'){
                        temp4.push_back(ligne[j4]);
                        j4++;
                    }
                if(temp4[0] == 0) m_genre = M;
                if(temp4[0] == 1) m_genre = F;

                std::cout << "\t\t\t\t+-------------------+--------------------+--------------------+--------------------+--------------------+\n";
                std::cout << "\t\t\t\t|"<< std::setw(20) << "N°Client";
                std::cout << "|"<< std::setw(20) << "Nom";
                std::cout << "|"<< std::setw(20) << "Prenom";
                std::cout << "|"<< std::setw(20) << "Date de naissance";
                std::cout << "|"<< std::setw(20) << "Genre";
                std::cout << "|\n";
                std::cout << "\t\t\t\t+-------------------+--------------------+--------------------+--------------------+--------------------+\n";

                std::cout << "\t\t\t\t|"<< std::setw(19) << m_numClient;
                std::cout << "|"<< std::setw(20) << m_nom;
                std::cout << "|"<< std::setw(20) << m_prenom;
                std::cout << "|"<< std::setw(20) << m_date_naissance;
                if(m_genre == M) std::cout << "|"<< std::setw(20) << "M";
                if(m_genre == F) std::cout << "|"<< std::setw(20) << "F";
                std::cout << "|\n";
                std::cout << "\t\t\t\t+-------------------+--------------------+--------------------+--------------------+--------------------+\n";

                
            }
            else{
                continue;   
            }
        }
    }
    else{
        std::cout << "Echec d'ouverture du fichier !!!\n";
    }
    
}



//Fonction de modification proprement dite

int Client::modifClient(int q,std::string id,std::string nom,std::string prenom,std::string date,genre sexe){
    
    m_numClient = id;
    m_nom = nom;      
    m_prenom = prenom;
    m_date_naissance = date;
    m_genre = sexe;
    
    int cmp = 0;
    std::string ligne;
    
    std::ifstream oldFile("client.txt");
    std::ofstream newFile("temp.txt");
    if(!newFile.fail()){
        if(!oldFile.fail()){
            cmp = 0;
            while(std::getline(oldFile,ligne)){
                cmp++;
                if(cmp==q){
                    newFile << "*" << m_numClient <<" "<< m_nom << "&" << m_prenom << "@" << m_date_naissance << "$" << m_genre << "!" << "\n" ;
                }
                
                if(cmp!=q) newFile << ligne <<'\n';
            }
          
        }
        else{
            std::cout << "Echec d'ouverture du fichier client\n";
        }
    }
    else{
            std::cout << "Echec d'ouverture du fichier temporaire\n";
          
    }
    remove("client.txt");
    rename("temp.txt","client.txt");
    return 1;
}
