#include "JeuDeCartesDameDePique.h"
#include <iostream>
#include <memory>
#include "EnsembleDeCartes.h"
#include "CarteInterface.h"
#include "CartePenalite.h"
#include "CarteAtout.h"
#include "Carte.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

JeuDeCartesDameDePique::JeuDeCartesDameDePique()
{
    taille = 0;
    pEnsembleCartes = std::make_unique<EnsembleDeCartes>();

}

void JeuDeCartesDameDePique::CreerJeux(const std::vector<std::string>& vFigures, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers) 
{
    for (const auto& figure : vFigures)
    {
        //on déduit la couleur (rouge ou noir) grâce à la figure
        std::string couleurPhysique = "Noir";
        if (figure == "Coeur" || figure == "Carreau") {
            couleurPhysique = "Rouge";
        }

        for (const auto& valeur : vValeurs)
        {
            //on passe les 3 caractéristiques au constructeur de carte  
            shared_ptr<CarteInterface> pCarte;
            if (figure == "Coeur")
                pCarte = make_shared<CartePenalite>(make_shared<Carte>(valeur, figure, couleurPhysique),1);
            else if(figure == "Pique" && valeur == "Dame") 
                pCarte = make_shared<CartePenalite>(make_shared<Carte>(valeur, figure, couleurPhysique), 13);
            else
                pCarte = std::make_shared<Carte>(valeur, figure, couleurPhysique);
            
            pEnsembleCartes->AjouterCarte(pCarte);
        }
    }

    for (unsigned int i = 0; i < uiNbJokers; ++i)
    {
        //le joker a des caractéristiques spécifiques
        std::shared_ptr<CarteInterface> pJoker = std::make_shared<Carte>("Joker", "Aucune", "NoirEtBlanc");
        pEnsembleCartes->AjouterCarte(pJoker);
    }
}

EnsembleDeCartes* JeuDeCartesDameDePique::ObtenirEnsemble() const
{
    return pEnsembleCartes.get();
}

void JeuDeCartesDameDePique::MelangeCarte() const {
    pEnsembleCartes->MelangeAleatoireCarte();
}


int JeuDeCartesDameDePique::ScoreCarte(const std::shared_ptr<CarteInterface>& carte) const
{
    //On créeait notre table de correspondance pour chaque carte. 
    //Variable statique pour éviter de la reconstruire à chaque appelle étant donné que le score des cartes seront toujours les mêmes
    static const std::unordered_map<string, int> valeurCarte = {
        {"as", 1}, {"deux", 2}, {"trois", 3}, {"quatre", 4}, {"cinq", 5}, {"six", 6}, {"sept", 7}, {"huit", 8}, {"neuf", 9}, {"dix", 10}, {"vallet", 11}, {"dame", 12}, {"roi", 13}
    };

    //On cherche la valeur de la carte dans notre map
    auto valeurDeLaCarte = valeurCarte.find(carte->ObtenirValeur());

    //Si on la trouve on renvoie so, score associé 
    if (valeurDeLaCarte != valeurCarte.end())
        return valeurDeLaCarte->second;

    //sinon on renvoie 0
    return 0;
}
