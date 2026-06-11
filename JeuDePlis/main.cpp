#include "Partie.h"
#include "PartieFactory.h"
#include "Interface.h"
#include <iostream>
#include <exception>


/*
* bloquer le joueur, la carte est du carreau (par ex.), si le joueur a du carreau, il doit alors jouer du carreau, sinon il jouer ce qu'il veut
* donner 3 cartes à son adversaire (1-2, 2-3, .., 4-1)
* améliorer l'interface 
* fonction interface qui demande le score max de la partie
* vérifier le score (ne dépasse pas le score entré au début de partie)
* 
* 
* Sofian : 
* PlisDameDepique
* Plis
* override
*/





using namespace std;
int main()
{
    try {
        //exemple initalisation d'un jeux
        Interface interface;
        PartieFactory jeux;
        auto partie = jeux.create(interface.DemanderJeux());
        

        if (partie) {
            
            
            partie->JouerPartie(interface);
        }
        else {
            cout << "Aucune partie trouvee";
        }
    }
    catch(exception erreur){
        cout << "Erreur : " << erreur.what() << endl;
    }
    
    
}