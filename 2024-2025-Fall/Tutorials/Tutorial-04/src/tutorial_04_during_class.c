#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void print_tmp(char* tmp, int length) {
  printf("tmp: ");
  for (int i = 0; i < length; i++) {
    printf("%c ", tmp[i]);
  }
  printf("\n");
}


void print_stack(char* stack, int top) {
  printf("Stack: ");
  for (int i = 0; i <= top; i++) {
    printf("%c ", stack[i]);
  }
  printf("\n");
}
// Function to decode the string
char* decodeString(char* s) {
  char* stack = (char*)malloc(sizeof(char) * MAX);
  int top = -1;
  int index = 0;

  while (s[index] != '\0') {
    if (s[index] != ']') {
      stack[++top] = s[index++];
      print_stack(stack, top);
      continue;
    }
    // We saw a ], so we pop everything until we hit a number or the bottom of the stack
    char tmp[MAX];
    int tmp_index = 0;

    while (top >= 0 && stack[top] != '[' && !isdigit(stack[top])) {
      tmp[tmp_index++] = stack[top--];
    }
    top--;

    for (int j = 0; j < tmp_index / 2; j++) {
      char a = tmp[j];
      tmp[j] = tmp[tmp_index - j - 1];
      tmp[tmp_index - j - 1] = a;
    }
    print_tmp(tmp, tmp_index);
    print_stack(stack, top);

    int base = 1;
    int rep = 0;
    while(top >= 0 && isdigit(stack[top])){
      rep = rep + base * (stack[top--] - '0');
      base = base * 10;
    }

    printf("Rep: %d\n", rep);

    for(int r = 0; r < rep; r++) {
      for(int i = 0; i < tmp_index; i++) {
        stack[++top] = tmp[i];
      }
    }

    print_stack(stack, top);

    index++;
  }
  return stack;
}

int main() {
  char s1[] = "3[a]2[bc]";
  char s2[] = "3[a2[c]]";
  char s3[] = "2[abc]3[cd]ef";

  char* s = decodeString(s1);
  printf("Decoded string [%s]: %s\n", s1, s);
  free(s);

  s = decodeString(s2);
  printf("Decoded string [%s]: %s\n", s2, s);
  free(s);

  s = decodeString(s3);
  printf("Decoded string [%s]: %s\n", s3, s);
  free(s);

  return 0;
}