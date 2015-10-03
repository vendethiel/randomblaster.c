#include <errno.h>

/* long conv error? */
int lconv_error() {
  return errno == EINVAL || errno == ERANGE;
}
