#ifndef H_EDC_H
#define H_EDC_H
#include <iostream>
#include <vector>
#include <memory>
#include "Carte.h"
#include <string>


class EnsembleDeCartes{
private:
	// Atribut
	std::vector<std::shared_ptr<Carte>> ensembleDeCarte;
	size_t taille;
public:
	// Constructeur et Destructeur
	EnsembleDeCartes();
	EnsembleDeCartes(size_t taille);
	EnsembleDeCartes(const EnsembleDeCartes& ensemble2) noexcept;
	EnsembleDeCartes(EnsembleDeCartes&& ensemble2) noexcept;
	~EnsembleDeCartes();

	EnsembleDeCartes& operator=(const EnsembleDeCartes& ensemble) = default; //redefini l'opérateur = car j'avais une erreur dans MainJoueur pour le setter. 
	 
	// Methodes
	void ajouterCarte(std::shared_ptr<Carte> carte);
	void ajouterCarte(Carte& carte);
	 
	void supprimerCarte(const std::shared_ptr<Carte> carteASupprimer); //On devrait pas mettre la carte qu'on veut supprimer en paramètre ? Cela permettrait de parcourir le vecteur avec un itérateur et de comparé avec la carte placée en param, puis la supprimer si elle est trouvé da,=ns le vecteur.
	void trieCarte(std::string typedetrie);
	void melangeAleatoireCarte();
	
	Carte& getCarte(unsigned int position) const;
	std::vector<const std::shared_ptr<Carte>> getensembleDeCarte() const;

	void setTaille(size_t taille) { this->taille = taille; }
	size_t getTaille() const { return taille; }

	void afficherCarte() const;

};
#endif // !H_EDC_H
