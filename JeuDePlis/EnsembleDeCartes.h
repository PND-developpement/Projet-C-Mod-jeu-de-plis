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

	/*
	* Constructeur par defaut
	* initalise la taille avec 0
	*/
	EnsembleDeCartes();

	/*
	* Constructeur qui initalise la taille
	* @param taille size_t
	*/
	EnsembleDeCartes(size_t taille);

	/*
	* Constructeur de recopie
	* @param ensemble2 const EnsembleDeCartes&
	*/
	EnsembleDeCartes(const EnsembleDeCartes& ensemble2) noexcept;

	/*
	* Constructeur de recopie avec move
	* @param ensemble2 const EnsembleDeCartes&&
	*/
	EnsembleDeCartes(EnsembleDeCartes&& ensemble2) noexcept;

	/*
	* Destructeur vide le vecteur
	*/
	~EnsembleDeCartes();
	
	/*
	* Surchage operator=
	* @param ensemble const EnsembleDeCartes
	*/
	EnsembleDeCartes& operator=(const EnsembleDeCartes& ensemble) = default; //redefini l'opérateur = car j'avais une erreur dans MainJoueur pour le setter. 
	 
	// Methodes

	/*
	* Ajoute une carte dans le vecteur
	* @param carte shared_ptr<CArte>
	*/
	void AjouterCarte(std::shared_ptr<Carte> carte);

	/*
	* Ajoute une carte dans le vecteur
	* @param carte Carte&
	*/
	void AjouterCarte(Carte& carte);
	
	/*
	* Supprimer carte dans le vecteur avec la carte en parametre
	* @param carteASupprimer shared_prt<Carte>
	*/
	void SupprimerCarte(std::shared_ptr<Carte> carteASupprimer);

	
	void TrieCarte(std::string typedetrie);

	/*
	* Melange les cartes aleatoirement
	*/
	void MelangeAleatoireCarte();
	
	/*
	* Renvoie une carte du vecteur dans la postion en parametre
	* @param position unsigned int
	*/
	Carte& GetCarte(unsigned int position) const;
	std::vector<std::shared_ptr<Carte>> GetensembleDeCarte() const { return ensembleDeCarte; }

	void SetTaille(size_t taille) { this->taille = taille; }
	size_t GetTaille() const { return taille; }

	void AfficherCarte() const;

};
#endif // !H_EDC_H
