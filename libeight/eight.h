#define NUM_STANDARD_RESPONSES 20

typedef struct {
  // Note: it is not possible to have both an additional
  // response and a callback function

  int has_additional_response;
  char *additional_response;

  int has_callback_response;
  char *(*callback_response)(void);
} eight_options;

// You must call this before making any other calls to libeight
void eight_setup();

// Basic magic 8 ball shake - no options required
char *eight_quick_shake();

// This is an advanced shake with options
char *eight_shake(eight_options *options);
