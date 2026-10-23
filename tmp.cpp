#include "stdio.h"

int main(){
  char ch;
  int letters=0,space=0,digit=0,other=0;
  while((ch=getchar())!='\n'){
    if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z'))letters++;
    else if(ch==' ')space++;
    else if(ch>='0' && ch<='9')digit++;
    else other++;
  }
  printf("letters=%d;space=%d;digit=%d;other=%d\n",letters,space,digit,other);
  
  return 0;
}