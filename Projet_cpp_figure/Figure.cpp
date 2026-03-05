#include "Figure.hpp"
#include <cmath>

using namespace std;


// Point 
Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double newX) {
    x = newX;
}

void Point::setY(double newY) {
    y = newY;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

double Point::distance(const Point& other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

void Point::saisie() {
    cout << "coordonnées (x y) : ";
    cin >> *this;
}

//  Figure2D 
Figure2D::Figure2D() : nom("Figure2D") {}

Figure2D::Figure2D(const Figure2D& other) : nom(other.nom) {}

string Figure2D::getNom() const {
    return nom;
}

void Figure2D::setNom(const string& nouveauNom) {
    nom = nouveauNom;
}

void Figure2D::saisie() {
    cout << "nom de la figure : ";
    cin >> nom;
}

Figure2D::~Figure2D() {}

//  Triangle 
Triangle::Triangle(const Point& a, const Point& b, const Point& c, const string& nom)
    : A(a), B(b), C(c) {
    this->nom = nom;
}

Triangle::Triangle(const Triangle& other) : Figure2D(other), A(other.A), B(other.B), C(other.C) {}

void Triangle::afficher() const {
    cout << "Triangle " << nom << ": A" << A << ", B" << B << ", C" << C << "\n";
}

void Triangle::saisie() {
    Figure2D::saisie();
    cout << "coordonnées des trois sommets :\n";
    cout << "Sommet A: ";
    A.saisie();
    cout << "Sommet B: ";
    B.saisie();
    cout << "Sommet C: ";
    C.saisie();
}

double Triangle::perimetre() const {
    return A.distance(B) + B.distance(C) + C.distance(A);
}

Triangle::~Triangle() {}

// Quadrilatere 
Quadrilatere::Quadrilatere(const Point& a, const Point& b, const Point& c, const Point& d, const std::string& nom) 
    : A(a), B(b), C(c), D(d) {
    setNom(nom);
}


Quadrilatere::Quadrilatere(const Quadrilatere& other)
    : Figure2D(other), A(other.A), B(other.B), C(other.C), D(other.D) {}

void Quadrilatere::afficher() const {
    cout << "Quadrilatere " << nom << ": A" << A << ", B" << B << ", C" << C << ", D" << D << "\n";
}

void Quadrilatere::saisie() {
    Figure2D::saisie();
    cout << "coordonnées des quatre sommets :\n";
    cout << "Sommet A: ";
    A.saisie();
    cout << "Sommet B: ";
    B.saisie();
    cout << "Sommet C: ";
    C.saisie();
    cout << "Sommet D: ";
    D.saisie();
}

double Quadrilatere::perimetre() const {
    return A.distance(B) + B.distance(C) + C.distance(D) + D.distance(A);
}


Quadrilatere::~Quadrilatere() {}

//  Rectangle
Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d)
    : Quadrilatere(a, b, c, "Rectangle"), longueur(0), hauteur(0), inclin(0) {
    D = d;
}

Rectangle::Rectangle(const Rectangle& other)
    : Quadrilatere(other), longueur(other.longueur), hauteur(other.hauteur), inclin(other.inclin) {}

Rectangle::Rectangle(const Point& P1, double longueur, double hauteur, double incline)
    : Quadrilatere(P1, Point(P1.getX() + longueur, P1.getY()), Point(P1.getX(), P1.getY() + hauteur), "Rectangle"),
      longueur(longueur), hauteur(hauteur), inclin(incline) {
    D = Point(P1.getX() + longueur, P1.getY() + hauteur);
}

void Rectangle::saisie() {
    Quadrilatere::saisie();
    cout << "Longueur : ";
    cin >> longueur;
    cout << "Hauteur : ";
    cin >> hauteur;
    cout << "Inclinaison : ";
    cin >> inclin;
}

void Rectangle::afficher() const {
    cout << "Rectangle " << nom << ": Longueur=" << longueur << ", Hauteur=" << hauteur
    << ", Inclinaison=" << inclin << "\n";
}

Point Rectangle::getp1() const {
    return A;
}

double Rectangle::get_long() const {
    return longueur;
}

double Rectangle::get_haut() const {
    return hauteur;
}

double Rectangle::getangl() const {
    return inclin;
}

double Rectangle::perimetre() const {
    return 2 * (longueur + hauteur);
}

Rectangle::~Rectangle() {}

// Cercle 
Cercle::Cercle(const Point& centre, double rayon, const string& nom)
    : O(centre), R(rayon) {
    this->nom = nom;
}

Cercle::Cercle(const Cercle& other) : Figure2D(other), O(other.O), R(other.R) {}

void Cercle::afficher() const {
    cout << "Cercle " << nom << ": Centre=" << O << ", Rayon=" << R << "\n";
}

void Cercle::saisie() {
    Figure2D::saisie();
    cout << "Saisissez les coordonnées du centre : ";
    O.saisie();
    cout << "Rayon : ";
    cin >> R;
}

double Cercle::perimetre() const {
    return 2 * M_PI * R;
}

Cercle::~Cercle() {}
