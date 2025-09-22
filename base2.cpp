#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


void exo_1 (){
    vector<int> tab;
    int N, V;
    bool count = false;
    for (int i =0; i<5; i++){
        cout<<"choisissez un nombre dans le tabelau : ";
        cin>>N;
        tab.push_back(N);
    }
    cout<<"choisissez V : ";
    cin>>V;

    for (int n : tab){
        if (V == n) {
        cout<< "V appartient au tableau";
        count = true;}

    }
    if (!count) cout<<" V n'est pas dans le tabelau";    

}
void exo_3(){
    vector<int> tab;
    int N, V;
    bool count = false;
    for (int i =0; i<5; i++){
        cout<<"choisissez un nombre dans le tabelau : ";
        cin>>N;
        tab.push_back(N);
    }

    for (int i = 0; i<5;i++){
        if (tab[i]<tab[i+1]) V = tab[i];
    }
    cout<<"indice de la valeur la plus petite : "<<tab[V];
}

void exo_4(){
    bool end = false;
    int N = 5;
    int choix;
    vector<int>tab;
    int entier;
    string decision;
   

    while (end == false){
        cout<<"1. Choisissez un entier\n";
        cout<<"2. Afficher la liste\n";
        cout<<"3. Supprimer le dernier entier\n";
        cout<<"4. Supprimer l'entier de votre choix\n";
        cout<<"5. Sortir"<<endl;
        cout<<endl<<"votre choix : ";
        cin>>choix;

        switch (choix)
        {
        case 1:
         do{
            if (tab.size() >= N) {cout<<"le tableau est plein\n"; break;}
            cout<<"1. Choisissez un entier : \n";
            cin>>entier;
            tab.push_back(entier);
            cout<<"choisir un autre entier ? (yes/no)"<<endl;
            
            cin>>decision;
         }
            while (decision == "yes"); break;
            
        case 3:
        if (!tab.empty()) {tab.pop_back(); cout<<"Entier supprimé\n";}
        else cout<<"la liste est vide\n";
        
        case 2:
        cout<<"voici la liste des entiers : ";
        for (int n : tab){ cout<<n<<" ";}
        cout<<endl;
        break;

        case 4:
        cout<<"Sélectionnez l'entier à enlever : "<<endl;
        cin>>entier;
        if (find(tab.begin(), tab.end(), entier) != tab.end()) tab.erase(remove(tab.begin(), tab.end(), entier), tab.end());
        else cout<<"l'entier n'est pas dans la liste";
        break;
       

        case 5:
        end = true; 
        cout<<"FIN";
        break;
            }

    }
}

bool exo_5(string mot){
    cout<<mot;
}
main (){
    exo_4();

}

