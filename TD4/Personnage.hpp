#pragma once
#include <cstddef>
#include <fstream>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include "Affichable.hpp" 
#include <string>
using namespace std;
using namespace iter;

class Personnage : public Affichable {
public:
	Personnage(string nom, string titre) :nom_(nom), titre_(titre){}
	virtual ~Personnage() = default;
	void afficher() ;
	void changerCouleur(ifstream fichier, string codeCouleur) ; 

private:
	string nom_, titre_;     
};