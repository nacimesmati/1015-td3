#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>
#include "bibliotheque_cours.hpp"
#include "Affichable.hpp"
#include "Personnage.hpp"
#include "Vilain.hpp"
#include "Heros.hpp"

using namespace std;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}

ostream& operator<< (ostream& os, const Personnage& p)
{
	p.afficher(os);
	return os; 
}

int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)
	size_t nHeros = lireUintTailleVariable(fichierHeros);
	size_t nVilains= lireUintTailleVariable(fichierVilains);


	vector<shared_ptr<Heros>> vHeros; 
	vector<shared_ptr<Vilain>> vVilain;
	vector<shared_ptr<Personnage>> vPersonnage;


	for (size_t i : range(nHeros)) {
		Heros heros(fichierHeros);
		shared_ptr<Heros> ptrHeros = make_shared<Heros>(heros);
		vHeros.push_back(ptrHeros);
		vPersonnage.push_back(ptrHeros); 
	}
	 
	for (size_t i : range(nVilains)) {  
		Vilain vilain(fichierVilains); 
		shared_ptr<Vilain> ptrVilain = make_shared<Vilain>(vilain);
		vVilain.push_back(ptrVilain);   
		vPersonnage.push_back(ptrVilain);  
	}

	for (auto&& p : vPersonnage) {
		cout << *p << '\n' << trait << "\n";
	}
	for (auto&& h : vHeros) {
		h->changerCouleur(cout, "94");
		cout << *h << '\n' << trait << "\n";
	}
	for (auto&& v : vVilain) { 
		v->changerCouleur(cout, "91");
		cout << *v << '\n' << trait << "\n";
	}



}
