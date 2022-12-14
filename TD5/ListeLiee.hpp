#pragma once
#include "gsl/gsl_assert"
#include "gsl/pointers"
#include <iostream>
#include <string>
using namespace std;

template<typename T> class ListeLiee;
template<typename T> class Iterateur;

template<typename T>
struct Noeud
{
	friend class ListeLiee<T>;
	friend class Iterateur<T>;
public:
	Noeud(const T& d) : donnee_(d) {}
private:
	Noeud<T>* suivant_ = past_end;
	Noeud<T>* precedent_ = past_end;
	T donnee_;
	inline static constexpr Noeud<T>* past_end = nullptr;
};

template<typename T>
class Iterateur
{
	friend class ListeLiee<T>;
public:
	//TODO: Constructeur(s).
	Iterateur(Noeud<T>* position = Noeud<T>::past_end) : position_(position) {} 
	
	void avancer()
	{
		Expects(position_ != nullptr);
		//TODO: Changez la position de l'itérateur pour le noeud suivant
		position_ = position_->suivant_;
	}
	void reculer()
	{
		//NOTE: On ne demande pas de supporter de reculer à partir de l'itérateur end().
		Expects(position_ != nullptr);
		position_ = position_->precedent_;
	}
	T& operator*()
	{
		return position_->donnee_;
	}
	//TODO: Ajouter ce qu'il manque pour que les boucles sur intervalles fonctionnent sur une ListeLiee.
	Iterateur<T>& operator++() {
		Expects(position_ != nullptr);
		position_ = position_->suivant_;
		return *this;
	}

	bool operator==(const Iterateur<T>& it) const = default;
private:
	Noeud<T>* position_;
};

template<typename T>
class ListeLiee
{
	friend class Iterateur<T>;
public:
	using iterator = Iterateur<T>;  // Définit un alias au type, pour que ListeLiee<T>::iterator corresponde au type de son itérateur.

	//TODO: La construction par défaut doit créer une liste vide valide.
	ListeLiee() = default;
	
	~ListeLiee()
	{
		//TODO: Enlever la tête à répétition jusqu'à ce qu'il ne reste aucun élément.
		// Pour enlever la tête, 
		// 1. La tête doit devenir le suivant de la tête actuelle.
		// 2. Ne pas oublier de désallouer le noeud de l'ancienne tête (si pas fait automatiquement).
		while (tete_ != Noeud<T>::past_end) {
			auto temp = tete_->suivant_;
			delete tete_;
			tete_ = temp;
		}
	/*	for (auto& noeud : *this) {
		}*/
	}

	bool estVide() const { return taille_ == 0; }
	unsigned size() const { return taille_; }
	//NOTE: to_address (C++20) permet que ce même code fonctionne que vous utilisiez des pointeurs bruts ou intelligents (ça prend le pointeur brut associé au pointeur intelligent, s'il est intelligent).
	iterator begin() { return { to_address(tete_) }; }
	iterator end() { return { to_address(queue_->suivant_) }; }

	// Ajoute à la fin de la liste.
	void push_back(const T& item)
	{
		//TODO: Vous devez créer un nouveau noeud en mémoire.
		//TODO: Si la liste était vide, ce nouveau noeud est la tête et la queue;
		// autrement, ajustez la queue et pointeur(s) adjacent(s) en conséquence.
		Noeud<T>* nouveauNoeud = new Noeud<T>(item);
		if (this->estVide()) {
			tete_ = nouveauNoeud;
		}
		else {
			queue_->suivant_ = nouveauNoeud;
			nouveauNoeud->precedent_ = queue_;
		}
		queue_ = nouveauNoeud;
	}

	// Insère avant la position de l'itérateur.
	iterator insert(iterator it, const T& item)
	{
		//NOTE: Pour simplifier, vous n'avez pas à supporter l'insertion à la fin (avant "past the end"),
		// ni l'insertion au début (avant la tête), dans cette méthode.
		//TODO:
		// 1. Créez un nouveau noeud initialisé avec item.
		// 2. Modifiez les attributs suivant_ et precedent_ du nouveau noeud
		//    afin que le nouveau noeud soit lié au noeud précédent et suivant
		//    à l'endroit où il est inséré selon notre itérateur.
		// 3. Modifiez l'attribut precedent_ du noeud après la position d'insertion
		//    (l'itérateur) afin qu'il pointe vers le noeud créé.
		// 4. Modifiez l'attribut suivant_ du noeud avant la position d'insertion
		//    (précédent de l'itérateur) afin qu'il point vers le noeud créé.
		// 5. Incrémentez la taille de la liste.
		// 6. Retournez un nouvel itérateur initialisé au nouveau noeud.
		Noeud<T>* nouveauNoeud = new Noeud<T>(item);
		nouveauNoeud->suivant_ = it.position_;
		nouveauNoeud->precedent_ = it.position_->precedent_;
		it.position_->precedent_ = nouveauNoeud;
		it.position_->precedent_->suivant_ = nouveauNoeud;
		++taille_;
		iterator nouveauIt(nouveauNoeud);
		return nouveauIt;
	}

	// Enlève l'élément à la position it et retourne un itérateur vers le suivant.
	iterator erase(iterator it)
	{
		//TODO: Enlever l'élément à la position de l'itérateur.
		//  1. Le pointeur vers le Noeud à effacer est celui dans l'itérateur.
		//  2. Modifiez l'attribut suivant_ du noeud précédent pour que celui-ci
		//     pointe vers le noeud suivant la position de l'itérateur (voir 1.).
		//  3. Modifiez l'attribut precedent_ du noeud suivant la position de
		//     l'itérateur pour que celui-ci pointe vers le noeud précédent
		//     de la position de l'itérateur (voir 1.).
		//  4. Désallouez le Noeud à effacer (voir 1.).
		//  5. Décrémentez la taille de la liste
		//  6. Retournez un itérateur vers le suivant du Noeud effacé.
		//TODO: On veut supporter d'enlever le premier élément de la liste,
		//  donc en 2. il se peut qu'il n'y ait pas de précédent et alors c'est
		//  la tête de liste qu'il faut ajuster.
		//NOTE: On ne demande pas de supporter d'effacer le dernier élément (c'est similaire au cas pour enlever le premier).
		Noeud<T>* courant = it.position_;
		Noeud<T>* suivant = it.position_->suivant_;
		Noeud<T>* precedent = it.position_->precedent_;

		if (precedent == nullptr) {
			tete_ = suivant;
		}
		else
		{
			precedent->suivant_ = suivant;
		}
		suivant->precedent_ = precedent;
		delete courant;
		--taille_;
		iterator nouveauIt(suivant);

		return nouveauIt;
	}

private:
	gsl::owner<Noeud<T>*> tete_;  //NOTE: Vous pouvez changer le type si vous voulez.

	Noeud<T>* queue_;
	unsigned taille_;
};