#include <iostream>
#include <string.h>
using namespace std;
int main() {
   int current = 0;
   char inputstr[10], c;
   cout<<"enter strig";
   cin>>inputstr;
  // gets(inputstr);
   int i =0;
   for (i=0;i<strlen(inputstr);i++)
    {
        while(1)
          {
              c=  inputstr[i];
              switch(current)
                    {
                        case 0: 
                                if(c=='0')
                                 {
                                     inputstr[i] = 'X';
                                     i++;
                                     current =1;
                                 }
                                else if(c=='Y')
                                {
                                    i++;
                                    current=3;
                                }
                                else
                                {
                                    current=-1;
                                }
                             break;
                             
                        case 1:
                               if(c=='0')
                                 {i++; current=1;}
                               else if(c = 'Y')
                                 {i++; current=1;}
                               else if (c =='1')
                                 { 
                                    inputstr[i] ='Y';
                                    i--;
                                    current =2;
                                 }
                             break;
                        case 2:
                              if(c=='0')
                               {i--;current= 2;}
                              else if(c=='Y')
                               {i--;current= 2;}
                              else if(c=='X')
                               {i++;current= 0;}  
                              else
                               {current= -1;}
                              break; 
                        case 3:
                             if(c=='Y')
                                {
                                  i++;current = 3;
                                }
                            else if (c=='\0')
                                {i++;current =4;}
                            else
                             {current = -1; }
                             break;
    
                    }
          
              break;
          }
        
        if (current= '4')
          {
              cout<< "accpeted string";
              
          }
          else
          {
              cout<< "rejected string";
              
          }
    }
    return 0;
}

