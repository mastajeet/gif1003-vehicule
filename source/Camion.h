/*
 * \file Camion.h
 * \brief fichier du prototype de la classe Camion
 *
 * \date Nov 29, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */

#include "Vehicule.h"

#ifndef CAMION_H_
#define CAMION_H_


/**
 * \class Camion
 * \brief Classe contennt les information requise pour creer un Camion
 *
 *              Attributs: 	std::string m_niv le numero de serie
 *   						std::string m_immatriculation le numero de plaque
 *              			util::Date m_dateEnregistrement le moment ou le vehicule a ete cree
 *              			int m_nbEssieux le nombre d'essieux du camion (plus grand que 1)
 *              			int m_poids le poids du camion (plus grand que 3000)
 *
 */


namespace tp{


class Camion: public Vehicule{

	public:
		Camion(const std::string& p_niv,
								  const std::string& p_immatriculation,
								  int p_poids,
								  int p_nbEssieux);
		virtual int reqPoids() const;
		virtual int reqNombreEssieux() const;
		virtual Vehicule* clone() const;
		virtual double tarificationAnnuelle() const;
		virtual std::string reqVehiculeFormate() const;


	protected:
		virtual void verifieInvariant() const;
		virtual void asgImmatriculation(const std::string& p_immatriculation);
	private:
		int m_poids;
		int m_nbEssieux;

	};


}


#endif /* CAMION_H_ */
