#include "fonctions.h"
#include <iostream>
    /***************************** Enregistrement du client **********************/
void enregistrement_client(){
    std::string nom, prenom, date_naiss;
    char genre;
    int i = 0,n=0 ;
    char a = 'N';
    std::cout << "\t\t\t Bienvenue dans la section d'enregistrement du client !!! \t\t\t" 
              << std::endl;
    std::cout <<'\n';
    do{
        i++; 
        std::cout << "Client N°" << i << std::endl;
        std::cout << "Nom :";
        std::cin >> nom;
        std::cout << "Prenom :";
        std::cin >> prenom;
        std::cout << "Date de naissance(JJ/MM/AAAA) :";
        std::cin >> date_naiss;
        do{
            std::cout << "Genre(M/F) :";
            std::cin >> genre;
        }while(genre != 'M' && genre != 'F' && genre != 'm' && genre != 'f' );
        Client cl;
        if(genre == 'M' || genre == 'm'){
            n = cl.enregistreClient(nom,prenom,date_naiss,M) ;
        }
        else{
            n = cl.enregistreClient(nom,prenom,date_naiss,F) ;
        }
        
        if(n) std::cout<< "\nMerci, vous venez d'enregistrer "<< i << " client !!!" << "\n\n";
        else std::cout << "\n!!! Une erreur c'est produite lors de l'enregistrement\n" ;
        std::cout << "voulez-vous enregistrer un "<< i+1 <<"eme client ?(O/N)";
        std::cin >> a;
        while(a != 'N' && a != 'n' && a != 'O' &&  a != 'o' ){
           std::cout << "\n!!!Veuillez choisir entre(O/N)";
           std::cin >> a;
        }
            
    }while(a == 'O' || a == 'o' );
              
}


    /***************************** Enregistrement de l'article **********************/

void enregistrement_article(){
    std::string lib;
    int pu,qte,seuil;
    int i = 0,n=0 ;
    char a = 'N';
    std::cout << "\t\t\t Bienvenue dans la section d'enregistrement des articles !!! \t\t\t" 
              << std::endl;
    std::cout <<'\n';
    do{
        i++; 
        std::cout << "Article N°" << i << std::endl;
        std::cout << "libelle :";
        std::cin >> lib;
        do{
            std::cout << "Prix unitaire :";
            std::cin >> pu;
        }while(pu<0);
        do{
            std::cout << "Quantite en stock :";
            std::cin >> qte;
        }while(qte<0);
        do{
            std::cout << "Seuil critique :";
            std::cin >> seuil;
        }while(seuil<0);
        
       
        Article  art;
        n = art.enregistreArticle(lib,pu,qte,seuil);
        
        if(n) std::cout<< "\nMerci, vous venez d'enregistrer "<< i << " article !!!" << "\n\n";
        else std::cout << "\n!!! Une erreur c'est produite lors de l'enregistrement\n" ;
        std::cout << "voulez-vous enregistrer un "<< i+1 <<"eme article ?(O/N)";
        std::cin >> a;
        while(a != 'N' && a != 'n' && a != 'O' &&  a != 'o' ){
           std::cout << "\n!!!Veuillez choisir entre(O/N)";
           std::cin >> a;
        }
            
    }while(a == 'O' || a == 'o' );

}



/***************************** Enregistrement de la commande **********************/
void enregistrement_cmd(){
    std::string numclient, ref;
    std::string etat;
    int i = 0, n=0, qte;
    char a = 'N';
    std::cout << "\t\t\t Bienvenue dans la section d'enregistrement de la commande !!! \t\t\t" 
              << std::endl;
    std::cout <<'\n';
    do{
        i++; 
        std::cout << "Commande N°" << i << std::endl;
        std::cout << "N°client :";
        std::cin >> numclient;
        std::cout << "Reference :";
        std::cin >> ref;
        std::cout << "Quantite commande :";
        std::cin >> qte;
        do{
            std::cout << "Etat(livre/en_cours) :";
            std::cin >> etat;
        }while(etat != "livre" && etat != "LIVRE" && etat != "Livre" && 
                etat != "en_cours" && etat !="EN_COURS" && etat != "En_cours");
        Cmd com;
        if(etat != "livre" || etat != "LIVRE" || etat != "Livre"){
            n = com.enregistreCmd(numclient,ref,qte,livre);
        }
        else{
            n = com.enregistreCmd(numclient,ref,qte,en_cours);
        }
        
        if(n) std::cout<< "\nMerci, vous venez d'enregistrer "<< i << " commande !!!" << "\n\n";
        else std::cout << "\n!!! Une erreur c'est produite lors de l'enregistrement\n" ;
        std::cout << "voulez-vous enregistrer une "<< i+1 <<"eme commande ?(O/N)";
        std::cin >> a;
        while(a != 'N' && a != 'n' && a != 'O' &&  a != 'o' ){
           std::cout << "\n!!!Veuillez choisir entre(O/N)";
           std::cin >> a;
        }
            
    }while(a == 'O' || a == 'o' );
              
}

 /**************************** ENREGISTREMENT DE LA LIVRAISON *************************/

void enregistrement_liv(){
    std::string numClient,numCmd;
    int qte;
    int i = 0,n=0 ;
    char a = 'N';
    std::cout << "\t\t\t Bienvenue dans la section d'enregistrement de la livraison !!! \t\t\t" 
              << std::endl;
    std::cout <<'\n';
    do{
        i++; 
        std::cout << "Livraison N°" << i << std::endl;
        std::cout << "N°client :";
        std::cin >> numClient;
        std::cout << "N°commande :";
        std::cin >> numCmd;
        do{
            std::cout << "Quantite a livre :";
            std::cin >> qte;
        }while(qte<0);
        
        
        Livraison  li;
        n = li.enregistreLivraison(numClient,numCmd,qte);
        
        if(n) std::cout<< "\nMerci, vous venez d'enregistrer "<< i << " livraison !!!" << "\n\n";
        else std::cout << "\n!!! Une erreur c'est produite lors de l'enregistrement\n" ;
        std::cout << "voulez-vous enregistrer une "<< i+1 <<"eme livraison ?(O/N)";
        std::cin >> a;
        while(a != 'N' && a != 'n' && a != 'O' &&  a != 'o' ){
           std::cout << "\n!!!Veuillez choisir entre(O/N)";
           std::cin >> a;
        }
            
    }while(a == 'O' || a == 'o' );

}

/**************************************************************************************/
/********************************** Recherche client ***********************************/

void rechercher_cl(){
    char t;
        std::cout << "\t\t\t Bienvenue dans la section de recherche du client !!! \t\t\t" 
                  << std::endl;
    do{
        
        int n=0,etat=0;
        std::string num,nom;
        std::cout << "\nQuelle information avez-vous le consernant ?\n";
        std::cout << "1) Son Numero \n2) Son Nom \n";
        do{
            std::cout <<"(1/2) ?";
            std::cin >> n;
        }while(n != 1 && n != 2);
        Client cl;
        if(n==1){
            std::cout << "N°client :";
            std::cin >> num;
            etat = cl.rechercheClient(num);
        }
        else{
            std::cout << "Nom :";
            std::cin >> nom;
            etat = cl.recherche2Client(nom);
        }
        if(etat != 0 && n==1) std::cout << "Le client N°"<<num << " est present.\n";
        if(etat != 0 && n==2) std::cout << "le client "<<nom << " est present\n";
        if(etat == 0) std::cout << "Client absent\n";
        //std::cout << etat <<"\n";
        do{
            std::cout<<"\nvoulez-vous rechercher un autre client ?(O/N)";
            std::cin >> t;
        }while(t != 'o' && t != 'O' && t != 'N' && t != 'n');
    }while(t == 'o' || t == 'O');
    
}



/**************************** Suppression du client ****************************/

void suppression_client(){
    std::string n;
    int i=0;
    std::cout << "\t\t\t Bienvenue dans la section de suppression du client !!! \t\t\t" 
              << std::endl;
    char t = ' ';
    do{
        std::cout <<'\n';
        std::cout << "N°client :";
        std::cin >> n;
        Client cl;
        i = cl.suppClient(n);
        if(i==0) std::cout << "\nLe client que vous voulez supprimer est absent\n";
        else std::cout << "\nLe client N°"<< n << " a ete suppimer avec succes !!!\n"; 

        do{
            std::cout << "Voulez-vous supprimer un autre client ?(O/N)";
            std::cin >> t;
        }while(t != 'o' && t != 'O' && t != 'N' && t != 'n');
    }while(t == 'o' || t == 'O');
}

/*********************** Modification du client ************************************/
/**
void modification_client(){
    char t;
    do{
    Client cl;
    std::string n;
    int i;
    std::cout << "\t\t\t Bienvenue dans la section de modification du client !!! \t\t\t" 
              << std::endl;
    std::cout <<'\n';
    std::cout <<"N°client :";
    std::cin >> n;
    int j = cl.rechercheClient(n);
    if(j==0){
        std::cout << "Le client N°"<< n << " n'est pas enregistre !!!" << std::endl;
        do{
            std::cout << "Voulez-vous l'enregistrer ?(O/N)";
            std::cin >> t;
        }while(t != 'o' && t != 'O' && t != 'N' && t != 'n');
        if(t == 'o' || t == 'O'){
            enregistrement_client();
        }
        else {
            std::cout << "Enregistrement annule !!!\n";
        }
    }
    else{
        
        std::cout <<"t\t\t\tInformation sur le client :\n\n";
        cl.afficheClient(n,j);
        
        //Menu 
        
        std::cout << "Entrer les nouveles informations :\n";
        std::string nom,prenom,date_naiss;
        char genre;
        int etat;
        std::cout << "Client N°" << n << std::endl;
        std::cout << "Nom :";
        std::cin >> nom;
        std::cout << "Prenom :";
        std::cin >> prenom;
        std::cout << "Date de naissance(JJ/MM/AAAA) :";
        std::cin >> date_naiss;
        do{
            std::cout << "Genre(M/F) :";
            std::cin >> genre;
        }while(genre != 'M' && genre != 'F' && genre != 'm' && genre != 'f' );
        
        if(genre == 'M' || genre == 'm'){
            etat = cl.modifClient(j,n,nom,prenom,date_naiss,M);
        }
        else {
            etat = cl.modifClient(j,n,nom,prenom,date_naiss,F);
        }
        if(etat) std::cout <<"\nModification effectuer avec success !!!\n";
        do{
            std::cout << "Voulez-vous modifier un autre client ?(O/N)";
            std::cin >> t;
        }while(t != 'o' && t != 'O' && t != 'N' && t != 'n');
}
    }while(t == 'o' || t == 'O');
        
}

 * **/
