
/** global static int variable. it will help us note 
*   when we stopped receiving signals
*/

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /** 
     *  create a variable static int i to count the numbers of bit read
     *  void the args you are not using
     *
     *  change the global varaible to 1
     *  if signum == SIGUSR2 
     *     increment i
     *  else if signum == SIGUSR1 
      *    print the number of bytes recieved (NB: 8 bits = 1 byte)
     */
}

int char_to_bin(char c, int pid)
{
  /** 
     *  VARIABLES
     *  
     *  create a variable int itr
     *  int bit_index to loop over each byte
     *
     *  initialise bit_index to 7 ie 0 -> 7 which will make 8 bits
     *  create a while loop to loop bit by bit by decrementing from 7 to 0
     * while(bit_idx >= 0)
     *{
          // initialize itr back to zero
          // conversion
          if ((c >> bit_index) & 1)
              kill(pid, SIGUSR1);
          else
              kill(pid, SIGUSR2);
          while (g_receiver == 0)
          {
             if (itr == 50) // wait for response after count of 50 (any number)
             {
                //print no response from server here and exit
             }
             // increment itr by 1
             usleep(100); // gives enough time for each signal to be processed
          }
          // re-initialize g_receiver back to zero and decrement bit_index by 1
         }
         return (0);
     */
}

int main(int argc, char* argv[])
{
  /** 
   *  VARIABLES
   *  create a struct for our sigaction
   *  create a variable for each byte
   *  then variable for the process identifier
   *
   *  SIGACTION
   *  Check if the right number of argument is being passed
   *  convert the servers pid argument from string to number
          and save it to the process identifier variable
   *  empty the signal numbers to prevent error 
   *  -> u can use the sigemptyset. some people also use the memset func
   *  set the appropraite flags for sigaction
   *  also set the sig_handler func
   *  call the sigaction function twice: with SIGUSR1 and SIGUSR2 respectively
   *  you can handle the error for the function call,
   *  where -1 means an error occurred
   *  Handle each character of the string by looping over
   *  and converting to binary using a function with a prototype of
   *  int char_to_bin(char c, int pid) // note: c -> argv[2][byte_index++]
   *  then outside the loop call the conversion function again but
   *  this time pass '\0' as char. This is important in preparing 
   *  the server for new feed of strings 
   */
}