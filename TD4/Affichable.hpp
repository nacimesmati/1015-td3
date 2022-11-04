#pragma once
#include <cstddef>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include <string>
using namespace std;
using namespace iter;

class Affichable {
public:
	virtual void afficher(ostream& o) const = 0;
	virtual ostream& changerCouleur(ostream& o, const string& codeCouleur) const = 0;

};