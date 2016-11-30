/*
 * VehiculePrommenade.cpp
 *
 *  Created on: 2016-11-29
 *      Author: etudiant
 */



/*
 * \file Camion.cpp
 * \brief fichier d'implementation de la classe Camion
 *
 * \date Nov 29, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */


#include "VehiculePromenade.h"

#include "validationFormat.h"
#include "contrat/ContratException.h"
#include <sstream>

namespace tp{

	/**
	 * \brief constructeur de la classe vehicule de promenade
	 * \param[in] p_niv un numero de serie valide
	 * \param[in] p_immatriculation une plaque de license valide pour un vehicule de promenade
	 * \param[in] p_nbPlaces Le nombre de places (doit etre plus grand que 0)
	 * \return un objet de type VehiculePromenade
	 */
	VehiculePromenade::VehiculePromenade(const std::string& p_niv,
			const std::string& p_immatriculation, int p_nbPlaces)
	:Vehicule(p_niv, p_immatriculation), m_nbPlaces(p_nbPlaces)
	{
		PRECONDITION(util::validerImmatriculationPromenade(this->reqImmatriculation()));
		PRECONDITION(this->reqNbPlaces()>0);
		POSTCONDITION(this->reqImmatriculation()==p_immatriculation);
		POSTCONDITION(this->reqNiv()==p_niv);
		POSTCONDITION(this->reqNbPlaces()==p_nbPlaces);
	}

	/**
	 * \brief accesseur de la propriete m_nbPlaces
	 */
	int VehiculePromenade::reqNbPlaces() const {
		return m_nbPlaces;

	}


	/**
	 * \brief fonction qui calcule le montant annuel du renouvellement de la plaque pour le vehicule de promenade
	 * \return un double contenant le montant de la tarification
	 */
	double VehiculePromenade::tarificationAnnuelle() const{

		return 217.82;
	}

	/**
	 * \brief mutateur de la propriete m_immatriculation
	 * \param[in] p_immatriculation un numero d'immatriculation valide pour une vehicule de promenade
	 * \pre valide si le numero d'immatriculation est possible pour un vehicule de promenade
	 * \post valide si l'immatriculation a bien ete enregistree
	 */
	void VehiculePromenade::asgImmatriculation(const std::string& p_immatriculation) {
		PRECONDITION(util::validerImmatriculationPromenade(p_immatriculation));
		m_immatriculation = p_immatriculation;
		POSTCONDITION(m_immatriculation == p_immatriculation);
	}


	/**
	 * \brief creer une copie de l'object VehiclePromenade dans un object polymorphe de type Vehicule
	 */
	Vehicule* VehiculePromenade::clone() const{
		return new VehiculePromenade(*this);

	}

	/**
	 * \brief fonction qui genere une vue en chaine de caractere des propriete du vehicule
	 * \return une string formatee avec les propriete du vehicule
	 */
	std::string VehiculePromenade::reqVehiculeFormate() const {
			std::ostringstream output_stream;
			output_stream << Vehicule::reqVehiculeFormate() ;

			output_stream << "Nombre Places                   :" << reqNbPlaces() << std::endl;
			output_stream << "tarif                           :" << tarificationAnnuelle() << "$" << std::endl;

			return output_stream.str();
		}

	void VehiculePromenade::verifieInvariant() const{
			Vehicule::verifieInvariant();
			INVARIANT(util::validerImmatriculationPromenade(this->reqImmatriculation()));
	}

}


