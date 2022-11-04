#include "lectureBinaire.hpp"
#include <fstream>
#include <vector>
#include "Personnage.hpp"
#include "Heros.hpp"
#include <sstream>
#include <memory>
#include <cassert>
#include "bibliotheque_cours.hpp"
using namespace std; 
using namespace iter;

Heros::Heros(ifstream& fichier) {  
	nom_ = lireString(fichier); 
	titre_ = lireString(fichier);
	ennemi_ = lireString(fichier);  
	size_t nAllies = lireUintTailleVariable(fichier); 

	for (size_t i : range(nAllies)) { 
		allies_.push_back(lireString(fichier)); 
	}
}

void Heros:: afficher(ostream& os) const  {
	Personnage::afficher(os);
	os << "\nEnnemi : " << ennemi_;
	os << "\nallies : " << "\n";
	for (auto& a : allies_) {
		os <<"\t"<< a << "\n";
	}
}