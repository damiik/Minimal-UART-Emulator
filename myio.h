// Code based on:
//https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux


#include <unistd.h>
#include <termios.h>
#include <fcntl.h>



int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

void enable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSANOW, &term);
}


static uint64_t GetTickCountNs()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (uint64_t) (ts.tv_nsec) + ((uint64_t) ts.tv_sec * 1000000000ull);
}



/*
int getch()
{
  struct termios oldt, newt;
  int ch;

  tcgetattr( STDIN_FILENO, &oldt );

  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );

  tcsetattr( STDIN_FILENO, TCSANOW, &newt );

  ch = getchar();
  
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}


int main ()
{
  char ch;
  while (1)
    {  
      ch = getch();
  
      if (ch == 125)
	printf ("\nYou pressed SHIFT+]");
      
      else if (ch == 27)
	{
	  ch = getch();
	  if (ch == 91)
	    {
	      ch = getch();
	      if (ch == 65)
		printf("\nYou pressed UP arrow");
	      else if (ch == 66)
		printf("\nYou pressed DOWN arrow");
	      else if (ch == 67)
		printf("\nYou pressed RIGHT arrow");
	      else if (ch == 68)
		printf("\nYou pressed LEFT arrow");
	    }
	}
    }
}
*/