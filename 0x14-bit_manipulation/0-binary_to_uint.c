#include "main.h"

unsigned int binary_to_uint(const char *b)
{
  int i;
  unsigned int dec_val = 0;

  for (i = 0; b[i]; i++) 
  {
   	 if (b[i] == '0') {
      	continue;
    } else if (b[i] == '1') {
      dec_val = dec_val * 2 + 1;
    } else {
      return 0;
    }
  }

  return dec_val;
}
