/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

static int recurse(int count) {
  if (count == 0) {
    return 77;
  }
  return recurse(count - 1) * 99;
}

int main(int argc, char* argv[]) {
  int fd = open("/dev/zero", O_RDONLY);
  char ch;
  test_assert(fd >= 0);

  test_assert(1 == read(fd, &ch, 1));
  test_assert(1 == read(fd, &ch, 1));

  atomic_printf("recurse=%d\n", recurse(10000));

  atomic_puts("EXIT-SUCCESS");

  return 0;
}
