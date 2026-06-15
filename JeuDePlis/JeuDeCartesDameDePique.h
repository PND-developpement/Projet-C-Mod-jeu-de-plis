#ifndef H_JDCDP_H
#include "JeuDeCarte.h"
#include "EnsembleDeCartes.h"
#include <string>
#include <vector>

class JeuDeCartesDameDePique : public JeuDeCartes
{
public:
    // - - - Constructeur et destructeur - - -
    JeuDeCartesDameDePique();
    ~JeuDeCartesDameDePique() = default;

    // - - - Accesseurs - - - 
    /*
    * place la nouvelle valeur de taille et change la taille de l'ensemble de carte
    * @param taille : size_t
    */
    void DefinirTaille(size_t taille) override { this->taille = taille; pEnsembleCartes->DefinirTaille(taille); }

    /*
    * renvoie l'attribut taille
    * @return size_t
    */
    size_t ObtenirTaille() const override { return taille; }

    // On utilise vFigures (Pique, Coeur, Carreau et Trefle) et vValeurs (As, 10, etc)
    void CreerJeux(const std::vector<std::string>& vFigures, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers = 0) override;

    /*
    * permet de récupérer l'ensemble de carte avec son getter
    * @return EnsembleDeCarte
    */
    EnsembleDeCartes* ObtenirEnsemble() const override;

    // - - - Methodes - - - 
    /*
    * permet de mélanger les carte de notre ensemble de carte
    */
    void MelangeCarte() const override;

    /*
    * Renvoie le score de la carte associé à sa valeur
    * @param carte : std::shared_ptr<CarteInterface>&, const
    * @return int
    */
    int ScoreCarte(const std::shared_ptr<CarteInterface>& carte) const override;
};

#endif 