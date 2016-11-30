/*
 * \file Vehicule.h
 * \brief fichier du prototype de la classe vehicule
 *
 * \date Oct 15, 2016
 * \author Jean-Thomas Baillargeon
 * \version 1.0
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_

#include <string>
#include "Date.h"




namespace tp{

/**
 * \class Vehicule
 * \brief Classe contennt les information requise pour creer un vehicule
 *
 *              Attributs: 	std::string m_niv le numero de serie
 *   etudiant           	std::string m_immatriculation le numero de plaque
 *              			util::Date m_dateEnregistrement le moment ou le vehicule a ete cree
 *
 */
	class Vehicule{

	public:
		Vehicule(const std::string& p_niv,const std::string& p_immatriculation);

		virtual std::string reqNiv() const;
		virtual std::string reqImmatriculation() const;
		virtual util::Date reqDateEnregistrement() const;
		virtual std::string reqVehiculeFormate() const;
		virtual bool operator== (const Vehicule& p_vehicule) const;

		virtual Vehicule* clone() const = 0;
		virtual double tarificationAnnuelle() const = 0;

		virtual ~Vehicule(){};


	protected:
		virtual void asgImmatriculation(const std::string& p_immatriculation) =0 ; //Je met cette methode pure virtuelle car il pourrait y avoir un trou de securite et pouvoir assigner un numero de plaque d'un mauvais type de vehicule
		std::string m_immatriculation;
		virtual void verifieInvariant() const;

	private:
		std::string m_niv;
		util::Date m_dateEnregistrement;
		virtual bool validerNiv(const std::string& p_niv) const;


	};




}


#endif /* VEHICULE_H_ */
