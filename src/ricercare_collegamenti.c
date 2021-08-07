
//Libreria
#include "MusicProject.h"


// Funzione che verifica che esistano collegamenti tra brano e album da cancellare

int VerificaCollegamentoBranoAlbum( int  IdBrano , database Database ) {

    int trovato = FALSO;
    int i = 0;

    i = 0;
    while ( ( Database.BranoAlbum[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

        if ( Database.BranoAlbum[ i ].idBrano == IdBrano ) {

            trovato = VERO;
        }

    i = i + 1;

    }

    return trovato;

}



// Funzione che verifica che ci sia un collegamento tra brano e genere da cancellare

 int VerificaCollegamentoBranoGenere( int IdBrano , database Database ) {

    int trovato = FALSO;
    int i = 0;

    i = 0;
    while( ( Database.BranoGenere[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

        if( Database.BranoGenere[ i ].idBrano == IdBrano ) {

            trovato = VERO;
        }

    i = i + 1;

    }


    return trovato;

  }


 // Funzione che verifica che ci sia un collegamento tra brano e playlist da cancellare

 int VerificaCollegamentoBranoPlaylist( int IdBrano , database Database ) {

     int trovato = FALSO;

     int i = 0;

     i = 0;
     while( ( Database.PlaylistBrano[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

         if( Database.PlaylistBrano[ i ].idBrano == IdBrano ) {

             trovato = VERO;
         }

     i = i + 1;

     }


     return trovato;

 }



 // Funzione che verifica che ci sia un collegamento tra brano e artista da cancellare

 int VerificaCollegamentoBranoArtista( int  IdBrano ,database Database ) {

     int trovato = 0;

     int i = 0;

     i = 0;
     while ( ( Database.BranoArtista[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

         if ( Database.BranoArtista[ i ].idBrano == IdBrano ) {

             trovato = VERO;
         }

     i = i + 1;

     }

     return trovato;

 }


 // Funzione che verifica che ci sia un collegamento tra album e più brani da cancellare

 int VerificaCollegamentoAlbumBrani( int IdAlbum , database Database ) {

     int trovato = FALSO;
     int i = 0;

     i = 0;
     while ( ( Database.BranoAlbum[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

         if ( Database.BranoAlbum[ i ].idAlbum == IdAlbum ) {

             trovato = VERO;
         }

     i = i + 1;

     }


     return trovato;

 }






 // Funzione che verifica che ci siano collegamenti tra artista e brano da cancellare

 int VerificaCollegamentoArtistaBrani( int IdArtista , database Database ) {

     int trovato = FALSO;
     int i = 0;

     i = 0;
     while ( ( Database.BranoArtista[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

         if ( Database.BranoArtista[ i ].idArtista == IdArtista ) {

             trovato = VERO;
         }

     i = i + 1;

     }


     return trovato;

 }


 // Funzione che verifica che ci siano collegamenti tra playlist e brano da cancellare

 int VerificaCollegamentoPlaylistBrani( int IdPlaylist , database Database ) {

     int trovato = FALSO;
     int i = 0;

     i = 0;
     while ( ( Database.PlaylistBrano[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

         if ( Database.PlaylistBrano[ i ].idPlaylist == IdPlaylist ) {

             trovato = VERO;
         }

     i = i + 1;

     }


     return trovato;

 }


 // Funzione che verifica che ci siano collegamenti tra genere e brano da cancellare

 int VerificaCollegamentoGenereBrani( int IdGenere , database Database ) {

     int trovato = FALSO;
     int i = 0;

     i = 0;
     while ( ( Database.BranoGenere[ i ].idBrano != SENTINELLA ) && ( trovato != VERO ) ) {

         if ( Database.BranoGenere[ i ].idGenere == IdGenere ) {

             trovato = VERO;
         }

     i = i + 1;

     }


     return trovato;

 }

