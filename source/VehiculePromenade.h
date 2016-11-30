
/*
 * \file VehiculePromenade.h
 * \brief fichier du prototype de la classe VehiculePromenade
 *
 * \date Nov 29, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */

#include "Vehicule.h"

#ifndef VEHICULEPROMMENADE_H_
#define VEHICULEPROMMENADE_H_





namespace tp {
/**
 * \class VehiculePromenade
 * \brief Classe contennt les information requise pour creer un VehiculePromenade
 *
 *              Attributs: 	std::string m_niv le numero de serie
 *   						std::string m_immatriculation le numero de plaque
 *              			util::Date m_dateEnregistrement le moment ou le vehicule a ete cree
 *              			int m_nbPlace le nombre de place du vehicule
 *
 */
	class VehiculePromenade: public Vehicule {

	public:
		VehiculePromenade(const std::string& p_niv,
				const std::string& p_immatriculation, int p_nbPlaces);
		virtual int reqNbPlaces() const;		virtual double tarificationAnnuelle() const;
		virtual std::string reqVehiculeFormate() const;
		virtual Vehicule* clone() const;


	protected:
		virtual void verifieInvariant() const;
		virtual void asgImmatriculation(const std::string& p_immatriculation);
	private:
		int m_nbPlaces;

	};

}



#endif /* VEHICULEPROMMENADE_H_ */
