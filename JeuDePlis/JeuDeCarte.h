#ifndef _JEU_DE_CARTE_H__
#define _JEU_DE_CARTE_H__

#include <vector>
#include <string>
#include <memory>

#include "EnsembleDeCartes.h"
#include "Carte.h"

class JeuDeCartes
{
protected: //protected car classe mère des jeux de cartes
    std::unique_ptr<EnsembleDeCartes> pEnsembleCartes; //ensemble de carte du jeu de carte
    size_t taille; //taille du jeu de carte
public: 
    // - - - Destructeur - - -
    ~JeuDeCartes() = default;

    // - - - accesseur - - -
    /*
    * définit la taille du vecteur
    * @param taille : size_t
    */
    virtual void DefinirTaille(size_t taille) = 0; 

    /*
    * renvoie la taille du vecteur
    * @return size_t
    */
    virtual size_t ObtenirTaille() const = 0;

    /*
    * renvoie l'ensemble de carte du jeu de carte
    * @return pointeur d'ensemble de cartes
    */
    virtual EnsembleDeCartes* ObtenirEnsemble() const = 0;

    // - - - Méthodes - - - 
    // On utilise vFigures (Pique, Coeur, Carreau et Trefle) et vValeurs (As, 10, etc)
    /*
    * permet de créer un jeu de carte selon les figures de la crate ainsi que les valeurs
    * @param vFigures : std::vector<std::string>, référence const
    * @param vValeurs : std::vector<std::string>, référence const
    * @param uiNbJokers : unsigned int
    */
    virtual void CreerJeux(const std::vector<std::string>& vFigures, const std::vector<std::string>& vValeurs, unsigned int uiNbJokers = 0) = 0;

    /*
    * mélange le jeu de carte
    */
    virtual void MelangeCarte() const = 0;

    /*
    * prend une carte en paramètre, et lui associe sa valeur de la carte selon le jeu.
    * @param carte : std::shared_ptr<CarteInterface>, référence const
    * @return int
    */
    virtual int ScoreCarte(const std::shared_ptr<CarteInterface>& carte) const = 0;
};

#endif