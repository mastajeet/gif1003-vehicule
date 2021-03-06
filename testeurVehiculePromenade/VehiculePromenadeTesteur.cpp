/*
 * main.cpp
 *
 *  Created on: 2016-11-29
 *      Author: etudiant
 */


/*
 * main.cpp
 *
 *  Created on: 2016-11-29
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include <VehiculePromenade.h>
#include "contrat/ContratException.h"
#include <iostream>
#include "Date.h"
#include <sstream>


using namespace tp;

/**
 * \brief test qui valide qu'un vehicule avec tous les bons parametre sera cree sans lever erreur
 */
TEST(VehiculePromenade,VehiculePromenadeValide){
	VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","ABC 123",12);
	//ASSERT_EQ(2,mon_camion.m_nbEssieux);
}

/**
 * \brief test qui valide qu'un vehicule avec tous les bons parametre et un autre type de plaque (A12 ABC) sera cree sans lever erreur
 */
TEST(VehiculePromenade,VehiculePromenadeValidePatternPlaque2){
	VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","K99 ACC",12);
	//ASSERT_EQ(2,mon_camion.m_nbEssieux);
}

/**
 * \brief test qui valide qu'un vehicule avec tous les bons parametre et un autre type de plaque (123E123) sera cree sans lever erreur
 */
TEST(VehiculePromenade,VehiculePromenadeValidePatternPlaque3){
	VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","123E123",12);
	//ASSERT_EQ(2,mon_camion.m_nbEssieux);
}

/**
 * \brief test qui valide qu'un vehicule avec tous les bons parametre et un autre type de plaque (123 ABC) sera cree sans lever erreur
 */
TEST(VehiculePromenade,VehiculePromenadeValidePatternPlaque4){
	VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","123 ABC",12);
	//ASSERT_EQ(2,mon_camion.m_nbEssieux);
}

/**
 * \brief test qui valide qu'une excception est lancee lorsque le NIV du vehicule est invalide
 */
TEST(VehiculePromenade,VehiculePromenadeMauvaisNIV){
	ASSERT_THROW(VehiculePromenade mon_vehicule("1FUJAPCK5DU88948","ABC 123",12),PreconditionException);
}

/**
 * \brief test qui valide qu'une excception est lancee lorsque la plaque du vehicule est invalide
 */
TEST(VehiculePromenade,VehiculePromenadeMauvaiseImmatriculation){
	ASSERT_THROW(VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","A1C 123",12),PreconditionException);
}

/**
 * \brief test qui valide qu'une excception est lancee lorsque le vehicule n'a pas aumoins une place
 */
TEST(VehiculePromenade,VehiculePasAssezPlaces){
	ASSERT_THROW(VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","ABC 123",0),PreconditionException);
}

/**
 * \brief test qui valide que le l'accessuer reqNBPlace fonctionne
 */

TEST(VehiculePromenade,VehiculePromenadeReqNombrePlace){
	VehiculePromenade mon_vehicule("1FUJAPCK25DU88948","ABC 123",3);
	ASSERT_EQ(3,mon_vehicule.reqNbPlaces());
}

/**
 * \brief test qui valide que le formattage du texte fonctionne
 */
TEST(VehiculePromenade,CamionReqVehiculeFormate){
	VehiculePromenade mon_vehiculePromenade("1FUJAPCK25DU88948","ABC 123",3);


	std::ostringstream output_stream;

	output_stream << "Numero de serie                 :" << "1FUJAPCK25DU88948" << std::endl;
	output_stream << "Numero d'immatriculation        :" << "ABC 123" << std::endl;
	output_stream << "date d'enregistrement           :" << mon_vehiculePromenade.reqDateEnregistrement().reqDateFormatee() << std::endl;
	output_stream << "Nombre Places                   :" << mon_vehiculePromenade.reqNbPlaces() << std::endl;
	output_stream << "tarif                           :" << mon_vehiculePromenade.tarificationAnnuelle() << "$" << std::endl;


	ASSERT_EQ(output_stream.str(),mon_vehiculePromenade.reqVehiculeFormate());
}

/**
 * \class fixture pour faire differents tests
 */
class VehiculePromenadeValide: public ::testing::Test{
public:
	VehiculePromenadeValide():
		vehiculePromenadeValide("1FUJAPCK25DU88948","ABC 123",12){};
	VehiculePromenade vehiculePromenadeValide;
};




/**
 * \brief test qui valide que la tarification anuelle est bien 217.82$
 */
TEST_F(VehiculePromenadeValide,TarificationAnnuelle){

	ASSERT_EQ(217.82,vehiculePromenadeValide.tarificationAnnuelle());
}





