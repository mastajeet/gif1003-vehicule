/*
 * main.cpp
 *
 *  Created on: 2016-11-29
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Camion.h"
#include "contrat/ContratException.h"
#include <iostream>

using namespace tp;

/**
 * \brief test qui valide qu'un objet camion est cree sans erreur lors que tous les parametres sont bons
 */
TEST(Camion,CamionValide){
	Camion mon_camion("1FUJAPCK25DU88948","L123456",3500,3);
	//ASSERT_EQ(2,mon_camion.m_nbEssieux);
}

/**
 * \brief test qui valide qu'une exception est levee lorsque le niv du vehicule est invalide
 */
TEST(Camion,CamionMauvaisNIV){
	ASSERT_THROW(Camion mon_camion("1FUJAPCK5DU88948","L123456",3500,3),PreconditionException);
}

/**
 * \brief test qui valide qu'une exception est levee lorsque la plaque d'immatriculation du vehicule est invalide
 */
TEST(Camion,CamionMauvaiseImmatriculation){
	ASSERT_THROW(Camion mon_camion("1FUJAPCK25DU88948","L12456",3500,3),PreconditionException);
}

/**
 * \brief test qui valide qu'une exception est levee lorsque le poids du vehicule est plus petit a 3001 kg
 */
TEST(Camion,CamionTropLeger){
	ASSERT_THROW(Camion mon_camion("1FUJAPCK25DU88948","L123456",3000,3),PreconditionException);
}

/**
 * \brief test qui valide qu'une exception est levee lorsque le nombre d'essieux est plus petit que 2
 */
TEST(Camion,CamionPasAssezEssieux){
	ASSERT_THROW(Camion mon_camion("1FUJAPCK25DU88948","L123456",3500,1),PreconditionException);
}


class CamionValide3500_2: public ::testing::Test{
public:
	CamionValide3500_2():
		camionValide("1FUJAPCK25DU88948","L123456",3500,2){};
	Camion camionValide;
};


class CamionValide4500_2: public ::testing::Test{
public:
	CamionValide4500_2():
		camionValide("1FUJAPCK25DU88948","L123456",4500,2){};
	Camion camionValide;
};

class CamionValide4500_3: public ::testing::Test{
public:
	CamionValide4500_3():
		camionValide("1FUJAPCK25DU88948","L123456",4500,3){};
	Camion camionValide;
};

class CamionValide4500_4: public ::testing::Test{
public:
	CamionValide4500_4():
		camionValide("1FUJAPCK25DU88948","L123456",4500,4){};
	Camion camionValide;
};

class CamionValide4500_5: public ::testing::Test{
public:
	CamionValide4500_5():
		camionValide("1FUJAPCK25DU88948","L123456",4500,5){};
	Camion camionValide;
};

class CamionValide4500_6: public ::testing::Test{
public:
	CamionValide4500_6():
		camionValide("1FUJAPCK25DU88948","L123456",4500,6){};
	Camion camionValide;
};

class CamionValide4500_10: public ::testing::Test{
public:
	CamionValide4500_10():
		camionValide("1FUJAPCK25DU88948","L123456",4500,10){};
	Camion camionValide;
};


/**
 * \brief test qui valide la tarification annuelle pour un camion de 2 essieux entre 3001 et 4000 kg
 */
TEST_F(CamionValide3500_2,TarificationAnnuelle){

	ASSERT_EQ(556.50,camionValide.tarificationAnnuelle());
}

/**
 * \brief test qui valide la tarification annuelle pour un camion de 2 essieux et plus lourds que 4000 kg
 */
TEST_F(CamionValide4500_2,TarificationAnnuelle){

	ASSERT_EQ(881.50,camionValide.tarificationAnnuelle());
}

/**
 * \brief test qui valide la tarification annuelle pour un camion de 3 essieux
 */
TEST_F(CamionValide4500_3,TarificationAnnuelle){

	ASSERT_EQ(1512.94,camionValide.tarificationAnnuelle());
}

/**
 * \brief test qui valide la tarification annuelle pour un camion de 4 essieux
 */
TEST_F(CamionValide4500_4,TarificationAnnuelle){

	ASSERT_EQ(2132.94,camionValide.tarificationAnnuelle());
}

/**
 * \brief test qui valide la tarification annuelle pour un camion de 5 essieux
 */
TEST_F(CamionValide4500_5,TarificationAnnuelle){

	ASSERT_EQ(2698.06,camionValide.tarificationAnnuelle());
}

/**
 * \brief test qui valide la tarification annuelle pour un camion de 6 essieux
 */
TEST_F(CamionValide4500_6,TarificationAnnuelle){

	ASSERT_EQ(3577.06,camionValide.tarificationAnnuelle());
}

/**
 * \brief test qui valide la tarification annuelle pour un camion de 10 essieux
 */
TEST_F(CamionValide4500_10,TarificationAnnuelle){

	ASSERT_EQ(3577.06,camionValide.tarificationAnnuelle());
}

