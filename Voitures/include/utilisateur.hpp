#ifndef utilisateur_hpp
#define utilisateur_hpp

#include <string>

class Utilisateur {
    public : 
    Utilisateur(const std::string& email, const std::string& nom_utilisateur, const std::string& mdp);
     
    std::string GetEmail () const; //getter
    std::string GetUserName ()const; //getter

    void ChangeEmail (const std::string& new_email); //setter

    void ChangeMDP (const std::string& new_MDP); //setter
    
    bool CheckMDP (const std::string& mdp_test) const;

    private : 
    std::string email, nom_utilisateur, mdp;

};

#endif