#include "PlisDameDePique.h"
#include "CarteInterface.h"
#include "JeuDeCartesDameDePique.h"
#include <memory>
#include <unordered_map>
#include <vector>
#include <optional>

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
         // remplacer GETSCoreCarte par Getpenalite;
        if (deplacementCartesJ->second->ObtenirPenalite() != nullopt) {
            scoretotal = (*deplacementCartesJ->second->ObtenirPenalite()) + scoretotal;
        }
        
        if (!memeCartes) {
            int scoreCarte = jeuxDameScore.ScoreCarte(deplacementCartesJ->second);
            if (scoreCarte > scoreBase) {
                joueurGagnant = deplacementCartesJ->first;
                scoreBase = jeuxDameScore.ScoreCarte(deplacementCartesJ->second);
            }
        }
    }
    resultatPlis.push_back(joueurGagnant);
    resultatPlis.push_back(scoretotal);
    return resultatPlis;
}
