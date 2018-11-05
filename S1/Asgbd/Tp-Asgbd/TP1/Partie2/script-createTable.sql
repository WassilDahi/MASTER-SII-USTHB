CREATE TABLE SERVICE (
	CODE_SERVICE varchar(10) not null,
	NOM_SERVICE varchar(30),
	BATIMENT varchar(2),
	DIRECTEUR integer,
	Constraint pk_service Primary key(CODE_SERVICE)	
);
CREATE TABLE CHAMBRE(
	CODE_SERVICE varchar(10) not null,
	NUM_CHAMBRE integer not null,
	SURVEILLANT integer,
	NB_LITS integer,
	Constraint pk_chambre Primary key(CODE_SERVICE,NUM_CHAMBRE)	
);
CREATE TABLE EMPLOYE(
	NUM_EMP integer not null,
	NOM_EMP varchar(30),
	PRENOM_EMP varchar(30),
	ADRESSE_EMP varchar(30),
	TELE_EMP varchar(30),
	Constraint pk_employe Primary key(NUM_EMP)	
);
CREATE TABLE MEDECIN (
	NUM_MED integer not null,
	SPECIALITE varchar(30),
	Constraint pk_medecin Primary key(NUM_MED)	
);
CREATE TABLE INFIRMIER(
	NUM_INF integer not null,
	CODE_SERVICE varchar(30),
	ROTATION varchar(10),
	SALAIRE float,
	Constraint pk_infirmier Primary key(NUM_INF)	
);
CREATE TABLE PATIENT (
	NUM_PATIENT integer not null,
	NOM_PATIENT varchar(30),
	PRENOM_PATIENT varchar(30),
	ADRESSE_PATIENT varchar(30),
	TELE_PATIENT varchar(30),
	MUTUELLE varchar(15),
	Constraint pk_patient Primary key(NUM_PATIENT)	
);
CREATE TABLE HOSPITALISATION  (
	NUM_PATIENT integer not null,
	CODE_SERVICE varchar(10),
	NUM_CHAMBRE integer,
	LIT integer,
	Constraint pk_hospitalisation Primary key(NUM_PATIENT)	
);
CREATE TABLE SOIGNE   (
	NUM_PATIENT integer not null,
	NUM_MED integer not null,
	Constraint pk_soigne Primary key(NUM_PATIENT,NUM_MED)	
);