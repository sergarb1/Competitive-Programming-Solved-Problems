#include <cstdlib>
#include <iostream>
using namespace std;


int comparar(const void *a,const void *b);

int main()
{
    int familiares[500];
    int nfam;
    int ntest;
    int i,j,k;
    
    cin >> ntest;
    
    for(i=0;i<ntest;i++)
    {
             int distancia=0,dis_temp=0,res=0,res2=0,res_aux=0; 
             cin >> nfam;
             for(j=0;j<nfam;j++)
             {
                    cin >> familiares[j];
             }           
             //qsort(familiares,nfam,sizeof(familiares[0]),comparar);
             for(j=0;j<nfam;j++)
             {
                  distancia+=familiares[j];
             }
             
             if(nfam>0)
                 distancia/=nfam;
             
             for(j=0;j<nfam;j++)
             {
                      if(familiares[j]<distancia)
                      {
                               res+=distancia-familiares[j];
                      }
                      else
                      {
                          res+=familiares[j]-distancia;
                      }
             }
             //cout << res << " " << distancia << endl;
             
             dis_temp=distancia;
             
             do{
                 
                 res2=0;
                 distancia++;
                 res_aux=res;
                 for(j=0;j<nfam;j++)
                 {
                      if(familiares[j]<(distancia))
                      {
                               res2+=(distancia)-familiares[j];
                      }
                      else
                      {
                          res2+=familiares[j]-(distancia);
                      }
                 }
                 if(res2<res)
                     res=res2;
                 //cout << res << " " << distancia << endl;
             }while(res_aux>res);
             
             distancia=dis_temp;
             
             do{
                 res2=0;
                 distancia--;
                 res_aux=res;
                 for(j=0;j<nfam;j++)
                 {
                      if(familiares[j]<(distancia))
                      {
                               res2+=(distancia)-familiares[j];
                      }
                      else
                      {
                          res2+=familiares[j]-(distancia);
                      }
                 }
                 if(res2<res)
                     res=res2;
             
                 //cout << res << " " << distancia << endl;
             }while(res_aux>res);
             
             cout << res << endl;
    }
    
    return 0;
}

int comparar(const void *a,const void *b)
{
     return (*(int *)a -*(int*)b);          
}
