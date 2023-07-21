
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the student node
struct Student {
    int rollNumber;
    char name[50];
    float marks;
    struct Student* next;
};

// Function to create a new student node with the given data
struct Student* createStudent(int rollNumber, const char* name, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student record at the end of the linked list
void insertStudent(struct Student** head, int rollNumber, const char* name, float marks) {
    struct Student* newStudent = createStudent(rollNumber, name, marks);

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to delete a student record with the given roll number
void deleteStudent(struct Student** head, int rollNumber) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Student* current = *head;
    struct Student* prev = NULL;

    while (current != NULL && current->rollNumber != rollNumber) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with roll number %d not found.\n", rollNumber);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to traverse and print the student records in the linked list
void traverseStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n", current->rollNumber, current->name, current->marks);
        current = current->next;
    }
}

// Function to free the memory occupied by the linked list of students
void freeStudents(struct Student* head) {
    struct Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Student* studentList = NULL;

    // Insert student records
    insertStudent(&studentList,1, "shanmukha", 85.2);
    insertStudent(&studentList,2, "sathwik", 80.5);
    insertStudent(&studentList,3, "somasekhar",75.5);

    // Traverse and print student records
    printf("Student List:\n");
    traverseStudents(studentList);

    // Delete a student record
    deleteStudent(&studentList,2);

    // Traverse and print the updated student records
    printf("\nStudent List after deleting record:\n");
    traverseStudents(studentList);

    // Free the memory
    freeStudents(studentList);

    return 0;
}
