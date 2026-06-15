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
#include <limits>
#include <ios>

using namespace std;

PartieDameDePique::PartieDameDePique()
{
    pLeJeu = make_unique<JeuDeCartesDameDePique>();
    nombreJoueur = 4;
    scoreTotal = 0;
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
        for (boucleAjouterCarte = 0; boucleAjouterCarte < 13; boucleAjouterCarte++) 
        {
            if (ajoutCarte<52){
                nmainjoueur->AjouterCarteMain(pLeJeu->ObtenirEnsemble()->ObtenirEnsembleDeCarte()[ajoutCarte]);
            }
            ajoutCarte++;
        }
        
        joueur->ModifierCartes(move(nmainjoueur));
    }

}

void PartieDameDePique::DonnerCarte(const Interface& interface)
{
    vector <shared_ptr<CarteInterface>> carteAdonneeAuJoueur;
    unsigned int selectionJoueur; // Choisit le joueur qui doit donner ses cartes
    for (selectionJoueur = 0; selectionJoueur < 4; selectionJoueur++)
    {
        interface.AfficherEcranNoir();
        interface.AfficherMessage("Donnez 3 cartes a votre adversaire");
        interface.AfficherPseudoJoueur(listeJoueur[selectionJoueur]->LirePseudo());
        interface.AfficherMessage("Appuyez sur Entree pour commencer :");
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //permet de vider le buffer pour attendre la validation du joueur
        cin.get();


        unsigned int nbCartesDonnees = 0;
        vector <shared_ptr<CarteInterface>> carteTable;
        while (nbCartesDonnees < 3)
        {

            interface.AfficherTable(carteTable);

            interface.AfficherMainDuJoueur((*listeJoueur[selectionJoueur]->LireCartes()));

            auto carteADonnee = listeJoueur[selectionJoueur]->JouerUneCarte(interface,"donner");

            carteAdonneeAuJoueur.push_back(carteADonnee);

            carteTable.push_back(carteADonnee);

            nbCartesDonnees++;
        }
    }

    int boucleAjoutCarteJoueur;
    int positionCarteVecteur = 0;

    for (selectionJoueur = 0; selectionJoueur < 4; selectionJoueur++)
    {
        
        if (selectionJoueur < 3)
        {
            size_t nouvelleTailleMainJoueur = listeJoueur[selectionJoueur + 1]->LireCartes()->ObtenirTaille() + 3;
            listeJoueur[selectionJoueur + 1]->LireCartes()->DefinirTaille(nouvelleTailleMainJoueur);
        }
        else {
            size_t nouvelleTailleMainJoueur = listeJoueur[0]->LireCartes()->ObtenirTaille() + 3;
            listeJoueur[0]->LireCartes()->DefinirTaille(nouvelleTailleMainJoueur);
        }
        
        for (boucleAjoutCarteJoueur = positionCarteVecteur; boucleAjoutCarteJoueur < positionCarteVecteur + 3; boucleAjoutCarteJoueur++)
        {
            if (selectionJoueur < 3)
                listeJoueur[selectionJoueur + 1]->LireCartes()->AjouterCarteMain(carteAdonneeAuJoueur[boucleAjoutCarteJoueur]);
            else
                listeJoueur[0]->LireCartes()->AjouterCarteMain(carteAdonneeAuJoueur[boucleAjoutCarteJoueur]);
        }
        positionCarteVecteur += 3;
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
    scoreTotal=interface.DemanderScoreTotal();
    unsigned int manche = 0;

    while (!VerifScore()) {
        DistribuerCartes();

        DonnerCarte(interface);
        interface.AfficherEcranNoir();
        interface.AfficherDebutPartie();
        interface.AfficherMessageAvecScore("MANCHE", manche+1);
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
        while (nombreDeTour < 13 && !VerifScore()) {
            interface.AfficherMessageAvecScore("TOUR", nombreDeTour+1);

            unsigned int nombreJoueurJouer = 0; // Compte si bien tout les joueurs on jouer
            unordered_map<unsigned int, shared_ptr<CarteInterface>> carteDuPlis; 
            unsigned int positionPremierJoueur = selectionJoueur;
            listeJoueur[selectionJoueur]->ModifierScoreManche(0);
            vector <shared_ptr<CarteInterface>> carteTable;

            while (nombreJoueurJouer < 4) {
                if (selectionJoueur == 4) {
                    selectionJoueur = 0;
                }
                

                interface.AfficherPseudoJoueur(listeJoueur[selectionJoueur]->LirePseudo());
                interface.AfficherMessage("Appuyez sur Entree pour commencer :");
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //permet de vider le buffer pour attendre la validation du joueur
                cin.get(); // attendre la validation du joueur


                interface.AfficherTable(carteTable);


                auto cartejouer = JouerCarte(carteTable, selectionJoueur, interface);
                interface.AfficherEcranNoir();
                carteDuPlis[selectionJoueur] = cartejouer;

                selectionJoueur++;
                nombreJoueurJouer++;

                carteTable.push_back(cartejouer);
            }
            
            
            vector<int> resultatPlis = plis.verifPlis(carteDuPlis, positionPremierJoueur);

            selectionJoueur = resultatPlis[0];
            listeJoueur[selectionJoueur]->ModifierScore(listeJoueur[selectionJoueur]->LireScore() + resultatPlis[1]);
            listeJoueur[selectionJoueur]->ModifierScoreManche(resultatPlis[1]);


            interface.AfficherTable(carteTable);

            interface.AfficherGagnantPli(listeJoueur[selectionJoueur]->LirePseudo());
            vector<string> nomjoueur;
            vector<int> scorejoueur;
            for (auto parcourJ = listeJoueur.begin(); parcourJ != listeJoueur.end(); parcourJ++) {
                nomjoueur.push_back(parcourJ->get()->LirePseudo());
                scorejoueur.push_back(parcourJ->get()->LireScore());
            }
            interface.AfficherScores(nomjoueur,scorejoueur);

            

            nombreDeTour++;
        }
        // VERIFIER SCORE J > 26 donner 26 adversaire
        if (!VerifScore()) {
            auto scoreJoueur = listeJoueur.begin();
            bool scoreSuperieur = false;
            while (scoreJoueur != listeJoueur.end() && !scoreSuperieur) {
                if (scoreJoueur->get()->LireScoreManche() == 26) {
                    scoreSuperieur = true;
                }
                scoreJoueur++;
            }
            if (scoreSuperieur) {
                for (auto scoreJoueur = listeJoueur.begin(); scoreJoueur != listeJoueur.end(); scoreJoueur++) {
                    if (scoreJoueur->get()->LireScoreManche() == 26) {
                        scoreJoueur->get()->ModifierScore(scoreJoueur->get()->LireScore() - 26);
                    }
                    else {
                        scoreJoueur->get()->ModifierScore(scoreJoueur->get()->LireScore() + 26);
                    }
                }

            }
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
        if (parcourirJoueur->get()->LireScore() >= scoreTotal) {
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
    cout << "1er : " << listeJoueur[0]->LirePseudo() << " score : " << listeJoueur[0]->LireScore() << endl;
    cout << "2eme : " << listeJoueur[1]->LirePseudo() << " score : " << listeJoueur[1]->LireScore() << endl;
    cout << "3eme : " << listeJoueur[2]->LirePseudo() << " score : " << listeJoueur[2]->LireScore() << endl;
    cout << "4eme : " << listeJoueur[3]->LirePseudo() << " score : " << listeJoueur[3]->LireScore() << endl;
}

std::shared_ptr<CarteInterface> PartieDameDePique::JouerCarte(vector<shared_ptr<CarteInterface>>& carteTable, unsigned int JoueurEnCours, const Interface& interface)
{
    vector<bool> carteJouable; //vecteur de booleen pour savoir quelles cartes sont jouables 
    bool aucuneCarteJouable; //booleeen indiquanr si aucune carte n'est de la même figure que la première carte du plis
    std::shared_ptr<CarteInterface> cartejouee; //comporte la carte jouée par le joueur.
    int positionCarte; //ici on récupère la position de la carte jouer par joueur

    //Si aucune carte n'est sur la table, alors le joueur joue la carte qu'il souhaite
    if (carteTable.empty())
    {
        //il n'y a aucune carte sur la table, donc le joueur peut jouer toutes les cartes qui se trouvent dans sa main. Ainsi, nous remplissons le vecteur de booleen de carte jouable
        //avec des 'true', poue que toutes les cartes est leur position en vert pour indiquer qu'elles sont jouables.
        carteJouable.assign(listeJoueur[JoueurEnCours]->LireCartes()->ObtenirTaille(), true); //remplie le vecteur de 'true' de la longueur de la main du joueur
        interface.AfficherMainDuJoueur((*listeJoueur[JoueurEnCours]->LireCartes()), carteJouable); //affiche la main du joueur
        cartejouee = listeJoueur[JoueurEnCours]->JouerUneCarte(interface,"jouer"); //permet au joueur de jouer une carte
    }

    //sinon, on distingue deux cas
    else
    {
        //on regarde si chaque carte a la même figure ou non que la première carte posée dans le plis.
        auto ensembleCarte = listeJoueur[JoueurEnCours]->LireCartes()->LireCartesMain()->ObtenirEnsembleDeCarte(); //vecteur de la main du joueur
        for (auto carteJoueur = ensembleCarte.begin(); carteJoueur != ensembleCarte.end(); carteJoueur++)
        {
            if (FigureCarteEgal(carteTable[0], *carteJoueur)) //si même figure => alors on ajoute true dans les cartes jouables pour gérer l'affichage
                carteJouable.push_back(true);
            else
                carteJouable.push_back(false); //false sinon
        }

        //On regarde si le joueur n'a aucune carte de la même figure que la première carte dans le plis
        //c'est a dire que si le vecteur est remplie de 'false', le joueur n'a aucune carte de la figure demandé, donc il peut jouer la carte qu'il désire
        aucuneCarteJouable = std::none_of(carteJouable.begin(), carteJouable.end(),[](bool b) { return b; });

        //premier cas : le joueur a des cartes de la même figure
        if (!aucuneCarteJouable)
        {
            //Ici on redistingue deux cas : le cas où le joueur est une IA et le cas où le joueur est un humain

            //1er cas : le joueur est une IA : on va se baser sur un code similaire à la fonction 'jouerCarte' dans la classe IA, sauf qu'on intègre le fait que l'ia doit choisir 
            //une position aléatoire avec la bonne figure
            if (typeid(*listeJoueur[JoueurEnCours]) == typeid(IA))
            {
                //interface.AfficherMainDuJoueur((*listeJoueur[JoueurEnCours]->LireCartes()), carteJouable); 

                positionCarte = rand() % listeJoueur[JoueurEnCours]->LireCartes()->ObtenirTaille(); //on récupère

                cartejouee = listeJoueur[JoueurEnCours]->LireCartes()->ObtenirCarte(positionCarte); //on récupère la carte à la position choisie

                //tant que la carte n'est pas de la même figure que la figure du plis en cours, on retire une position aléatoire
                while (!FigureCarteEgal(carteTable[0], cartejouee)) {
                    //std::cout << "Rentrer un numero de carte valide : " << std::endl;
                    positionCarte = rand() % listeJoueur[JoueurEnCours]->LireCartes()->ObtenirTaille();
                    cartejouee = listeJoueur[JoueurEnCours]->LireCartes()->ObtenirCarte(positionCarte);
                }

                //on retire la carte de la main du joueur
                if (cartejouee != nullptr)
                    listeJoueur[JoueurEnCours]->LireCartes()->SupprimerCarteMain(cartejouee);
            }
            else {
                interface.AfficherMainDuJoueur((*listeJoueur[JoueurEnCours]->LireCartes()), carteJouable); //on affiche la main du joueur 

                positionCarte = interface.DemanderCarte((*listeJoueur[JoueurEnCours]->LireCartes()), listeJoueur[JoueurEnCours]->LirePseudo(), "jouer"); //le joueur choisit une carte
                cartejouee = listeJoueur[JoueurEnCours]->LireCartes()->ObtenirCarte(positionCarte); //on récupère la carte

                //tant que la carte n'est pas de la même figure que la figure du plis en cours, le joueur rechoisit une carte
                while (!FigureCarteEgal(carteTable[0], cartejouee)) {
                    std::cout << "Rentrer un numero de carte valide : " << std::endl;
                    positionCarte = interface.DemanderCarte((*listeJoueur[JoueurEnCours]->LireCartes()), listeJoueur[JoueurEnCours]->LirePseudo(), "jouer");
                    cartejouee = listeJoueur[JoueurEnCours]->LireCartes()->ObtenirCarte(positionCarte);
                }

                //on retire la carte de la main du joueur
                if (cartejouee != nullptr)
                    listeJoueur[JoueurEnCours]->LireCartes()->SupprimerCarteMain(cartejouee);
            }
        }
        else //deuxième cas : il n'a aucune carte du même figure, il peut donc jouer la carte qu'il souhaite.
        {
            //ici on ne distingue pas IA et humain car les deux peuvent jouer la carte qu'il désire

            //on passe tous les false a true car vu que le joueur n'a aucune carte de la même figure, avec la boucle for au dessus, nous avons passer que des false dans le vecteur des cartes jouables
            //ainsi on repasse tout a true car le joueur peut jouer la carte qu'il souhaite
            std::fill(carteJouable.begin(), carteJouable.end(), true);
            interface.AfficherMainDuJoueur((*listeJoueur[JoueurEnCours]->LireCartes()), carteJouable);
            cartejouee = listeJoueur[JoueurEnCours]->JouerUneCarte(interface,"jouer");
        }
    }

    return cartejouee; //on renvoie la carte jouée pour qu'ensuite la fonction du déroulement de la partie puisse s'en servir
}