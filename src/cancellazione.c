//Libreria
#include "./../include/MusicProject.h"

database CancellareBrano(database Database) {

	int IdBrano = 0;
	char scelta[20];

	VisualizzaBrani(Database);

	Database = CancellaDatiBrano(Database, IdBrano);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t\t ++++++++++++ BRANO NON PRESENTE! ++++++++++++ \n\n\t\t [1] CANCELLA UN ALTRO BRANO \n\n\t\t [0] ESCI");
		printf("\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaBrani(Database);

			Database = CancellaDatiBrano(Database, IdBrano);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;
		}

	}

	return Database;

}

database CancellaDatiBrano(database Database, int IdBrano) {

	int i = 0;

	printf(
			"\n\n\n\t\t ################## ID BRANO DA CANCELLARE ################## ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdBrano);

	if (VerificaIdBrano(Database, IdBrano) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		/* posizione del brano da cancellare */

		i = IdBrano;

		while (Database.Brano[i + 1].idBrano != SENTINELLA) {

			Database.Brano[i] = Database.Brano[i + 1];

			Database.Brano[i].idBrano = Database.Brano[i].idBrano - 1;

			i++;
		}

		Database.Brano[i].idBrano = SENTINELLA;

		Database = CancellareCollegamentiBrano(IdBrano, Database);

		Database.UltimoEsito = 0;

	}

	return Database;
}

int VerificaIdBrano(database Database, int IdBrano) {

	int trovato = FALSO;
	int i = 0;

	while ((Database.Brano[i].idBrano != SENTINELLA) && (trovato != VERO)) {

		if (Database.Brano[i].idBrano == IdBrano) {

			trovato = VERO;
		}

		i++;
	}

	return trovato;
}

database CancellareAlbum(database Database) {

	int IdAlbum = 0;
	char scelta[20];

	VisualizzaAlbum(Database);

	Database = CancellaDatiAlbum(Database, IdAlbum);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t ++++++++++++ ALBUM NON PRESENTE! ++++++++++++ \n\n\t\t [1] CANCELLA UN ALTRO ALBUM \n\n\t\t [0] ESCI");

		printf("\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaAlbum(Database);

			Database = CancellaDatiAlbum(Database, IdAlbum);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;
		}

	}

	return Database;

}

database CancellaDatiAlbum(database Database, int IdAlbum) {

	int i = 0;

	printf(
			"\n\n\n\n\t\t ################# ID ALBUM DA CANCELLARE ################# \n\n");
	printf("\n\n\n\t\t ID: ");

	scanf("%d", &IdAlbum);

	if (VerificaIdAlbum(Database, IdAlbum) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		/* posizione dell'album da cancellare */

		i = IdAlbum;

		while (Database.Album[i + 1].idAlbum != SENTINELLA) {

			Database.Album[i] = Database.Album[i + 1];
			Database.Album[i].idAlbum = Database.Album[i].idAlbum - 1;

			i++;
		}

		Database.Album[i].idAlbum = SENTINELLA;

		/* cancellazione di eventuali collegamenti brano - album */
		Database = CancellaCollegamentiAlbumBrani(IdAlbum, Database);

		Database.UltimoEsito = 0;

	}

	return Database;
}

int VerificaIdAlbum(database Database, int IdAlbum) {

	int trovato = FALSO;
	int i = 0;

	while ((Database.Album[i].idAlbum != SENTINELLA) && (trovato != VERO)) {

		if (Database.Album[i].idAlbum == IdAlbum) {

			trovato = VERO;
		}
		i++;
	}

	return trovato;
}

database CancellareArtista(database Database) {

	int IdArtista = 0;
	char scelta[20];

	VisualizzaArtisti(Database);

	Database = CancellaDatiArtista(Database, IdArtista);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t\t +++++++++++++++++++++++++++++++++ ARTISTA NON PRESENTE! +++++++++++++++++++++++++++++++++ \n\n\t\t [1] CANCELLA UN ALTRO ARTISTA \n\n\t\t [0] ESCI");
		printf("\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaArtisti(Database);

			Database = CancellaDatiArtista(Database, IdArtista);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;
		}

	}

	return Database;

}

database CancellaDatiArtista(database Database, int IdArtista) {

	int i = 0;

	printf(
			"\n\n\n\n\t\t ################# ID ARTISTA DA CANCELLARE ################# ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdArtista);

	if (VerificaIdArtista(Database, IdArtista) == 0) {

		Database.UltimoEsito = 1;

	} else {

		/* posizione dell'artista da cancellare */

		i = IdArtista;

		while (Database.Artista[i + 1].idArtista != SENTINELLA) {

			Database.Artista[i] = Database.Artista[i + 1];
			Database.Artista[i].idArtista = Database.Artista[i].idArtista - 1;

			i++;
		}

		Database.Artista[i].idArtista = SENTINELLA;

		/* cancellazione di eventuali collegamenti artista - brano */
		Database = CancellaCollegamentiArtistaBrani(IdArtista, Database);

		Database.UltimoEsito = 0;

	}

	return Database;
}

int VerificaIdArtista(database Database, int IdArtista) {

	int trovato = FALSO;
	int i = 0;

	while ((Database.Artista[i].idArtista != SENTINELLA) && (trovato != VERO)) {

		if (Database.Artista[i].idArtista == IdArtista) {

			trovato = VERO;
		}

		i++;
	}

	return trovato;

}

database CancellarePlaylist(database Database) {

	int IdPlaylist = 0;
	char scelta[20];

	VisualizzaPlaylist(Database);

	Database = CancellaDatiPlaylist(Database, IdPlaylist);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t ++++++++++++ PLAYLIST NON PRESENTE! ++++++++++++ \n\n\t\t [1] CANCELLA UN ALTRA PLAYLIST \n\n\t\t [0] ESCI");
		printf("\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaPlaylist(Database);

			Database = CancellaDatiPlaylist(Database, IdPlaylist);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;
		}

	}

	return Database;

}

database CancellaDatiPlaylist(database Database, int IdPlaylist) {

	int i = 0;

	printf(
			"\n\n\n\n\t\t ################### ID PLAYLIST DA CANCELLARE ################### ");
	printf("\n\n\n\t ID: ");

	scanf("%d", &IdPlaylist);

	if (VerificaIdPlaylist(Database, IdPlaylist) == 0) {

		Database.UltimoEsito = 1;

	} else {

		/* posizione della playlist da cancellare */

		i = IdPlaylist;

		while (Database.Playlist[i + 1].idPlaylist != SENTINELLA) {

			Database.Playlist[i] = Database.Playlist[i + 1];

			Database.Playlist[i].idPlaylist = Database.Playlist[i].idPlaylist
					- 1;

			i++;
		}

		Database.Playlist[i].idPlaylist = SENTINELLA;

		/* cancellazione di eventuali collegamenti playlist - brano */

		Database = CancellaCollegamentiPlaylistBrani(IdPlaylist, Database);

		Database.UltimoEsito = 0;

	}

	return Database;
}

int VerificaIdPlaylist(database Database, int IdPlaylist) {

	int trovato = FALSO;
	int i = 0;

	while ((Database.Playlist[i].idPlaylist != SENTINELLA) && (trovato != VERO)) {

		if (Database.Playlist[i].idPlaylist == IdPlaylist) {

			trovato = VERO;
		}

		i++;
	}

	return trovato;

}

database CancellareGenere(database Database) {

	int IdGenere = 0;
	char scelta[20];

	VisualizzaGeneri(Database);

	Database = CancellaDatiGenere(Database, IdGenere);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t\t ++++++++++++ GENERE NON PRESENTE! ++++++++++++ \n\n\t\t [1] CANCELLA UN ALTRO GENERE \n\n\t\t [0] ESCI");

		printf("\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaGeneri(Database);

			Database = CancellaDatiGenere(Database, IdGenere);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;
		}

	}

	return Database;

}

database CancellaDatiGenere(database Database, int IdGenere) {

	int i = 0;

	printf(
			"\n\n\n\n\t\t ####################### ID GENERE DA CANCELLARE ####################### ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdGenere);

	if (VerificaIdGenere(Database, IdGenere) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		/* posizione del genere da cancellare */

		i = IdGenere;

		while (Database.Genere[i + 1].idGenere != SENTINELLA) {

			Database.Genere[i] = Database.Genere[i + 1];

			Database.Genere[i].idGenere = Database.Genere[i].idGenere - 1;

			i++;
		}

		Database.Genere[i].idGenere = SENTINELLA;

		/* cancellazione di eventuali collegamenti genere - brani */
		Database = CancellaCollegamentiGenereBrani(IdGenere, Database);

		Database.UltimoEsito = 0;

	}

	return Database;
}

int VerificaIdGenere(database Database, int IdGenere) {

	int trovato = FALSO;
	int i = 0;

	while ((Database.Genere[i].idGenere != SENTINELLA) && (trovato != VERO)) {

		if (Database.Genere[i].idGenere == IdGenere) {

			trovato = VERO;
		}

		i++;
	}

	return trovato;

}

database CancellareUtente(database Database) {

	int IdUtente = 0;
	char scelta[20];

	VisualizzaUtenti(Database);

	Database = CancellaDatiUtente(Database, IdUtente);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t\t ++++++++++++ UTENTE NON PRESENTE! ++++++++++++ \n\n\t\t [1] CANCELLA UN ALTRO UTENTE \n\n\t\t [0] ESCI");

		printf("\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf("\n\n");

			VisualizzaUtenti(Database);

			Database = CancellaDatiUtente(Database, IdUtente);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;
		}

	}

	return Database;

}

database CancellaDatiUtente(database Database, int IdUtente) {

	int i = 0;

	printf(
			"\n\n\n\n\t\t ########################### ID UTENTE DA CANCELLARE ########################### ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdUtente);

	if (VerificaIdUtente(Database, IdUtente) == 0) {

		Database.UltimoEsito = 1;

	} else {

		/* posizione dell'utente da cancellare */

		i = IdUtente;

		while (Database.Utente[i + 1].idUtente != SENTINELLA) {

			Database.Utente[i] = Database.Utente[i + 1];
			Database.Utente[i].idUtente = Database.Utente[i].idUtente - 1;

			i++;
		}

		Database.Utente[i].idUtente = SENTINELLA;

		Database.UltimoEsito = 0;

	}

	return Database;
}

int VerificaIdUtente(database Database, int IdUtente) {

	int trovato = FALSO;
	int i = 0;

	while ((Database.Utente[i].idUtente != SENTINELLA) && (trovato != VERO)) {

		if (Database.Utente[i].idUtente == IdUtente) {

			trovato = VERO;
		}

		i++;
	}

	return trovato;

}

