#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string LowerName(const string& name){
    string output = name;
    transform(output.begin(), output.end(), output.begin(), [](unsigned char c) {return tolower(c);});
        return output;
    }

class Utilisateur {
    public : 
    Utilisateur(const string& email, const string& nom_utilisateur, const string& mdp)
     : email(email), nom_utilisateur(nom_utilisateur), mdp(mdp) {};

    string GetEmail () const {return email;} //getter
    string GetUserName () const {return nom_utilisateur;} //getter

    void ChangeEmail (const string& new_email) { //setter
            email = new_email;
        }

    void ChangeMDP (const string& new_MDP) { //setter
            mdp = new_MDP;
        }
    
    bool CheckMDP (const string& mdp_test) const{
        if (mdp_test != mdp ) {
            return false;
    }
    else return true;
};

    private : 
    string email, nom_utilisateur, mdp;

};

class UserManager{
    public :
    bool AddUser(const string& email, const string& nom_utilisateur, const string& mdp){
        for (auto& elem : Users){
            if (LowerName(nom_utilisateur) == LowerName(elem.GetUserName())){
                cout<<"utilisateur déjà créé"<<endl; 
                return false;}
        }
        Users.push_back(Utilisateur(email, nom_utilisateur, mdp));
        cout<<"Utilisateur créé"<<endl;
        return true;
    }

    void AllUserList()const {
        cout<<"liste de tous les utilisateurs : \n";
        if (Users.size() == 0) cout<<"aucun utilisateur enregistré"<<endl;
        else {for (const auto &elem : Users){
            cout<<elem.GetUserName()<<" \n"<<endl;
        }}
        
    }

    string ConnectUser(const string& nom_utilisateur, const string& mdp){
        for (const auto &elem : Users){
            if (LowerName(nom_utilisateur) == LowerName(elem.GetUserName())){
                if (elem.CheckMDP(mdp)){
                cout<<"connecté au compte de "<<elem.GetUserName()<<endl;
                return nom_utilisateur;}
                else { cout<<"mot de passe incorrect\n";return user_default;}
            }
        }
        cout<<"aucun utilisateur trouvé"<<endl;
        return user_default;
    }

    bool DeleteUser(const string& nom_utilisateur, const string& mdp_test){
        for (size_t n = 0; n< Users.size(); n ++){
            if (LowerName(nom_utilisateur) == LowerName(Users[n].GetUserName())){
                if (Users[n].CheckMDP(mdp_test)){
                Users.erase(Users.begin() + n);
                cout<<"utilisateur supprimé"<<endl;
                return true;
                } else {cout<<"mot de passe incorrect"<<endl;return false;}
            }
    }
    cout<<"aucun utilisateur trouvé"<<endl;
    return false;
}    

bool ChangeEmail (const string& nom_utilisateur, const string& mdp_test, const string& new_email) { //setter
        for (auto &u : Users){
            if (LowerName(nom_utilisateur) == LowerName(u.GetUserName())){
                if (u.CheckMDP(mdp_test)){
                    u.ChangeEmail(new_email);
                    cout<<"email modifié avec succès"<<endl;
                    return true;
        }
        else { cout <<"mauvais mot de passe"<<endl; return false;}
    }
}cout <<"Utilisateur pas trouvé"<<endl; return false;
}
    bool ChangeMDP (const string& nom_utilisateur, const string& mdp_test, const string& new_mdp) { //setter
        for (auto &u : Users){
            if (LowerName(nom_utilisateur) == LowerName(u.GetUserName())){
                if (u.CheckMDP(mdp_test)){
                    u.ChangeMDP(new_mdp);
                    cout<<"mot de passe modifié avec succès"<<endl;
                    return true;
        }
                else { cout <<"mauvais mot de passe"<<endl; return false;}
    }
}cout <<"Utilisateur pas trouvé"<<endl; return false;
}

void Deconnect(){
                    user_default = "";
                    cout<<"Vous êtes déconnecté"<<endl;
}



    private : 
    vector<Utilisateur> Users;
    string user_default = "";
};

int main (){

    int choix, choix2;
    bool quit = false, quit2 = false;
    string email, nom_utilisateur, mdp, CurrentUser;
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
                CurrentUser = UserStore.ConnectUser(nom_utilisateur, mdp);
                if (!CurrentUser.empty()){
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
                                    UserStore.ChangeEmail(CurrentUser,mdp_test, new_email);                           
                                    break;}

                            case 2: {
                                string mdp_test, new_MDP;
                                cout<<"Mot de passe actuel : "<<endl;
                                cin>>mdp_test;
                                cout<<"Nouveau mot de passe : "<<endl;
                                cin>>new_MDP;
                                UserStore.ChangeMDP(CurrentUser, mdp_test, new_MDP);
                                break;}

                             case 3 :{
                                cout<<"mot de passe : \n";
                                cin>>mdp;
                                bool deleted = UserStore.DeleteUser(CurrentUser, mdp);
                                if (deleted){
                                    CurrentUser = "";
                                    cout << "Vous avez été déconnecté car le compte a été supprimé.\n";
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