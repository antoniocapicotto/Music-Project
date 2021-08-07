#ifndef CANCELLAZIONE_H_INCLUDED
#define CANCELLAZIONE_H_INCLUDED

#include "MusicProject.h"


/* ========================== BRANO ======================================== */

database CancellareBrano( database Database );
database CancellaDatiBrano( database Database ,int IdBrano );
int VerificaIdBrano( database Database , int IdBrano );


/* ======================== ALBUM ================================ */

database CancellareAlbum( database Database );
database CancellaDatiAlbum( database Database ,int IdAlbum );
int VerificaIdAlbum( database Database , int IdAlbum );


/* ======================= ARTISTA ================================ */

database CancellareArtista( database Database );
database CancellaDatiArtista( database Database ,int IdArtista );
int VerificaIdArtista( database Database ,int IdArtista );


/* ============================== PLAYLIST ============================================== */

database CancellarePlaylist( database Database );
database CancellaDatiPlaylist( database Database , int IdPlaylist );
int VerificaIdPlaylist( database Database , int  IdPlaylist );


/* =============================== GENERE ================================================= */

database CancellareGenere( database Database );
database CancellaDatiGenere( database Database , int IdGenere );
int VerificaIdGenere( database Database , int IdGenere );


/* ====================================== UTENTE ============================================ */

database CancellareUtente( database Database );
database CancellaDatiUtente( database Database , int IdUtente );
int VerificaIdUtente( database Database , int IdUtente );



#endif // CANCELLAZIONE_H_INCLUDED
