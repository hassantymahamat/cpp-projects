#include "Vehicule.hpp"


int Vehicule::cpt = 0;


Vehicule::Vehicule(int poids, const std::string& nom) : poids(poids), nom(nom) {
    ++cpt; 
}

Vehicule::Vehicule(const Vehicule& other) : poids(other.poids), nom(other.nom) {
    ++cpt; 
}


Vehicule::~Vehicule() {
    --cpt; 
}


std::string Vehicule::get_nom() const {
    return nom;
}

int Vehicule::get_poids() const {
    return poids;
}


void Vehicule::set_nom(const std::string& new_nom) {
    nom = new_nom;
}

void Vehicule::set_poids(int new_poids) {
    poids = new_poids;
}


int Vehicule::Compteur() {
    return cpt;
}


void Vehicule::afficher() const {
    std::cout << "Le Vehicule se nomme \"" << nom 
              << "\" et pèse " << poids << " kg." << std::endl;
}


Vehicule Vehicule::operator+(int ajout) const {
    return Vehicule(poids + ajout, nom);
}
void Vehicule::saisie() {
    std::cout << "Saisie d'un Vehicule :\n";
    std::cout << "Nom : ";
    std::cin >> nom;
    std::cout << "Poids : ";
    std::cin >> poids;
}




// Voiture
int Voiture::cpt = 0;


Voiture::Voiture(int poids, int place, const std::string& nom) 
    : Vehicule(poids, nom), place(place) {
    ++cpt;  
}


Voiture::~Voiture() {
    --cpt; 
    --Vehicule::cpt; 
}


int Voiture::get_place() const {
    return place;
}


void Voiture::set_place(int new_place) {
    place = new_place;
}


int Voiture::Compteur() {
    return cpt;
}


void Voiture::afficher() const {
    std::cout << "La Voiture se nomme \"" << nom 
              << "\", pèse " << poids 
              << " kg et possède " << place << " place(s)." << std::endl;
}

void Voiture::saisie() {
    std::cout << "Saisie d'une Voiture :\n";
    Vehicule::saisie();
    std::cout << "Nombre de places : ";
    std::cin >> place;
}




// Avion
int Avion::cpt = 0;

    Avion::Avion(const int pds, const std::string& nm, const int plc, const double alt)
    : Vehicule(pds, nm), place(plc) {
    ++cpt; 
};

    
    Avion::~Avion() {
    --cpt; 
}

    
    int Avion::get_place() const{
        return place;
    }
    int Avion::get_alt_crosiere() const{
        return alt_croisiere;
    };


    void Avion::set_place(int new_place){
        place = new_place;
    }
    void Avion::set_alt_croisire(double new_alt_croisiere){
        alt_croisiere = new_alt_croisiere;
    }

    
    int Avion:: Compteur(){
        return cpt;
    };


    void Avion::afficher() const {
    std::cout << "L'Avion d'altitude de croisière \"" << alt_croisiere
              << "\", pèse " << poids 
              << " kg et possède " << place << " place(s)." << std::endl;
}

void Avion::saisie() {
    std::cout << "Saisie d'un Avion :\n";
    Vehicule::saisie();
    std::cout << "Nombre de places : ";
    std::cin >> place;
    std::cout << "Altitude de croisière : ";
    std::cin >> alt_croisiere;
}
