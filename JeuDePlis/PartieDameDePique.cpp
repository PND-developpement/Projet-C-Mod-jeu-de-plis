#include "PartieDameDePique.h"
#include "JeuDeCarte.h"
#include "JeuDeCartesDameDePique.h"
#include "IA.h"
#include "Humain.h"
#include "MainJoueur.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <memory>
#include "Partie.h"

using namespace std;
PartieDameDePique::PartieDameDePique() : Partie()
{
    pLeJeu = make_unique<JeuDeCartesDameDePique>();
    nombreJoueur = 4;
}


void PartieDameDePique::AfficherRegles() const{
    cout << "\n=================================================" << endl;
    cout << "           JEU DE LA DAME DE PIQUE          " << endl;
    cout << "=================================================\n" << endl;
    cout << "CONSIGNES DU JEU :" << endl;
    cout << "- Le jeu se joue a 4 joueurs avec 52 cartes." << endl;
    cout << "- Le but est de marquer le MOINS de points possible." << endl;
    cout << "- Chaque carte de Coeur vaut 1 point." << endl;
    cout << "- La malicieuse Dame de Pique vaut 13 points" << endl;
    cout << "- Le joueur qui a le 2 de Trefle commence le premier pli.\n" << endl;
    cout << "Appuyez sur Entree pour commencer la partie..." << endl;
    cin.get();
}

void PartieDameDePique::InitaliserPartie()
{
    //inscription des joueurs à la table
    
    cout << "Entree le nombre de joueur Humain : " << endl;
    unsigned int nombreJoueurHumain=0;
    cin >> nombreJoueurHumain;

    size_t boucleAjoutJoueurHumain;
    for (boucleAjoutJoueurHumain = 0; boucleAjoutJoueurHumain < nombreJoueurHumain; boucleAjoutJoueurHumain++) {
        cout << "Entree pseudo joueur :" << endl;
        string pseudo;
        cin >> pseudo;
        unique_ptr <Humain> nJoueur = make_unique<Humain>();
        nJoueur->ModifierPseudo(pseudo);
        listeJoueur.push_back(move(nJoueur));
    }

    if (nombreJoueurHumain > nombreJoueur) { // Si jamais le joueur renvoie une valeur supérieure à la limite autorisée
        throw invalid_argument("Nombre de joueur trop grand pour le jeux : InitaliserPartie PartieDameDePique");
    }

    unsigned int nombreJoueurIA = nombreJoueur-nombreJoueurHumain;

    vector<string> nomIA = { "Terminator", "Sososlazdeg", "Evaninha", "Coco" };
    size_t boucleAjoutJoueurIA;
    for (boucleAjoutJoueurIA = 0; boucleAjoutJoueurIA < nombreJoueurIA; boucleAjoutJoueurIA++) {
        unique_ptr <IA> nJoueur = make_unique<IA>();
        nJoueur->ModifierPseudo(nomIA[boucleAjoutJoueurIA]);
        listeJoueur.push_back(move(nJoueur));
    }

    cout << "Joueurs inscrits : ";
    for (const auto& nom : listeJoueur) {
        cout << nom->LirePseudo() << " ";
    }
    cout << "\n\n";

    vector<string> figures = { "Pique", "Coeur", "Carreau", "Trefle" };
    vector<string> valeurs = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi", "As" };

    //deduction de la couleur
    pLeJeu->SetTaille(52);
    pLeJeu->CreerJeux(figures,valeurs,0);

    if (pLeJeu == nullptr)
    {
        throw invalid_argument("Echec de l'initialisation du jeu : InitaliserPartie PartieDameDePique");
    }
  
    cout << "La partie de Dame de Pique est initialisee (52 cartes pretes)." << std::endl;
}

void PartieDameDePique::DistribuerCartes()
{
    if (pLeJeu == nullptr) {
        throw invalid_argument("Impossible de distribuer, le jeu n'est pas initialise : DistribuerCartes PartieDameDePique");
    }

    cout << "Melange des cartes en cours" << std::endl;
    pLeJeu->MelangeCarte();
    cout << "Distribution de 13 cartes a chaque joueur..." << std::endl;
    for (const auto& joueur : listeJoueur) {
        unique_ptr<MainJoueur> nmainjoueur = make_unique<MainJoueur>();
        nmainjoueur->SetTaille(13);
        size_t boucleAjouterCarte;
        unsigned int ajoutCarte=0;
        for (boucleAjouterCarte = 0; boucleAjouterCarte < 13; boucleAjouterCarte++) {
            ajoutCarte++;
            
            if (ajoutCarte<52){
                nmainjoueur->AjouterCarteMain(pLeJeu->ObtenirEnsemble()->GetensembleDeCarte()[ajoutCarte]);
            }
        }
        
        joueur->ModifierCartes(move(nmainjoueur));
    }

}

void PartieDameDePique::LancerPartie()
{
    AfficherRegles();
    InitaliserPartie();
    DistribuerCartes();
    cout << "\nLa partie commence " << std::endl;

}
