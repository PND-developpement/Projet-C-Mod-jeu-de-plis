#include "PlisDameDePique.h"
#include "CarteInterface.h"
#include "JeuDeCartesDameDePique.h"
#include <memory>
#include <unordered_map>

using namespace std;

unsigned int PlisDameDePique::verifePlis(unordered_map<unsigned int, shared_ptr<CarteInterface>> carteDuPlis)
{
    unsigned int positionJoueur = 0;
    auto carteJoueur1 = JeuDeCartesDameDePique::ScoreCarte(carteDuPlis.at(0));
    return positionJoueur;
}
