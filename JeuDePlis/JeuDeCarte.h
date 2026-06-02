//C'est ta classe CPartieDameDePique qui va contenir les listes
// de couleurs et de valeurs
// et qui va appeler CreerJeuSurMesure au moment de lancer la partie.

#ifndef _C_JEU_DE_CARTES_H__
#define _C_JEU_DE_CARTES_H__

#include <vector>
#include <string>
#include <memory>

#include "CEnsembleDeCartes.h"
#include "CCarte.h"

class CJeuDeCartes
{
private:
    std::unique_ptr<CEnsembleDeCartes> pEnsembleCartes;

    CJeuDeCartes();

public:
    ~CJeuDeCartes() = default;

    static std::unique_ptr<CJeuDeCartes> CreerJeuSurMesure(
        const std::vector<std::string>& vCouleurs,
        const std::vector<std::string>& vValeurs,
        unsigned int uiNbJokers = 0);

    CEnsembleDeCartes* ObtenirEnsemble() const;
};

#endif