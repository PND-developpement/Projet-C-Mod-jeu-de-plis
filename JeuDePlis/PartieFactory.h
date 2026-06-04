#ifndef H_PFC_H
#include "Partie.h"
#include <unordered_map>
#include <memory>
#include <functional>

class PartieFactory{
private:
	std::unordered_map<int,std::function<std::unique_ptr<Partie>()>> jeux;

public:
	PartieFactory();
	~PartieFactory() = default;
	std::unique_ptr<Partie> create(int choix);
};

#endif