#ifndef _JEU_DE_CARTES_H__
#define _JEU_DE_CARTES_H__

#include <vector>
#include <string>
#include <memory>

#include "EnsembleDeCartes.h"
#include "Carte.h"

class JeuDeCartes
{
protected:
    std::unique_ptr<EnsembleDeCartes> pEnsembleCartes;
    size_t taille;
public:
    ~JeuDeCartes() = default;

    virtual void SetTaille(size_t taille) = 0;
    virtual size_t GetTaille() const = 0;

    // On utilise vFigures (Pique, Coeur, Carreau et Trefle) et vValeurs (As, 10, etc)
    virtual void CreerJeux(const std::vector<std::string>& vFigures, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers = 0) = 0;
    virtual EnsembleDeCartes* ObtenirEnsemble() const = 0;
    virtual void MelangeCarte() const = 0;
    virtual int ScoreCarte(const std::shared_ptr<CarteInterface>& carte) const = 0;
};

#endif