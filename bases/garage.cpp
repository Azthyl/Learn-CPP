#include <iostream>
#include <tuple>
#include <vector>
#include <string>


// dans un garage on peut avoir différents types de véhicules {camion, voiture, bateau, avion, moto} avec un nombre de 
// véhicules et une localisation
// Dans un ensemble de véhicule, on le compose par plusiuers véhicule donc un véhicule a nb roues, poids, couleur
// Un utilisateur va demander je veux un camion bleu a bordeaux -> on en a pas ( bleu -> toulouse ou rouge a bordeaux)
// Utilisateur et veudeur
using namespace std;

struct Flotte {
    string type;
    int nombre;
};

class Garage {
    public : 
    Garage(){
        cout<<"le garage est construit"<<endl;};

    ~Garage(){
        cout<<"la flotte est détruite"<<endl;
    };


    void ajout(){
        Flotte f;
        cout<<"type de flotte ? "<<endl;
        cin>>f.type;
        cout<<"nombre de véhicules ? "<<endl;
        cin>>f.nombre;
        flotte.push_back({f.type, f.nombre});
        cout<<"la flotte "<<f.type<<" est créee avec "<<f.nombre<<" véhicules"<<endl;
    }

    void FlotteGetter(){
        if (flotte.empty()){
            cout<<"vous n'avez pas de flotte"<<endl;
                return;
    }
    for(const auto &elem : flotte){
            cout<<"type : "<<elem.type<<" | nombre : "<<elem.nombre<<endl;
        }
    }

    bool disponible (int nb_acheteur, string type_acheteur){
        for (const auto &elem : flotte){
            if (type_acheteur == elem.type && nb_acheteur <= elem.nombre) return true;
        }
        return false;
    }

    void remove(int nb_acheteur, string type_acheteur){
        for (auto &elem : flotte){
             if (type_acheteur == elem.type){
                if (nb_acheteur <= elem.nombre) {
                     elem.nombre = elem.nombre - nb_acheteur;
        cout<<"il reste "<<elem.nombre<<" "<<elem.type<<endl;
                }    
    }
        }
    }

    private:
    
    vector<Flotte> flotte;

};

int main (){
    int choix, choix2, nb_acheteur;
    vector<tuple<string, int>> actuelle_flotte;
    string type_acheteur;
    bool quit = false;
    Garage Garage_A;

    while (!quit) {
        cout<<"1. Vendeur\n";
        cout<<"2. Acheteur\n";

        cin>>choix;

    switch (choix){
        case 1 : 
        cout<<"1. créer une flotte\n";
        cout<<"2. consulter la base de donnée\n";
        cin>>choix2;
        switch(choix2){
            case 1 : 
                Garage_A.ajout();
                break;

            case 2 : 
            Garage_A.FlotteGetter();
            break;
        }
        break;
        case 2 : {
        cout<<"quel type de véhicule et combien ? (ex 5 voitures)\n";
        cin>>nb_acheteur>>type_acheteur;
        cout<<"vous voulez acheter "<<nb_acheteur<<" "<<type_acheteur<<endl;
        if (Garage_A.disponible(nb_acheteur, type_acheteur)) {
            cout<< "votre demande est disponible"<<endl;
            Garage_A.remove(nb_acheteur, type_acheteur);
        }
        else cout<<"ce n'est pas possible"<<endl;
        break;
        }
        


        }
    }
}