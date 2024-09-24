#include <stdio.h>

#include <string.h>

#define MAX 100
int top = -1;
char stack[MAX];
int isEmpty() {
  return top == -1;
}
int isfull() {
  return top == (MAX - 1);
}
void push(char x) {
  if (isfull()) {
    printf("stack overflow");
    return;
  } else
    stack[++top] = x;
}
char pop(char x) {
  if (isEmpty()) {
    printf("stack underflow");
    return x;
  } else
    return stack[top--];
}
int main() {
  int count;
  char s[] = "()"; //editable
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      push(s[i]);
      count++;
    } else if (s[i] == ')') {
      if (pop(s[i]) == '(')
        count--;
    } else if (s[i] == '}') {
      if (pop(s[i]) == '{')
        count--;
    } else if (s[i] == ']') {
      if (pop(s[i]) == ']')
        count--;
    } else continue;
  }
  if (count == 0)
    printf("balanced");
  else
    printf("unbalanced");
  return 0;
}
