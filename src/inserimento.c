
//Librerie

#include "MusicProject.h"


database InserireBrano( database Database ) {

	Brano NuovoBrano;
	char scelta[20];

    printf( "\n\n\n\n\t\t  ############################ NUOVO BRANO ########################### \n\n\n\n" );

    Database = InserireDatiBrano( Database , NuovoBrano );

    while( Database.UltimoEsito != 0 ) {

        printf( "\n\n\n\n\n\t\t ++++++++++++++++++++++ BRANO GIA' PRESENTE! ++++++++++++++++++++++ \n\n\t\t [1] NUOVO BRANO \n\n\t\t [0] ESCI \n\n" );
        printf("\n\n\t\t SCELTA: ");
        scanf( " %[^\n]" , scelta );

        if ( strcmp( scelta , "1" ) == 0 ) {

        	Database = InserireDatiBrano( Database , NuovoBrano );

        } else {

        	Database.UltimoEsito = 0;
        }
    }



    return Database;
}

database InserireDatiBrano( database Database , Brano NuovoBrano ) {


	/* lettura del campo titolo del NuovoBrano */

    do {

    printf( "\n\n\t\t TITOLO: " );
    scanf( " %[^\n]" , NuovoBrano.titolo );
    ModificaStringa( NuovoBrano.titolo );

    } while ( ( strlen( NuovoBrano.titolo ) >= 30 ) || ( strlen( NuovoBrano.titolo ) < 1 ) );


    /* lettura del campo anno di NuovoBrano */

    do {

        printf( "\n\t\t ANNO: " );
        scanf( "%d" , &NuovoBrano.anno );

    } while ( NuovoBrano.anno < 1900 );


    if ( TrovaIdBrano( Database , NuovoBrano.titolo , NuovoBrano.anno ) != SENTINELLA ) {

    	Database.UltimoEsito = 1;

    } else {


        do {

        printf( "\n\t\t DURATA(secondi): " );
        scanf( "%d",&NuovoBrano.durata );

        } while( NuovoBrano.durata <= 0 );

        do {

        printf( "\n\t\t ASCOLTI: " );
        scanf( "%d" , &NuovoBrano.ascolti );

        } while( NuovoBrano.ascolti < 0 );

        /* ricerca id del nuovo brano */
        NuovoBrano.idBrano = AssegnareIdBrano( Database , NuovoBrano );

        /* inserisco il nuovo brano che soddisfa i requisiti nel data base */
        Database.Brano[ NuovoBrano.idBrano ] = NuovoBrano;

        /* sposto in avanti di uno la sentinella */

        Database.Brano[ NuovoBrano.idBrano + 1 ].idBrano = SENTINELLA;
        Database = CreareCollegamentiBrano( NuovoBrano ,  Database );

        Database.UltimoEsito = 0;


    }



    return Database;

}

// Funzione che permette di assegnare l'id al brano

int AssegnareIdBrano( database Database , Brano NuovoBrano ) {

    int i = 0;

    i = 0;
    while( Database.Brano[ i ].idBrano != SENTINELLA ) {

        i++;
    }

    NuovoBrano.idBrano = i;

    return NuovoBrano.idBrano;

}

database InserireAlbum( database Database ) {

	Album NuovoAlbum;
	char scelta[20];

    printf( "\n\n\n\n\n\n\t\t\t  ########################  NUOVO ALBUM ######################## \n\n" );

    Database = InserireDatiAlbum( Database , NuovoAlbum );

    while ( Database.UltimoEsito != 0 ) {

        printf( "\n\n\n\n\n\t\t\t +++++++++++++++++ ALBUM GIA' PRESENTE! +++++++++++++++++ \n\n\t\t [1] NUOVO ALBUM \n\n\t\t [0] ESCI \n\n" );

        printf( "\n\n\t\t\t SCELTA: " );
        scanf( " %[^\n]" , scelta );

        if ( strcmp( scelta , "1" ) == 0 ) {

        	Database = InserireDatiAlbum( Database , NuovoAlbum );

        } else {

        	Database.UltimoEsito = 0;
        }
    }


    return Database;

}

database InserireDatiAlbum( database Database , Album NuovoAlbum ) {

    do {

    printf( "\n\t\t\t TITOLO: " );
    scanf( " %[^\n]" , NuovoAlbum.titolo );

    ModificaStringa( NuovoAlbum.titolo );

    } while( ( strlen( NuovoAlbum.titolo ) >= 30 ) || ( strlen( NuovoAlbum.titolo ) < 0 ) );


    do {

        printf( "\n\t\t\t ANNO: " );
        scanf( "%d" , &NuovoAlbum.anno );

    } while( NuovoAlbum.anno < 1900 );


    if ( TrovaIdAlbum( Database , NuovoAlbum.titolo , NuovoAlbum.anno ) != SENTINELLA ) {

    	Database.UltimoEsito = 1;

    } else {


        /* ricerca id del nuovo album */

        NuovoAlbum.idAlbum = AssegnareIdAlbum( Database , NuovoAlbum );

        Database.Album[ NuovoAlbum.idAlbum ] = NuovoAlbum;

        /* sposto di uno in avanti la sentinella */
        Database.Album[ NuovoAlbum.idAlbum + 1 ].idAlbum = SENTINELLA;
        Database = CreareCollegamentiAlbumBrani( Database , NuovoAlbum );

        Database.UltimoEsito = 0;


    }

    return Database;

}

int AssegnareIdAlbum( database DataBase , Album NuovoAlbum ) {

    int i = 0;

    i = 0;
    while( DataBase.Album[ i ].idAlbum != SENTINELLA ) {

        i++;
    }

    NuovoAlbum.idAlbum = i;

    return NuovoAlbum.idAlbum;

}

database InserireGenere( database Database ) {


	Genere NuovoGenere;
	char scelta[ 20 ];


    printf( "\n\n\n\n\t\t ################### NUOVO GENERE ################### \n\n" );


    Database = InserireDatiGenere( Database , NuovoGenere );

    while ( Database.UltimoEsito != 0 ) {

        printf( "\n\n\n\n\n\t\t ++++++++++++++++++ GENERE GIA' PRESENTE! ++++++++++++++++++ \n\n\t [1] INSERIRE UN NUOVO GENERE \n\n\t [0] ESCI \n\n" );

        printf( "\n\n\t\t SCELTA: " );

        scanf( " %[^\n]" , scelta );

        if ( strcmp( scelta , "1" ) == 0 ) {

        	Database = InserireDatiGenere( Database , NuovoGenere );

        } else {

        	Database.UltimoEsito = 0;
        }
    }



    return Database;
}


database InserireDatiGenere( database Database , Genere NuovoGenere ) {


    do {

    printf( "\n\n\t\t NOME: " );
    scanf( " %[^\n]" , NuovoGenere.nome );
    ModificaStringa( NuovoGenere.nome );

    } while ( ( strlen( NuovoGenere.nome ) >= 30 ) || ( strlen( NuovoGenere.nome ) < 0 ) );

    if ( TrovaIdGenere( Database , NuovoGenere.nome ) != SENTINELLA ) {

    	Database.UltimoEsito = 1;

    } else {

        /*ricerca id del nuovo genere*/
        NuovoGenere.idGenere = AssegnareIdGenere( Database , NuovoGenere );

        /* inserisco il NuovoGenere nel database */
        Database.Genere[ NuovoGenere.idGenere ] = NuovoGenere;

        /*sposto di uno in avanti la sentinella*/
        Database.Genere[ NuovoGenere.idGenere + 1 ].idGenere = SENTINELLA;

        /* creo dei collegamenti tra il NuovoGenere e i brani */
        Database = CreareCollegamentiGenereBrani( Database , NuovoGenere );

        Database.UltimoEsito = 0;


    }


    return Database;
}

 // Funzione che assegna un id al genere

int AssegnareIdGenere( database Database , Genere NuovoGenere ) {

    int i = 0;

    i = 0;
    while( Database.Genere[ i ].idGenere != SENTINELLA ) {

        i++;
    }

    NuovoGenere.idGenere = i;

    return NuovoGenere.idGenere;

}

database InserirePlaylist( database Database ) {


	Playlist NuovaPlaylist;
	char scelta[ 20 ];

    printf( "\n\n\n\n\t\t ########################### NUOVA PLAYLIST ########################### \n\n" );

    Database = InserireDatiPlaylist( Database , NuovaPlaylist );

    while ( Database.UltimoEsito != 0 ) {

        printf( "\n\n\n\n\n\t\t +++++++++++++++++++ PLAYLIST GIA' PRESENTE! +++++++++++++++++++ \n\n\t\t [1] NUOVA PLAYLIST \n\n\t\t [0] ESCI \n\n" );

        printf( "\n\n\t\t SCELTA: " );

        scanf( " %[^\n]" , scelta );

        if ( strcmp( scelta , "1" ) == 0 ) {

                Database = InserireDatiPlaylist( Database , NuovaPlaylist );

        } else {

            Database.UltimoEsito = 0;
        }
    }



    return Database;
}



 // Funzione che inserisce i dati delle playlist

database InserireDatiPlaylist( database DataBase , Playlist NuovaPlaylist ) {

	int esito = FALSO;

    do {

    printf( "\n\t\t NOME: " );
    scanf( " %[^\n]" , NuovaPlaylist.nome );
    ModificaStringa( NuovaPlaylist.nome );

    } while( ( strlen( NuovaPlaylist.nome ) >= 30 ) || ( strlen( NuovaPlaylist.nome ) < 0 ) );

    while ( esito != VERO ) {

    	printf( "\n\t\t PUBBLICA( [1] SI - [0] NO ) : " );
    	scanf( "%d" , &NuovaPlaylist.pubblica );

    	if ( (NuovaPlaylist.pubblica == 1) || (NuovaPlaylist.pubblica == 0) ){

    		esito = VERO;
    	}

    }

    if ( TrovaIdPlaylist( DataBase , NuovaPlaylist.nome , NuovaPlaylist.pubblica  ) != SENTINELLA ) {

        DataBase.UltimoEsito = 1;

    } else {

        /* scrittura di tutti i campi della nuova playlist */

        do {

        printf("\n\t\t DESCRIZIONE: ");


        scanf( " %[^\n]" , NuovaPlaylist.descrizione );
        ModificaStringa(NuovaPlaylist.descrizione);


        } while( ( strlen( NuovaPlaylist.descrizione ) >= 250 ) || ( strlen( NuovaPlaylist.descrizione ) < 0  )   );


        /* ricerca id della nuova playlist */

        NuovaPlaylist.idPlaylist = AssegnareIdPlaylist( DataBase , NuovaPlaylist );

        /* sposto di uno in avanti la sentinella */

        DataBase.Playlist[ NuovaPlaylist.idPlaylist ] = NuovaPlaylist;
        DataBase.Playlist[ NuovaPlaylist.idPlaylist + 1 ].idPlaylist = SENTINELLA;

        DataBase = CreareCollegamentiPlaylistBrani( DataBase , NuovaPlaylist );

        DataBase.UltimoEsito = 0;


    }


    return DataBase;
}

int AssegnareIdPlaylist( database Database , Playlist NuovaPlaylist ) {

    int i = 0;

    i = 0;
    while( Database.Playlist[ i ].idPlaylist != SENTINELLA ) {

        i++;
    }

    NuovaPlaylist.idPlaylist = i;

    return NuovaPlaylist.idPlaylist;

}

database InserireArtista( database Database ) {

	Artista NuovoArtista;
	char scelta[20];

    printf( "\n\n\n\n\t\t\t ######################## NUOVO ARTISTA ######################## \n\n" );


    Database = InserireDatiArtista( Database , NuovoArtista );

    while ( Database.UltimoEsito != 0 ) {

        printf( "\n\n\n\n\n\t\t\t ++++++++++++++++++ ARTISTA GIA' PRESENTE! ++++++++++++++++++ \n\n\t [1] NUOVO ARTISTA \n\n\t [0] ESCI \n\n" );

        printf( "\n\n\t\t SCELTA: " );

        scanf( " %[^\n]" , scelta );

        if ( strcmp( scelta , "1" ) == 0 ) {

                Database = InserireDatiArtista( Database , NuovoArtista );

        } else {

            Database.UltimoEsito = 0;
        }
    }

    return Database;
}

database InserireDatiArtista( database Database , Artista NuovoArtista ) {

     /* scrittura di tutti i campi della nuovo artista */

    do {

    	printf( "\n\t\t\t NOME: " );
    	scanf( " %[^\n]" , NuovoArtista.nome );
    	ModificaStringa( NuovoArtista.nome );

    } while ( ( strlen( NuovoArtista.nome ) >= 30 ) || ( strlen( NuovoArtista.nome ) < 0 ) );



    do {

        printf( "\n\t\t\t COGNOME: " );
        scanf( " %[^\n]" ,  NuovoArtista.cognome );
        ModificaStringa( NuovoArtista.cognome );

    } while ( ( strlen( NuovoArtista.cognome ) >= 30 ) || ( strlen( NuovoArtista.cognome ) < 0  )   );


    do {

            printf( "\n\t\t\t NOME D'ARTE: " );
            scanf( " %[^\n]" ,  NuovoArtista.nomeArte );
            ModificaStringa( NuovoArtista.nomeArte );

    } while ( ( strlen( NuovoArtista.nomeArte ) >= 30 ) || ( strlen( NuovoArtista.nomeArte ) < 0  ) );

    if ( TrovaIdArtista( Database , NuovoArtista.nome , NuovoArtista.cognome ) == 1 ) {

        Database.UltimoEsito = 1;

    } else {

        /* ricerca id del nuovo Artista */

        NuovoArtista.idArtista = AssegnareIdArtista( Database , NuovoArtista );

        /* sposto di uno in avanti la sentinella */

        Database.Artista[ NuovoArtista.idArtista ] = NuovoArtista;

        Database.Artista[ NuovoArtista.idArtista + 1 ].idArtista = SENTINELLA;

        Database = CreareCollegamentiArtistaBrani( Database , NuovoArtista );

        Database.UltimoEsito = 0;

    }

    return Database;
}

 // FUnzione che assegna una id ad un artista

int AssegnareIdArtista( database Database , Artista NuovoArtista ) {

    int i = 0;

    i = 0;
    while( Database.Artista[i].idArtista != SENTINELLA ) {

        i++;
    }

    NuovoArtista.idArtista = i;

    return NuovoArtista.idArtista;

}

database InserireUtente( database Database ) {

	Utente NuovoUtente;
	char scelta[20];


    printf( "\n\n\n\n\t\t ###########################  NUOVO UTENTE ########################### \n\n" );

    Database = InserireDatiUtente( Database , NuovoUtente );

    while( Database.UltimoEsito != 0 ) {

        printf( "\n\n\n\n\n\t\t ++++++++++++++++ UTENTE GIA' PRESENTE! +++++++++++++++++ \n\n\t\t [1] INSERIRE NUOVO UTENTE \n\n [0] ESCI \n\n" );

        printf( "\n\t\t SCELTA: " );
        scanf( " %[^\n]" , scelta );

        if ( strcmp( scelta , "1" ) == 0 ) {

                Database = InserireDatiUtente( Database , NuovoUtente );

        } else {

            Database.UltimoEsito = 0;
        }
    }



    return Database;
}



 // Funzione che permette di inserire i dati dell'utente

database InserireDatiUtente( database Database , Utente NuovoUtente ) {

    do {

    	printf("\n\t\t USERNAME( Min 6 caratteri ): ");
    	scanf( " %[^\n]" , NuovoUtente.nomeUtente );
    	ModificaStringa( NuovoUtente.nomeUtente );

    } while( ( strlen( NuovoUtente.nomeUtente ) >= 60 ) || ( strlen( NuovoUtente.nomeUtente ) < 6 ) );

    do {


        LeggerePassword( NuovoUtente.password );

    } while ( ( strlen( NuovoUtente.password ) >= 60 ) || ( strlen( NuovoUtente.password ) < 6 )   );


    if ( TrovaIdUtente(Database,NuovoUtente.nomeUtente , NuovoUtente.password ) != SENTINELLA ) {

        Database.UltimoEsito = 1;

    } else {

    	NuovoUtente.admin = 0;

        /* ricerca id del nuovo Utente */
        NuovoUtente.idUtente = AssegnareIdUtente( Database , NuovoUtente );

        /* inserisco il NuovoUtente nel Database*/
        Database.Utente[ NuovoUtente.idUtente ] = NuovoUtente;

        /* sposto di uno in avanti la sentinella */
        Database.Utente[ NuovoUtente.idUtente + 1 ].idUtente = SENTINELLA;

        Database.UltimoEsito = 0;


    }


    return Database;
}

// lettura della password con asterischi

void LeggerePassword( char password[] ) {


	  int ch;
	  char pword[BUFSIZ];
	  int i = 0;

	  printf("\n\n\t\t PASSWORD( Min 6 caratteri ): ");
	  fflush(stdout);

	  while ( (ch = getch() ) != EOF && (ch != '\n') && (ch != '\r') && (i < sizeof( pword ) - 1) ) {

	    if ( ( ch == '\b' ) && ( i > 0 ) ) {

	      printf("\b \b");
	      fflush(stdout);
	      i--;
	      pword[i] = '\0';

	    } else if ( isalnum( ch ) ) {

	      putchar('*');
	      pword[ i++ ] = (char)ch;
	    }

	  }

	  pword[ i ] = '\0';


	  strcpy( password , pword );



	return ;
}

int AssegnareIdUtente( database DataBase , Utente NuovoUtente ) {

    int i = 0;

    i = 0;
    while ( DataBase.Utente[ i ].idUtente != SENTINELLA ) {

        i++;
    }

    NuovoUtente.idUtente = i;

    return NuovoUtente.idUtente;

}
