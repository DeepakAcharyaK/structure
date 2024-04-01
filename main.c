#include <stdio.h>
#include <string.h>

int main(void) {
  int n;
  int big = 0;  // Initialize big to 0
  float grandavg=0;

  struct Student {
    int roll, m1, m2, m3, tot;
    float avg;
    char name[10];
  } std[10];

  printf("enter the no of students\n");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("enter the information of student %d\n", i + 1);
    printf("Enter the rollno\n");
    scanf("%d", &std[i].roll);
    printf("Enter the student name\n");
    scanf("%s", std[i].name);
    printf("Enter the marks in three subjects\n");
    scanf("%d %d %d", &std[i].m1, &std[i].m2, &std[i].m3);

    std[i].tot = std[i].m1 + std[i].m2 + std[i].m3;
    std[i].avg = (float)std[i].tot / 3.0;  // Calculate average

    printf("Total marks of student %d is %d\n", i + 1, std[i].tot);
    printf("Average marks of student %d is %.2f\n", i + 1, std[i].avg);

    printf("----------------------------------------\n");

    // Update big if current student has more marks
    if (std[i].tot > big) {
      big = std[i].tot;
    }

    if (std[i].avg > grandavg) {
      big = std[i].avg;
    }
  }


  // Find and print the student with the maximum marks
  printf("Student(s) with maximum marks:\n");
  for (int i = 0; i < n; i++) {
    if (std[i].tot >= big) {
      big=std[i].tot;
    }
  }
  for (int i = 0; i < n; i++) {
    if (std[i].tot == big) {
      printf("Roll No: %d, Name: %s\n", std[i].roll, std[i].name);
    }
  }
  printf("Maximum marks: %d\n", big);

  //MAX Average 

  printf("Student(s) with maximum Average:\n");\
  for (int i = 0; i < n; i++) {
    if (std[i].avg >= grandavg) {
      grandavg=std[i].avg;
    }
  }
  for (int i = 0; i < n; i++) {
    if (std[i].avg == grandavg) {
      printf("Roll No: %d, Name: %s\n", std[i].roll, std[i].name);
    }
  }
  printf("Maximum Average: %f\n", grandavg);

  return 0;
}

