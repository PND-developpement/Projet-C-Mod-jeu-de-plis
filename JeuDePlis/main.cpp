#include "Partie.h"
#include "PartieFactory.h"
#include "Interface.h"
#include <iostream>
#include <exception>
using namespace std;
int main()
{
    try {
        //exemple initalisation d'un jeux
        PartieFactory jeux;
        auto partie = jeux.create(1);

        if (partie) {
            cout << "partie ok";
            Interface interface;
            partie->JouerPartie(interface);
        }
        else {
            cout << "Aucune partie trouvee";
        }
    }
    catch(exception erreur){
        cout << "Erreur : " << erreur.what() << endl;
    }
    //Erreur : invalid vector subscript
    
}