#include "header.h"

// provided function

int daysInMonth(int month, int year) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    return 31 case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
      default : throw runtime_error("Invalid month");
  }
}

int daysBetween(int year1, int month1, int day1, int year2, int month2,
                int day2) {}