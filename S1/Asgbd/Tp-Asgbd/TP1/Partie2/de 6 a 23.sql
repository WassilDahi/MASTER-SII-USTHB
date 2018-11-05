/* 6 */
ALTER TABLE HOSPITALISATION
ADD Date_Host Date;

/* 7 */			
ALTER TABLE INFIRMIER
MODIFY SALAIRE not null;

ALTER TABLE PATIENT
MODIFY MUTUELLE not null;

/* 8 */
ALTER TABLE PATIENT
MODIFY PRENOM_PATIENT varchar(35);

/* 9 */
ALTER TABLE EMPLOYE
DROP COLUMN TELE_EMP;

DESC EMPLOYE;

ALTER TABLE EMPLOYE
ADD TELE_EMP varchar(30);

/* 10 */

ALTER TABLE PATIENT
RENAME COLUMN ADRESSE_PATIENT TO adr_pat;

DESC PATIENT;

/* 11 */
ALTER TABLE INFIRMIER
ADD CONSTRAINT CHK_Sallaire CHECK (SALAIRE>=10000 AND SALAIRE<=30000);

/* 12 */
ALTER TABLE MEDECIN
MODIFY SPECIALITE not null;

/* 13 */

voir les fichiers insertion.

/* 14 */
UPDATE SERVICE
SET DIRECTEUR =(SELECT NUM_EMP FROM EMPLOYE WHERE NOM_EMP='BOULARAS' AND PRENOM_EMP='FATIMA')
WHERE NOM_SERVICE='Cardiologie';

/* 15 */
ALTER TABLE INFIRMIER DISABLE CONSTRAINT CHK_SALLAIRE;

UPDATE INFIRMIER
SET SALAIRE = SALAIRE-5000 WHERE Rotation='JOUR';

/*reactivation de la contrainte impossible */
ALTER TABLE INFIRMIER ENABLE CONSTRAINT CHK_Sallaire;
 
 
/* 16 */
DELETE FROM MEDECIN WHERE SPECIALITE='CARDIOLOGUE';

/* 17 */
    CREATE INDEX SPEC ON MEDECIN('SPECIALITE');


/*********************Langage d'interrogation de dennées*******/
/*18 */
SELECT NOM_PATIENT , PRENOM_PATIENT FROM PATIENT WHERE MUTUELLE='MAAF';

/*19*/
SELECT lit, num_chambre, nom_service , prenom_patient , nom_patient, mutuelle FROM hospitalisation h , service s, patient p
WHERE h.num_patient=p.num_patient AND p.mutuelle like 'MN%' AND h.code_service = s.code_service AND s.batiment='B';

/*20*/ 
/* CREATE VIEW*/ 
CREATE VIEW Patmedspec (num_patient,nbmed,nbspec) 
AS SELECT num_patient,count(s.num_med),count(distinct SPECIALITE) 
FROM soigne s, medecin m WHERE (s.num_med=m.num_med ) GROUP BY(num_patient);

SELECT * FROM patmedspec WHERE nbmed>3; 

/* 21*/ 


/* 22*/

CREATE VIEW serpatient (code_service,nbpat)  
AS SELECT code_service,count(num_patient) 
FROM hospitalisation GROUP BYcode_service;

CREATE VIEW serinf (code_service,nbinf) 
AS SELECT code_service,count(num_inf)
FROM infirmier GROUP BYcode_service;

SELECT si.code_service,nbinf,nbpat,(nbpat/nbinf) 
FROM serinf si , serpatient sp 
WHERE si.code_service=sp.code_service ;

/*23*/ 
CREATE VIEW medecinservice(num_med,code_service) AS SELECT distinct num_med,code_service
FROM soigne s , hospitalisation h WHERE h.num_patient=s.num_patient ;

CREATE VIEW medecinservice2 (num_med,nbservice) AS SELECT num_med,count(code_service) 
FROM medecinservice GROUP BY(num_med);

SELECT nom_emp,prenom_emp FROM employe E , medecinservice2 M 
WHERE  M.nbser=(SELECT count (*) FROM service )
AND E.num_emp=M.num_med ;
