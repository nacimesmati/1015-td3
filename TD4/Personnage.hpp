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
	Personnage() = default;
	Personnage(string nom, string titre) :nom_(nom), titre_(titre) {}
	//void changerCouleur(ifstream fichier, string codeCouleur); 
	
	//getter
	const string& getTitre() const;
	const string& getNom() const;

	//setter
	void setTitre(const string& titre);
	void setNom(const string& nom);

	//Affichage
	ostream& afficher(ostream& o) const override;
private:
	string nom_, titre_;
};