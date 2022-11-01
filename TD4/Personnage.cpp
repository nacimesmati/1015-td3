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


ostream& Personnage:: afficher(ostream& o) const  { return o << "\nNom :\t\t\t" << nom_ << "\nParution :\t\t\t" << titre_; }
 
const string& Personnage::getTitre() const { return titre_; }

const string& Personnage::getNom() const { return nom_; }

void Personnage::setTitre(const string& titre) { titre_ = titre; }

void Personnage::setNom(const string& nom) { nom_ = nom; }

//void Personnage::changerCouleur(ifstream fichier, string codeCouleur) {
//
//}