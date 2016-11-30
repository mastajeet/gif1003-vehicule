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
	Proprietaire mon_proprietaire("Ross", "Rick");
}


/**
 * \brief test qui valide qu'un objet proprietaire est bien formate
 */
TEST(Proprietaire,ReqProprietaireFormate){

	Proprietaire mon_proprietaire("Ross", "Rick");

	std::ostringstream output_stream;


			output_stream << "Proprietaire                     " << std::endl;
			output_stream << "-----------------                " << std::endl;
			output_stream << "Nom                             :" << "Ross" << std::endl;
			output_stream << "Prenom                          :" << "Rick" <<  std::endl;

	ASSERT_EQ(output_stream.str(),mon_proprietaire.reqProprietaireFormate());
}

/**
 * \brief test qui valide que l'accesseur reqNom fonctionne
 */
TEST(Proprietaire, ProprietaireReqNom){
	Proprietaire mon_proprietaire("Ross", "Rick");
	ASSERT_EQ("Ross",mon_proprietaire.reqNom());
}

/**
 * \brief test qui valide que l'accesseur reqNom fonctionne
 */
TEST(Proprietaire, ProprietaireReqPrenom){
	Proprietaire mon_proprietaire("Ross", "Rick");
	ASSERT_EQ("Rick",mon_proprietaire.reqPrenom());
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
		proprietaireValide("Louvain","Michel"){};


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
TEST_F(ProprietaireValide,ReqProprietaireFormate){

	VehiculePromenade mon_vechiculePromenade("1FUJAPCK25DU88948","ABC 123",3);
	proprietaireValide.ajouterVehicule(mon_vechiculePromenade);

	std::ostringstream output_stream;


			output_stream << "Proprietaire                     " << std::endl;
			output_stream << "-----------------                " << std::endl;
			output_stream << "Nom                             :" << proprietaireValide.reqNom() << std::endl;
			output_stream << "Prenom                          :" << proprietaireValide.reqPrenom() <<  std::endl;
			output_stream << "-----------------                " << std::endl;
			output_stream << "Numero de serie                 :" << "1FUJAPCK25DU88948" << std::endl;
			output_stream << "Numero d'immatriculation        :" << "ABC 123" << std::endl;
			output_stream << "date d'enregistrement           :" << mon_vechiculePromenade.reqDateEnregistrement().reqDateFormatee() << std::endl;
			output_stream << "Nombre Places                   :" << mon_vechiculePromenade.reqNbPlaces() << std::endl;
			output_stream << "tarif                           :" << mon_vechiculePromenade.tarificationAnnuelle() << "$" << std::endl;

	ASSERT_EQ(output_stream.str(),proprietaireValide.reqProprietaireFormate());
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
