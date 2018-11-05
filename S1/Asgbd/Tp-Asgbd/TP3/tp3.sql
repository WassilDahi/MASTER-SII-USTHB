/*q1*/
connect sys as sysdba
select * from DICTIONARY;
select count(*) from DICTIONARY;


/*q2 */
select COLUMN_NAME from USER_TAB_COLUMNS where table_name ='ALL_TAB_COLUMNS' order by table_name;
select COLUMN_NAME from USER_TAB_COLUMNS where table_name ='USER_TAB_PRIVS' order by table_name;
select COLUMN_NAME from USER_TAB_COLUMNS where table_name ='USER_USERS' order by table_name;
select COLUMN_NAME from USER_TAB_COLUMNS where table_name ='ALL_CONSTRAINTS' order by table_name;


/* q3 */
select username , account_status   from user_users;

/* q4 */
select COLUMN_NAME from USER_TAB_COLUMNS where table_name ='ALL_TAB_COLUMNS' order by column_name;
select COLUMN_NAME from USER_TAB_COLUMNS where table_name ='USER_TAB_COLUMNS' order by column_name;

/* q6 */
select TABLE_NAME,OWNER from ALL_TAB_COLUMNS where OWNER='DBAHOPITAL';
select TABLE_NAME,OWNER from ALL_TAB_COLUMNS where OWNER='system';

/* q8 */

select TABLE_name,R_CONSTRAINT_NAME from USER_CONSTRAINTS;

select * from ALL_TAB_PRIVS where username='AdminHopital'; 
select * from SESSION_PRIVS where username='AdminHopital';


/*q11 */

select username, privilege from ALL_SYS_PRIVS order by username;
select * from DBA_TAB_PRIVS where owner='AdminHopital';

select * from SESSION_ROLES;