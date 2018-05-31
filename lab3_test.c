#include "types.h"
#include "stat.h"
#include "user.h"

int test(int n)
{ 
   int x = n + 1;
   return x;
}

int StackGrowth(int n){
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  
  int a, b, d;
  register int sp asm ("sp");
  printf(1, "%x\n", sp);
  a = StackGrowth(n - 1);
  b = StackGrowth(n - 1);
  d = a + b;
  return d;// StackGrowth(d);

}


int main(int argc, char *argv[]) {
    printf(1, "####################################################\n");
    printf(1, "# This program tests the correctness of your lab #3\n");
    printf(1, "####################################################\n");

    printf(1, "Test 1: Simple test\n");
    int pid = 0;
    pid = fork();
    if(pid == 0){
        test(1);
        exit();
    }
    wait();

    printf(1, "Test 2: Stack growth test.\n");

    pid = fork();
     if(pid == 0){
       StackGrowth(102);
       printf(1, "---complete---\n");
       exit();
    }
    wait();
    exit();
}
   
