/*
 * \file Proprietaire.h
 * \brief fichier du prototype de la classe Proprietaire
 * \date Nov 29, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */

#include <string>
#include <vector>
#include "Vehicule.h"

#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_

namespace tp{
/**
 * \class Proprietaire
 * \brief Classe contennt les information requise pour creer un Proprietaire
 *
 *              Attributs: 	std::string m_nom le nom du proprieraire
 *   						std::string m_prenom le prenom du proprietaire
 *              			std::vector<Vehicule*> m_vVehicules un vecteur de vehicules
 *
 */
	class Proprietaire{

	public:
		Proprietaire(const std::string& p_nom, const std::string& p_prenom);
		std::string reqNom() const;
		std::string reqPrenom() const;
		void ajouterVehicule (const Vehicule& p_nouveauVehicule);
		std::string reqProprietaireFormate() const;
		~Proprietaire();

	private:
		std::string m_nom;
		std::string m_prenom;
		std::vector<Vehicule*> m_vVehicules;
		virtual void verifieInvariant() const;

	};

}

#endif /* PROPRIETAIRE_H_ */
