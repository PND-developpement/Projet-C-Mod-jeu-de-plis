#include "PartieFactory.h"
#include "PartieDameDePique.h"
#include <memory>
using namespace std;


PartieFactory::PartieFactory(){
	jeux.insert({ 1, [] { return make_unique<PartieDameDePique>(); } });
}

unique_ptr<Partie> PartieFactory::create(int choix)
{
    auto it = jeux.find(choix);
    if (it != jeux.end()) {
        return it->second();
    }
        
    return nullptr;
}
