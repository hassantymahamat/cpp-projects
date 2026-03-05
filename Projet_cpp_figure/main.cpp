#include "Figure.hpp"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


bool compareFiguresByPerimeter(Figure2D* f1, Figure2D* f2) {
    return f1->perimetre() < f2->perimetre();
}


int main() {
    vector<Figure2D*> figures; 
    int choix, choix2, pos;

    do {
        cout << "Menu:" << endl;
        cout << "0 - Quitter" << endl;
        cout << "1 - Ajouter une figure " << endl;
        cout << "2 - Consulter les figures" << endl;
        cout << "3 - Ordonner les figures " << endl;
        cout << "4 - Supprimer une figure" << endl;
        cin >> choix;

        switch (choix) {
            case 0:
                cout << "Au revoir" << endl;
                break;

            case 1: {
                cout << "vous voulez ajouter quoi?" << endl;
                cout << "1 - Un Triangle" << endl;
                cout << "2 - Un Quadrilatere" << endl;
                cout << "3 - Un Rectangle" << endl;
                cout << "4 - Un Cercle" << endl;
                cin >> choix2;

                Figure2D* figure = nullptr;
                Point A, B, C, D;
                string nom;

                switch (choix2) {
                    case 1:
                        cout << "Création d'un Triangle." << endl;
                        cout << "coordonnées des points A, B, C : " << endl;
                        A.saisie(); B.saisie(); C.saisie();
                        cout << "nom du Triangle : ";
                        cin >> nom;
                        figure = new Triangle(A, B, C, nom);
                        break;

                    case 2:
                        cout << "Création d'un Quadrilatere." << endl;
                        cout << "coordonnées des points A, B, C, D : " << endl;
                        A.saisie(); B.saisie(); C.saisie(); D.saisie();
                        cout << "nom du Quadrilatere : ";
                        cin >> nom;
                        figure = new Quadrilatere(A, B, C, D, nom);
                        break;

                    case 3:
                        cout << "Création d'un Rectangle." << endl;
                        cout << "le point A (coin inférieur gauche), la longueur, la hauteur et l'angle d'inclinaison : " << endl;
                        A.saisie();
                        double longueur, hauteur, inclinaison;
                        cout << "Longueur : "; cin >> longueur;
                        cout << "Hauteur : "; cin >> hauteur;
                        cout << "Inclinaison : "; cin >> inclinaison;
                        cout << "nom du Rectangle : ";
                        cin >> nom;
                        figure = new Rectangle(A, longueur, hauteur, inclinaison);
                        break;

                    case 4:
                        cout << "Création d'un Cercle." << endl;
                        cout << "centre et le rayon : " << endl;
                        A.saisie();
                        double rayon;
                        cout << "Rayon : "; cin >> rayon;
                        cout << "nom du Cercle : ";
                        cin >> nom;
                        figure = new Cercle(A, rayon, nom);
                        break;

                    default:
                        cout << "Choix invalide" << endl;
                        break;
                }

                if (figure) {
                    figures.push_back(figure);
                    cout << "Figure ajoutée" << endl;
                }
                break;
            }

            case 2: {
                cout << "Liste des figures : " << endl;
                for (size_t i = 0; i < figures.size(); ++i) {
                    cout << "Figure " << i + 1 << " : ";
                    figures[i]->afficher();
                    cout << endl;
                }
                break;
            }

            case 3: {
                cout << "Tri" << endl;
                sort(figures.begin(), figures.end(), compareFiguresByPerimeter);  
                cout << "Figures triées" << endl;
                break;
            }


            case 4: {
                cout << "position de la figure à supprimer : ";
                cin >> pos;
                if (pos >= 1 && pos <= static_cast<int>(figures.size())) {
                    delete figures[pos - 1]; 
                    figures.erase(figures.begin() + (pos - 1)); 
                    cout << "Figure supprimée " << endl;
                } else {
                    cout << "Position invalide " << endl;
                }
                break;
            }

            default:
                cout << "Choix invalide" << endl;
                break;
        }
    } while (choix != 0);

    
    for (Figure2D* figure : figures) {
        delete figure;
    }
    figures.clear();

    return 0;
}
