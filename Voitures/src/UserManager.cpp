#include <iostream>
#include "utilisateur.hpp"
#include "UserManager.hpp"

using namespace std;

string LowerName(const string& name){
    string output = name;
    transform(output.begin(), output.end(), output.begin(), [](unsigned char c) {return tolower(c);});
        return output;
    }

    bool UserManager::AddUser(const string& email, const string& nom_utilisateur, const string& mdp){
        for (auto& elem : Users){
            if (LowerName(nom_utilisateur) == LowerName(elem.GetUserName())){
                cout<<"utilisateur déjà créé"<<endl; 
                return false;}
        }
        Users.push_back(Utilisateur(email, nom_utilisateur, mdp));
        cout<<"Utilisateur créé"<<endl;
        return true;
    }

    void UserManager::AllUserList()const {
        cout<<"liste de tous les utilisateurs : \n";
        if (Users.size() == 0) cout<<"aucun utilisateur enregistré"<<endl;
        else {for (const auto &elem : Users){
            cout<<elem.GetUserName()<<" \n"<<endl;
        }}
        
    }

    string UserManager::ConnectUser(const string& nom_utilisateur, const string& mdp){
        for (const auto &elem : Users){
            if (LowerName(nom_utilisateur) == LowerName(elem.GetUserName())){
                if (elem.CheckMDP(mdp)){
                cout<<"connecté au compte de "<<elem.GetUserName()<<endl;
                user_default = nom_utilisateur;
                return user_default;}
                else { cout<<"mot de passe incorrect\n";return user_default;}
            }
        }
        cout<<"aucun utilisateur trouvé"<<endl;
        return user_default;
    }

    bool UserManager::DeleteUser(const string& mdp_test){
        for (size_t n = 0; n< Users.size(); n ++){
            if (LowerName(user_default) == LowerName(Users[n].GetUserName())){
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

bool UserManager::ChangeEmail (const string& mdp_test, const string& new_email) { //setter
        for (auto &u : Users){
            if (LowerName(user_default) == LowerName(u.GetUserName())){
                if (u.CheckMDP(mdp_test)){
                    u.ChangeEmail(new_email);
                    cout<<"email modifié avec succès"<<endl;
                    return true;
        }
        else { cout <<"mauvais mot de passe"<<endl; return false;}
    }
}cout <<"Utilisateur pas trouvé"<<endl; return false;
}
    bool UserManager::ChangeMDP (const string& mdp_test, const string& new_mdp) { //setter
        for (auto &u : Users){
            if (LowerName(user_default) == LowerName(u.GetUserName())){
                if (u.CheckMDP(mdp_test)){
                    u.ChangeMDP(new_mdp);
                    cout<<"mot de passe modifié avec succès"<<endl;
                    return true;
        }
                else { cout <<"mauvais mot de passe"<<endl; return false;}
    }
}cout <<"Utilisateur pas trouvé"<<endl; return false;
}

void UserManager::Deconnect(){
                    user_default = "";
                    cout<<"Vous êtes déconnecté"<<endl;
}