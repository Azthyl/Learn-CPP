#include "UserManager.hpp"
#include "utilisateur.hpp"
#include "PasswordHasher.hpp"
#include <iostream>

using namespace std;

int main (){

    

    int choix, choix2;
    bool quit = false, quit2 = false;
    string email, nom_utilisateur, mdp;
    UserManager UserStore;

    while (!quit){
        cout<<"1. Créer un nouvel utilisateur\n";
        cout<<"2. Se connecter\n";
        cout<<"3. Lister tous les utilisateurs\n";
        cout<<"4. Quitter\n";
        cin>>choix;

        switch (choix){
            case 1:{
                cout<<"adresse mail : \n";
                cin>> email;
                cout<<"nom d'utilisateur : \n";
                cin>> nom_utilisateur;
                cout<<"mot de passe : \n";
                cin>> mdp;
                UserStore.AddUser(email, nom_utilisateur, mdp);
                break;
            }

            case 2: {
                cout<<"nom d'utilisateur : \n";
                cin>> nom_utilisateur;
                cout<<"mot de passe : \n";
                cin>>mdp;
                if (!UserStore.ConnectUser(nom_utilisateur, mdp).empty()){
                    quit2 = false;
                    while (!quit2){
                        cout<<"1. Changer d'adresse mail\n";
                        cout<<"2. Changer de mot de passe\n";
                        cout<<"3. Supprimer utilisateur\n";
                        cout<<"4. Se deconnecter\n";
                        cin>>choix2;

                        switch (choix2){
                            case 1: {
                                    string mdp_test, new_email;
                                    cout<<"Mot de passe actuel : "<<endl;
                                    cin>>mdp_test; 
                                    cout<<"Nouveau mail : "<<endl;
                                    cin>>new_email;
                                    UserStore.ChangeEmail(mdp_test, new_email);                           
                                    break;}

                            case 2: {
                                string mdp_test, new_MDP;
                                cout<<"Mot de passe actuel : "<<endl;
                                cin>>mdp_test;
                                cout<<"Nouveau mot de passe : "<<endl;
                                cin>>new_MDP;
                                UserStore.ChangeMDP(mdp_test, new_MDP);
                                break;}

                             case 3 :{
                                cout<<"mot de passe : \n";
                                cin>>mdp;
                                bool deleted = UserStore.DeleteUser(mdp);
                                if (deleted){
                                    UserStore.Deconnect();
                                    quit2 = true;}
                                
                                break;
                            }

                            case 4 : { 
                                UserStore.Deconnect();
                                quit2 = true;
                                break;
                            }
                                
                        }
                    }
                }
                break;
            }
           
            case 3 : 
                UserStore.AllUserList();
                break;

            case 4 :{
                quit = true;
                break;
            }    
    }
}   
return 0;
};