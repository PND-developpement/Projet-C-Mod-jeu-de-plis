//C'est ta classe CPartieDameDePique qui va contenir les listes
// de couleurs et de valeurs
// et qui va appeler CreerJeuSurMesure au moment de lancer la partie.

#ifndef _C_JEU_DE_CARTES_H__
#define _C_JEU_DE_CARTES_H__

#include "EnsembleDeCartes.h"
#include "Carte.h"

#include <vector>
#include <string>
#include <memory>


class JeuDeCarte
{
private:
    std::unique_ptr<EnsembleDeCartes> pEnsembleCartes;

public:
    JeuDeCarte();
    ~JeuDeCarte() = default;

    static std::unique_ptr<JeuDeCarte> CreerJeuSurMesure(const std::vector<std::string>& vCouleurs, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers = 0);

    EnsembleDeCartes* ObtenirEnsemble() const;
};

#endif