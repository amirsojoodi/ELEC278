#include <stdio.h>

// Always '0' through '9'.
typedef char digit;

// Numeric values match T1 form.
enum marital {
  MARRIED = 1,
  COMMON_LAW = 2,
  WIDOWED = 3,
  DIVORCED = 4,
  SEPARATED = 5,
  SINGLE = 6,
};

struct numeric_date {
  digit year[4];
  digit month[2];
  digit day[2];
};

struct tax_info {
  // Social insurance number.
  digit sin[9];
  // Always a valid date.
  struct numeric_date date_of_birth;
  // Always a valid date, or all zeros if empty.
  struct numeric_date date_of_death;
  // Always a valid enum value.
  enum marital marital_status;
};

int main() {
  
  struct tax_info my_tax_info = {
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

  // TODO: print out the contents of the form.

  return 0;
}