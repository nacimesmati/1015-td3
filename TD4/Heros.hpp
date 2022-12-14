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

class Heros : public Personnage {
public:
	Heros() = default;
	Heros(ifstream& fichier); 


	void afficher(ostream& os) const override;

private: 
	string ennemi_; 
	vector<string> allies_; 
};