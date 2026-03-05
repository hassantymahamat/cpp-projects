#include "Vehicule.hpp"
#include <iostream>
#include <list>

using namespace std;

void afficher_menu();

int main() {
   list<Vehicule*> parc;
    int choix;

    do {
        afficher_menu();
        cin >> choix;

        switch (choix) {
            case 1: { 
                Vehicule* v = new Vehicule(0);
                v->saisie();
                parc.push_back(v);
                break;
            }
            case 2: { 
                Voiture* v = new Voiture(1200, 5, "Peugeot 208");
                v->saisie();
                parc.push_back(v);
                break;
            }
            case 3: { 
                Avion* v = new Avion(70000, "Airbus", 180, 11000.0);
                v->saisie();
                parc.push_back(v);
                break;
            }
            case 4: { 
                cout << "Nombre de Vehicules : " << Vehicule::Compteur() << endl;
                cout << "Nombre de Voitures : " << Voiture::Compteur() << endl;
                cout << "Nombre d'Avions : " << Avion::Compteur() <<endl;
                break;
            }
            case 5: { 
                for (list<Vehicule*>::const_iterator it = parc.cbegin(); it != parc.cend(); ++it) {
                    (*it)->afficher();
            }

                break;
            }
            case 6: { 
                cout << "bye bye !" << endl;
                break;
            }
            default:
                cout << "veuillez réessayer s'il vous plait.\n";
        }
    } while (choix != 6);

    return 0;
}


void afficher_menu() {
    cout << "\n--- Menu Parc de Vehicules ---\n";
    cout << "1. Ajouter un Vehicule générique\n";
    cout << "2. Ajouter une Voiture\n";
    cout << "3. Ajouter un Avion\n";
    cout << "4. Afficher le nombre de Vehicules, Voitures, et Avions\n";
    cout << "5. Afficher tout le parc\n";
    cout << "6. Quitter\n";
    cout << "Choix : ";
}