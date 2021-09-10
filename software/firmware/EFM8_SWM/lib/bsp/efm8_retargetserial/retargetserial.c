/////////////////////////////////////////////////////////////////////////////
// retargetserial.c
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "retargetserial.h"

#if defined __C51__
#include <reg51.h>

#elif defined __ICC8051__
#include <io8052.h>

#endif

/////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////

#if defined __C51__

char RETARGET_ReadChar ()  {
  char c;

  while (!RI);
  c = SBUF;
  RI = 0;
  return (c);
}

char RETARGET_WriteChar (char c)  {
  if (c == '\n')  {
    while (!TI);
    TI = 0;
    SBUF = '\r';
  }
  while (!TI);
  TI = 0;
  return (SBUF = c);
}

#elif defined __ICC8051__

int RETARGET_ReadChar(void){
  while (!SCON_bit.RI);
  {
    int c = SBUF;
    SCON_bit.RI = 0;
    return (c);
  }
}

int RETARGET_WriteChar(int c)  {
  if (c == '\n')  {
    while (!SCON_bit.TI);
    SCON_bit.TI = 0;
    SBUF = '\r';
  }
  while (!SCON_bit.TI);
  SCON_bit.TI = 0;
  return (SBUF = c);
}

#endif
