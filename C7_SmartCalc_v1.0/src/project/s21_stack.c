#include "s21_calculation.h"

// luchshe parser syuda pihnut'

void push(my_stack **head, int type);  // hz pochemu ne rabotaet
void push_str(my_str **head, double value,
              int ifX);  // dobavlenie operanda v stroku
void push_str_func(my_str **head,
                   element_type func);  // dobavlenie operatora v stroku
my_stack pop(my_stack **head);
my_stack top(my_stack head);
int topSimType(my_stack head);
double add_digit(char *str, int *i, int *check);  // schitivanie chisla
void destr(my_stack **root);                      // chistka pamyati
int notat_helper(char *str, int *i, int *check);  // razbor operatorov
void add_to_str(my_stack **root, my_str **str_pol,
                int *check);  // dobavlenie v final'nue stroku
int notat_func(char *str, int *i, int *check);

int Notation(my_str **str_pol, char *str) {
  my_stack *root = NULL;
  int len = strlen(str);
  int stat = 1;
  for (int i = 0; i < len; i++) {
    if (*(str + i) == ' ') continue;
    if (*(str + i) == 'X' || (*(str + i) >= '0' && *(str + i) <= '9') ||
        ((*(str + i) == '-' || *(str + i) == '+') &&
         (i == 0 || *(str + i - 1) == '('))) {
      int sign = 1;
      if (*(str + i) == '-' || *(str + i) == '+') {
        sign = (*(str + i) == '-') ? -1 : 1;
        i++;
      }
      if (*(str + i) == 'X') {
        push_str(str_pol, sign, 1);
      } else {
        push_str(str_pol, sign * add_digit(str, &i, &stat), 0);
      }
    } else if (*(str + i) == '(') {
      push(&root, LEFT_BRACKET);
    } else if (*(str + i) == ')') {
      push(&root, RIGHT_BRACKET);
    } else {
      int a = notat_helper(str, &i, &stat);
      push(&root, a);
    }
    if (!stat) break;
    add_to_str(&root, str_pol, &stat);
  }
  if (!(*(str + len - 1) == 'X' ||
        (*(str + len - 1) >= '0' && *(str + len - 1) <= '9') ||
        *(str + len - 1) == ')'))
    stat = 0;
  /*while (root != NULL) {
      my_stack add;
      add = pop(&root);
      push_str_func(str_pol, add.type);
  }*/
  while (root != NULL && root->type != LEFT_BRACKET) {
    my_stack add;
    add = pop(&root);
    push_str_func(str_pol, add.type);
  }
  if (root != NULL) {
    stat = 0;
    destr(&root);
  }
  return stat;
}

void push_str(my_str **head, double value, int ifX) {
  my_str *new = (my_str *)malloc(sizeof(my_str));
  if (ifX) {
    strcpy(new->info, (value == 1) ? "X\0" : "-X\0");
  } else {
    sprintf(new->info, "%lf", value);
  }
  new->next = NULL;
  if (*head == NULL) {
    *head = new;
  } else {
    my_str **last = head;
    while ((*last)->next != NULL) last = &((*last)->next);
    (*last)->next = new;
  }
}

double add_digit(char *str, int *i, int *check) {
  int stat = 0;
  double sum = 0;
  sum = atof((str + *i));
  while ((*(str + *i) >= '0' && *(str + *i) <= '9') || *(str + *i) == '.') {
    if (*(str + *i) == '.') stat++;
    *i += 1;
  }
  *i -= 1;
  if (stat > 1) *check = 0;
  return sum;
}

void destr(my_stack **root) {
  if ((*root)->next != NULL) destr(&(*root)->next);
  free(*root);
}

int notat_helper(char *str, int *i, int *check) {
  int stat = 0;
  switch (*(str + *i)) {
    case '+':
      stat = PLUS;
      break;
    case '-':
      stat = MINUS;
      break;
    case '*':
      stat = MULTIPLY;
      break;
    case '/':
      stat = DIVIDE;
      break;
    case '^':
      stat = POWER;
      break;
    default:
      if (!strncmp((str + *i), "mod", 3)) {
        stat = MODULATE;
        *i += 2;
      } else {
        stat = notat_func(str, i, check);
      }
      break;
  }
  return stat;
}

int notat_func(char *str, int *i, int *check) {
  int stat = 0;
  char copy[5];
  for (int j = 0; j < 5 && *(str + *i) != '('; j++) {
    copy[j] = *(str + *i);
    *i += 1;
  }
  if (*(str + *i) != '(') {
    *check = 0;
  } else {
    *i -= 1;
    if (!strncmp(copy, "sin", 3)) stat = SIN;
    if (!strncmp(copy, "cos", 3)) stat = COS;
    if (!strncmp(copy, "tan", 3)) stat = TAN;
    if (!strncmp(copy, "log", 3)) stat = LOG;
    if (!strncmp(copy, "ln", 2)) stat = LN;
    if (!strncmp(copy, "asin", 4)) stat = ASIN;
    if (!strncmp(copy, "acos", 4)) stat = ACOS;
    if (!strncmp(copy, "atan", 4)) stat = ATAN;
    if (!strncmp(copy, "sqrt", 4)) stat = SQRT;
  }
  return stat;
}

void add_to_str(my_stack **root, my_str **str_pol, int *check) {
  if (*root != NULL) {
    my_stack buf = pop(root);
    if (buf.type == LEFT_BRACKET || buf.type >= COS) {
      push(root, buf.type);
    }
    if (buf.type == RIGHT_BRACKET) {
      while (*root != NULL && (*root)->type != LEFT_BRACKET) {
        my_stack add;
        add = pop(root);
        push_str_func(str_pol, add.type);
      }
      if (*root == NULL) {
        *check = 0;
      } else {
        pop(root);
        if (*root != NULL && (*root)->type >= COS) {
          my_stack add2;
          add2 = pop(root);
          push_str_func(str_pol, add2.type);
        }
      }
    } else if (buf.type == PLUS || buf.type == MINUS) {
      while (*root != NULL && (*root)->type >= PLUS) {
        my_stack add;
        add = pop(root);
        push_str_func(str_pol, add.type);
      }
      push(root, buf.type);
    } else if (buf.type == MULTIPLY || buf.type == DIVIDE ||
               buf.type == MODULATE) {
      while (*root != NULL && (*root)->type >= DIVIDE) {
        my_stack add;
        add = pop(root);
        push_str_func(str_pol, add.type);
      }
      push(root, buf.type);
    } else if (buf.type == POWER) {
      while (*root != NULL && (*root)->type == POWER) {
        my_stack add;
        add = pop(root);
        push_str_func(str_pol, add.type);
      }
      push(root, buf.type);
    }
  }
}

void push_str_func(my_str **head, element_type func) {
  my_str *new = (my_str *)malloc(sizeof(my_str));
  switch (func) {
    case PLUS:
      strcpy(new->info, "+\0");
      break;
    case MINUS:
      strcpy(new->info, "-\0");
      break;
    case DIVIDE:
      strcpy(new->info, "/\0");
      break;
    case MULTIPLY:
      strcpy(new->info, "*\0");
      break;
    case MODULATE:
      strcpy(new->info, "mod\0");
      break;
    case POWER:
      strcpy(new->info, "^\0");
      break;
    case COS:
      strcpy(new->info, "cos\0");
      break;
    case SIN:
      strcpy(new->info, "sin\0");
      break;
    case TAN:
      strcpy(new->info, "tan\0");
      break;
    case ACOS:
      strcpy(new->info, "acos\0");
      break;
    case ASIN:
      strcpy(new->info, "asin\0");
      break;
    case ATAN:
      strcpy(new->info, "atan\0");
      break;
    case SQRT:
      strcpy(new->info, "sqrt\0");
      break;
    case LN:
      strcpy(new->info, "ln\0");
      break;
    case LOG:
      strcpy(new->info, "log\0");
      break;
    case LEFT_BRACKET:
      break;
    case RIGHT_BRACKET:
      break;
  }
  new->next = NULL;
  if (*head == NULL) {
    *head = new;
  } else {
    my_str **last = head;
    while ((*last)->next != NULL) last = &((*last)->next);
    (*last)->next = new;
  }
}

void push(my_stack **head, int type) {
  my_stack *element = (my_stack *)malloc(sizeof(my_stack));
  // проверка на выделенную память? if (!element) exit();
  element->type = type;
  element->next = NULL;
  if (*head == NULL) {
    *head = element;
  } else {
    element->next = (*head);
    (*head) = element;
  }
}

my_stack pop(my_stack **head) {
  my_stack *prev = (*head);
  my_stack element = {0};
  element.type = prev->type;
  element.next = NULL;
  (*head) = (*head)->next;
  free(prev);
  return element;
}

my_stack top(my_stack head) {
  my_stack element = head;
  return element;
}

int topSimType(my_stack head) { return head.type; }
