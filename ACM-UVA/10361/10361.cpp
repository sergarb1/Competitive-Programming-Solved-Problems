#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int main()
{
    int n;
    int i,j;
    char linea1[101];
    char linea2[101];
    
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10361.in", O_RDONLY);
        close (1); 
        open ("10361.out", O_WRONLY | O_CREAT, 0600);
    #endif
    cin >> n;
    cin.getline(linea1,100,'\n');
    
    for(i=0;i<n;i++)
    {
        char s2[101];
        char s3[101];
        char s4[101];
        char s5[101];
    
        int tam1,tam2;
        int es_s2=0,es_s3=0,es_s4=0,es_s5=0;
        cin.getline(linea1,100,'\n');
        cin.getline(linea2,100,'\n');
        tam1=strlen(linea1);
        tam2=strlen(linea2);
        for(j=0;j<tam1;j++)
        {
            if(linea1[j]!='<' && linea1[j]!='>')
            {
                cout << linea1[j];
            }    
            if(es_s2)
            {
                if(linea1[j]=='>')
                {
                     s2[es_s2-1]=0;
                     es_s2=0;
                     es_s3=1;
                }
                else
                {
                    s2[es_s2-1]=linea1[j];
                    es_s2++;
                }        
            }
            else if(es_s3)
            {
                
                if(linea1[j]=='<')
                {
                     s3[es_s3-1]=0;
                     es_s3=0;
                     es_s4=1;
                }
                else
                {
                    s3[es_s3-1]=linea1[j];
                    es_s3++;
                }        
            }
            else if(es_s4)
            {
                
                if(linea1[j]=='>')
                {
                     s4[es_s4-1]=0;
                     es_s4=0;
                     es_s5=1;
                }
                else
                {
                    s4[es_s4-1]=linea1[j];
                    es_s4++;
                }        
            }
            else if(es_s5)
            {
                
                if(linea1[j]=='>')
                {
                     s5[es_s5-1]=0;
                }
                else
                {
                    s5[es_s5-1]=linea1[j];
                    es_s5++;
                }        
            }
            else
            {
                if(linea1[j]=='<')
                        es_s2=1;
            }                    
        }
        
        s5[es_s5-1]=0;
        
        cout << endl;
        
        for(j=0;j<tam2-3;j++)
        {
            cout << linea2[j];
        }    
        
        cout << s4 << s3 << s2 << s5;
        cout << endl;
        
    }    
    
    
    return 0;
}
