#include "s21_calculation.h"

int calc(my_str *str, double *ans, double x) {
  int stat = 1;
  my_str *buf = str;
  double number[100] = {0};
  int j = 0;
  while (buf != NULL && stat) {
    if (((buf->info[0] >= '0' && buf->info[0] <= '9') || buf->info[0] == 'X') ||
        ((buf->info[0] >= '-' || buf->info[0] >= '+') &&
         ((buf->info[1] >= '0' && buf->info[1] <= '9') ||
          buf->info[1] == 'X'))) {
      if (buf->info[0] != 'X' && buf->info[1] != 'X') {
        number[j] = atof(buf->info);
      } else {
        number[j] = (buf->info[0] != '-') ? x : -x;
      }
      j++;
    } else if (buf->info[0] == '+') {
      number[j - 2] = number[j - 2] + number[j - 1];
      j--;
    } else if (buf->info[0] == '-') {
      number[j - 2] = number[j - 2] - number[j - 1];
      j--;
    } else if (buf->info[0] == '/') {
      number[j - 2] = number[j - 2] / number[j - 1];
      j--;
    } else if (buf->info[0] == '*') {
      number[j - 2] = number[j - 2] * number[j - 1];
      j--;
    } else if (buf->info[0] == '^') {
      number[j - 2] = pow(number[j - 2], number[j - 1]);
      j--;
    } else if (!strncmp(buf->info, "mod", 3)) {
      number[j - 2] = (int)number[j - 2] % (int)number[j - 1];
      j--;
    } else if (!strncmp(buf->info, "sin", 3)) {
      number[j - 1] = sin(number[j - 1]);
    } else if (!strncmp(buf->info, "cos", 3)) {
      number[j - 1] = cos(number[j - 1]);
    } else if (!strncmp(buf->info, "tan", 3)) {
      number[j - 1] = tan(number[j - 1]);
    } else if (!strncmp(buf->info, "log", 3)) {
      if (number[j - 1] < 0.0) {
        stat = 0;
        break;
      }
      number[j - 1] = log10(number[j - 1]);
    } else if (!strncmp(buf->info, "asin", 4)) {
      if (fabs(number[j - 1]) > 1.0) {
        stat = 0;
        break;
      }
      number[j - 1] = asin(number[j - 1]);
    } else if (!strncmp(buf->info, "acos", 4)) {
      if (fabs(number[j - 1]) > 1.0) {
        stat = 0;
        break;
      }
      number[j - 1] = acos(number[j - 1]);
    } else if (!strncmp(buf->info, "atan", 4)) {
      number[j - 1] = atan(number[j - 1]);
    } else if (!strncmp(buf->info, "sqrt", 4)) {
      if (number[j - 1] < 0.0) {
        stat = 0;
        break;
      } else {
        number[j - 1] = sqrt(number[j - 1]);
      }
    } else if (!strncmp(buf->info, "ln", 2)) {
      if (number[j - 1] < 0.0) {
        stat = 0;
        break;
      }
      number[j - 1] = log(number[j - 1]);
    } else {
      stat = 0;
      break;
    }
    buf = buf->next;
  }
  if (stat) *ans = number[0];
  return stat;
}
