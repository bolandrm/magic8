#include "eight.h"
#include <stdio.h>
#include <stddef.h>

int main() {
  eight_setup();

  eight_options *opts;
  opts->has_additional_response = 0;
  opts->additional_response = "Yeah, right";

  for(int i = 0; i < 20; i++) {
    puts(eight_shake(opts));
  }

  return 0;
}
