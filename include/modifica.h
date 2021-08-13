#ifndef MODIFICA_H_INCLUDED
#define MODIFICA_H_INCLUDED

#include "MusicProject.h"

void ModificaStringa(char stringa[]);

/* ========================  BRANO ==================================== */

database ModificareBrano(database Database);
database ModificaDatiBrano(Brano BranoModificato, database Database,
		int IdBrano);

/* =========================  ALBUM =================================== */

database ModificareAlbum(database Database);
database ModificaDatiAlbum(Album AlbumModificato, database Database,
		int IdAlbum);

/* ========================== GENERE ================================== */

database ModificareGenere(database Database);
database ModificaDatiGenere(Genere GenereModificato, database Database,
		int IdGenere);

/* ========================= PLAYLIST =================================== */

database ModificarePlaylist(database Database);
database ModificaDatiPlaylist(Playlist PlaylistModificato, database Database,
		int IdPlaylist);

/* ======================== ARTISTA =================================== */

database ModificareArtista(database Database);
database ModificaDatiArtista(Artista ArtistaModificato, database Database,
		int IdArtista);

/* ========================= UTENTE ================================== */

database ModificareUtente(database Database);
database ModificaDatiUtente(Utente UtenteModificato, database Database,
		int IdUtente);

#endif // MODIFICA_H_INCLUDED
