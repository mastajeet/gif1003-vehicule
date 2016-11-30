/*
 * main.cpp
 *
 *  Created on: 2016-11-29
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Proprietaire.h"
#include "contrat/ContratException.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include <iostream>


using namespace tp;

/**
 * \brief test qui valide qu'un objet proprietaire est cree sans erreur lors que tous les parametres sont bons
 */
TEST(Proprietaire, ProprietaireValide){
	Proprietaire mon_proprietaire("Rick","Ross");
}

/**
 * \brief test qui valide qu'une exception est levee lorsque le nom de famille est vide
 */
TEST(Proprietaire, ProprietaireManqueNomFamille){
	ASSERT_THROW(Proprietaire mon_proprietaire("Mr.305",""),PreconditionException);
}

/**
 * \brief test qui valide qu'une exception est levee lorsque le prenom est vide
 */
TEST(Proprietaire, ProprietairePrenom){
	ASSERT_THROW(Proprietaire mon_proprietaire("","Worldwide"),PreconditionException);
}



class ProprietaireValide: public ::testing::Test{

public:
	ProprietaireValide() :
		proprietaireValide("Michel","Louvain"){};


	Proprietaire proprietaireValide;

};

/**
 * \brief test qui valide qu'aucune erreur ne survient lorsqu'on ajoute un camion valide
 */
TEST_F(ProprietaireValide,AjoutCamion){

	Camion mon_camion("1FUJAPCK25DU88948","L123456",3500,3);
	proprietaireValide.ajouterVehicule(mon_camion);

}

/**
 * \brief test qui valide qu'aucune erreur ne survient lorsqu'on ajoute un vehicule de promenade valide
 */
TEST_F(ProprietaireValide,AjoutVehiculePromenade){

	VehiculePromenade mon_vechiculePromenade("1FUJAPCK25DU88948","ABC 123",3);
	proprietaireValide.ajouterVehicule(mon_vechiculePromenade);

}

/**
 * \brief test qui valide qu'aucune erreur ne survient lorsqu'on ajoute deux vehicule polymorphe valides
 */
TEST_F(ProprietaireValide,AjoutDeuxVehiculePolymorphes){

	VehiculePromenade mon_vechiculePromenade("1FUJAPCK25DU88948","ABC 123",3);
	proprietaireValide.ajouterVehicule(mon_vechiculePromenade);
	Camion mon_camion("1FUJAPCK25DU88948","L123456",3500,3);
	proprietaireValide.ajouterVehicule(mon_camion);


}
