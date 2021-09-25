/////////////////////////////////////////////////////////////////////////////
// retargetio.c
/////////////////////////////////////////////////////////////////////////////

#if defined __C51__

extern char RETARGET_ReadChar(void);
extern char RETARGET_WriteChar(char c);

char _getkey ()  {
  return(RETARGET_ReadChar());
}

char putchar (char c)
{
  return(RETARGET_WriteChar(c));
}

#elif defined __ICC8051__

extern int RETARGET_ReadChar(void);
extern int RETARGET_WriteChar(int c);

int getchar(void){
  return(RETARGET_ReadChar());
}

int putchar(int c)
{
  return(RETARGET_WriteChar(c));
}

#endif
