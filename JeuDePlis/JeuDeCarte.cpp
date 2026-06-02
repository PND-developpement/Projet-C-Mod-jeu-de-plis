#include "CJeuDeCartes.h"
#include <iostream>

CJeuDeCartes::CJeuDeCartes()
{
    pEnsembleCartes = std::make_unique<CEnsembleDeCartes>();
}

std::unique_ptr<CJeuDeCartes> CJeuDeCartes::CreerJeuSurMesure(
    const std::vector<std::string>& vCouleurs,
    const std::vector<std::string>& vValeurs,
    unsigned int uiNbJokers)
{
    try
    {
        std::unique_ptr<CJeuDeCartes> pNouveauJeu(new CJeuDeCartes());

        for (const auto& couleur : vCouleurs)
        {
            for (const auto& valeur : vValeurs)
            {
                // Allocation partagée : la carte pourra exister simultanément 
                // dans le paquet, dans la main d'un joueur, et sur un pli.
                std::shared_ptr<CCarte> pCarte = std::make_shared<CCarte>(valeur, couleur);
                pNouveauJeu->pEnsembleCartes->AjouterCarte(pCarte);
            }
        }

        for (unsigned int i = 0; i < uiNbJokers; ++i)
        {
            std::shared_ptr<CCarte> pJoker = std::make_shared<CCarte>("Joker", "Aucune");
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

CEnsembleDeCartes* CJeuDeCartes::ObtenirEnsemble() const
{
    return pEnsembleCartes.get();
}