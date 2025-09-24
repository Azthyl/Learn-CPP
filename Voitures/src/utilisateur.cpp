#include "utilisateur.hpp"
#include "PasswordHasher.hpp"

using namespace std;


Utilisateur::Utilisateur(const string& email, const string& nom_utilisateur, const string& mdp)
    : email(email), nom_utilisateur(nom_utilisateur), hash(PasswordHasher::hash(mdp)) {};

string Utilisateur::GetEmail () const {return email;} //getter
string Utilisateur::GetUserName () const {return nom_utilisateur;} //getter

void Utilisateur::ChangeEmail (const string& new_email) { //setter
        email = new_email;
    }

void Utilisateur::ChangeMDP (const string& new_MDP) { //setter
        hash = PasswordHasher::hash(new_MDP);
    }

bool Utilisateur::CheckMDP (const string& mdp_test) const{
    if (!PasswordHasher::verify(hash, mdp_test)) {
        return false;
}
else return true;
}