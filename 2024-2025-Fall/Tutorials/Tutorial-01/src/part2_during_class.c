#include <stdio.h>

// Always '0' through '9'.
typedef char digit;

// Numeric values match T1 form.
enum marital {
  MARRIED = 0,
  COMMON_LAW,
  WIDOWED,
  DIVORCED,
  SEPARATED,
  SINGLE
};

char *marital_status_array[] = {"MARRIED",  "COMMON_LAW", "WIDOWED",
                              "DIVORCED", "SEPARATED",  "SINGLE"};

typedef enum marital marital_t;

struct numeric_date {
  digit year[4];
  digit month[2];
  digit day[2];
};

typedef struct numeric_date numeric_date_t;

struct tax_info {
  // Social insurance number.
  digit sin[9];
  // Always a valid date.
  numeric_date_t date_of_birth;
  // Always a valid date, or all zeros if empty.
  numeric_date_t date_of_death;
  // Always a valid enum value.
  marital_t marital_status;
};

typedef struct tax_info tax_info_t;

void print_date_of_birth(tax_info_t *tax_info_var) {
  printf("DOB: ");

  for (int i = 0; i < 4; i++) {
    printf("%c", tax_info_var->date_of_birth.year[i]);
  }

  printf(":%c%c:%c%c\n", tax_info_var->date_of_birth.month[0],
         tax_info_var->date_of_birth.month[1],
         tax_info_var->date_of_birth.day[0],
         tax_info_var->date_of_birth.day[1]);
}

void print_marital_status(tax_info_t *tax_info_var) {
  printf("Marital Status: ");
  printf("%s", marital_status_array[tax_info_var->marital_status]);
  // switch (tax_info_var->marital_status) {
  // case MARRIED:
  //   printf("MARRIED\n");
  //   break;
  // case SINGLE:
  //   printf("SINGLE\n");
  //   break;
  // case WIDOWED:
  //   printf("WIDOWED\n");
  //   break;
  // default:
  //   printf("Invalid marital Status!");
  // }
}

int main() {

  tax_info_t my_tax_info = {
      .sin = {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
      .date_of_birth =
          {
              .year = {'1', '9', '9', '7'},
              .month = {'0', '3'},
              .day = {'2', '9'},
          },
      .date_of_death =
          {
              .year = {'0', '0', '0', '0'},
              .month = {'0', '0'},
              .day = {'0', '0'},
          },
      .marital_status = SINGLE,
  };

  printf("SIN: ");
  for (int i = 0; i < 9; i++) {
    printf("%c", my_tax_info.sin[i]);
  }
  printf("\n");

  print_date_of_birth(&my_tax_info);

  print_marital_status(&my_tax_info);

  return 0;
}