/*
  Tutorial 2 - Structures

  - Array of Stuctures
  - Dynamic structure allocation

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-09-19
*/

// To use malloc/free include stdlib.h
#include <stdio.h>
#include <stdlib.h>

#define STUDENTS_COUNT 10

typedef struct {
  char first_name[20];
  char last_name[20];
  int student_id;
} student;

void print_student(student s) { 
  printf("%s %s %d\n", s.first_name, s.last_name, s.student_id); 
}

void main() {
  student *students;
  // Another way of declaring an array of students
  // student students[STUDENTS_COUNT];
  
  FILE *input, *output;

  input = fopen("2-students.in", "r");
  output = fopen("2-students.out", "w");

  // students = (student *)malloc(sizeof(students[0]) * STUDENTS_COUNT);
  students = (student *)malloc(sizeof(student) * STUDENTS_COUNT);

  for (int s = 0; s < STUDENTS_COUNT; s++) {
    fscanf(input, "%s", students[s].first_name);
    fscanf(input, "%s", students[s].last_name);
    fscanf(input, "%d", &students[s].student_id);
    print_student(students[s]);
  }

  for (int s = 0; s < STUDENTS_COUNT; s++) {
    fprintf(output, "%d %s %s\n", students[s].student_id, students[s].first_name,
            students[s].last_name);
  }

  free(students);

  fclose(input);
  fclose(output);
}