#pragma once
#include <cstddef>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include "Personnage.hpp" 
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using namespace iter;


void Personnage::afficher() {
	cout << "Nom :" << " " << nom_ << "\n"
		<< "Parution :" << " " << titre_ << endl;
}
//void Personnage::changerCouleur(ifstream fichier, string codeCouleur) {
//
//}
