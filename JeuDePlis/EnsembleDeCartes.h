#ifndef H_EDC_H
#define H_EDC_H
#include <vector>
#include <memory>
#include <string>
#include "CarteInterface.h"

class EnsembleDeCartes{
private:
	// Atribut
	std::vector<std::shared_ptr<CarteInterface>> ensembleDeCarte;
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
	~EnsembleDeCartes() = default;
	
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
	void AjouterCarte(std::shared_ptr<CarteInterface> carte);

	/*
	* Ajoute une carte dans le vecteur
	* @param carte Carte&
	*/
	//void AjouterCarte(CarteInterface& carte); //Surement innutile
	
	/*
	* Supprimer carte dans le vecteur avec la carte en parametre
	* @param carteASupprimer shared_prt<Carte>
	*/
	void SupprimerCarte(std::shared_ptr<CarteInterface> carteASupprimer);

	/*
	* Trie les cartes selon un ordre donner en parametre
	* @param valeur std::string
	*/
	void TrieCarte(std::string typedetrie);

	/*
	* Melange les cartes aleatoirement
	*/
	void MelangeAleatoireCarte();
	
	/*
	* Renvoie une carte du vecteur dans la postion en parametre
	* @param position unsigned int
	*/
	std::shared_ptr<CarteInterface> GetCarte(unsigned int position) const;

	/*
	* Renvoie le vecteur de carte
	* @return ensembleDeCarte
	*/
	std::vector<std::shared_ptr<CarteInterface>> GetensembleDeCarte() const { return ensembleDeCarte; }

	/*
	* Modifie la taille avec la valeur passer en prametre
	* @param taille size_t
	*/
	void SetTaille(size_t taille) { this->taille = taille; }

	/*
	* Renvoie la taille de l'ensemble
	* @return taille
	*/
	size_t GetTaille() const { return taille; }

	/*
	* Afficher l’ensemble des cartes avec la méthode de l’interface
	*/
	void AfficherEnsembleDeCarte() const;

};
#endif