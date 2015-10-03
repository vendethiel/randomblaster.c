#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char  *read_line()
{
  ssize_t  ret;
  char     *buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
  {
    buff[ret - 1] = '\0';
    return (buff);
  }
  buff[0] = '\0';
  return (buff);
}

