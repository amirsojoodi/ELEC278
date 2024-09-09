/*
  Tutorial 2 - Structures

  Read 2 integers from a file, assign them to structures,
  write to another file.

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-09-19
*/

// To use strcpy, include string.h
#include <stdio.h>
#include <string.h>

typedef struct {
  char first_name[20];
  char last_name[20];
  int student_id;
} student;

void print_student(student s){
  printf("%s %s %d\n", s.first_name, s.last_name, s.student_id);
}

void main() {
  student a, b;
  FILE *input, *output;

  student j = {"Jack", "Pearson", 20051231};
  student h = {.last_name = "Hatake", .student_id = 20032131, .first_name = "Kakashi"};
  print_student(j); 
  print_student(h);
  // a = {"Ed", "Sheeran", 20001203};

  input = fopen("student_ids.in", "r");
  output = fopen("students.out", "w");

  strcpy(a.first_name, "Janice");
  strcpy(a.last_name, "Litman");
  fscanf(input, "%d\n", &a.student_id);

  strcpy(b.first_name, "Chandler");
  strcpy(b.last_name, "Bing");
  fscanf(input, "%d\n", &b.student_id);

  fprintf(output, "%s %s %d\n", a.first_name, a.last_name, a.student_id);
  fprintf(output, "%s %s %d\n", b.first_name, b.last_name, b.student_id);

  fclose(input);
  fclose(output);
}