#include <cstdio>

void Test1() {
  FILE *fp;
  char str[60];

  /* opening file for reading */
  fp = fopen("file.txt", "r");
  if (fp == nullptr) {
    perror("Error opening file");
  }
  if (fgets(str, 60, fp) != nullptr) {
    /* writing content to stdout */
    puts(str);
  }
  fclose(fp);
}

void Test2() {
  printf("username %s", "leo");
}

int main() {
}
