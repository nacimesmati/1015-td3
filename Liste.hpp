#pragma once
#include <cstddef>
#include "cppitertools/range.hpp"
#include "gsl/span"  // On utilise encode gsl::span au lieu de std::span car c'est la version de span disponible à l'examen.
#include "Jeu.hpp"  
#include "Concepteur.hpp"
#include <memory>
#include <string>
using namespace std;
using namespace iter;

template <typename T>
class Liste
{

public:
	Liste() = default;

	const size_t& getNElements() const {
		return nElements_;
	}

	Liste<T>& operator=(const Liste<T>& autre)
	{
		if (this != &autre)
		{
			capacite_ = autre.capacite_;
			nElements_ = autre.nElements_;
			elements_ = make_unique<shared_ptr<T>[]>(capacite_);

			for (int i : iter::range(capacite_))
			{
				elements_[i] = autre.elements_[i];
			}
		}

		return *this;
	}

	// Constructeur de copie.
	Liste(const Liste<T>& liste)
	{
		*this = liste;
	}

	void setNElements(size_t nElements) {
		nElements_ = nElements;
	}


	const unique_ptr<shared_ptr<T>>& getElements() const {
		return elements_;
	}

	void ajouter(shared_ptr<T> element)
	{
		if (nElements_ == capacite_)
			changerCapacite(max(size_t(1), capacite_ * 2));

		elements_[nElements_++] = element;
	}

	void retirer(const shared_ptr<T> aRetirer) 
	{ 
		for (shared_ptr<T>& d : enSpan()) { 
			if (d == aRetirer) {
				if (nElements_ > 1)
					d = elements_[nElements_ - 1]; 
				nElements_--; 
			}
		}
	}

	void afficher() const
	{
		for (const shared_ptr<T> d : enSpan()) 
			d->afficher(); 
	}


	gsl::span<shared_ptr<T>> enSpan() const { return { elements_, nElements_ }; }  
private:

	void changerCapacite(size_t nouvelleCapacite)
	{
		assert(nouvelleCapacite >= nElements_);

		unique_ptr<shared_ptr<T>>  nouvelleListe = make_unique<shared_ptr<T>>[nouvelleCapacite];
		for (size_t i : range(nElements_)) {
			nouvelleListe[i] = move(elements_[i]);
		}

		elements_ = nouvelleListe;
		capacite_ = nouvelleCapacite;
	}



	size_t nElements_ = 0, capacite_ = 0;  // Pas besoin de déclarer explicitement un corps de constructeur avec ces initialisations.
	unique_ptr<shared_ptr<T>[]> elements_ = nullptr;
};

