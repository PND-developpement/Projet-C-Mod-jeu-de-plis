#ifndef H_PFC_H
#include "Partie.h"
#include <unordered_map>
#include <memory>
#include <functional>

class PartieFactory{
private:
	std::unordered_map<int,std::function<std::unique_ptr<Partie>()>> jeux;

public:
	//Constructeur et destructeur
	PartieFactory();
	~PartieFactory() = default;

	//Méthode
	/*
	* créer le jeu associer à la valeur entrée
	* @param choix : int
	* @return std::unique_ptr<Partie>
	*/
	std::unique_ptr<Partie> create(int choix);
};

#endif