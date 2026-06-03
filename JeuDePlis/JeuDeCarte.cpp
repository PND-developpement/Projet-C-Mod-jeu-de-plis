#include "JeuDeCarte.h"
#include <iostream>

JeuDeCarte::JeuDeCarte()
{
    pEnsembleCartes = std::make_unique<EnsembleDeCartes>();
}

std::unique_ptr<JeuDeCarte> JeuDeCarte::CreerJeuSurMesure(const std::vector<std::string>& vCouleurs, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers)
{
    std::vector<std::string>::const_iterator itCouleur;
    std::vector<std::string>::const_iterator itValeur;


    try
    {
        std::unique_ptr<JeuDeCarte> pNouveauJeu(new JeuDeCarte());

        for (itCouleur = vCouleurs.begin(); itCouleur != vCouleurs.end(); itCouleur++)
        {
            for (itValeur = vValeurs.begin(); itValeur != vValeurs.end(); itValeur++)
            {
                // Allocation partagée : la carte pourra exister simultanément 
                // dans le paquet, dans la main d'un joueur, et sur un pli. 
                std::shared_ptr<Carte> pCarte = std::make_shared<Carte>(itValeur, itCouleur);
                pNouveauJeu->pEnsembleCartes->ajouterCarte(pCarte);
            }
        }

        for (unsigned int i = 0; i < uiNbJokers; ++i)
        {
            std::shared_ptr<Carte> pJoker = std::make_shared<Carte>("Joker", "Aucune");
            pNouveauJeu->pEnsembleCartes->ajouterCarte(pJoker);
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