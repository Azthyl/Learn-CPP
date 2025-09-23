#ifndef UserManager_hpp
#define UserManager_hpp

#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include "utilisateur.hpp"

std::string LowerName(const std::string& name);

class UserManager{
    public : 
    bool AddUser(const std::string& email, const std::string& nom_utilisateur, const std::string& mdp);
    void AllUserList()const;
    std::string ConnectUser(const std::string& nom_utilisateur, const std::string& mdp);
    bool DeleteUser(const std::string& mdp_test);
    bool ChangeEmail (const std::string& mdp_test, const std::string& new_email);
    bool ChangeMDP (const std::string& mdp_test, const std::string& new_mdp);
    void Deconnect();

    private : 
        std::vector<Utilisateur> Users;
        std::string user_default = "";
};

#endif