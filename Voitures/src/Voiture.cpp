#include <iostream>
#include <cstring>

using namespace std;

class Voitures {
    public:
    Voitures(string initMarque, unsigned int initVitesse = 0){
        Marque = initMarque;
        Vitesse = initVitesse;
        cout<<"création de la voiture : "<<Marque<<endl;
    }
    ~Voitures(){
        cout<<"la voiture est détruite";
    }
    void accelerer(unsigned int acceleration){
        Vitesse += acceleration;
        cout<<"acceleration de "<<acceleration;
    }
    void ralentir(unsigned int deceleration){
        if (Vitesse > deceleration)
        Vitesse -= deceleration;
        cout<<"deceleration de "<<deceleration;
    }

    void afficher(){
        cout<<"Voiture "<<Marque<<" : Vitesse "<<Vitesse<<" km/h"<<endl;
    }
    


    private:
    string Marque;
    unsigned int Vitesse;
};

main(){


    int choix;
    string marque;
    bool rouler = true;
    Voitures *maVoiture = nullptr;

    while (rouler) { 
    cout<<"que voulez vous faire ?\n";
    cout<<"1. Créer votre voiture\n";
    cout<<"2. Accélérer\n";
    cout<<"3. Décélérer\n";
    cout<<"4. quitter"<<endl;


    cin>>choix;

    switch(choix)
    {
        case 1 : 
        cout<<"quelle marque ?"<<endl;
        cin>>marque;
        maVoiture = new Voitures(marque);
        break;

        case 2 : 
        if (!maVoiture) {
                    cout << "Aucune voiture créée — choisissez l'option 1 d'abord." << endl;
                    break;
                }
            unsigned int acceleration;
            cout<<"de combien voulez-vous accélérer ?"<<endl;
            cin>>acceleration;
            maVoiture->accelerer(acceleration);
            maVoiture->afficher();
            break;

        case 3 : 
        if (!maVoiture) {
                    cout << "Aucune voiture créée — choisissez l'option 1 d'abord." << endl;
                    break;
                }
            unsigned int deceleration;
            cout<<"de combien voulez-vous ralentir ?\n"<<endl;
            cin>>deceleration;
            maVoiture->ralentir(deceleration);
            maVoiture->afficher();
            break;

        case 4 : 
        rouler = false;

    if (maVoiture) {delete maVoiture; maVoiture = nullptr;}
    break;

    }
}
}
