
#ifndef CANCELLARE_COLLEGAMENTI_H_
#define CANCELLARE_COLLEGAMENTI_H_

#include "MusicProject.h"

database CancellareCollegamentiBrano( int IdBrano , database Database );

/* rimuovere collegamento brano-album */
database CancellaCollegamentoBranoAlbum( int IdBrano , database Database );

/*rimuovere collegamento brano - genere */
database CancellaCollegamentoBranoGenere(int IdBrano , database Database );

/* rimuovere collegamento playlist - brano */
database CancellaCollegamentoPlaylistBrano( int IdBrano ,database Database );

/*rimuovere collegamento brano - artista */
database CancellaCollegamentoBranoArtista( int  IdBrano , database Database );

/* cancellare tutti i collegamenti album - brani */
database CancellaCollegamentiAlbumBrani( int IdAlbum , database Database );

/* cancellare tutti i collegamenti artista - brani */
database CancellaCollegamentiArtistaBrani( int IdArtista , database Database );

/* cancellare tutti i collgamenti playlist - brani */
database CancellaCollegamentiPlaylistBrani( int IdPlaylist , database Database );

/* cancellare tutti i collegamenti genere - brani */
database CancellaCollegamentiGenereBrani( int IdGenere , database Database );



#endif /* CANCELLARE_COLLEGAMENTI_H_ */
