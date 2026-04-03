#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
	char* name;
	char* id;
	double gpa;
	int creditHours;
} Student;

typedef struct StudentNode{
	Student* pStudent;
	struct StudentNode* pNext;
} StudentNode;

typedef struct {
	StudentNode* pIDList;
	StudentNode* pHonorRollList;
	StudentNode* pAcademicProbationList;
	StudentNode* pFreshmanList;
	StudentNode* pSophomoreList;
	StudentNode* pJuniorList;
	StudentNode* pSeniorList;
} Database;

void deleteStudentfromDB(Database* DB, char* stID, Student* stToDelete );

void printStudent(Student* st){
         printf("%s:\n\tID - %s\n\tGPA - %.2f\n\tCredit Hours - %d\n",st->name,st->id,st->gpa,st->creditHours);
        //printf("\t%s\t%.2f\t%d\t%s\n",st->id,st->gpa,st->creditHours,st->name);
}

void clearDB(Database* DB){
    StudentNode* current = DB->pIDList;
    while(current != NULL)
    {
        deleteStudentfromDB(DB,current->pStudent->id, current->pStudent);
        current = DB->pIDList;
    }

}
void printList(StudentNode* current, int numrecords){
    if (current == NULL){
        printf("There are no students matching that criteria.\n\n\n");
        //printf("There are no students matching that criteria.\n");
        return;
    }
    int count=1;
    while(current != NULL){
        if ( count > numrecords ){
            return;
        }
        printStudent(current->pStudent);
        current = current->pNext;
        count++;
    }
    printf("\n\n");
   //printf("\n");
}
bool isInValidEntry(Database *DB, Student* newStudent)
{
    StudentNode* current = DB->pIDList;
    
    if(strcmp(newStudent->id,"") ==0 ) return true;
    //check for duplicate entry
    while(current != NULL){
        if(strcmp(current->pStudent->id,newStudent->id) == 0 ){
            return true;
        }
       if(current->pNext == NULL) {break;}
       current = current->pNext;
       
    }
    return false;
}
void addToSeniorList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;
    StudentNode* current = DB->pSeniorList;

    if(current == NULL){
        DB->pSeniorList = stNode;
        return;
    }
    
   while(current != NULL){
        if(strcmp(newStudent->name,current->pStudent->name) <= 0){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
    
}
void addToJuniorList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;;
    StudentNode* current = DB->pJuniorList;

    if(current == NULL){
        DB->pJuniorList = stNode;
        return;
    }
    
    while(current != NULL){
        if(strcmp(newStudent->name,current->pStudent->name) <= 0){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
    
}
void addToSophmoreList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;;
    StudentNode* current = DB->pSophomoreList;

    if(current == NULL){
        DB->pSophomoreList = stNode;
        return;
    }
    
    while(current != NULL){
        if(strcmp(newStudent->name,current->pStudent->name) <= 0){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
    
}
void addToFreshmanList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;;
    StudentNode* current = DB->pFreshmanList;

    if(current == NULL){
        DB->pFreshmanList = stNode;
        return;
    }
    
    while(current != NULL){
        if(strcmp(newStudent->name,current->pStudent->name) <= 0){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
    
}
void addToProbationList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;;
    StudentNode* current = DB->pAcademicProbationList;

    if(current == NULL){
        DB->pAcademicProbationList = stNode;
        return;
    }
    
   while(current != NULL){
        if(newStudent->gpa <= current->pStudent->gpa){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
    
}
void addToHonorRollList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;;
    StudentNode* current = DB->pHonorRollList;
    if(current == NULL){
        DB->pHonorRollList = stNode;
        return;
    } 
    while(current != NULL){
        if(newStudent->gpa <= current->pStudent->gpa){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
}
void addToIDList(Student* newStudent, Database* DB){
    StudentNode* stNode = (StudentNode*) malloc(sizeof(StudentNode));
    stNode->pStudent = newStudent;
    stNode->pNext = NULL;;
    StudentNode* current = DB->pIDList;
    if(current == NULL){
        DB->pIDList = stNode;
        return;
    }
   while(current != NULL){
        if(strcmp(newStudent->id,current->pStudent->id) < 0){
            //swap the students
            stNode->pStudent = current->pStudent;
            current->pStudent = newStudent;
            stNode->pNext = current->pNext;
            current->pNext = stNode;
            return;
        }
        if(current->pNext ==NULL)
        {
            break;
        }
        current = current->pNext;
    }
    current->pNext = stNode;
}
bool addToDB(Student* newStudent, Database* DB){
    if(isInValidEntry(DB, newStudent))
    {
        free(newStudent);
        return false;
    }
    addToIDList(newStudent,DB);
    if(newStudent->gpa >= 3.5){
        addToHonorRollList(newStudent,DB);
    }
    if(newStudent->gpa < 2.0){
        addToProbationList(newStudent,DB);
    }
    if(newStudent->creditHours >= 0 && newStudent->creditHours <= 29){
        addToFreshmanList(newStudent,DB);
    }
    if(newStudent->creditHours >= 30 && newStudent->creditHours <= 59){
        addToSophmoreList(newStudent,DB);
    }
    if(newStudent->creditHours >= 60 && newStudent->creditHours <= 89){
        addToJuniorList(newStudent,DB);
    }
    if(newStudent->creditHours >= 90){
        addToSeniorList(newStudent,DB);
    }
    return true;
}
void getInput(char* inputName, size_t size){
    fgets(inputName,size,stdin);
    inputName[strcspn(inputName, "\n")] = '\0';
}
void getNewStudent(Database* DB){
    printf("Enter the name of the new student: ");
    char name[100] = "";
    getInput(name,sizeof(name));
	printf("Enter the ID of the new student: ");
    char ID[100] = "";
    getInput(ID,sizeof(ID));
    char GPA[100] = "";
    bool validGPA = true;
    bool validCreditHours = true;
    printf("Enter the GPA of the new student: ");
    getInput(GPA,sizeof(GPA));
    /*char *invChar;
    double g  = strtod(GPA, &invChar);
    if(*invChar != '\0' && !isspace(*invChar)) {
        validGPA = false;
    }
    */
 
    char creditHours[100] = "";
	printf("Enter the credit hours of the new student: ");
    getInput(creditHours,sizeof(creditHours));
    /*long ch = strtol(creditHours, &invChar, 10);
    if(*invChar != '\0' && !isspace(*invChar)) {
        validCreditHours=false;
    }
    if (!validGPA || !validCreditHours) {return;}*/
     Student* newStudent;
        newStudent = (Student*) malloc(sizeof(Student));
        newStudent->name = malloc(strlen(name)+1);
        newStudent->id = malloc(strlen(ID)+1);
        //strcpy(newStudent->name, strdup(name));
        strncpy(newStudent->name, name,strlen(name)+1);
        strncpy(newStudent->id,ID, strlen(ID)+1);
        //free(name);
        //free(ID);
        newStudent->gpa = atof(GPA);
        newStudent->creditHours = atoi(creditHours);
        if (addToDB(newStudent,DB))
        {
            printf("Successfully added the following student to the database!\n");
            printStudent(newStudent);
           // printf("\n");
        }
    return;

}
void displayStudentInfo(Database* DB){
    printf("Enter the id of the student to find: ");
    char stID[100];
    fgets(stID,sizeof(stID),stdin);
    stID[strcspn(stID, "\n")] = '\0';
    StudentNode* current = DB->pIDList;
    while(current != NULL){
        if(strcmp(current->pStudent->id,stID) == 0){
            break;
        }
        current = current->pNext;
    }
    if(current == NULL){
        printf("Sorry, there is no student in the database with the id %s.\n",stID);
        return;
    }
    printStudent(current->pStudent);
       // 
       // printf("Sorry, there is no student in the database with the id 6ABCDEFGH.\n");
}
void readOperations(Database* DB){
    printf("Select one of the following: \n");
    char choice[25];
    printf("\t1) Display the head (first 10 rows) of the database\n");
    printf("\t2) Display students on the honor roll, in order of their GPA\n");
    printf("\t3) Display students on academic probation, in order of their GPA\n");
    printf("\t4) Display freshmen students, in order of their name\n");
    printf("\t5) Display sophomore students, in order of their name\n");
    printf("\t6) Display junior students, in order of their name\n");
    printf("\t7) Display senior students, in order of their name\n");
    printf("\t8) Display the information of a particular student\n");
    while(true){
        printf("Your choice --> ");
        
        fgets(choice,sizeof(choice),stdin);
        choice[strcspn(choice, "\n")] = '\0';
        
       if (strcmp(choice, "1")==0){printList(DB->pIDList,10);return;}
       if (strcmp(choice, "2")==0){printList(DB->pHonorRollList,99999);return;}
        if (strcmp(choice, "3")==0){printList(DB->pAcademicProbationList,99999);return;}
        if (strcmp(choice, "4")==0){printList(DB->pFreshmanList,99999);return;}
        if (strcmp(choice, "5")==0){printList(DB->pSophomoreList,99999);return;}
        if (strcmp(choice, "6")==0){printList(DB->pJuniorList,99999);return;}
        if (strcmp(choice, "7")==0){printList(DB->pSeniorList,99999);return;}
        if (strcmp(choice, "8")==0){displayStudentInfo(DB);return;}
        printf("Sorry, that input was invalid. Please try again.\n");
    }
        

}
void deleteStudentFromList(char* stID, StudentNode* fromList){
    StudentNode* prev = fromList;
    StudentNode* current = prev->pNext;
    
    while (current != NULL){
        if(strcmp(current->pStudent->id, stID) ==0 ){
            prev->pNext = current->pNext;
            current->pStudent = NULL;
            free(current);
            return;
        }
        current = current->pNext;
        prev = prev->pNext;
    }
}



void deleteStudentfromDB(Database* DB, char* stID, Student* stToDelete ){
    StudentNode* temp;
    if(DB->pHonorRollList != NULL){
        if( strcmp(DB->pHonorRollList->pStudent->id, stID) ==0){
            temp = DB->pHonorRollList;
            DB->pHonorRollList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pHonorRollList);
        }
    }
    if(DB->pIDList != NULL){
        if( strcmp(DB->pIDList->pStudent->id, stID) ==0){
            temp = DB->pIDList;
            DB->pIDList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pIDList);
        }
    }
    if (DB->pFreshmanList != NULL){
        if( strcmp(DB->pFreshmanList->pStudent->id, stID) ==0){
            temp = DB->pFreshmanList;
            DB->pFreshmanList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pFreshmanList);
        }
    }
    if(DB->pJuniorList != NULL){
        if( strcmp(DB->pJuniorList->pStudent->id, stID) ==0){
            temp = DB->pJuniorList;
            DB->pJuniorList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pJuniorList);
        }
    }
    if (DB->pSeniorList != NULL){
        if(strcmp(DB->pSeniorList->pStudent->id, stID) ==0){
            temp = DB->pSeniorList;
            DB->pSeniorList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pSeniorList);
        }
    }
    if(DB->pSophomoreList != NULL){
        if( strcmp(DB->pSophomoreList->pStudent->id, stID) ==0){
            temp = DB->pSophomoreList;
            DB->pSophomoreList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pSophomoreList);
        }
    }
   if(DB->pAcademicProbationList != NULL){
        if( strcmp(DB->pAcademicProbationList->pStudent->id, stID) ==0){
            temp = DB->pAcademicProbationList;
            DB->pAcademicProbationList = temp->pNext;
            temp->pStudent = NULL;
            free(temp);
        }else{
            deleteStudentFromList(stID,DB->pAcademicProbationList);
        }
   }
   free(stToDelete->name);
   free(stToDelete->id);
    free(stToDelete);
  
    
}
void deleteStudent(Database* DB){
    printf("Enter the id of the student to be removed: ");
    char stID[100];
    fgets(stID,sizeof(stID),stdin);
    stID[strcspn(stID, "\n")] = '\0';
    StudentNode* current = DB->pIDList;
    while(current != NULL){
        if(strcmp(current->pStudent->id,stID) == 0){
            break;
        }
        current = current->pNext;
    }
    if(current == NULL){
        printf("Sorry, there is no student in the database with the id %s.\n",stID);
        return;
    }
    Student* stToDelete = current->pStudent;
    deleteStudentfromDB(DB,stID,stToDelete);
    printf("\n");
}
void getCRDX(Database* DB){
    while(true){
        printf("\nEnter: \tC to create a new student and add them to the database,\n");
        printf("\tR to read from the database,\n");
        printf("\tD to delete a student from the database, or\n");
        printf("\tX to exit the program.\n");
        char choice[100] = "";
        while(true){
            printf("Your choice --> ");

            
            getInput(choice,sizeof(choice));
            choice[strcspn(choice, "\n")] = '\0';
            if(strcmp(choice,"C") != 0 && strcmp(choice,"R") != 0 && strcmp(choice,"D") != 0 && strcmp(choice,"X") != 0 ){
                printf("Invalid option. Try again.\n");
                continue;
            }
            break;
        }
       
        if (strcmp(choice,"C") == 0){getNewStudent(DB);}
        if (strcmp(choice,"R") == 0){readOperations(DB);}
        if (strcmp(choice,"D") == 0){deleteStudent(DB);}
        if (strcmp(choice,"X") == 0){
            clearDB(DB);
            printf("\nThanks for playing!\n");
            printf("Exiting...\n");
            return;
        }
    }
}
void getFile(char fileName[100], Database *DB){
    FILE* fptr;
    char buf[1024];
    const char* delim = ",";
    fptr = fopen(fileName,"r");
    if(fptr == NULL){
        printf("Error: Cannot open file");
        return;
    }
    fgets(buf,sizeof(buf),fptr);
    while(fgets(buf,sizeof(buf),fptr)){
      //  printf("\nline from the file : %s", buf);
        char* name = strtok(buf, delim);
        name[strcspn(name, "\n")] = '\0';
        char* id = strtok(NULL, delim);
        id[strcspn(id, "\n")] = '\0';
        char* gpa = strtok(NULL, delim);
        gpa[strcspn(gpa, "\n")] = '\0';
        char* creditHours = strtok(NULL, delim);
        creditHours[strcspn(creditHours, "\n")] = '\0';

       // printf("Reading from file: %s \t: %s \t: %s \t: %s <newline>\n",name, id, gpa, creditHours);
        Student* newStudent;
        newStudent = (Student*) malloc(sizeof(Student));
        newStudent->name = malloc(strlen(name)+1);
        newStudent->id = malloc(strlen(id)+1);
        strncpy(newStudent->name, name, strlen(name)+1); //strdup(name));
        strncpy(newStudent->id,id, strlen(id)+1);
        //free(name);
        //free(id);
        newStudent->gpa = atof(gpa);
        newStudent->creditHours = atoi(creditHours);
       // printf("creating record : %s \t: %s \t: %.2f \t: %d \t <newline>\n",newStudent->name,newStudent->id, newStudent->gpa, newStudent->creditHours);
        addToDB(newStudent,DB);
        
    }
    
    
}
int main() {

	printf("CS 211, Spring 2023\n");
	printf("Program 4: Database of Students\n\n");

    Database studentDb;
    studentDb.pIDList = NULL;
    studentDb.pHonorRollList = NULL;
    studentDb.pAcademicProbationList = NULL;
    studentDb.pFreshmanList = NULL;
    studentDb.pSophomoreList = NULL;
    studentDb.pJuniorList = NULL;
    studentDb.pSeniorList = NULL;
	printf("Enter E to start with an empty database, \n");
	printf("or F to start with a database that has information on students from a file.\n");
    char choice[100];
    while(true){
	printf("Your choice --> ");
    fgets(choice,sizeof(choice),stdin);
    choice[strcspn(choice, "\n")] = '\0';
    //scanf(" %c",&choice);
    //getchar();
    if(strcmp(choice,"E") == 0 || strcmp(choice,"F") == 0){
        break;
    }
	printf("Sorry, that input was invalid. Please try again.\n");
    }
    if(strcmp(choice,"F")==0){
        printf("Enter the name of the file you would like to use: ");
        char fileName[100];
        fgets(fileName,sizeof(fileName),stdin);
        fileName[strcspn(fileName, "\n")] = '\0';
        getFile(fileName,&studentDb);
    }
    getCRDX(&studentDb);	
	return 0;
}