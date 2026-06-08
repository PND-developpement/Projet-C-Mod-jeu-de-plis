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
using namespace std;

JeuDeCartesDameDePique::JeuDeCartesDameDePique()
{
    taille = 0;
    pEnsembleCartes = std::make_unique<EnsembleDeCartes>();

}

void JeuDeCartesDameDePique::CreerJeux(const std::vector<std::string>& vFigures, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers) {
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
            if (figure == "Coeur") {
                pCarte = make_shared<CarteAtout>(make_shared<Carte>(valeur, figure, couleurPhysique),1);
            }
            else{
                if (figure == "Pique" && valeur == "Dame") {
                    pCarte = make_shared<CarteAtout>(make_shared<Carte>(valeur, figure, couleurPhysique),13);
                }
                pCarte = std::make_shared<Carte>(valeur, figure, couleurPhysique);
            }
            
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
    switch(carte->GetValeur())
    {
        case 'as':
            return 1;
        
        case 'deux':
            return 2;

        case 'trois':
            return 3;

        case 'quatre':
            return 4;

        case 'cinq':
            return 5;

        case 'six':
            return 6;

        case 'sept':
            return 7;

        case 'huit':
            return 8;

        case 'neuf':
            return 9;

        case 'dix':
            return 10;

        case 'vallet':
            return 11;

        case 'dame':
            return 12;

        case 'roi':
            return 13;
    }
}
