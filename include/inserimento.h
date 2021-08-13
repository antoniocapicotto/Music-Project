#ifndef INSERIMENTO_H_INCLUDED
#define INSERIMENTO_H_INCLUDED

#include "MusicProject.h"

/* =============================== BRANO =================== */

database InserireBrano(database Database);
database InserireDatiBrano(database Database, Brano NuovoBrano);
int AssegnareIdBrano(database Database, Brano NuovoBrano);

/* ================================= ALBUM ====================== */

database InserireAlbum(database Database);
database InserireDatiAlbum(database Database, Album NuovoAlbum);
int AssegnareIdAlbum(database Database, Album NuovoAlbum);

/* ==================================== GENERE =================== */

database InserireGenere(database Database);
database InserireDatiGenere(database Database, Genere NuovoGenere);
int AssegnareIdGenere(database Database, Genere NuovoGenere);

/* ================================= PLAYLIST ===================  */

database InserirePlaylist(database Database);
database InserireDatiPlaylist(database Database, Playlist NuovaPlaylist);
int AssegnareIdPlaylist(database Database, Playlist NuovaPlaylist);

/* ================================= ARTISTA ===================== */

database InserireArtista(database Database);
database InserireDatiArtista(database Database, Artista NuovoArtista);
int AssegnareIdArtista(database Database, Artista NuovoArtista);

/* ================================ UTENTE ============================  */

database InserireUtente(database Database);
database InserireDatiUtente(database Database, Utente NuovoUtente);
void LeggerePassword(char password[]);
int AssegnareIdUtente(database Database, Utente NuovoUtente);

#endif // INSERIMENTO_H_INCLUDED
