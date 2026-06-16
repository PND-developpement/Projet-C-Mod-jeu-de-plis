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