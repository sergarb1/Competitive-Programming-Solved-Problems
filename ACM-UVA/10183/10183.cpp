#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std; 


#define   MAXDIGITS   5000
#define PLUS     1          
#define MINUS    -1        
#define max(a,b) ((a>b)?a:b)
typedef struct {
        char digits[MAXDIGITS]; /* represent the number */
        int signbit;            /* 1 if positive, -1 if negative */ 
        int lastdigit;          /* index of high-order digit */
} bignum;
 

int add_bignum(bignum *a, bignum *b, bignum *c);

void print_bignum(bignum *n)
{
   int i;
   if (n->signbit == MINUS) printf("- ");
   printf(n->digits);
   printf("\n");
}
 

void int_to_bignum(int s, bignum *n)
{
   if (s >= 0) n->signbit = PLUS;
   else n->signbit = MINUS;
   int t = abs(s);
   sprintf(n->digits,"%d",t);
   n->lastdigit=strlen(n->digits);
}

void int_to_bignum(char *s, bignum *n)
{
   int i;
   if (s[0] != -1) 
   {  
       n->signbit = PLUS;
       i = 0;
   }
   else 
   {  i = 1;
       n->signbit = MINUS;
   }
   strcpy(n->digits,&s[i]);
   n->lastdigit = strlen(n->digits);
}

void initialize_bignum(bignum *n)
{   int_to_bignum(0,n);    }  

/*int max( int a, int b )
{
//	if (a > b) return(a); else return(b); 
	return ( a > b ) ? a : b;
}*/

void zero_justify(bignum *n)
{
	while ((n->lastdigit > 0) && (n->digits[ n->lastdigit ] == 0))
		n->lastdigit --;

	if ((n->lastdigit == 0) && (n->digits[0] == 0))
		n->signbit = PLUS;	/* hack to avoid -0 */
}

int compare_bignum(bignum *a, bignum *b)
{
   int i;           /* counter */
 
   if ((a->signbit == MINUS) && (b->signbit == PLUS)) return(PLUS);
   if ((a->signbit == PLUS) && (b->signbit == MINUS)) return(MINUS);
 
   if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);
   if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);
 
   for (i = 0;  i < a->lastdigit; i++ ) 
   {
       if (a->digits[i] > b->digits[i]) return(MINUS * a->signbit);
       if (b->digits[i] > a->digits[i]) return(PLUS * a->signbit);
   }
 
   return(0);
}

/*	c = a - b;	*/
int subtract_bignum(bignum *a, bignum *b, bignum *c)
{
   int borrow;                      /* has anything been borrowed? */
   int v;                           /* placeholder digit */
   register int i,j,op=0;           /* counter */
   int n_borrow;
   int temp;
   
   c->signbit = PLUS;
   if ((a->signbit == MINUS) || (b->signbit == MINUS)) 
   {
       b->signbit = -1 * b->signbit;
        n_borrow = add_bignum(a,b,c);
        b->signbit = -1 * b->signbit;
       return n_borrow;
    }
 
   if (compare_bignum(a,b) == PLUS) 
   {
      n_borrow = subtract_bignum(b,a,c);
       c->signbit = MINUS;
       return n_borrow;
   }
 
   int k = c->lastdigit = max(a->lastdigit,b->lastdigit);
   n_borrow=0;
   c->digits[k--]='\0';
   for(i=a->lastdigit-1,j=b->lastdigit-1;j>=0;i--,j--)
   {
       temp = a->digits[i]-'0'-( b->digits[j]-'0'+op);
      if(temp < 0)
       {
          temp += 10;
          op=1;
          n_borrow++;
       }
       else op=0;
       c->digits[k--]= temp+'0';
   }
 
   while(op)
   {
       temp = a->digits[i--]-op-'0';
      if(temp < 0)
       {
          temp += 10;
          op=1;
          n_borrow++;
       }
       else op=0;
       c->digits[k--]= temp+'0';
   }
 
   for(;i>=0;i--)
       c->digits[k--]=a->digits[i];
   
   for(i=0;!(c->digits[i]-'0');i++);
   c->lastdigit = c->lastdigit - i;
   if(i==a->lastdigit)
      strcpy(c->digits,"0");
   else
   {
       char string[MAXDIGITS];
      strcpy(string,&c->digits[i]);
      strcpy(c->digits,string);
   }
   return n_borrow;
}

/*	c = a + b;	*/
int add_bignum(bignum *a, bignum *b, bignum *c)
{
   int carry;                /* carry digit */
   int i,j,op=0;;            /* counter */
   int n_carry,temp;
   initialize_bignum(c);

   if(a->lastdigit < b->lastdigit)
       return add_bignum(b,a,c);
   int k = c->lastdigit = a->lastdigit+1;
   c->digits[k--]='\0';
   carry = 0;
   n_carry = 0;
   
   for(i=b->lastdigit-1,j=a->lastdigit-1;i>=0;i--,j--)
   {
       carry = b->digits[i]-'0'+a->digits[j]-'0'+carry;
       c->digits[k--]= (carry%10)+'0';
      carry=carry/10;
      if(carry)
          n_carry++;
   }
   
   for(;j>=0;j--)
   {
       carry = a->digits[j]-'0'+carry;
       c->digits[k--] = (carry % 10)+'0';
       carry = carry/10;
      if(carry)
          n_carry++;
   }
   if(carry)
       c->digits[k]=carry+'0';
   else
   {
       char string[MAXDIGITS];
      strcpy(string,&c->digits[1]);
      strcpy(c->digits,string);
       c->lastdigit=c->lastdigit - k - 1;
   }
   return n_carry;
}

void digit_shift( bignum *n, int d )		/* multiply n by 10^d */
{
	int i;				/* counter */

	if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;

	for (i=n->lastdigit; i>=0; i--)
		n->digits[i+d] = n->digits[i];

	for (i=0; i<d; i++) n->digits[i] = 0;

	n->lastdigit = n->lastdigit + d;
}

/*	c = a * b;	*/
void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
   long int n_d;
   register long int i,j,k;
   short int num1[MAXDIGITS],num2[MAXDIGITS],of=0,res[MAXDIGITS]={0};
   
   n_d=(a->lastdigit<b->lastdigit)?b->lastdigit:a->lastdigit;
   n_d++         ;
   
 
   for(i=0,j= a->lastdigit-1;i< a->lastdigit ;i++,j--)
      num1[i]=a->digits[j]-48;
 
   for(i=0,j= b->lastdigit-1;i< b->lastdigit ;j--,i++)
      num2[i]=b->digits[j]-48;
   res[0]=0;
   
   for(j=0;j< b ->lastdigit;j++)
   {   for(i=0,k=j;i< a->lastdigit || of;k++,i++)
       {   if(i<a->lastdigit)
             res[k] += num1[i] * num2[j] + of;
          else   res[k] += of;
          of=res[k]/10;
          res[k]=res[k]%10;
       }
   }
   
   for(i=k-1,j=0;i>=0;i--,j++)
       c->digits[j]=res[i]+48;
   c->digits[j]='\0';
   c->lastdigit=k; 
   c->signbit = a->signbit*b->signbit;
}

/*	c = a / b;	*/
void divide_bignum( bignum *a, bignum *b, bignum *c )
{
	bignum row;             /* represent shifted row */
	bignum tmp;             /* placeholder bignum */
	int asign, bsign;		/* temporary signs */
	int i;                  /* counters */

	initialize_bignum(c);

	c->signbit = a->signbit * b->signbit;

	asign = a->signbit;
	bsign = b->signbit;

	a->signbit = PLUS;
	b->signbit = PLUS;

	initialize_bignum(&row);
	initialize_bignum(&tmp);

	c->lastdigit = a->lastdigit;

	for (i=a->lastdigit; i>=0; i--) {
		digit_shift(&row,1);
		row.digits[0] = a->digits[i];
		c->digits[i] = 0;
		while (compare_bignum(&row,b) != PLUS) {
			c->digits[i] ++;
			subtract_bignum(&row,b,&tmp);
			row = tmp;
		}
	}

	zero_justify(c);

	a->signbit = asign;
	b->signbit = bsign;
}

void copy(bignum *a, bignum *b)
{
    a->lastdigit=b->lastdigit;
    a->signbit = b->signbit;
    strcpy(a->digits,b->digits);
}

int is_zero(bignum *a)
{
    for(int i=0;i<a->lastdigit;i++)
	{
	 	if(a->digits[i]!='0')
		      return 0;	
	}	
	return 1;
}

int is_one(bignum *a)
{
    for(int i=0;i<a->lastdigit;i++)
	{
	 	if(a->digits[i]!='1')
		      return 0;	
	}	
	return 1;
}





bignum fibonacci[490];
bignum aux, tope, base;
char num1[110], num2[110];
bignum numb1, numb2;

int main() 
{ 
  int i, j, res;

 /* #ifndef ONLINE_JUDGE 
          close (0); open ("10183.in", O_RDONLY); 
          close (1); open ("10183.out", O_WRONLY | O_CREAT, 0600); 
  #endif */
  
  // Calcular 10^100 , que es el maximo a calcular
  
  int_to_bignum(10, &base);
  int_to_bignum(1, &tope);
  for(i=0; i<100; i++)
  {
   		multiply_bignum(&tope, &base, &aux);
		tope=aux;
  }
  
  //Calcular los numeros de Fibonacci hasta que sean <=10^100
  int_to_bignum(1, &fibonacci[0]);
  aux=fibonacci[0];
  int_to_bignum(2, &fibonacci[1]);
  aux=fibonacci[1];
  
  for(i=2;compare_bignum(&fibonacci[i-1], &tope)>=0;i++)
  {
      add_bignum(&fibonacci[i-1], &fibonacci[i-2], &fibonacci[i]);
      aux=fibonacci[i];
  }
  
  //Calculamos los numeros de fibonacci que hay entre 2 numeros
  cin >> num1 >> num2;

  int_to_bignum(num1, &numb1);
  int_to_bignum(num2, &numb2);
  
  // Mientras ninguno sea cero, ejecutamos el programa
  while(is_zero(&numb1)==0 || is_zero(&numb2)==0)
  {           
              // Intercambiamos el orden si no estan ordenados
      if(compare_bignum(&numb1, &numb2)==-1)
      {
	      aux=numb1;
	      numb1=numb2;
          numb2=aux;
      }		
		for(j=0;j<=i;j++)
	    {
 			if(compare_bignum(&numb1,&fibonacci[j])>=0)
            {
				break;
            }
        }

		res=0;
		while(j<=i)
	    {
            if(compare_bignum(&numb2,&fibonacci[j])>0)
            {
				break;
            }
			res++;
			j++;
        }
        
        cout<<res<<endl;

        cin>>num1>>num2;
        
        int_to_bignum(num1, &numb1);
        int_to_bignum(num2, &numb2);
  }

  return 0;
}
