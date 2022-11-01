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
	const string getNom() const { return nom_; }


private: 
	string nom_, titre_;
	vector<shared_ptr<string>> allies_; 
};