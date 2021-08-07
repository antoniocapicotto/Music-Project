
//Libreria
#include "MusicProject.h"

database LoginUtente( database* Database ) {


    char scelta[20];


    *Database = VerificareUtente( Database );

    while ( Database->UltimoEsito != 0 ) {

            printf( "\n\n\n\t\t ++++++++++++++++++++++++++++ CREDENZIALI INCORRETTE! ++++++++++++++++++++++++ \n\n\t\t [1] REINSERIRE CREDENZIALI \n\n\t\t [2] CREARE NUOVO UTENTE \n\n " );

            printf( "\n\n\t\t\t SCELTA: " );
            scanf( " %[^\n]" , scelta );

            if ( strcmp( scelta , "1" ) == 0 ) {

                    *Database = VerificareUtente( Database );

            } else if ( strcmp( scelta , "2" ) == 0 ) {

                /* crea un nuovo utente */

                *Database = InserireUtente( *Database );
                *Database = VerificareUtente( Database );

            }


    }


    return *Database;
}


database VerificareUtente( database* Database ) {

    char username[60];
    char password[60];
    int i = 0;

    printf( "\n\n\t\t ########################## INSERISCI CREDENZIALI ########################## \n\n" );

    do {

    	printf( "\n\n\t\t USERNAME( Min 6 caratteri ): " );
    	scanf( " %[^\n]" , username );
    	ModificaStringa( username );

    } while( ( strlen( username ) >= 60 ) || ( strlen( username ) < 6 ) );


    do {

    	LeggerePassword( password );

    } while ( ( strlen( password ) >= 60 ) || ( strlen( password ) < 6 )   );


    Database->UltimoEsito = 1;

    i = 0;
    while ( ( Database->Utente[ i ].idUtente != SENTINELLA ) && ( Database->UltimoEsito != 0 ) ) {

        if ( ( strcmp( Database->Utente[ i ].nomeUtente , username ) == 0 ) && ( strcmp( Database->Utente[ i ].password , password ) == 0 ) ) {

            Database->UltimoEsito = 0;
            Database->utenteCorrente = i;
        }

        i++;
    }


    return *Database;


}

void RicercaPerAnagrafico( database Database ) {

    int id = 0;
    char titolo[30];
    int anno = 0;

    printf( "\n\n\n\n\n\t\t ########################### RICERCA BRANO ########################### \n\n");

    do {

    printf("\n\t\t TITOLO: " );
    scanf( " %[^\n]" , titolo );
    ModificaStringa( titolo );

    } while( ( strlen( titolo ) >= 30 ) || ( strlen( titolo ) < 0 ) );

    do {

        printf( "\n\t\t ANNO: " );
        scanf( "%d" , &anno );

    } while( anno < 1900 );

    id = TrovaIdBrano( Database , titolo , anno );


    if ( id != SENTINELLA ) {

        StampareInfoBrano( Database , id );

        if( ( VerificaCollegamentoBranoAlbum( id , Database ) == 1 ) || ( VerificaCollegamentoBranoGenere( id , Database ) == 1 )  || ( VerificaCollegamentoBranoPlaylist( id , Database ) == 1 ) || (VerificaCollegamentoBranoArtista(id,Database) == 1 ) ){

        StampareInfoCollegamentiBrano( Database , id );

        }

    } else {

        printf( "\n\n\n\n\n\t\t +++++++++ BRANO NON PRESENTE ++++++++++ \n\n\n\n\n" );
    }


    return ;

}



int TrovaIdBrano( database DataBase , char titolo[] , int anno ) {

    int i = 0;
    int id = SENTINELLA;
    int trovato = FALSO;

    i = 0;
    while ( ( DataBase.Brano[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

        if (  ( strcmp( DataBase.Brano[ i ].titolo , titolo ) == 0 ) && ( DataBase.Brano[ i ].anno == anno )  ) {

           id = DataBase.Brano[i].idBrano;
           trovato = VERO;

        }

        i++;
    }

    return id;

}


void RicercaPerAlbum( database Database ) {

    int id = 0;
    char titolo[30];
    int anno = 0;


    do {

    printf( "\n\n\n\n\n\t\t  ########################## RICERCA ALBUM ########################## \n\n" );

    printf("\n\n\n\t\t TITOLO: ");
    scanf( " %[^\n]" , titolo );
    ModificaStringa( titolo );

    } while( ( strlen( titolo ) >= 30 ) || ( strlen( titolo ) < 0 ) );

    do {

        printf( "\n\t\t ANNO: " );
        scanf( "%d" , &anno );

    } while( anno < 1900 );

    id = TrovaIdAlbum( Database , titolo , anno );

    if ( id != SENTINELLA ) {

        StampareInfoAlbum( Database , id );

        if ( VerificaCollegamentoAlbumBrani( id , Database ) == VERO ){

        printf( "\n\n\t -- I BRANI DI QUESTO ALBUM SONO -- \n\n" );

        StampareInfoCollegamentiAlbum( Database , id );

        }

    } else {

        printf( "\n\n\n\n\n\n\t\t\t ++++++++++++++++++++ ALBUM NON PRESENTE ++++++++++++++++++++ \n\n\n\n\n" );
    }


    return ;

}

int TrovaIdAlbum( database Database , char titolo[] ,  int anno ) {


    int i = 0;
    int id = SENTINELLA;
    int trovato = FALSO;


    i = 0;
    while ( ( Database.Album[ i ].idAlbum != SENTINELLA ) && ( trovato != VERO ) ) {

        if (  ( strcmp( Database.Album[ i ].titolo , titolo ) == 0 ) && ( Database.Album[ i ].anno == anno )  ) {

           id = Database.Album[ i ].idAlbum;
           trovato = VERO;

        }

        i++;
    }


    return id;

}


void RicercaPerArtista( database Database ) {

    int id = 0;
    char nome[30];
    char cognome[30];


    printf("\n\n\n\n\t\t ########################### RICERCA ARTISTA ########################### \n\n ");

    do {

    	printf( "\n\n\n\t\t NOME: " );
    	scanf( " %[^\n]" , nome );
    	ModificaStringa( nome );

    } while( ( strlen( nome ) >= 30 ) || ( strlen( nome ) < 0 ) );

    do {

        printf( "\n\t\t COGNOME: " );
        scanf( " %[^\n]" , cognome );
        ModificaStringa( cognome );

    } while( ( strlen( cognome ) >= 30 ) || ( strlen( cognome ) < 0 ) );

    id = TrovaIdArtista( Database , nome , cognome );

    if ( id != SENTINELLA ) {

    	StampareInfoArtista( Database , id );

    	if ( VerificaCollegamentoArtistaBrani( id , Database ) == VERO ){

        printf( "\n\n\t\t -- I BRANI DI QUESTO ARTISTA SONO -- \n\n" );

        StampareInfoCollegamentiArtista( Database , id );

    	}

    } else {

        printf( " \n\n\n\n\n\t\t +++++++++++++++++++++++ ARTISTA NON PRESENTE +++++++++++++++++++++ \n\n\n\n\n" );
    }


    return ;

}

int TrovaIdArtista( database Database , char nome[] ,  char cognome[] ) {

    int i = 0;
    int id = SENTINELLA;
    int trovato = 0;

    i = 0;
    while ( ( Database.Artista[ i ].idArtista != SENTINELLA ) && ( trovato != VERO ) ) {

        if (  ( strcmp( Database.Artista[ i ].nome , nome ) == 0 ) && ( strcmp( Database.Artista[ i ].cognome , cognome ) == 0  ) ) {

           id = Database.Artista[ i ].idArtista;

           trovato = VERO;

        }

        i++;
    }

    return id;

}


void RicercaPerGenere( database Database ) {

    int id = 0;
    char nome[30];

    printf("\n\n\n\n\t\t ############################## RICERCA GENERE ############################## \n\n");

    do {

    	printf( "\n\n\t\t NOME: " );
    	scanf( " %[^\n]" , nome );
    	ModificaStringa( nome );

    } while( ( strlen( nome ) >= 30 ) || ( strlen( nome ) < 0 ) );

    id = TrovaIdGenere( Database , nome  );

    if ( id != SENTINELLA ) {

        StampareInfoGenere( Database , id );

        if ( VerificaCollegamentoGenereBrani( id , Database ) == 1 ){

        printf( "\n\n\t -- I BRANI DI QUESTO GENERE SONO -- \n\n" );

        StampareInfoCollegamentiGenere( Database , id );

        }

    } else {

        printf( " \n\n\n\n\n\t\t\t +++++++++++++++++++ GENERE NON PRESENTE ++++++++++++++++++++ \n\n\n\n\n" );
    }


    return ;

}

int TrovaIdGenere( database Database , char nome[] ) {


    int i = 0;
    int id = SENTINELLA;
    int trovato = FALSO;


    i = 0;
    while ( ( Database.Genere[ i ].idGenere != SENTINELLA ) && ( trovato != VERO ) ) {

        if ( strcmp( Database.Genere[ i ].nome , nome ) == FALSO  ) {

           id = Database.Genere[ i ].idGenere;

           trovato = VERO;

        }

        i++;
    }

    return id;

}

void RicercaPerPlaylist( database Database ) {

    int id = 0;
    char nome[30];
    int pubblica = FALSO;
    int esito = FALSO;

    printf("\n\n\n\n\t\t ########################### RICERCA PLAYLIST ########################### \n\n");

    //lettura del nome della playlist

    do {

    	printf( "\n\n\t\t NOME: " );
    	scanf( " %[^\n]" , nome );
    	ModificaStringa( nome );

    } while( ( strlen( nome ) >= 30 ) || ( strlen( nome ) < 0 ) );


    // lettura del campo pubblica

    	while ( esito == FALSO ) {

    	printf( "\n\n\t\t PUBBLICA( [1] SI - [0] NO ): " );
    	scanf( "%d" , &pubblica );

    	if( pubblica == 1 ){

    		esito = VERO;

    	} else if ( pubblica == 0 ) {

    		esito = VERO;

    	} else {

    		esito = FALSO;
    	}

    	}

    id = TrovaIdPlaylist( Database , nome , pubblica  );


    if ( id != SENTINELLA ) {

        StampareInfoPlaylist( Database , id );

        if( VerificaCollegamentoPlaylistBrani( id , Database ) == 1 ) {

        printf( "\n\n\t -- I BRANI DI QUESTA PLAYLIST SONO -- \n\n" );

        StampareInfoCollegamentiPlaylist( Database , id );

        }



    } else {

        printf( "\n\n\n\n\n\t\t\t ++++++++++++++++++++ PLAYLIST NON PRESENTE ++++++++++++++++++++ \n\n\n\n\n" );
    }


    return ;

}

int TrovaIdPlaylist( database Database , char nome[] , int pubblica ) {


    int i = 0;
    int id = SENTINELLA;
    int trovato = FALSO;



    i = 0;
    while( ( Database.Playlist[ i ].idPlaylist != SENTINELLA ) && ( trovato != VERO ) ) {

        if( ( strcmp( Database.Playlist[ i ].nome , nome ) == 0 ) && ( Database.Playlist[ i ].pubblica == pubblica )  ) {

           id = Database.Playlist[ i ].idPlaylist;

           trovato = VERO;

        }

        i++;
    }




    return id;

}

void RicercaPerUtente( database Database ) {

	char username[60];
	char password[60];
	int id = 0;

	printf("\n\n\n\n\t\t ########################### RICERCA UTENTE ########################### \n\n");

	//lettura del username

	do {

	    	printf( "\n\n\t\t NOME UTENTE( Min 6 caratteri ): " );
	    	scanf( "%s" , username );

	} while( ( strlen( username ) >= 60 ) || ( strlen( username ) < 6 ) );

	//lettura della password

	do {

	    	LeggerePassword( password );

	} while ( ( strlen( password ) >= 60 ) || ( strlen( password ) < 6 )   );

	id = TrovaIdUtente( Database , username , password );


	if ( id != SENTINELLA ) {

			printf("\n\n");

	        StampareInfoUtente( Database , id );

		} else {

	        printf( "\n\n\n\n\n\t\t ++++++++++++ UTENTE NON PRESENTE ++++++++++++ \n\n\n\n\n" );
	}

	return ;
}

int TrovaIdUtente( database Database, char username[] , char password[] ) {

	int id = SENTINELLA;
	int i = 0;
	int trovato = FALSO;

	i = 0;
	while ( ( Database.Utente[ i ].idUtente != SENTINELLA ) && ( trovato != VERO ) ) {

		if ( ( strcmp( Database.Utente[ i ].nomeUtente , username ) == 0 ) && ( strcmp( Database.Utente[i].password  ,password ) == 0 )  ){

			id = Database.Utente[i].idUtente;
			trovato = VERO;

		}

		i++;

	}


	return id;
}


