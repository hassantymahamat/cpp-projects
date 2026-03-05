#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include<string>

class Point {
protected:
    double x;
    double y;

public:
    
    Point(); 
    
    Point(double x, double y); 

    double getX() const;
    
    double getY() const;
    
    void setX(double newX);
    
    void setY(double newY);
    
    double distance(const Point& other) const;
    
    void saisie();
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    friend std::istream& operator>>(std::istream& is, Point& p);
    
    Point operator+(const Point& other) const; 
    
    Point operator-(const Point& other) const; 

    
    
};


class Figure2D {
    
protected:
    std::string nom;

public:
   
    Figure2D();
    
    Figure2D(const Figure2D&);
    
    std::string getNom() const;
    
    void setNom(const std::string& nouveauNom);

    virtual void afficher() const = 0; 
    
    virtual double perimetre() const = 0; 

    void saisie();

    virtual ~Figure2D();
};



class Triangle : public Figure2D{

protected:
    
    Point A, B, C; 

public:
    
    Triangle(const Point&, const Point&, const Point&, const std::string&);
    
    Triangle(const Triangle&);
    
    void afficher() const;
    
    void saisie();

    double perimetre() const; 

    virtual ~Triangle();

};


class Quadrilatere : public Figure2D{

protected:
    
    Point A, B, C, D; 
    
public:
    Quadrilatere(const Point&, const Point&, const Point&, const Point&, const std::string&);

    
    Quadrilatere(const Quadrilatere&);
    
    virtual void afficher() const;
    
    void saisie();
    
    virtual ~Quadrilatere();
    
    double perimetre() const; 
};

class Rectangle : public Quadrilatere{

protected:
    double longueur;  
    double hauteur;
    double inclin;

public:
    
    Rectangle(const Point& A, const Point& B, const Point& C, const Point& D);
    
    Rectangle( const Rectangle&);
    
    Rectangle(const Point& P1, double longueur, double hauteur, double incline); 
    
    void saisie();
    
    void afficher() const;
    
    virtual Point getp1() const;
    
    double get_long() const;
    
    double get_haut() const;
    
    double getangl() const;
    
    double perimetre() const;
    
    virtual~Rectangle();

};

class Cercle : public Figure2D{

protected:
    
    Point O;
    double R;

public:
    
    Cercle(const Point& centre, double rayon, const std::string& nom);
    
    Cercle(const Cercle&);
    
    void afficher() const;
    
    void saisie();
    
    double perimetre() const; 

    virtual ~Cercle();

};


#endif
