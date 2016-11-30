#include <iostream>
#include <string>

#include "validationFormat.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Proprietaire.h"

using namespace std;



void afficherInformation(const tp::Proprietaire& p_proprietaire)
{
	cout << endl ;
	cout << "-- Information sur le proprietaire -------------------"<< endl ;
	cout << p_proprietaire.reqProprietaireFormate() << endl;
	cout << endl ;
}

string obtenirImmatriculationVehiculePromenade()
{

	bool valid_immatriculation = false;
	string immatriculation;

	do{
		cout << "Veuillez entrer le numero d'immatriculation du vehicule de promenade" << endl;

		getline(cin,immatriculation);

		if(util::validerImmatriculationPromenade(immatriculation))
		{
			valid_immatriculation = true;
		}

	}while(!valid_immatriculation);

	return immatriculation;
}

string obtenirImmatriculationCamion()
{

	bool valid_immatriculation = false;
	string immatriculation;

	do{
		cout << "Veuillez entrer le numero d'immatriculation du camion" << endl;

		getline(cin,immatriculation);

		if(util::validerImmatriculationCamion(immatriculation))
		{
			valid_immatriculation = true;
		}

	}while(!valid_immatriculation);

	return immatriculation;
}

string obtenirNumeroSerie()
{
	bool valid_niv = false;
	string niv;
	do{
		cout << "Veuillez entrer le numero de serie du vehicule" << endl;
		cin >> niv;
		if(util::validerNiv(niv))
		{
			valid_niv = true;
		}

	}while(!valid_niv);
	cin.ignore();
	return niv;
}

int obtenirNbPlaces()
{



	bool valid = false;
	int nbPlaces ;
	do{
		cout << "Veuillez entrer le nombre de place du vehicule (Plus grand que 0)" << endl;
		cin >> nbPlaces;
		if(nbPlaces>0)
		{
			valid = true;
		}

	}while(!valid);

	cin.ignore();
	return nbPlaces;
}


int obtenirNbEssieux()
{



	bool valid = false;
	int nbEssieux ;
	do{
		cout << "Veuillez entrer le nombre d'essieux (Plus grand que 1)" << endl;
		cin >> nbEssieux;
		if(nbEssieux>1)
		{
			valid = true;
		}

	}while(!valid);

	cin.ignore();
	return nbEssieux;
}

int obtenirPoids()
{



	bool valid = false;
	int poids ;

	do{
		cout << "Veuillez entrer le poids du vehicule (Plus grand que 3000)" << endl;
		cin >> poids;
		if(poids>3000)
		{
			valid = true;
		}

	}while(!valid);

	cin.ignore();
	return poids;
}



string obtenirPrenom()
{


	bool valid = false;
	string prenom;
	do{
		cout << "Veuillez entrer le prenom du proprietaire" << endl;
		cin >> prenom;
		if(prenom!="")
		{
			valid = true;
		}

	}while(!valid);

	cin.ignore();
	return prenom;
}

string obtenirNom()
{
	bool valid = false;
	string nom;
	do{
		cout << "Veuillez entrer le nom de famille du proprietaire" << endl;
		cin >> nom;
		if(nom!="")
		{
			valid = true;
		}

	}while(!valid);

	cin.ignore();
	return nom;
}


int main() {

	string prenom;
	string nom;


	string niv_camion;
	string immatriculation_camion;
	int nbEssieux;
	int poids;

	string niv_vehiculePromenade;
	string immatriculation_vehiculePromenade;
	int nbPlaces;


	cout << "-- Section proprietaire ----- " << endl;
	prenom = obtenirPrenom();
	nom = obtenirNom();

	cout << "-- Section camion       ----- " << endl;
	niv_camion = obtenirNumeroSerie();
	immatriculation_camion = obtenirImmatriculationCamion();
	poids = obtenirPoids();
	nbEssieux = obtenirNbEssieux();

	cout << "-- Section Vehicule Promenade " << endl;

	niv_vehiculePromenade = obtenirNumeroSerie();
	immatriculation_vehiculePromenade = obtenirImmatriculationVehiculePromenade();
	nbPlaces = obtenirNbPlaces();

	tp::Proprietaire mon_proprietaire = tp::Proprietaire(nom,prenom);
	tp::VehiculePromenade mon_vehicule = tp::VehiculePromenade(niv_vehiculePromenade,immatriculation_vehiculePromenade,nbPlaces);
	tp::Camion mon_camion = tp::Camion(niv_camion,immatriculation_camion,poids,nbEssieux);
	mon_proprietaire.ajouterVehicule(mon_camion);
	mon_proprietaire.ajouterVehicule(mon_vehicule);
	afficherInformation(mon_proprietaire);

	cout << "Merci d'avoir utilise le createur de voiture 2000" << endl;
}
