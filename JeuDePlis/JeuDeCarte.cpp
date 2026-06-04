#include "JeuDeCartes.h"
#include <iostream>

JeuDeCartes::JeuDeCartes()
{
    pEnsembleCartes = std::make_unique<EnsembleDeCartes>();
}

std::unique_ptr<JeuDeCartes> JeuDeCartes::CreerJeuSurMesure(
    const std::vector<std::string>& vFigures,
    const std::vector<std::string>& vValeurs,
    unsigned int uiNbJokers)
{
    try
    {
        std::unique_ptr<JeuDeCartes> pNouveauJeu(new JeuDeCartes());

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
                std::shared_ptr<Carte> pCarte = std::make_shared<Carte>(valeur, figure, couleurPhysique);
                pNouveauJeu->pEnsembleCartes->AjouterCarte(pCarte);
            }
        }

        for (unsigned int i = 0; i < uiNbJokers; ++i)
        {
            //le joker a des caractéristiques spécifiques
            std::shared_ptr<Carte> pJoker = std::make_shared<Carte>("Joker", "Aucune", "NoirEtBlanc");
            pNouveauJeu->pEnsembleCartes->AjouterCarte(pJoker);
        }

        return pNouveauJeu;
    }
    catch (const std::exception& erreur)
    {
        std::cerr << "Erreur generation jeu : " << erreur.what() << std::endl;
        return nullptr;
    }
}

EnsembleDeCartes* JeuDeCartes::ObtenirEnsemble() const
{
    return pEnsembleCartes.get();
}