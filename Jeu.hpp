#pragma once
#include <string>
#include "ListeConcepteurs.hpp"
#include "Liste.hpp"


struct Jeu
{
	std::string titre;
	int anneeSortie;
	std::string developpeur;
	Liste<Concepteur> concepteurs; 
};
