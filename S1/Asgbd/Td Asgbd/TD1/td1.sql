/* Q1 et Q2*/


CREATE TABLESPACE ORG DATAFILE  'ORG.dat'  SIZE 1024M AUTOEXTEND ON  ONLINE;
   
CREATE TEMPORARY TABLESPACE ORG_Temp TEMPFILE 'ORG_Temp.dat' SIZE 100M  AUTOEXTEND ON;

CREATE user GESTORG identified by gestion default Tablespace ORG  Temporary Tablespace ORG_Temp;

alter user GestOrg quota 700M ON ORG;

alter user GestOrg quota 50M on ORG_Temp;

CREATE TABLE LABORATOIRE-RECH();
CREATE TABLE PRODUIT-RECH();
CREATE TABLE BREVET-INVENTION();
CREATE TABLE ORGANISME();
CREATE TABLE DOMAINE-RECH();
CREATE TABLE THEMATIQUE-RECH();

/* ----------------- Q3 -------------------*/

/* Q3-a */
delete from  organisme
 where code_org='Univ10';

/* Q3-b */
Grant delete organisme to GestOrg;

/* G3-c */

i) La suppression a échoué a cause des clés étrangères.

ii) la conséquence : suppression qui va toucher toute les tables;

iii) elle sp