#include "PartieDameDePique.h"
#include "JeuDeCarte.h"
#include "JeuDeCartesDameDePique.h"
#include "IA.h"
#include "Humain.h"
#include "MainJoueur.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <stdexcept>
#include <memory>
#include "Partie.h"
#include "CarteInterface.h"
#include <algorithm>
#include "Joueur.h"
#include "PlisDameDePique.h"

using namespace std;
PartieDameDePique::PartieDameDePique()
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
    pLeJeu->DefinirTaille(52);
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
    unsigned int ajoutCarte = 0;
    for (const auto& joueur : listeJoueur) {
        unique_ptr<MainJoueur> nmainjoueur = make_unique<MainJoueur>();
        nmainjoueur->DefinirTaille(13);
        size_t boucleAjouterCarte;
        
        for (boucleAjouterCarte = 0; boucleAjouterCarte < 13; boucleAjouterCarte++) {
            
            
            if (ajoutCarte<52){
                nmainjoueur->AjouterCarteMain(pLeJeu->ObtenirEnsemble()->ObtenirEnsembleDeCarte()[ajoutCarte]);
            }
            ajoutCarte++;
        }
        
        joueur->ModifierCartes(move(nmainjoueur));
    }

}

void PartieDameDePique::LancerPartie()
{
    AfficherRegles();
    InitaliserPartie();
    
}

void PartieDameDePique::JouerPartie(const Interface& interface)
{
    LancerPartie();
    unsigned int manche = 0;
    while (!VerifScore()) {
        DistribuerCartes();
        cout << "\nLa partie commence " << endl;
        cout << "Manche : " << manche << endl;
        manche++;

        unsigned int selectionJoueur = 0; // Choisit le joueur qui doit jouer
        bool trouverJoueur = false; // Recherche le joueur avec la carte 2 de Trefle
        while (selectionJoueur < 4 && !trouverJoueur) {
            if (listeJoueur[selectionJoueur]->LireCartes()->TrouverCarte("2", "Trefle")) {
                trouverJoueur = true;
            }
            else
            {
                selectionJoueur++;
            }
            
        }

        unsigned int nombreDeTour=0; // Compte le nombre de tour du manche
        PlisDameDePique plis;
        while (nombreDeTour < 13) {
            unsigned int nombreJoueurJouer = 0; // Compte si bien tout les joueurs on jouer
            unordered_map<unsigned int, shared_ptr<CarteInterface>> carteDuPlis; 
            unsigned int positionPremierJoueur = selectionJoueur;
            vector <shared_ptr<CarteInterface>> carteTable;
            while (nombreJoueurJouer < 4) {
                if (selectionJoueur == 4) {
                    selectionJoueur = 0;
                }
                cout << "Autour du joueur " << listeJoueur[selectionJoueur]->LirePseudo() << " de jouer" << endl;
                cin.get(); // attendre la validation du joueur
                // interface afficher le bloque noire
               
                auto cartejouer = listeJoueur[selectionJoueur]->JouerUneCarte(interface);
                carteDuPlis[selectionJoueur] = cartejouer;
                selectionJoueur++;
                nombreJoueurJouer++;
                carteTable.push_back(cartejouer);
            }
            // Plis verifier qui gagne en passer le la unordered_map carteduplie et renvoie la postion du joueur
            cout << "verif plis" << endl;
            interface.AfficherTable(carteTable);
            vector<int> resultatPlis = plis.verifPlis(carteDuPlis, positionPremierJoueur);
            selectionJoueur = resultatPlis[0];
            listeJoueur[selectionJoueur]->ModifierScore(resultatPlis[1]);
            cout << "fin verif plis" << endl;
            nombreDeTour++;
        }
        
    }
    cout << "Fin Partie Classement finale :" << endl;
    AfficherScore();
}

bool PartieDameDePique::VerifScore()
{
    bool scoreFinale = false;
    auto parcourirJoueur = listeJoueur.begin();
    while (parcourirJoueur != listeJoueur.end() && !scoreFinale) {
        if (parcourirJoueur->get()->LireScore() == 100) {
            scoreFinale = true;
        }
        parcourirJoueur++;
    }
    return scoreFinale;
}

void PartieDameDePique::AfficherScore(){
    sort(listeJoueur.begin(), listeJoueur.end(), [](const unique_ptr<Joueur>& j1, const unique_ptr<Joueur>& j2) {
        return j1->LireScore() < j2->LireScore();
    });
    cout << "1er : " << listeJoueur[0] << " score : " << listeJoueur[0]->LireScore() << endl;
    cout << "2eme : " << listeJoueur[1] << " score : " << listeJoueur[1]->LireScore() << endl;
    cout << "3eme : " << listeJoueur[2] << " score : " << listeJoueur[2]->LireScore() << endl;
    cout << "4eme : " << listeJoueur[3] << " score : " << listeJoueur[3]->LireScore() << endl;
}




