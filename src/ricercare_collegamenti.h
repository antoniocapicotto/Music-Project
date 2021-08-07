

#ifndef RICERCARE_COLLEGAMENTI_H_
#define RICERCARE_COLLEGAMENTI_H_

#include "MusicProject.h"

/* verifica dei collegamenti tra un brano e un album,artista,genere,playlist */

int VerificaCollegamentoBranoAlbum( int  IdBrano , database Database );
int VerificaCollegamentoBranoGenere( int IdBrano , database Database );
int VerificaCollegamentoBranoPlaylist( int IdBrano , database Database );
int VerificaCollegamentoBranoArtista( int IdBrano , database Database );


int VerificaCollegamentoAlbumBrani( int IdAlbum , database Database );
int VerificaCollegamentoArtistaBrani( int IdArtista , database Database );
int VerificaCollegamentoPlaylistBrani( int IdPlaylist , database Database );
int VerificaCollegamentoGenereBrani( int IdGenere , database Database );


#endif /* RICERCARE_COLLEGAMENTI_H_ */
