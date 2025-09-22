#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Utilisateur {
    public : 
    Utilisateur(const string& email, const string& nom_utilisateur, const string& mdp)
     : email(email), nom_utilisateur(nom_utilisateur), mdp(mdp) {};

    string GetEmail () const {return email;} //getter
    string GetUserName () const {return nom_utilisateur;} //getter

    void ChangeEmail (const string& new_email) { //setter
            email = new_email;
            cout<<"email changé"<<endl;
        }

    void ChangeMDP (const string& new_MDP) { //setter
            mdp = new_MDP;
            cout<<"Mot de passe changé"<<endl;
            
        }
    
    bool CheckMDP (const string& mdp_test) const{
        if (mdp_test != mdp ) {
            cout<<"mauvais mot de passe"<<endl;
            return false;
    }
    else return true;
};

    private : 
    string email, nom_utilisateur, mdp;

};

class UserManager{
    public :
    void AddUser(const string& email, const string& nom_utilisateur, const string& mdp){
        Users.push_back(Utilisateur(email, nom_utilisateur, mdp));
        cout<<"Utilisateur créé"<<endl;
    }

    void AllUserList()const {
        cout<<"liste de tous les utilisateurs : \n";
        if (Users.size() == 0) cout<<"aucun utilisateur enregistré"<<endl;
        else {for (const auto &elem : Users){
            cout<<elem.GetUserName()<<" \n"<<endl;
        }}
        
    }

    bool ConnectUser(const string& nom_utilisateur, const string& mdp){
        for (const auto &elem : Users){
            if (nom_utilisateur == elem.GetUserName()){
                if (elem.CheckMDP(mdp)){
                cout<<"connecté au compte de "<<elem.GetUserName()<<endl;
                return true;}
                else { cout<<"mot de passe faux";return false;}
            }
        }
        cout<<"aucun utilisateur trouvé"<<endl;
        return false;
    }

    bool DeleteUser(const string& nom_utilisateur, const string& mdp_test){
        for (int n = 0; n< Users.size(); n ++){
            if (nom_utilisateur == Users[n].GetUserName()){
                if (Users[n].CheckMDP(mdp_test)){
                Users.erase(Users.begin() + n);
                cout<<"utilisateur supprimé"<<endl;
                return true;
                }
            }
    }
    cout<<"aucun utilisateur trouvé"<<endl;
    return false;
}    

bool ChangeEmail (const string& nom_utilisateur, const string& mdp_test, const string& new_email) { //setter
        for (auto &u : Users){
            if (nom_utilisateur == u.GetUserName()){
                if (u.CheckMDP(mdp_test)){
                    u.ChangeEmail(new_email);
                    return true;
        }
        else { cout <<"mauvais mot de passe"<<endl; return false;}
    }
}cout <<"Utilisateur pas trouvé"<<endl; return false;
}
    bool ChangeMDP (const string& nom_utilisateur, const string& mdp_test, const string& new_mdp) { //setter
        for (auto &u : Users){
            if (nom_utilisateur == u.GetUserName()){
                if (u.CheckMDP(mdp_test)){
                    u.ChangeMDP(new_mdp);
                    return true;
        }
                else { cout <<"mauvais mot de passe"<<endl; return false;}
    }
}cout <<"Utilisateur pas trouvé"<<endl; return false;
}

    private : 
    vector<Utilisateur> Users;
};

int main (){

    int choix;
    bool quit = false, connected = false;
    string email, nom_utilisateur, mdp;
    UserManager UserStore;

    while (!quit){
        cout<<"1. Créer un nouvel utilisateur\n";
        cout<<"2. Se connecter\n";
        cout<<"3. Changer d'adresse mail\n";
        cout<<"4. Changer de mot de passe\n";
        cout<<"5. Supprimer utilisateur\n";
        cout<<"6. Lister tous les utilisateurs\n";
        cout<<"7. Quitter\n";
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
                connected = UserStore.ConnectUser(nom_utilisateur, mdp);
                break;
            }
            case 3: {
                if (!connected){
                    cout<<"Vous n'êtes pas connecté\n";
                    break;
                }
            else {
                string mdp_test, new_email;
                cout<<"Nom d'utilisateur : "<<endl;
                cin>>nom_utilisateur; 
                cout<<"Mot de passe actuel : "<<endl;
                cin>>mdp_test; 
                cout<<"Nouveau mail : "<<endl;
                cin>>new_email;
                UserStore.ChangeEmail(nom_utilisateur,mdp_test, new_email);
                break;
        
            }break;}
            case 4: 
                if (!connected){
                    cout<<"Vous n'êtes pas connecté\n";
                    break;
            }
            else {
                string mdp_test, new_MDP;
                cout<<"Nom d'utilisateur : "<<endl;
                cin>>nom_utilisateur;
                cout<<"Mot de passe actuel : "<<endl;
                cin>>mdp_test;
                cout<<"Nouveau mot de passe : "<<endl;
                cin>>new_MDP;
                UserStore.ChangeMDP(nom_utilisateur, mdp_test, new_MDP);
                break;
            }
            

            case 5 :{
                cout<<"nom d'utilisateur : \n";
                cin>> nom_utilisateur;
                cout<<"mot de passe : \n";
                cin>>mdp;
                UserStore.DeleteUser(nom_utilisateur, mdp);
                break;
            }
           

            case 6 : 
                UserStore.AllUserList();
                break;

            case 7 :{
                quit = true;
                break;
            }    
    }
}   
return 0;
};