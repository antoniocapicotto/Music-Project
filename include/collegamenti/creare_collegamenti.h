#ifndef CREARE_COLLEGAMENTI_H_
#define CREARE_COLLEGAMENTI_H_

#include "./../MusicProject.h"

// collegamenti tra brano-album , brano-genere , playlist-brano, brano-artista

database CreareCollegamentiBrano(Brano NuovoBrano, database Database);

database CreaCollegamentoBranoAlbum(Brano NuovoBrano, database Database);
database AssociaBranoAlbum(database Database, int IdBrano, int IdAlbum);

database CreaCollegamentoBranoGenere(Brano NuovoBrano, database Database);
database AssociaBranoGenere(database Database, int IdBrano, int IdGenere);

database CreaAssociazioneBranoArtista(Brano NuovoBrano, database Database);
database AssociaBranoArtista(database Database, int IdBrano, int IdArtista);

database CreaCollegamentoPlaylistBrano(Brano NuovoBrano, database Database);
database AssociaPlaylistBrano(database Database, int IdBrano, int IdPlaylist);

/* creazione di collegamenti album-brani*/

database CreareCollegamentiAlbumBrani(database Database, Album NuovoAlbum);
database CreareCollegamentiGenereBrani(database Database, Genere NuovoGenere);
database CreareCollegamentiPlaylistBrani(database Database,
										 Playlist NuovaPlaylist);
database CreareCollegamentiArtistaBrani(database Database, Artista NuovoArtista);

#endif /* CREARE_COLLEGAMENTI_H_ */
