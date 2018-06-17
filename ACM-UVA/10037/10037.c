#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

struct persona {

	int	cost,
		consumit,
		part;  /* 0=origen  1=desti */
};

struct persona	P[1000];
int 			n, no, nd;

int registre[2000][2], nr, temps_total;

int compara( const void *v1, const void *v2 )
{
	struct persona *p1=(struct persona *)v1,
				   *p2=(struct persona *)v2;

	if ( p1->cost < p2->cost ) return -1;
	if ( p1->cost > p2->cost ) return 1;
	return 0;
}

void registra( int p1, int p2 )
{
/* fprintf( stderr, "%d %d\n", p1, p2 ); */
/*
	assert( nr < 2000 );
*/
	registre[nr][0] = p1;
	registre[nr][1] = p2;
	nr++;


	temps_total += (p1>p2)?p1:p2;
}

void passa_persona( struct persona *p, int consum )
{
	p->consumit += consum;
	p->part = (p->part+1)%2;	
}

struct persona *mes_rapid( int part, struct persona *p )
{
	struct persona *tope = &P[n];

	while( p < tope ) {

		if ( p->part == part ) return p;

		p++;
	}

	return NULL;
}
struct persona *mes_lent( int part, struct persona *p )
{
	while( p >= P ) {
		if ( p->part == part ) return p;
		p--;
	}

	return NULL;
}

void passalos()
{
	struct persona	*r1, *r2, *l1, *l2;
	no=n; nd=0;

	temps_total=0;
	nr=0;

	r1=P;
	l1=&P[n-1];

	while( no > 0 ) {

		if ( no == 2 ) {

			/* Passen els dos que queden al destí */
			r1 = mes_rapid( 0, r1 );
			r2 = mes_rapid( 0, r1+1 );
			passa_persona( r1, r2->cost );  no--; nd++;
			passa_persona( r2, r2->cost );  no--; nd++;
			registra( r1->cost, r2->cost );
			break;

		} else if ( no == 3 ) {

			r1 = mes_rapid( 0, r1 );
			r2 = mes_rapid( 0, r1+1 );
			passa_persona( r1, r2->cost );  no--; nd++;
			passa_persona( r2, r2->cost );  no--; nd++;
			registra( r1->cost, r2->cost );

			passa_persona( r1, r1->cost );  no++; nd--;
			registra( r1->cost, -1 );

			l1 = mes_lent( 0, l1 );
			passa_persona( r1, l1->cost );  no--; nd++;
			passa_persona( l1, l1->cost );  no--; nd++;
			registra( r1->cost, l1->cost );

			break;

		} else {

			r1 = mes_rapid( 0, r1 );
			r2 = mes_rapid( 0, r1+1 );
			l1 = mes_lent( 0, l1 );
			l2 = mes_lent( 0, l1-1 );

			if ( (r2->cost+l1->cost+l2->cost)+(2*r1->cost)
				< ( r2->cost + r1->cost + l1->cost + r2->cost + r2->cost ) ) {

				passa_persona( r1, r2->cost );  no--; nd++;
				passa_persona( r2, r2->cost );  no--; nd++;
				registra( r1->cost, r2->cost );

				passa_persona( r1, r1->cost );  no++; nd--;
				registra( r1->cost, -1 );

				passa_persona( r1, l2->cost );  no--; nd++;
				passa_persona( l2, l2->cost );  no--; nd++;
				registra( r1->cost, l2->cost );

				passa_persona( r1, r1->cost );  no++; nd--;
				registra( r1->cost, -1 );

				passa_persona( r1, l1->cost );  no--; nd++;
				passa_persona( l1, l1->cost );  no--; nd++;
				registra( r1->cost, l1->cost );

				if ( no > 0 ) {
					passa_persona( r1, r1->cost );  no++; nd--;
					registra( r1->cost, -1 );
				}

				l1=l2-1;

			} else {

				/* Passes els dos més ràpids al destí */
				passa_persona( r1, r2->cost );  no--; nd++;
				passa_persona( r2, r2->cost );  no--; nd++;
				registra( r1->cost, r2->cost );
				if ( no <= 0 ) break;

				if ( no >= 2 ) {
/*
					cerca_el_parell_mes_eficient( &r1, &r2, 1 );
					assert( r1 != NULL );
					assert( r2 != NULL );
*/

					/* Torna el més ràpid */
					passa_persona( r1, r1->cost );  no++; nd--;
					registra( r1->cost, -1 );

					/* Passen els dos més lents al destí */
					passa_persona( l1, l1->cost );  no--; nd++;
					passa_persona( l2, l1->cost );  no--; nd++;
					registra( l2->cost, l1->cost );

					/* Torna el segon més ràpid */
					passa_persona( r2, r2->cost );  no++; nd--;
					registra( r2->cost, -1 );

					l1=l2-1;

				} else {

					l1 = mes_lent( 0, P+n-1 );
/*			
					cerca_el_mes_eficient_compatible_amb( l1, 1, &r1 );
					assert( r1 != NULL );
*/
					/* Torna el més ràpid a pel que queda */
					passa_persona( r1, r1->cost );  no++; nd--;
					registra( r1->cost, -1 );
					passa_persona( r1, l1->cost );  no--; nd++;
					passa_persona( l1, l1->cost );  no--; nd++;
					registra( r1->cost, l1->cost );
				}
			}
		}
	}
}

int main( int argc, char *argv[] )
{
	int		 num_casos, i;
	char	linia[128];

	scanf( "%d", &num_casos );
	fgets( linia, 120, stdin );

	while( --num_casos >= 0 ) {

		scanf( "%d", &n );

/*
		assert( 1 <= n  &&  n <= 1000 );
*/
		for( i=0; i < n; i++ ) {
			scanf( "%d", &P[i].cost );
/*
			assert( P[i].cost > 0 );
			assert( P[i].cost <= 100 );
*/
			P[i].consumit = 0;
			P[i].part = 0;
		}
		fgets( linia, 120, stdin );

		if ( n > 1 ) {

			qsort( P, n, sizeof( struct persona ), compara );

			passalos();

			printf( "%d\n", temps_total );
			for( i=0; i < nr; i++ ) {
				if ( registre[i][1] > 0 ) {
					printf( "%d %d\n", registre[i][0], registre[i][1] );
				} else {
					printf( "%d\n", registre[i][0] );
				}
			}

		} else if ( n == 1 ) {
			printf( "%d\n", P[0].cost );
			printf( "%d\n", P[0].cost );
		}

		if ( num_casos > 0 ) putchar( '\n' );

		while( fgets( linia, 120, stdin ) != NULL ) {
			i=strlen(linia)-1;
			while( i >= 0 && isspace(linia[i]) ) linia[i--] = '\0';
			if ( strlen( linia ) == 0 ) break;
		}
	}
	
	return 0;
}
