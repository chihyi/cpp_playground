int count_x(const char *string, char x) {
  if (!string) {
    return 0;
  }

  int count = 0;
  while (*string) {
    if (*string == x)
      count++;
    string++;
  }
  return count;
}
