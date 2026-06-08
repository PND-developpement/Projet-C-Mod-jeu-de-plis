#ifndef H_JDCDP_H
#include "JeuDeCarte.h"
#include "EnsembleDeCartes.h"
#include <string>
#include <vector>

class JeuDeCartesDameDePique : public JeuDeCartes{
public:
    JeuDeCartesDameDePique();
    ~JeuDeCartesDameDePique() = default;
    void SetTaille(size_t taille) { this->taille = taille; pEnsembleCartes->SetTaille(taille); }
    size_t GetTaille() const { return taille; }

    // On utilise vFigures (Pique, Coeur, Carreau et Trefle) et vValeurs (As, 10, etc)
    void CreerJeux(const std::vector<std::string>& vFigures, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers = 0);
    EnsembleDeCartes* ObtenirEnsemble() const;
    void MelangeCarte() const;
    int ScoreCarte(const std::shared_ptr<CarteInterface>& carte) const override;
};

#endif 