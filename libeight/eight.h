#define NUM_STANDARD_RESPONSES 20

typedef struct {
  int has_additional_response;
  char *additional_response;
} eight_options;

void eight_setup();
char *eight_shake(eight_options *options);
