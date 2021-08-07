
// Librerie

#include "MusicProject.h"


void logo(){

   printf("\n\n\n\n\n\n\n\n\n\n\n");

   printf("\t\t");
   printf("   _____               .__         __________                   __               __    " );
   printf("\n");

   printf("\t\t");
   printf("  /     \\  __ __  _____|__| ____   \\______   \\_______  ____    |__| ____   _____/  |_  " );
   printf("\n");

   printf("\t\t");
   printf(" /  \\ /  \\|  |  \\/  ___/  |/ ___\\   |     ___/\\_  __ \\/  _ \\   |  |/ __ \\_/ ___\\   __\\ " );
   printf("\n");

   printf("\t\t");
   printf("/    Y    \\  |  /\\___ \\|  \\  \\___   |    |     |  | \\(  <_> )  |  \\  ___/\\  \\___|  |   " );
   printf("\n");

   printf("\t\t");
   printf("\\____|__  /____//____  >__|\\___  >  |____|     |__|   \\____/\\__|  |\\___  >\\___  >__|   ");
   printf("\n");

   printf("\t\t");
   printf("        \\/           \\/        \\/                          \\______|    \\/     \\/       " );
   printf("\n");


	return ;
}

void VisualizzaBrani( database Database ) {

    int i = 0;

    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ********************************* BRANI ************************************ \n\n" );

    while( Database.Brano[i].idBrano != SENTINELLA ) {


        printf( "\n\n\t\t TITOLO: %s \n\t\t ANNO: %d \n\t\t DURATA: %d \n\t\t ASCOLTI: %d \n\t\t IDBRANO: %d \n" , Database.Brano[ i ].titolo , Database.Brano[ i ].anno, Database.Brano[ i ].durata , Database.Brano[ i ].ascolti , Database.Brano[ i ].idBrano );

        i++;
    }

    printf("\n\n\t\t **************************************************************************** \n\n" );

    return ;

}

void VisualizzaAlbum( database Database ) {

    int i = 0;

    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ********************************* ALBUM ************************************ \n\n" );

    i = 0;
    while( Database.Album[ i ].idAlbum != SENTINELLA ) {

        printf( "\n\n\t\t TITOLO: %s \n\t\t ANNO: %d \n\t\t ID: %d \n" , Database.Album[ i ].titolo , Database.Album[ i ].anno , Database.Album[ i ].idAlbum );

        i++;
    }

    printf("\n\n\t\t **************************************************************************** \n\n" );



    return ;

}

void VisualizzaArtisti( database Database ) {

    int i = 0;

    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ********************************* ARTSITI ************************************ \n\n" );

    i = 0;
    while( Database.Artista[ i ].idArtista != -1 ) {

        printf( "\n\n\t\t NOME: %s\n\t\t COGNOME: %s \n\t\t NOME D'ARTE: %s \n\t\t ID: %d \n" , Database.Artista[ i ].nome , Database.Artista[ i ].cognome , Database.Artista[ i ].nomeArte , Database.Artista[ i ].idArtista );

        i++;
    }

    printf("\n\n\t\t **************************************************************************** \n\n" );

    return ;

}

void VisualizzaPlaylist( database Database ) {

    int i = 0;
    char s[10];

    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ********************************* PLAYLIST ************************************ \n\n" );

    i = 0;
    while ( Database.Playlist[ i ].idPlaylist != SENTINELLA ) {

    	if ( Database.Playlist[ i ].pubblica == 1 ) {

    		strcpy( s , "SI" );

    	} else {

    		strcpy( s , "NO" );
    	}

        printf( "\n\n\t\t NOME: %s \n\t\t DESCRIZIONE: %s \n\t\t PUBBLICA: %s \n\t\t ID: %d \n" , Database.Playlist[ i ].nome , Database.Playlist[ i ].descrizione , s , Database.Playlist[ i ].idPlaylist );

        i++;

    }

    printf("\n\n\t\t ****************************************************************************** \n\n" );



    return ;

}

void VisualizzaUtenti( database Database ) {

    int i = 0;
    char s[10];

    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ********************************* UTENTI ************************************ \n\n" );

    i = 0;
    while( Database.Utente[ i ].idUtente != SENTINELLA ) {

    	if ( Database.Utente[ i ].admin == 1 ) {

    		strcpy( s , "SI" );

    	} else {

    		strcpy( s , "NO" );
    	}

        printf( "\n\n\t\t USERNAME: %s \n\t\t PASSWORD: %s \n\t\t ADMIN: %s \n\t\t ID: %d \n" , Database.Utente[ i ].nomeUtente   , Database.Utente[i].password ,s , Database.Utente[ i ].idUtente );

        i++;
    }

    printf("\n\n\t\t **************************************************************************** \n\n" );


    return ;

}

void VisualizzaGeneri( database Database ) {

    int i = 0;

    printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ********************************* GENERI ************************************ \n\n" );

    i = 0;
    while(Database.Genere[ i ].idGenere != SENTINELLA ) {

        printf("\n\n\t\t NOME: %s \n\t\t ID: %d \n" ,  Database.Genere[ i ].nome , Database.Genere[ i ].idGenere );
        i++;
    }

    printf( "\n\n\t\t **************************************************************************** \n\n" );

    return ;

}

void StampareInfoBrano( database Database , int IdBrano ) {

    printf( "\n\n\t\t ''''' BRANO ''''' \n" );

    printf( "\n\t\t TITOLO: %s" , Database.Brano[ IdBrano ].titolo );
    printf( "\n\t\t ANNO: %d" , Database.Brano[ IdBrano ].anno );
    printf( "\n\t\t DURATA: %d" , Database.Brano[ IdBrano ].durata );
    printf( "\n\t\t ASCOLTI: %d" , Database.Brano[ IdBrano ].ascolti );
    printf( "\n\t\t ID: %d" , Database.Brano[ IdBrano ].idBrano );


    return ;
}

void StampareInfoAlbum( database Database , int IdAlbum ) {

    printf( "\n\n\t\t ''''' ALBUM ''''' \n" );
    printf( "\n\t\t TITOLO: %s" , Database.Album[ IdAlbum ].titolo );
    printf( "\n\t\t ANNO: %d" , Database.Album[ IdAlbum ].anno );
    printf( "\n\t\t ID: %d" , Database.Album[ IdAlbum ].idAlbum );

    return ;

}


void StampareInfoGenere( database Database , int IdGenere ) {

    printf( "\n\n\t\t ''''' GENERE ''''' \n" );
    printf( "\n\t\t NOME: %s" , Database.Genere[ IdGenere ].nome );
    printf( "\n\t\t ID: %d" , Database.Genere[ IdGenere ].idGenere );

    return ;

}

void StampareInfoArtista( database Database , int IdArtista ) {

    printf( "\n\n\t\t ''''' ARTISTA ''''' \n" );
    printf( "\n\t\t NOME: %s" , Database.Artista[ IdArtista ].nome );
    printf( "\n\t\t COGNOME: %s" , Database.Artista[ IdArtista ].cognome );
    printf( " \n\t\t NOME ARTE: %s" , Database.Artista[ IdArtista ].nomeArte );
    printf( "\n\t\t ID: %d" , Database.Artista[ IdArtista ].idArtista );


    return ;

}

void StampareInfoPlaylist( database Database , int IdPlaylist ) {

    printf( "\n\n\t\t ''''' PLAYLIST ''''' \n" );
    printf( "\n\t\t NOME: %s" , Database.Playlist[ IdPlaylist ].nome );
    printf( "\n\t\t DESCRIZIONE: %s" , Database.Playlist[ IdPlaylist ].descrizione );

    if ( Database.Playlist[ IdPlaylist ].pubblica == 1 ) {

    	printf( "\n\t\t PUBBLICA: %s" , "SI" );

    } else {

    printf( "\n\t\t PUBBLICA: %s" , "NO" );

    }

    printf( "\n\t\t ID: %d" , Database.Playlist[ IdPlaylist ].idPlaylist );

    return ;

}

void StampareInfoUtente(database  Database ,int IdUtente ){


	printf( "\n\n\t\t ''''' UTENTE ''''' \n" );
	printf( "\n\t\t NOME UTENTE: %s" , Database.Utente[ IdUtente ].nomeUtente );
	printf( "\n\t\t PASSWORD: %s" , Database.Utente[ IdUtente ].password );

	if ( Database.Utente[ IdUtente ].admin == 1 ) {

		printf( "\n\t\t ADMIN: %s" , "SI" );

	} else {

		printf( "\n\t\t ADMIN: %s" , "NO" );

	}

	printf( "\n\t\t ID: %d" , Database.Utente[ IdUtente ].idUtente );

	return ;
}

