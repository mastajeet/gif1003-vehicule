/*
 * \file Camion.cpp
 * \brief fichier d'implementation de la classe Camion
 *
 * \date Nov 29, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */


#include "Camion.h"
#include "validationFormat.h"
#include "contrat/ContratException.h"
#include <sstream>

namespace tp{

	/**
	 * \brief constructeur de la classe camion
	 * \param[in] p_niv un numero de serie valide
	 * \param[in] p_immatriculation une plaque de license valide pour un camion
	 * \param[in] p_poids Le poids du vehicule (doit etre plus grand que 3000)
	 * \param[in] p_nbEssieux Le nombre d'essieux (doit etre plus grand que 1)
	 * \return un objet de type camion
	 */
	Camion::Camion(const std::string& p_niv,
			const std::string& p_immatriculation, int p_poids, int p_nbEssieux)
	:Vehicule(p_niv, p_immatriculation), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
	{
		PRECONDITION(util::validerImmatriculationCamion(this->reqImmatriculation()));
		PRECONDITION(this->reqNombreEssieux()>=2);
		PRECONDITION(this->reqPoids()>3000);
		POSTCONDITION(this->reqImmatriculation()==p_immatriculation);
		POSTCONDITION(this->reqNiv()==p_niv);
		POSTCONDITION(this->reqNombreEssieux()==p_nbEssieux);
		POSTCONDITION(this->reqPoids()==p_poids);
		INVARIANTS();
	}

	/**
	 * \brief accesseur de la propriete m_poids
	 */
	int Camion::reqPoids() const {
		return m_poids;

	}

	/**
	 * \brief accesseur de la propriete m_nbEssieux
	 */
	int Camion::reqNombreEssieux() const {
		return m_nbEssieux;
	}

	/**
	 * \brief fonction qui calcule le montant annuel du renouvellement de la plaque pour le camion
	 * \return un double contenant le montant de la tarification
	 */
	double Camion::tarificationAnnuelle() const{
		double tarification=0;
		switch (this->reqNombreEssieux()) {
			case 2:
				tarification = 	(this->m_poids<=4000) ? 556.50 : 881.50;
				break;
			case 3:
				tarification = 1512.94;
				break;
			case 4:
				tarification = 2132.94;
				break;
			case 5:
				tarification = 2698.06;
				break;
			default:
				tarification = 3577.06;
				break;
		}

		return tarification;
	}

	/**
	 * \brief mutateur de la propriete m_immatriculation
	 * \param[in] p_immatriculation un numero d'immatriculation valide pour un camion
	 * \pre valide si le numero d'immatriculation est possible pour un camion
	 * \post valide si l'immatriculation a bien ete enregistree
	 */
	void Camion::asgImmatriculation(const std::string& p_immatriculation) {
		PRECONDITION(util::validerImmatriculationCamion(p_immatriculation));
		m_immatriculation = p_immatriculation;
		POSTCONDITION(m_immatriculation == p_immatriculation);
		INVARIANTS();
	}


	Vehicule* Camion::clone() const{
		return new Camion(*this);

	}

	/**
	 * \brief fonction qui genere une vue en chaine de caractere des propriete du vehicule
	 * \return une string formatee avec les propriete du vehicule
	 */
	std::string Camion::reqVehiculeFormate() const {
			std::ostringstream output_stream;
			output_stream << Vehicule::reqVehiculeFormate() ;

			output_stream << "Nombre Essieux                  :" << reqNombreEssieux() << std::endl;
			output_stream << "Poids                           :" << reqPoids() << " kg" << std::endl;
			output_stream << "tarif                           :" << tarificationAnnuelle() << "$" << std::endl;

			return output_stream.str();
		}

	void Camion::verifieInvariant() const{
		Vehicule::verifieInvariant();
		INVARIANT(util::validerImmatriculationCamion(this->reqImmatriculation()));
	}



}

