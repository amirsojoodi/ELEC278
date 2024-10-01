#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to decode the string
char* decodeString(char* s) {
  // to do: complete
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