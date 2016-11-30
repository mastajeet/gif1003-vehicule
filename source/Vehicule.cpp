/*
 * \file Vehicule.cpp
 * \brief implementation de la classe vehicule
 *
 * \date Oct 15, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */
#include "contrat/ContratException.h"
#include "validationFormat.h"
#include "Vehicule.h"
#include "Date.h"
#include <sstream>
#include <iostream>


namespace tp{

	/**
	 * \brief constructeur de la classe vehicule
	 * \param[in] un numero de serie valid
	 * \param[in] une plaque de license valide
	 * \return un objet de type vehicule
	 */
	Vehicule::Vehicule(const std::string& p_niv,const std::string& p_immatriculation)
	:m_niv(p_niv), m_immatriculation(p_immatriculation), m_dateEnregistrement(util::Date())
	{
		PRECONDITION(util::validerNiv(p_niv))
		POSTCONDITION(m_niv==p_niv);
		POSTCONDITION(m_immatriculation==p_immatriculation);
		INVARIANTS();
	}

	/**
	 * \brief accesseur de la propriete m_niv
	 */
	std::string Vehicule::reqNiv() const {
		return m_niv;
	}

	/**
	 * \brief accesseur de la propriete m_immatriculation
	 */
	std::string Vehicule::reqImmatriculation() const {
		return m_immatriculation;
	}

	/**
	 * \brief accesseur de la propriete m_dateEnregistrement
	 */
	util::Date Vehicule::reqDateEnregistrement() const {
		return m_dateEnregistrement;
	}


//	void Vehicule::asgImmatriculation(const std::string& p_immatriculation) {
//		m_immatriculation = p_immatriculation;
//	}

	/**
	 * \brief fonction qui genere une vue en chaine de caractere des propriete du vehicule
	 * \return une string formatee avec les propriete du vehicule
	 */
	std::string Vehicule::reqVehiculeFormate() const {
		std::ostringstream output_stream;

		output_stream << "Numero de serie                 :" << reqNiv() << std::endl;
		output_stream << "Numero d'immatriculation        :" << reqImmatriculation() << std::endl;
		output_stream << "date d'enregistrement           :" << reqDateEnregistrement().reqDateFormatee() << std::endl;

		return output_stream.str();
	}

	/**
	 * \brief surcharge de l'operateur ==, comparant tous les attribus membre de la classe vehicule
	 * \param[in] p_vehicule un autre objet de type vehicule
	 * \return un boolein vrai si tous les attribus sont egaux
	 */
	bool Vehicule::operator ==(const Vehicule& p_vehicule) const {
		bool vehiculeEstEgal = false;
		if(m_niv == p_vehicule.m_niv and m_immatriculation == p_vehicule.m_immatriculation and m_dateEnregistrement == p_vehicule.m_dateEnregistrement)
		{
			vehiculeEstEgal = true;
		}

		return vehiculeEstEgal;
	}




	/**
	 * \brief fonction qui valide si un numero d'identifiaction est valide ou non
	 * \param[in] p_niv un numero d'identification a tester
	 * \return un boolein vrai si le niv est valide
	 */
	bool Vehicule::validerNiv(const std::string& p_niv) const{
		return util::validerNiv(p_niv);

	}

	void Vehicule::verifieInvariant() const{
		INVARIANT(util::validerNiv(this->reqNiv()));
	}


}
