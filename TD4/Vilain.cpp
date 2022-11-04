#include "lectureBinaire.hpp"
#include <fstream>
#include <vector>
#include "Personnage.hpp"
#include "Vilain.hpp" 
#include <sstream>
#include <memory>
#include <cassert>
#include "bibliotheque_cours.hpp"
using namespace std;
using namespace iter;

Vilain::Vilain(ifstream& fichier) { 
	nom_ = lireString(fichier); 
	titre_ = lireString(fichier);
	objectif_ = lireString(fichier);
}

void Vilain::afficher(ostream& os) const { 
	Personnage::afficher(os); 
	os << "\nObjectif : " << objectif_;  
}