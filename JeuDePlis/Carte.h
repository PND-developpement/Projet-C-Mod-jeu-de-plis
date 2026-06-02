#ifndef _CARTE_H__
#define _CARTE_H__
#include <iostream>
#include <string>
#include <memory>

class Carte{
protected:
	// Atributs
	std::string valeur;
	std::string figure;
	std::string couleur;
public:
	// Constructeur et Destructeur
	Carte();
	Carte(const Carte& carte2) noexcept;
	Carte(Carte&& carte2) noexcept;
	Carte(std::shared_ptr<Carte> carte2) noexcept;
	Carte(std::string valeur, std::string figure, std::string couleur);
	~Carte();

	// Methodes

	void setValeur(std::string& valeur) { this->valeur = valeur; }
	std::string getValeur() const { return valeur; }

	void setFigure(std::string& figure) { this->figure = figure; }
	std::string getFigure() const { return figure; }

	void setCouleur(std::string& couleur) { this->couleur = couleur; }
	std::string getCouleur() const { return couleur; }


};

#endif