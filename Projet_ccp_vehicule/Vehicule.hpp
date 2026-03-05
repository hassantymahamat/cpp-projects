#ifndef VEHICULE_HPP
#define VEHICULE_HPP  

#include <string>
#include <iostream>

class Vehicule {
protected: 
    std::string nom;
    int poids;
    static int cpt; 

public: 
    
    Vehicule(int poids, const std::string& nom = "Vehicule");
    Vehicule(const Vehicule&); 
    
    ~Vehicule();

    std::string get_nom() const;
    
    int get_poids() const;

    void set_nom(const std::string& nom);
    
    void set_poids(int poids);

    static int Compteur(); 
    
    void afficher() const;

    Vehicule operator+(int ajout) const;
    virtual void saisie();
};





class Voiture : public Vehicule {
protected:
    int place; 
    static int cpt; 

public:
    
    Voiture(int, int, const std::string& = "Vehicule");

    
    ~Voiture();

    
    int get_place() const;

    
    void set_place(int);

    
    static int Compteur(); 
    virtual void afficher() const; 
    void saisie();
};






class Avion : public Vehicule {

protected:
    int place; 
    double alt_croisiere;
    static int cpt;

public:
    
    Avion(const int, const std::string&, const int, const double);

    
    ~Avion();

    
    int get_place() const;
    int get_alt_crosiere() const;


    void set_place(int);
    void set_alt_croisire(double);

    
    static int Compteur(); 
    void afficher() const; 
    void saisie() ;
};


#endif
