
/*
 * \file Proprietaire.cpp
 * \brief fichier de l'implementation de la classe Proprietaire
 * \date Nov 29, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */

#include "contrat/ContratException.h"
#include "Proprietaire.h"
#include <sstream>

namespace tp{


	/**
	 * \brief constructeur de la classe proprietaire
	 * \param[in] le nom du proprietaire
	 * \param[in] le prenom du proprietaire
	 * \return un objet de type proprietaire
	 */
	Proprietaire::Proprietaire(const std::string& p_nom,
			const std::string& p_prenom)
	:m_nom(p_nom), m_prenom(p_prenom)
	{
		PRECONDITION(this->reqNom()!="");
		PRECONDITION(this->reqPrenom()!="");

		POSTCONDITION(this->reqNom()==p_nom);
		POSTCONDITION(this->reqPrenom()==p_prenom);

	}

	/**
	 * \brief accesseur de la propriete m_nom
	**/
	std::string Proprietaire::reqNom() const {
		return this->m_nom;
	}

	/**
	 * \brief accesseur de la propriete m_prenom
	**/
	std::string Proprietaire::reqPrenom() const {
		return this->m_prenom;
	}

	/**
	 * \brief fonction qui ajoute un vehicule a la liste du proprietaire
	 * \param[in] p_nouveauVehicule un objet polymorphe de type vehicule
	**/
	void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule) {
		const int nb_vehicule = m_vVehicules.size();

		m_vVehicules.push_back(p_nouveauVehicule.clone());

		POSTCONDITION((nb_vehicule+1)==(int)m_vVehicules.size());
	}

	/**
	 * \brief fonction qui genere une vue en chaine de caractere du proprietaire et de ses vehicules
	 * \return une string formatee
	 */
	std::string Proprietaire::reqProprietaireFormate() const {

		std::ostringstream output_stream;


		output_stream << "Proprietaire                     " << std::endl;
		output_stream << "-----------------                " << std::endl;
		output_stream << "Nom                             :" << this->reqNom() << std::endl;
		output_stream << "Prenom                          :" << this->reqPrenom() <<  std::endl;


		for (int i=0; i < (int)m_vVehicules.size(); i++) {
			output_stream << "-----------------                " << std::endl;
			output_stream << this->m_vVehicules[i]->reqVehiculeFormate();
		}

		return output_stream.str();

	}

	/**
	 * \brief destructeur qui libere la memoire pour chacun des pointeurs vehicules crees
	 */
	Proprietaire::~Proprietaire() {
		for (int i=0; i < (int)m_vVehicules.size(); i++) {
			this->m_vVehicules[i]->~Vehicule();
		}

	}

}
