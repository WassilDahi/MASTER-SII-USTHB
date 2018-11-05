Create User  AdminHopital  identified by password default Tablespace HOPITAL_TBS
Temporary Tablespace HOPITAL_TempTBS;

/* q2 */

connect AdminHopital

/* q3 */

Grant create session to AdminHopital ;
connect AdminHopital

/* q4 */

grant create table, create user to AdminHopital;


select username, privilege from USER_SYS_PRIVS order by username;

alter user AdminHopital QUOTA 100M ON HOPITAL_TBS;

alter user AdminHopital QUOTA 100M ON HOPITAL_TempTBS;

/* q5 */

Select * from DBAHOPITAL.EMPLOYE;

erreur ; ma3douche droit 

/* q6 */

 grant select on DBAHOPITAL.employe to AdminHopital;

/* q7 */

    update DBAHOPITAL.EMPLOYE
       set adresse_emp='152, rue Hassiba Ben Bouali 2ème étage -Hamma-
Alger'
     where nom_emp='ABDELMOUMEN' and prenom_emp='Nassima';

/* q8 */
connect DBAHOPITAL

grant update on DBAHOPITAL.EMPLOYE to AdminHopital;

select table_name , privilege from USER_TAB_PRIVS order by table_name ;

update DBAHOPITAL.EMPLOYE
       set adresse_emp='152, rue Hassiba Ben Bouali 2ème étage -Hamma-
Alger'
     where nom_emp='ABDELMOUMEN' and prenom_emp='Nassima';

/* q9 */
    CREATE INDEX EMPLOYENOM_IX on DBAHOPITAL.employe(NOM_EMP);

    connect DBAHOPITAL

   

/* 10 */
 grant  index on DBAHOPITAL.employe to AdminHopital;
    select table_name , privilege from USER_TAB_PRIVS order by table_name ;

    CREATE INDEX EMPLOYENOM_IX on DBAHOPITAL.employe(NOM_EMP);

/* 11 */
connect DBAHOPITAL
revoke index,select , update  on DBAHOPITAL.employe from AdminHopital;

/* 12 */
select table_name , privilege from USER_TAB_PRIVS order by table_name ;

/*13 */

create profile Admin_Profil LIMIT 
SESSIONS_PER_USER 4 
CPU_PER_CALL 40 
CONNECT_TIME 50 
LOGICAL_READS_PER_SESSION 1500 
LOGICAL_READS_PER_CALL 1500 
IDLE_TIME 30 
PRIVATE_SGA 20k 
FAILED_LOGIN_ATTEMPTS 3  
PASSWORD_LIFE_TIME 60 
PASSWORD_REUSE_TIME 40 
PASSWORD_LOCK_TIME 1/5 
PASSWORD_GRACE_TIME 5;

/*14 */

alter user AdminHopital Profile Admin_Profil;

/* 15 */

create role GestionnairePatient;
grant select on patient to GestionnairePatient;
grant select,update on hospitalisation to GestionnairePatient;
grant select on soigne to GestionnairePatient;

/* 16 */

grant GestionnairePatient to AdminHopital;
