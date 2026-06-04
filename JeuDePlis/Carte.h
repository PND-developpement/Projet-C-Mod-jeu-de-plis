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

	/*
	* Ajoute la valeur par celle mis en parametre
	* @param valeur std::string
	*/
	void SetValeur(std::string& valeur) { this->valeur = valeur; }

	/*
	* Renvoie la valeur 
	* @return valeur std::string
	*/
	std::string GetValeur() const { return valeur; }

	/*
	* Ajoute la figure par celle mis en parametre
	* @param figure std::string
	*/
	void SetFigure(std::string& figure) { this->figure = figure; }

	/*
	* Renvoie la figure
	* @return figure std::string
	*/
	std::string GetFigure() const { return figure; }

	/*
	* Ajoute la couleur par celle mis en parametre
	* @param couleur std::string
	*/
	void SetCouleur(std::string& couleur) { this->couleur = couleur; }

	/*
	* Renvoie la couleur
	* @return couleur std::string
	*/
	std::string GetCouleur() const { return couleur; }


};

#endif