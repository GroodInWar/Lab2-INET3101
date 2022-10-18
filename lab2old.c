#include "lab2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



int main() {
    // First Temp
    char temp1name[] = "GustavoSakamotodeToledo\0"; 
    char temp1clsname[] = "C_Programming_and_Applications\0";
    char temp1clsid[] = "INET3101\0";
    int temp1id = 5717290;
    struct record *temp1 = malloc(sizeof(struct record));

    temp1->studentFullName = malloc(sizeof(char)*strlen(temp1name));
    temp1->className = malloc(sizeof(char)*strlen(temp1clsname));
    temp1->classID = malloc(sizeof(char)*strlen(temp1clsid));

    strncpy(temp1->studentFullName, temp1name, strlen(temp1name));
    strncpy(temp1->className, temp1clsname, strlen(temp1clsname));
    strncpy(temp1->classID, temp1clsid, strlen(temp1clsid));
    temp1->studentID = temp1id;


    // Second Temp
    char temp2name[] = "GustavoSakamotodeToledo\0"; 
    char temp2clsname[] = "Multivariable_Calculus\0";
    char temp2clsid[] = "MATH2263\0";
    int temp2id = 5717290;
    struct record *temp2 = malloc(sizeof(struct record));

    temp2->studentFullName = malloc(sizeof(char)*strlen(temp2name));
    temp2->className = malloc(sizeof(char)*strlen(temp2clsname));
    temp2->classID = malloc(sizeof(char)*strlen(temp2clsid));

    strncpy(temp2->studentFullName, temp2name, strlen(temp2name));
    strncpy(temp2->className, temp2clsname, strlen(temp2clsname));
    strncpy(temp2->classID, temp2clsid, strlen(temp2clsid));
    temp2->studentID = temp2id;


    // Third Temp
    char temp3name[] = "GustavoSakamotodeToledo\0"; 
    char temp3clsname[] = "Applied_Linear_Algebra\0";
    char temp3clsid[] = "MATH4242\0";
    int temp3id = 5717290;
    struct record *temp3 = malloc(sizeof(struct record));

    temp3->studentFullName = malloc(sizeof(char)*strlen(temp3name));
    temp3->className = malloc(sizeof(char)*strlen(temp3clsname));
    temp3->classID = malloc(sizeof(char)*strlen(temp3clsid));

    strncpy(temp3->studentFullName, temp3name, strlen(temp3name));
    strncpy(temp3->className, temp3clsname, strlen(temp3clsname));
    strncpy(temp3->classID, temp3clsid, strlen(temp3clsid));
    temp3->studentID = temp3id;
    
    // ADDING TEMPS TO DB
    add_record(temp1);
    add_record(temp2);
    add_record(temp3);

    while(true) {
        printf("\n============MENU============\n1. Print all records\n2. Print number of records\n3. Print size of database\n4. Add record\n5. Delete record\n6. Print number of accesses\n   to database\n7. Exit\n\n>");
        int action;
        scanf("%d", &action);
        getchar();
        switch (action) {
            case 1:
                // Print all records code
                print_all_records();
                break;
            case 2:
                // Print number of records 
                print_num_records();
                break;
            case 3:
                // Print size of database
                print_size_database();
                break;
            case 4:
                // Add records
                char stdname[100];
                int stdid;
                char clsname[100];
                char clsid[9];

                printf("Type the student's name: \n");
                scanf("%s", stdname);
                
                printf("Type the student's ID: \n");
                scanf("%d", &stdid);
                
                printf("Type the student's class name: \n");
                scanf("%s", clsname);
                
                printf("Type the student's class ID: \n");
                scanf("%s", clsid);
                

                struct record *temp = malloc(sizeof(struct record));
                temp->studentFullName = malloc(sizeof(char)*strlen(stdname));
                temp->className = malloc(sizeof(char)*strlen(clsname));
                temp->classID = malloc(sizeof(char)*strlen(clsid));

                strncpy(temp->studentFullName, stdname, strlen(stdname));
                strncpy(temp->className, clsname, strlen(clsname));
                strncpy(temp->classID, clsid, strlen(clsid));
                temp->studentID = stdid;

                add_record(temp);
                break;
            case 5:
                // Delete record
                delete_record();
                printf("Last record in the database was deleted\n");
                break;
            case 6:
                // Print number of accesses to database
                print_number_of_accesses();
                break;
            case 7:
                while(num_records != 0) 
                    delete_record();
                printf("User exited the program\n");
                exit(1);
            default:
                //invalid commands
                printf("\nError: Invalid Command\n");
                break;
        }
    }
    return 0;
}


void print_all_records() {
    if(num_records == 0) {
        printf("Error: The database is empty\n");
    }
    else {
        struct record *mover = DataBase;
        printf("-----Student database-----\n");
        for(int i  = 0; i < num_records; i++) {
            printf("--------------------------\n");
            printf("%s : %d\n%s :\n%s\n", mover->studentFullName, mover->studentID, mover->className,mover->classID);
            mover++;
        }         
    }
}

void print_num_records() {
    printf("The number of records in the database is %d\n", num_records);
}

void print_size_database() {
    printf("The database has size of %ld bytes\n", num_records * sizeof(struct record));
}

void print_number_of_accesses() {
    printf("The database was accessed a total of %d time(s)\n", num_of_accesses);
}

int add_record(struct record *stdrecord) {
    if(stdrecord == NULL) {
        return 1;
    }
    if(num_records == 0) {
        DataBase = malloc(sizeof(struct record));
        memcpy(DataBase, stdrecord, sizeof(struct record));
        free(stdrecord);
        num_records++;
        num_of_accesses++;
        return 0;
    }
    else if(num_records == 1) {
        struct record *newDB = malloc((num_records+1)*sizeof(struct record));
        struct record *DBhead = DataBase;
        struct record *newDBmover = newDB;
        memcpy(newDBmover++, DBhead, sizeof(struct record));
        memcpy(newDBmover, stdrecord, sizeof(struct record));
        num_records++;
        num_of_accesses++;
        free(stdrecord);
        free(DBhead);
        DataBase = newDB;
        return 0;
    }
    else {
        struct record *newDB = malloc((num_records+1)*sizeof(struct record));
        struct record *DBtail = DataBase;
        struct record *DBmover = DataBase;
        DBmover++;
        struct record *newDBmover = newDB;
        for(int i = 0; i < num_records; i++) {
            memcpy(newDBmover, DBtail, sizeof(struct record));
            free(DBtail);
            DBtail = DBmover;
            DBmover++;
            newDBmover++;
        }
        memcpy(newDBmover, stdrecord, sizeof(struct record));
        free(stdrecord);
        num_records++;
        num_of_accesses++;
        free(DataBase);
        DataBase = newDB;
        return 0;
    }
}

int delete_record() {
    struct record *DBmover = DataBase;
    DBmover+(num_records-1);
    free(DBmover->classID);
    free(DBmover->className);
    free(DBmover->studentFullName);
    free(DBmover);
    num_records--;
    num_of_accesses++;
    return 0;
}