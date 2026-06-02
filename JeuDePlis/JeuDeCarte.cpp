#include "JeuDeCarte.h"
#include <iostream>

JeuDeCarte::JeuDeCarte()
{
    pEnsembleCartes = std::make_unique<EnsembleDeCartes>();
}

std::unique_ptr<JeuDeCarte> JeuDeCarte::CreerJeuSurMesure(
    const std::vector<std::string>& vCouleurs,
    const std::vector<std::string>& vValeurs,
    unsigned int uiNbJokers)
{
    try
    {
        std::unique_ptr<JeuDeCarte> pNouveauJeu(new JeuDeCarte());

        for (const auto& couleur : vCouleurs)
        {
            for (const auto& valeur : vValeurs)
            {
                // Allocation partagée : la carte pourra exister simultanément 
                // dans le paquet, dans la main d'un joueur, et sur un pli.
                std::shared_ptr<Carte> pCarte = std::make_shared<Carte>(valeur, couleur);
                pNouveauJeu->pEnsembleCartes->AjouterCarte(pCarte);
            }
        }

        for (unsigned int i = 0; i < uiNbJokers; ++i)
        {
            std::shared_ptr<Carte> pJoker = std::make_shared<Carte>("Joker", "Aucune");
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

EnsembleDeCartes* JeuDeCarte::ObtenirEnsemble() const
{
    return pEnsembleCartes.get();
}