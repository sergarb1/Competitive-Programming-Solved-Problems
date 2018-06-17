#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std; 


#define INFINITO 100000000

#define MAXV 5001 
#define MAXDEGREE 1001

typedef struct {
        int edges[MAXV+1][MAXDEGREE];
        int degree[MAXV+1];
        int nvertices;
        int nedges;
}graph;

int papers[MAXV];

int res[MAXV];

graph g;

map <string, int> diccionario;


void imprimir_grafo()
{
     
     int i,j,k;
     cout << endl <<"IMPRIMO GRAFO" << endl;
     for(i=0;i<g.nvertices;i++)
     {
         for(j=0;j<g.degree[i];j++)
         {
             cout << g.edges[i][j] << " ";
         }
         cout << endl << endl;
     }
}

void leer_linea(int nlinea)
{
     char linea[10005];
     cin.getline(linea,10002 );
     int tam=strlen(linea);
     char nombre[210];
     int poslinea=0;
     int i,j,k,l;
     int ncomas=0;
     j=0;
     k=0;
     for(i=0;i<tam;i++)
     {
        if(linea[i]==',')
        {
           if(ncomas==1)
           {
                 nombre[j]=0;
                 string tmp=nombre;
                 if (diccionario.find(tmp) == diccionario.end()) // se habia insertado previamente?
                 {
                        diccionario[tmp]=g.nvertices++;
                        g.degree[diccionario[tmp]]=0;
                 }
                       
                 papers[k++]=diccionario[tmp];
                 
                 j=0;
                 for(l=0;l<k-1;l++)
                 {
                    g.edges[papers[k-1]][g.degree[papers[k-1]]]=papers[l];
                    g.degree[papers[k-1]]++;
                    g.edges[papers[l]][g.degree[papers[l]]]=papers[k-1];
                    g.degree[papers[l]]++;
                    
                 }    
                 //imprimir_grafo();
                 ncomas=0;   
           }
           else
           {
               ncomas=1;
               nombre[j]=linea[i];
               j++;
           }
        }
        else if(linea[i]==':' || linea[i]==0 ||linea[i]=='\n')
        {
             
                 nombre[j]=0;
                 string tmp=nombre;
                 if (diccionario.find(tmp) == diccionario.end()) // se habia insertado previamente?
                 {
                        diccionario[tmp]=g.nvertices++;
                        g.degree[diccionario[tmp]]=0;
                 }
                       
                 papers[k++]=diccionario[tmp];
                 //cout << "PAPWLWA "<< papers[k-1] << " " << k<< " " << nlinea << endl;
                 j=0;
                 for(l=0;l<k-1;l++)
                 {
                    g.edges[papers[k-1]][g.degree[papers[k-1]]]=papers[l];
                    g.degree[papers[k-1]]++;
                   // cout << "grado" <<g.degree[papers[k-1]]<<endl;
                    g.edges[papers[l]][g.degree[papers[l]]]=papers[k-1];
                    g.degree[papers[l]]++;
                    
                 } 
             break;
        }
        else
        {
            if( isspace(linea[i]) || linea[i]=='\t' || linea[i]=='\r')
            {
            }
            else
            {
                nombre[j]=linea[i];
                j++;
            
            }
        }
     }
}


void busqueda_en_anchura()
{
     queue<int> q;
     string n="Erdos,P.";
     if(diccionario.find(n) == diccionario.end()) // Por si no esta ERDOS, cancelar la busqueda y meter a ERDOS
     {  
           diccionario[n]=g.nvertices++;// MEtemos a ERDOS por si nos preguntan sacarle en 0
           res[diccionario[n]]=0;
           g.degree[diccionario[n]]=0;              
           return;
     }
     int num=diccionario[n];
     res[num]=0;
     q.push(num);
     
     while(!q.empty())
     {
             int n=q.front();
             q.pop();
             for(int i=0;i<g.degree[n];i++)
             {
                     if(res[g.edges[n][i]]>res[n]+1)
                     {
                         res[g.edges[n][i]]=res[n]+1;
                         q.push(g.edges[n][i]);
                     }
             }
     }
}

void sergi_trim(char a[])
{
     char n[10005];
     strcpy(n,a);
     int tam=strlen(n);
     int j=0;
     for(int i=0;i<tam;i++)
     {
             if(isspace(n[i]) ||n[i]=='\t' || n[i]=='\r')
             {
             }
             else
             {
                               a[j++]=n[i];
             }
     }
     a[j]=0;
 }

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10044.in", O_RDONLY); 
          close (1); open ("10044.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int nesc;
  cin >> nesc;
  for(i=0;i<nesc;i++)
  {                  
                     g.nvertices=0;
                     diccionario.clear();
                     for(j=0;j<MAXV;j++)
                          res[j]=INFINITO;
                     int n,p;
                     cin >> p >> n;
                     char tmp=cin.get();
                     for(j=0;j<p;j++)
                     {
                        leer_linea(j);  
                              
                     }
                     //imprimir_grafo();
                     busqueda_en_anchura();
                     cout << "Scenario " << i+1 << endl;
                     for(j=0;j<n;j++)
                     {
                                     char nb[10005];
                                     
                                     char nz[10005];
                                     
                                     cin.getline(nb,10002);
                                     strcpy(nz,nb);
                                     sergi_trim(nb);
                                     string nombre=nb;
                                     int t=diccionario[nombre];
                                     if (diccionario.find(nombre) == diccionario.end())
                                     {
                                         cout << nz << " infinity" << endl;
                                     } 
                                     else
                                     {
                                         if(res[t]==INFINITO)
                                         {
                                                             
                                              cout << nz << " infinity" << endl;
                                         }
                                         else
                                         {
                                             cout << nz << " " << res[t] << endl;
                                         }
                                     }
                     }
                     
                     
  }
  return 0;
}
