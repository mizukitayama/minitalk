void bin_to_char(int signum, char* c)
{
/**
 * if (signum == SIGUSR1) *c = (*c << 1) | 1;
 * else if (signum == SIGUSR2) *c <<= 1;
*/
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /**
  * create static int variable for pid and i and static char for c
  * void unused arg
  * set the details of the pid you are receiving from to the pid by using
  * info->pid
  * send the signal number and address of c to the bin_to_char function
  * if (++i == 8) // for every 8 bit read c
     {
      initialize i to 0
      if (!c) // this if block prepares the server for new feed of strings
      {
         kill(pid, SIGUSR1);
         // initialize pid to zero, so that you can handle multiple terminals
         // return
      }
      // since we have read 8 bits we can now read c and then initalise it back
      // back to null
     }
     kill(pid, SIGUSR2);
  */
}

int main(void)
{
/** 
   *  VARIABLES
   *  create a struct for our sigaction
   * 
   *  print the server pid using getpid()
   *  SIGACTION
   *  -> u can use the sigemptyset. some people also use the memset func
   *  set the appropraite flags for sigaction
   *  also set the sig_handler func
   *  call the sigaction function twice: with SIGUSR1 and SIGUSR2 respectively
   *  you can handle the error for the function call,
   *  create a while loop to wait for signals while(1) pause();
   */
 return (0);
}ï