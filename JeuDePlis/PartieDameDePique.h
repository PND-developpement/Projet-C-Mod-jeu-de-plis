<<<<<<< HEAD
#ifndef _PARTIE_DAME_DE_PIQUE_H__
#define _PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "JeuDeCartes.h"
#include <memory>
#include <vector>
#include <string>
=======
#ifndef _C_PARTIE_DAME_DE_PIQUE_H__
#define _C_PARTIE_DAME_DE_PIQUE_H__

#include "Partie.h"
#include "JeuDeCarte.h"
#include <memory>
>>>>>>> d9376c345bdeba0df2ef8ff52b9078a5bf11f28c

class PartieDameDePique : public Partie
{
private:
<<<<<<< HEAD
    std::unique_ptr<JeuDeCartes> pLeJeu;
    std::vector<std::string> vNomsJoueurs;
=======
    //la partie possède et gère son propre paquet de cartes
    std::unique_ptr<JeuDeCarte> pLeJeu;
>>>>>>> d9376c345bdeba0df2ef8ff52b9078a5bf11f28c

public:
    PartieDameDePique();
    ~PartieDameDePique() = default;

<<<<<<< HEAD
    void AfficherRegles() const;
    void InitialiserLaPartie();
    void DistribuerCartes();
    void LancerPartie();
};

#endif
=======
    void InitialiserLaPartie();
};

#endif
>>>>>>> d9376c345bdeba0df2ef8ff52b9078a5bf11f28c
