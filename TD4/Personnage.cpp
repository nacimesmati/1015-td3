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


void Personnage:: afficher(ostream& o) const  {  o << "\nNom : " << nom_ << "\nParution : " << titre_; }
 
const string& Personnage::getTitre() const { return titre_; }

const string& Personnage::getNom() const { return nom_; }

void Personnage::setTitre(const string& titre) { titre_ = titre; }

void Personnage::setNom(const string& nom) { nom_ = nom; }

ostream& Personnage::changerCouleur(ostream& o, const string& codeCouleur) const {   
	return o << "\033[" + codeCouleur + "m";  
}