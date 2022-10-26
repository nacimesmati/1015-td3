#pragma once
#include <cstddef>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include <string>
using namespace std;
using namespace iter;

class Affichable {
public:
	virtual void afficher() = 0;
	virtual void changerCouleur() = 0;
};