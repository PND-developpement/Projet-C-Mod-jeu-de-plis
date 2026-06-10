#include "PlisDameDePique.h"
#include "CarteInterface.h"
#include "JeuDeCartesDameDePique.h"
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> PlisDameDePique::verifPlis(unordered_map<unsigned int, shared_ptr<CarteInterface>> carteDuPlis, unsigned int positionPremierJoueur)
{
    vector<int> resultatPlis;
    int scoretotal = 0;
    int scoreBase = 0;
    unsigned int joueurGagnant = positionPremierJoueur;
    JeuDeCartesDameDePique jeuxDameScore;
    shared_ptr<CarteInterface> carteJoueur1 = carteDuPlis.at(positionPremierJoueur);
    bool memeCartes = false;
    for (auto deplacementCartesJ = carteDuPlis.begin(); deplacementCartesJ != carteDuPlis.end(); deplacementCartesJ++) {
        if (deplacementCartesJ->second->ObtenirFigure() != carteJoueur1->ObtenirFigure()) {
            memeCartes = true;
        }
        scoretotal = (*deplacementCartesJ->second->ObtenirPenalite()) + scoretotal;
        if (memeCartes) {
            if (jeuxDameScore.ScoreCarte(deplacementCartesJ->second) > scoreBase) {
                joueurGagnant = deplacementCartesJ->first;
            }
        }
    }
    resultatPlis.push_back(joueurGagnant);
    resultatPlis.push_back(scoretotal);
    return resultatPlis;
}
