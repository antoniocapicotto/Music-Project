
//Libreria
#include "./../include/MusicProject.h"

void VisualizzaBranoArtista(database Database) {

	int i = 0;

	printf("\n\n\n\n\n\t  COLLEGAMENTI BRANOARTISTA  \n\n");

	i = 0;
	while (Database.BranoArtista[i].idBrano != SENTINELLA) {

		printf("\n\n\t\t [BRANO] %s <--->  %s [ARTISTA] \n",
				Database.Brano[Database.BranoArtista[i].idBrano].titolo,
				Database.Artista[Database.BranoArtista[i].idArtista].nome);

		i++;
	}

	return;

}

void VisualizzaBranoAlbum(database Database) {

	int i = 0;

	printf(
			"\n\n\n\n\n\t ********************* COLLEGAMENTI BRANOALBUM ************************* \n\n");

	i = 0;
	while (Database.BranoAlbum[i].idBrano != SENTINELLA) {

		printf("\n\n\t\t [BRANO] %s <--->  %s [ALBUM] \n",
				Database.Brano[Database.BranoAlbum[i].idBrano].titolo,
				Database.Album[Database.BranoAlbum[i].idAlbum].titolo);

		i++;

	}

	printf(
			"\n\n\t\t **************************************************************************** \n\n");

	return;

}

void VisualizzaBranoGenere(database Database) {

	int i = 0;

	printf(
			"\n\n\n\n\n\t ****************************** COLLEGAMENTI BRANOGENERE ****************************** \n\n");

	i = 0;
	while (Database.BranoGenere[i].idBrano != SENTINELLA) {

		printf("\n\n\t\t [BRANO] %s <--->  %s [GENERE] \n",
				Database.Brano[Database.BranoGenere[i].idBrano].titolo,
				Database.Genere[Database.BranoGenere[i].idGenere].nome);

		i++;
	}

	printf(
			"\n\n\t\t **************************************************************************** \n\n");

	return;

}

void VisualizzaPlaylistBrano(database Database) {

	int i = 0;

	printf("\n\n\n\n\n\t COLLEGAMENTI PLAYLISTBRANO \n\n");

	i = 0;
	while (Database.PlaylistBrano[i].idBrano != SENTINELLA) {

		printf("\n\n\t\t [BRANO] %s <--->  %s [PLAYLIST] \n",
				Database.Brano[Database.PlaylistBrano[i].idBrano].titolo,
				Database.Playlist[Database.PlaylistBrano[i].idPlaylist].nome);

		i++;
	}

	return;
}

void StampareInfoCollegamentiBrano(database Database, int IdBrano) {

	StamapareInfoBranoAlbum(Database, IdBrano);
	StampareInfoBranoGenere(Database, IdBrano);
	StampareInfoBranoArtista(Database, IdBrano);
	StampareInfoBranoPlaylist(Database, IdBrano);

	return;
}

void StamapareInfoBranoAlbum(database Database, int IdBrano) {

	int i = 0;

	if (VerificaCollegamentoBranoAlbum(IdBrano, Database) == VERO) {

		/* ricerca della posizione del collegamento brano - album presente */

		i = 0;
		while ((Database.BranoAlbum[i].idBrano != SENTINELLA)
				&& (Database.BranoAlbum[i].idBrano != IdBrano)) {

			i++;
		}

		StampareInfoAlbum(Database, Database.BranoAlbum[i].idAlbum);

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return;

}

void StampareInfoBranoGenere(database Database, int IdBrano) {

	int i = 0;

	if (VerificaCollegamentoBranoGenere(IdBrano, Database) == VERO) {

		/* ricerca della posizione del collegamento brano - genere presente */

		i = 0;
		while ((Database.BranoGenere[i].idBrano != SENTINELLA)
				&& (Database.BranoGenere[i].idBrano != IdBrano)) {
			i++;
		}

		StampareInfoGenere(Database, Database.BranoGenere[i].idGenere);

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return;

}

void StampareInfoBranoArtista(database Database, int IdBrano) {

	int i = 0;

	if (VerificaCollegamentoBranoArtista(IdBrano, Database) == VERO) {

		/* ricerca della posizione del collegamento brano - genere presente */
		i = 0;
		while ((Database.BranoArtista[i].idBrano != SENTINELLA)
				&& (Database.BranoArtista[i].idBrano != IdBrano)) {
			i++;
		}

		StampareInfoArtista(Database, Database.BranoArtista[i].idArtista);

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return;

}

void StampareInfoBranoPlaylist(database Database, int IdBrano) {

	int i = 0;

	if (VerificaCollegamentoBranoPlaylist(IdBrano, Database) == VERO) {

		/* ricerca della posizione del collegamento brano - playlist presente */

		i = 0;
		while ((Database.PlaylistBrano[i].idBrano != SENTINELLA)
				&& (Database.PlaylistBrano[i].idBrano != IdBrano)) {
			i++;
		}

		StampareInfoPlaylist(Database, Database.PlaylistBrano[i].idPlaylist);

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return;

}

void StampareInfoCollegamentiAlbum(database Database, int IdAlbum) {

	int i = 0;

	i = 0;
	while (Database.BranoAlbum[i].idBrano != SENTINELLA) {

		if (Database.BranoAlbum[i].idAlbum == IdAlbum) {

			/* stampa del brano */

			StampareInfoBrano(Database, Database.BranoAlbum[i].idBrano);

		}

		i++;

	}

	return;

}

/* stampa di tutti i collegamenti artista - brani */

void StampareInfoCollegamentiArtista(database Database, int IdArtista) {

	int i = 0;

	i = 0;
	while (Database.BranoArtista[i].idBrano != SENTINELLA) {

		if (Database.BranoArtista[i].idArtista == IdArtista) {

			/* stampa del brano */

			StampareInfoBrano(Database, Database.BranoArtista[i].idBrano);

		}

		i++;

	}

	return;

}

/* stampa di tutti i collegamenti genere - brani */

void StampareInfoCollegamentiGenere(database Database, int IdGenere) {

	int i = 0;

	i = 0;
	while (Database.BranoGenere[i].idBrano != SENTINELLA) {

		if (Database.BranoGenere[i].idGenere == IdGenere) {

			/* stampa del brano */

			StampareInfoBrano(Database, Database.BranoGenere[i].idBrano);

		}

		i++;

	}

	return;

}

// stampa di tutti i collegamenti playlist - brani

void StampareInfoCollegamentiPlaylist(database Database, int IdPlaylist) {

	int i = 0;

	i = 0;
	while (Database.PlaylistBrano[i].idBrano != SENTINELLA) {

		if (Database.PlaylistBrano[i].idPlaylist == IdPlaylist) {

			/* stampa del brano */

			StampareInfoBrano(Database, Database.PlaylistBrano[i].idBrano);

		}

		i++;

	}

	return;

}
