
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cassert>

using namespace std;

string erdos_autor="Erdos, P.";

class autor
{
private:
	string			nom;
	int				num;
	vector<int>		pubs;

public:
	autor( string & nom )
	{
		this->nom = nom;
		this->num = -1;
	}
	~autor()
	{
	}

	void add_pub( int p )
	{
		pubs.push_back( p );
	}

	int pub( int i ) { return pubs[i]; }

	string & get_nom() { return nom; }
	int get_num() { return num; }

	vector<int> & get_pubs() { return pubs; }

	bool posa_num( int num )
	{
		if ( this->num < 0 || num < this->num ) {
			this->num = num;
//			cout << "Asigne num a " << this->nom << " " << num << "/" << this->num << endl;
			return true;
		}
		return false;
	}
};

class dicc_nodo;

class dicc_arco
{
public :
	dicc_nodo	*nodo;
	char		ch;

	dicc_arco( dicc_nodo *n, char c )
	{
		nodo = n;
		ch = c;
	}
	~dicc_arco()
	{
		// if ( nodo != NULL ) delete nodo;
	}
};

class dicc_nodo
{
public :
	vector<dicc_arco *>	arcos;
	autor				*a;

	dicc_nodo()
	{
		a=NULL;
	}
	dicc_nodo( autor *a )
	{
		this->a = a;
	}
	~dicc_nodo()
	{
		if ( a != NULL ) delete a;
	}

	void destrueix_node()
	{
		for( unsigned int i=0; i < arcos.size(); i++ ) {
			arcos[i]->nodo->destrueix_node();
			delete arcos[i]->nodo;
			delete arcos[i];
		}
	}

	dicc_arco * cerca_arco( char ch )
	{
		for( unsigned int i=0; i < arcos.size(); i++ ) {
			if ( ch == arcos[i]->ch )
				return arcos[i];
		}

		return NULL;
	}

};


class autors
{
public :
	dicc_nodo			*arbre;
	unsigned int		n;

	autors()
	{
		arbre = NULL;
	}
	~autors()
	{
		if ( arbre != NULL ) {
			arbre->destrueix_node();
			delete arbre;
		}
	}
	void inicialitza()
	{
		if ( arbre != NULL ) {
			arbre->destrueix_node();
			delete arbre;
		}
		arbre=new dicc_nodo();
	}

	autor *cerca_autor( string & nom )
	{
		dicc_nodo		*nodo=arbre;
		unsigned int	i=0;

		while( i < nom.length() ) {
			dicc_arco *arc = nodo->cerca_arco( nom[i] );
			if ( arc == NULL ) return NULL;
			nodo = arc->nodo;
			i++;
		}
		if ( nodo != NULL && nodo->a != NULL )
			return nodo->a;
		else
			return NULL;
	}
	autor *afegeix_autor( string & nom, int pub )
	{
		dicc_nodo		*nodo=arbre;
		unsigned int	i=0;

		while( i < nom.length() ) {
			dicc_arco *arc = nodo->cerca_arco( nom[i] );
			if ( arc == NULL ) {
				arc = new dicc_arco( new dicc_nodo(), nom[i] );
				nodo->arcos.push_back( arc );
			}
			nodo = arc->nodo;
			i++;
		}
		assert( nodo != NULL );
		if ( nodo->a == NULL ) {
			nodo->a = new autor( nom );
		}

		if ( pub >= 0 ) nodo->a->add_pub(pub);

		return nodo->a;
	}
	autor *afegeix_autor( char nom[] )
	{
		string str = nom;
		return afegeix_autor( str, -1 );
	}

	void mostra()
	{
		mostra( arbre );
	}
	void mostra( dicc_nodo *nodo )
	{
		if ( nodo->a != NULL )
			cout << "A: " << nodo->a->get_nom() << endl;

		for( unsigned int i=0; i < nodo->arcos.size(); i++ )
			mostra( nodo->arcos[i]->nodo );
	}
};

class publicacio
{
	public :
		vector<autor *>		p_autors;
		string				titol;
		unsigned int		n;

	publicacio()
	{
		n=0;
	}
	void inicialitza()
	{
		n=0;
	}
	void afegeix_autor( autor * a )
	{
		if ( n < p_autors.size() ) {
			p_autors[n] = a;
		} else {
			p_autors.push_back( a );
		}
		n++;
	}
	unsigned int tamany() { return n; }
};

class publicacions
{
	private :
		enum estats { AUTOR, TITOL };

	public :
		vector<publicacio *>	llista;
		unsigned int			n;

		publicacions()
		{
			n=0;
		}
		~publicacions()
		{
			for( unsigned int i=0; i < n; i++ ) delete llista[i];
		}
		void inicialitza()
		{
			n=0;
		}
		void processa_publicacio( autors & general )
		{
			if ( n < llista.size() ) {
				llista[n]->inicialitza();
			} else {
				llista.push_back( new publicacio() );
			}

			int comes=0;

			string	str="";

			estats estat=AUTOR;

			char ch = cin.get();
			while( !cin.eof() && ch != '\n' ) {

				switch( estat ) {
					case AUTOR :
						switch( ch ) {
							case ':' : estat=TITOL;
							case ',' : if ( comes == 1 ) {
										   comes = 0;
										   autor *a=general.afegeix_autor( str, n );
										   llista[n]->afegeix_autor( a );
										   str="";
									   } else {
										   str += ch;
										   comes++;
									   }
									   break;

							case ' ' : if ( str.length() > 0 )
										   str += ch;
									   break;
							
							default : str += ch;
									  break;
						}
						break;

					case TITOL :
						switch( ch ) {
							case ' ' : if ( str.length() > 0 )
										   str += ch;
									   break;

							default : str += ch;
									  break;
						}
				}

				ch = cin.get();
			}
			llista[n]->titol = str;

			n++;
		}

		void mostra( autors & general )
		{
			for( unsigned int i=0; i < n; i++ ) {
				int A=llista[i]->tamany();
				for( int a=0; a < A; a++ ) {
					cout << llista[i]->p_autors[a]->get_nom();
					cout << ((a+1==A) ? ": " : ", ");
				}
				cout << llista[i]->titol << endl;
			}
		}

		void asigna_nums( autors & general )
		{
			autor *a = general.cerca_autor( erdos_autor );
			a->posa_num( 0 );

			list<autor *>	llista_autors, llista_aux;

			llista_autors.push_back( a );

			while( llista_autors.size() > 0 ) {
				while( llista_autors.size() > 0 ) {

					a = llista_autors.front();
					llista_autors.pop_front();

					vector<int>	& lp = a->get_pubs();
					int num_act = a->get_num();

					for( vector<int>::iterator p=lp.begin(); p < lp.end(); p++ ) {
						int i=*p;

//cout << endl << i << " " << llista[i]->titol << endl;
						for( unsigned int k=0; k < llista[i]->tamany(); k++ ) {

							autor *a2 = llista[i]->p_autors[k];
							if ( a2->posa_num( num_act+1 ) )
								llista_aux.push_back( a2 );
						}
					}
				}
//				llista_aux.sort();
//				llista_aux.unique();
				while( llista_aux.size() > 0 ) {
					/*
					int a=llista_aux.front();
					bool trobat=false;
					for( list<int>::iterator l=llista_autors.begin(); l <= llista_autors.end(); l++ ) {
						if ( *l == a ) {
							trobat=true;
							break;
						}
					}
					if ( !trobat )
						*/
						llista_autors.push_back( llista_aux.front() );
					llista_aux.pop_front();
				}
			}
		}
};

int main( int argc, char *argv[] )
{
	int				num_escenaris=0, P, N;
	publicacions	t_publicacions;
	autors			t_autors;
	vector<autor *>	candidats;
	unsigned int	num_candidats;
	char			linia[1024];

	cin >> num_escenaris;
	cin.ignore( 1024, '\n' );

	for( int ns = 1; ns <= num_escenaris; ns++ ) {

		cin >> P >> N;
		cin.ignore( 1024, '\n' );

		t_publicacions.inicialitza();
		t_autors.inicialitza();
		num_candidats=0;

		for( int p=0; p < P; p++ ) {
			t_publicacions.processa_publicacio( t_autors );
		}
		for( int n=0; n < N; n++ ) {
			cin.getline( linia, 1020 );
			if ( num_candidats < candidats.size() ) {
				candidats[num_candidats] = t_autors.afegeix_autor( linia );
			} else {
				candidats.push_back( t_autors.afegeix_autor( linia ) );
			}
			num_candidats++;
		}

//		t_publicacions.mostra( t_autors );
//		t_autors.mostra();
		t_publicacions.asigna_nums( t_autors );
		cout << "Scenario " << ns << endl;
		for( int n=0; n < N; n++ ) {
			cout << candidats[n]->get_nom() << " ";
			int num = candidats[n]->get_num();
			if ( num >= 0 )
				cout << num << endl;
			else
				cout << "infinity" << endl;
		}
	}

	return 0;
}
