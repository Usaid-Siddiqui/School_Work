#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h" 


/////////////////////////////////////////////////////////////////////////////////////////////
// add a student to the list of students
//	   1. Make sure a student by that name does not exist (print an error message and do nothing if it exists)
//	   2. Add a new student with that name (add-at-front)

Student* addStudent(Student *headStudentList, char last[], char first[])
{
	for(Student* ptr=headStudentList; ptr != NULL; ptr=ptr->next) {						//checks whether name already exists. If so, return error message.
		if ((strcmp(ptr->firstName,first)==0) && (strcmp(ptr->lastName,last)==0)) {
			printf("Error. Student with name %s %s already exists.\n", first, last);
			return headStudentList;
		}
	}

	Student* newStudent = malloc(sizeof(Student));			//create new node of student type
	newStudent->firstName = malloc(strlen(first) + 1);
	strcpy(newStudent->firstName, first);
	newStudent->lastName = malloc(strlen(last) + 1);
	strcpy(newStudent->lastName, last);

	newStudent->headGradeList=NULL;

	newStudent->next = headStudentList;						//add node to front of studentList. Grade pointer still remains empty so far.

	return newStudent;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a grade to the specified student
//   1. Make sure a student by that name exists (so you can add grade to it)
//   2. If the specifed grade already exists, update the grade's value to the new value
//   3. Otherwise, add the grade to the end of the student's grade list (add-at-end)

void addGrade(Student *headStudentList, char last[], char first[], char gradeName[], double value) {
	for (Student* ptr=headStudentList; ptr!=NULL; ptr=ptr->next) {
		if ((strcmp(ptr->firstName,first)==0) && (strcmp(ptr->lastName,last)==0)) {
			for (Grade* curr = ptr->headGradeList; curr!=NULL; curr=curr->next) {		//If grade already exists just update the value
				if (strcmp(curr->name,gradeName)==0) {
					curr->value = value;
					return;
				}
			}

			Grade* newGrade = malloc(sizeof(Grade));					//Create new node for the new grade, only if matching student is found
			newGrade->value=value;
			strcpy(newGrade->name, gradeName);
			newGrade->next = NULL;

			if (ptr->headGradeList==NULL) {
				ptr->headGradeList=newGrade;
				return;
			}

			for (Grade* curr = ptr->headGradeList; curr!=NULL; curr=curr->next) {		//insert new grade node at end of grade list
				if (strcmp(curr->name,gradeName)==0) curr->value = value;
				else if (curr->next == NULL) {
					curr->next = newGrade;
					return;
				}
			}
		}
	}
	printf("Error. Student not found.\n");
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// return the number of students in the list
// Iterate through the student list to count the number of students, return that count

int count(Student *headStudentList) {
	if (headStudentList==NULL) return 0;

	int i = 0;
	for (Student *ptr = headStudentList; ptr!=NULL; ptr=ptr->next) {
		i++;
	}
	return i;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// print all the grades for a given student
//	1. Make sure a student with that name exists
//	2. Print the name of that student
//	3. Print all the "grade name: grade value" pairs for that student

void printStudent(Student *headStudentList, char last[], char first[])
{
	for (Student* ptr=headStudentList; ptr!=NULL; ptr=ptr->next) {
		if (strcmp(ptr->firstName, first)==0 && strcmp(ptr->lastName,last)==0) {
			printf("\n\nStudent Name: %s, %s\n", last, first);
			if (ptr->headGradeList == NULL) return;
			for (Grade* curr = ptr->headGradeList; curr != NULL; curr=curr->next) {
				printf("\t%-4s: %g\n", curr->name, curr->value);
			}
			return;
		}
	}
	printf("Error. Student not found.\n");
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// print all the students
// For each student
//	   a. Print the name of that student
//	   b. Print all the "grade name: grade value" pairs for that student

void print(Student *headStudentList)
{
	for (Student* ptr=headStudentList; ptr!=NULL; ptr=ptr->next) {
		printf("\nStudent Name: %s, %s\n", ptr->lastName, ptr->firstName);
		for (Grade* curr = ptr->headGradeList; curr != NULL; curr=curr->next) {
			printf("\t%-4s: %g\n", curr->name, curr->value);
		}
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a student (in alphabetical order)
//	1. Make sure a student by that name does not exist 
//	2. Add a student with that name (add-in-order)

//HELPER FUNCTION TO COMPARE TWO STUDENTS' NAMES ALPHABETICALLY
int nameCmp(Student *firstStd, Student *secondStd) {
	if (strcmp(firstStd->lastName, secondStd->lastName)==0) return strcmp(firstStd->firstName, secondStd->firstName);
	else return strcmp(firstStd->lastName, secondStd->lastName);
}

Student *addStudentOrdered(Student *headStudentList, char last[], char first[])
{
	for(Student* ptr=headStudentList; ptr != NULL; ptr=ptr->next) {						//checks whether name already exists. If so, return error message.
		if ((strcmp(ptr->firstName,first)==0) && (strcmp(ptr->lastName,last)==0)) {
			printf("Error. Student with name %s %s already exists.\n", first, last);
			return headStudentList;
		}
	}
	
	Student* newStudent = malloc(sizeof(Student));			//create new node of student type
	newStudent->firstName = malloc(strlen(first) + 1);
	strcpy(newStudent->firstName, first);
	newStudent->lastName = malloc(strlen(last) + 1);
	strcpy(newStudent->lastName, last);

	newStudent->next = NULL;
	newStudent->headGradeList=NULL;

    // case #1, empty list
    if (headStudentList==NULL) {
		newStudent->next=NULL;
		return newStudent;
	}
    // case #2, d is the largest, add at front
    if (nameCmp(newStudent, headStudentList)<0) {
        newStudent->next=headStudentList;
        return newStudent;
    }

    // search for a correction location to insert

    for (Student* cur = headStudentList; cur!= NULL; cur=cur->next) {
        if (cur->next == NULL) { // Case 3: Insert at the end
            cur->next = newStudent;
            return headStudentList;
        }

        if (nameCmp(newStudent, cur->next) < 0) { // Case 4: Insert between cur and cur->next
			newStudent->next = cur->next;
            cur->next = newStudent;
            return headStudentList;
        }
    }

    return headStudentList;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a grade to the specified student in order
//	1. Make sure a student by that name exists (so you can add a grade to the student)
//	2. If the grade already exists, update the value
//	3. Otherwise, add the grade to the student (add-in-order)

int gradeCmp(char grade1[4], char grade2[4]) {
	// Get the type (first character)
    char type1 = grade1[0];
    char type2 = grade2[0];

    // Compare types first
    if (type1 != type2) {
        return type1 - type2;
    }

    // If types are the same, compare the numbers
    int num1 = atoi(grade1 + 1);  // Convert substring starting from the second character to int
    int num2 = atoi(grade2 + 1);  // Same for the second grade

    // Compare the numbers
    return num1 - num2;
}

void addGradeOrdered(Student *headStudentList, char last[], char first[], char gradeName[], double value)
{
	for (Student* ptr=headStudentList; ptr!=NULL; ptr=ptr->next) {
		if ((strcmp(ptr->firstName,first)==0) && (strcmp(ptr->lastName,last)==0)) {
			for (Grade* curr = ptr->headGradeList; curr!=NULL; curr=curr->next) {		//If grade already exists just update the value
				if (strcmp(curr->name,gradeName)==0) {
					curr->value = value;
					return;
				}
			}

			Grade* newGrade = malloc(sizeof(Grade));					//Create new node for the new grade, only if matching student is found, and node doesnt already exist
			newGrade->value=value;
			strcpy(newGrade->name, gradeName);
			newGrade->next = NULL;

			if (ptr->headGradeList==NULL) {				//case 1: if gradelist is empty
				ptr->headGradeList=newGrade;
				return;
			}

			if (gradeCmp(gradeName,ptr->headGradeList->name)<0) {		//case 2, newGrade should be the first in the list
        		newGrade->next=ptr->headGradeList;
				ptr->headGradeList=newGrade;
        		return;
    		}

			for (Grade* curr = ptr->headGradeList; curr!=NULL; curr=curr->next) {		//insert new grade node at end of grade list
				if (curr->next==NULL) {
					curr->next=newGrade;
					return;
				}
				if (gradeCmp(newGrade->name, curr->next->name)<0) {
					newGrade->next=curr->next;
            		curr->next=newGrade;
            		return;
				}
			}
		}
	}
	printf("Error. Student not found.\n");
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// remove a grade from a student
//	1. Make sure a student with that name exists
//	2. Make sure the grade exists in that student
//	3. Remove the grade from that student

void removeGrade(Student *headStudentList, char last[], char first[], char gradeName[])
{
	for(Student* ptr=headStudentList; ptr != NULL; ptr=ptr->next) {						//checks whether name already exists.
		if ((strcmp(ptr->firstName,first)==0) && (strcmp(ptr->lastName,last)==0)) {
			if (ptr->headGradeList == NULL) {
				printf("Error. No existing grades for this student.\n");
				return;
			}

			if (strcmp(ptr->headGradeList->name, gradeName)==0) {
        		Grade *temp=ptr->headGradeList;
        		ptr->headGradeList=ptr->headGradeList->next;
        		free(temp);
        		return;
    		}

			for (Grade* curr = ptr->headGradeList; curr!=NULL; curr=curr->next) {		//Finds grade
				if (strcmp(curr->next->name,gradeName)==0) {
					Grade* temp = curr->next;
					curr->next=curr->next->next;
					free(temp);
					return;
				}
			}
			printf("Error. Grade not found.\n");
			return;
		}
	}
	printf("Error. Student not found.\n");
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a student
//	1. Make sure a student with that name exists
//	2. Remove that student and all the grades of that student 

Student *removeStudent(Student *headStudentList, char last[], char first[])
{
	if (headStudentList==NULL) {
		printf("Error. List is empty.\n");
		return NULL;
	}

	if ((strcmp(headStudentList->firstName,first)==0) && (strcmp(headStudentList->lastName,last)==0)) {
		Student* temp1=headStudentList;
    	headStudentList=headStudentList->next;
		free(temp1->firstName);
		free(temp1->lastName);

		Grade* current = temp1->headGradeList;
		Grade* next;
		while (current != NULL) {			//delete the grades
        	next = current->next;
        	free(current);
        	current = next;
    	}

        free(temp1);
    	return headStudentList;
	}

	for(Student* ptr=headStudentList; ptr != NULL; ptr=ptr->next) {						   //finds student name
		if (ptr->next != NULL && (strcmp(ptr->next->firstName,first)==0) && strcmp(ptr->next->lastName,last)==0) {
			Grade* current1 = ptr->next->headGradeList;
			Grade* next1;
			while (current1 != NULL) {			//delete the grades
        		next1 = current1->next;
        		free(current1);
        		current1 = next1;
    		}

			free(ptr->next->firstName);				//free allocated space for student's names
			free(ptr->next->lastName);

			Student* temp2 = ptr->next;
			ptr->next=ptr->next->next;
			free(temp2);

			return headStudentList;
		}
	}
	printf("Error. Student not found.\n");
	return headStudentList;
}