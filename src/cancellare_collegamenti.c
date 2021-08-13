//Libreria
#include "./../include/MusicProject.h"

// Funzione che permette di cancellare i collegamenti con il brano

database CancellareCollegamentiBrano(int IdBrano, database Database) {

	Database = CancellaCollegamentoBranoAlbum(IdBrano, Database);
	Database = CancellaCollegamentoBranoGenere(IdBrano, Database);
	Database = CancellaCollegamentoBranoArtista(IdBrano, Database);
	Database = CancellaCollegamentoPlaylistBrano(IdBrano, Database);

	return Database;
}

// Funzione che permette di cancellare i collegamenti tra brano e album

database CancellaCollegamentoBranoAlbum(int IdBrano, database Database) {

	int i = 0;

	if (VerificaCollegamentoBranoAlbum(IdBrano, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.BranoAlbum[i].idBrano != IdBrano)
				&& (Database.BranoAlbum[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento brano-genere */

		while (Database.BranoAlbum[i + 1].idBrano != SENTINELLA) {

			Database.BranoAlbum[i] = Database.BranoAlbum[i + 1];

			i = i + 1;

		}

		Database.BranoAlbum[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra brano e genere

database CancellaCollegamentoBranoGenere(int IdBrano, database Database) {

	int i = 0;

	if (VerificaCollegamentoBranoGenere(IdBrano, Database) == 1) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.BranoGenere[i].idBrano != IdBrano)
				&& (Database.BranoGenere[i].idBrano != SENTINELLA)) {

			i++;

		}

		/* cancellazione del collegamento brano - genere */

		while (Database.BranoGenere[i + 1].idBrano != SENTINELLA) {

			Database.BranoGenere[i] = Database.BranoGenere[i + 1];

			i = i + 1;

		}

		/* aggiornamento della posizione del valore sentinella */

		Database.BranoGenere[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra brano e playlist

database CancellaCollegamentoPlaylistBrano(int IdBrano, database Database) {

	int i = 0;

	if (VerificaCollegamentoBranoPlaylist(IdBrano, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.PlaylistBrano[i].idBrano != IdBrano)
				&& (Database.PlaylistBrano[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento playlist - brano */

		while (Database.PlaylistBrano[i + 1].idBrano != SENTINELLA) {

			Database.PlaylistBrano[i] = Database.PlaylistBrano[i + 1];

			i = i + 1;

		}

		Database.PlaylistBrano[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra brano e artista

database CancellaCollegamentoBranoArtista(int IdBrano, database Database) {

	int i = 0;

	if (VerificaCollegamentoBranoArtista(IdBrano, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.BranoArtista[i].idBrano != IdBrano)
				&& (Database.BranoArtista[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento brano - artista */

		while (Database.BranoArtista[i + 1].idBrano != SENTINELLA) {

			Database.BranoArtista[i] = Database.BranoArtista[i + 1];

			i = i + 1;

		}

		Database.BranoArtista[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	} else {

		Database.UltimoEsito = 1;
	}

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra un album con pi� brani

database CancellaCollegamentiAlbumBrani(int IdAlbum, database Database) {

	int i = 0;

	while (VerificaCollegamentoAlbumBrani(IdAlbum, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.BranoAlbum[i].idAlbum != IdAlbum)
				&& (Database.BranoAlbum[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento album - brano */

		while (Database.BranoAlbum[i + 1].idBrano != SENTINELLA) {

			Database.BranoAlbum[i] = Database.BranoAlbum[i + 1];
			i = i + 1;

		}

		Database.BranoAlbum[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 1;

	}

	VisualizzaAlbum(Database);

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra artisti e brani

database CancellaCollegamentiArtistaBrani(int IdArtista, database Database) {

	int i = 0;

	while (VerificaCollegamentoArtistaBrani(IdArtista, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.BranoArtista[i].idArtista != IdArtista)
				&& (Database.BranoArtista[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento artista - brano */

		while (Database.BranoArtista[i + 1].idBrano != SENTINELLA) {

			Database.BranoArtista[i] = Database.BranoArtista[i + 1];

			i = i + 1;

		}

		Database.BranoArtista[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 1;

	}

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra playlist e brani

database CancellaCollegamentiPlaylistBrani(int IdPlaylist, database Database) {

	int i = 0;

	while (VerificaCollegamentoPlaylistBrani(IdPlaylist, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.PlaylistBrano[i].idPlaylist != IdPlaylist)
				&& (Database.PlaylistBrano[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento playlist - brano */

		while (Database.PlaylistBrano[i + 1].idBrano != SENTINELLA) {

			Database.PlaylistBrano[i] = Database.PlaylistBrano[i + 1];

			i = i + 1;

		}

		Database.PlaylistBrano[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 1;

	}

	return Database;

}

// Funzione che permette di cancellare i collegamenti tra genere e brani

database CancellaCollegamentiGenereBrani(int IdGenere, database Database) {

	int i = 0;

	while (VerificaCollegamentoGenereBrani(IdGenere, Database) == VERO) {

		/* ricerca della posizione dell'elemento da cancellare */

		i = 0;
		while ((Database.BranoGenere[i].idGenere != IdGenere)
				&& (Database.BranoGenere[i].idBrano != SENTINELLA)) {

			i++;
		}

		/* cancellazione del collegamento genere - brano */

		while (Database.BranoGenere[i + 1].idBrano != SENTINELLA) {

			Database.BranoGenere[i] = Database.BranoGenere[i + 1];

			i = i + 1;

		}

		Database.BranoGenere[i].idBrano = SENTINELLA;

		Database.UltimoEsito = 1;

	}

	return Database;

}
