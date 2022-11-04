#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <vector>
#include "Personnage.hpp"
#include <sstream>
#include <memory>
#include <cassert>
#include "bibliotheque_cours.hpp"
using namespace std;

class Vilain : public Personnage {
public:
	Vilain() = default;
	Vilain(ifstream& fichier);


	void afficher(ostream& os) const override;

private:
	string objectif_; 
	
};