#include "PartieDameDePique.h"
#include <iostream>
#include <vector>
#include <string>
#include "JeuDeCarte.h"
#include "IA.h"
#include "Humain.h"
#include <utility>
#include <stdexcept>

using namespace std;
PartieDameDePique::PartieDameDePique() : Partie()
{
    pLeJeu = nullptr;
    nombreJoueur = 4;
}


void PartieDameDePique::AfficherRegles() const
{
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
    //{ "Terminator", "Sososlazdeg", "Evaninha", "Coco" }

    cout << "Entree le nombre de joueur Humain : " << endl;
    unsigned int nombreJoueurHumain=0;
    cin >> nombreJoueurHumain;

    size_t boucleAjoutJoueurHumain;
    for (boucleAjoutJoueurHumain = 0; boucleAjoutJoueurHumain < nombreJoueurHumain; boucleAjoutJoueurHumain++) {
        cout << "Entree pseudo joueur :" << endl;
        string pseudo;
        cin >> pseudo;
        std::unique_ptr <Humain> nJoueur = make_unique<Humain>();
        nJoueur->ModifierPseudo(pseudo);
        listeJoueur.push_back(move(nJoueur));
    }

    if (nombreJoueurHumain > nombreJoueur) { // Si jamais le joueur renvoie une valeur supérieure à la limite autorisée
        throw invalid_argument("Nombre de joueur trop grand pour le jeux");
    }

    unsigned int nombreJoueurIA = nombreJoueur-nombreJoueurHumain;

    size_t boucleAjoutJoueurIA;
    for (boucleAjoutJoueurIA = 0; boucleAjoutJoueurIA < nombreJoueurIA; boucleAjoutJoueurIA++) {
        string pseudo = "IA";
        
        std::unique_ptr <IA> nJoueur = make_unique<IA>();
        nJoueur->ModifierPseudo(pseudo+to_string(boucleAjoutJoueurIA));
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
    pLeJeu = JeuDeCartes::CreerJeuSurMesure(figures, valeurs, 0);

    if (pLeJeu != nullptr)
    {
        cout << "La partie de Dame de Pique est initialisee (52 cartes prêtes)." << std::endl;
    }
    else
    {
        cerr << "Echec de l'initialisation du jeu." << std::endl;
    }
}

void PartieDameDePique::DistribuerCartes()
{
    if (pLeJeu == nullptr) {
        cerr << "Erreur : Impossible de distribuer, le jeu n'est pas initialise." << std::endl;
        return;
    }

    cout << "Melange des cartes en cours" << std::endl;
    pLeJeu->MelangeCarte();
    cout << "Distribution de 13 cartes a chaque joueur..." << std::endl;

}

void PartieDameDePique::LancerPartie()
{
    AfficherRegles();
    InitaliserPartie();
    DistribuerCartes();

    cout << "\nLa partie commence " << std::endl;
}
