//Libreria
#include "./../include/MusicProject.h"

void ModificaStringa(char stringa[]) {

	int i = 0;

	i = 0;
	while (stringa[i] != FINESTRINGA) {

		stringa[i] = toupper(stringa[i]);

		i++;
	}

	return;

}

// =============================================  BRANO ==================================================

database ModificareBrano(database Database) {

	char scelta[20];
	int IdBrano = 0;
	Brano BranoModificato;

	VisualizzaBrani(Database);

	Database = ModificaDatiBrano(BranoModificato, Database, IdBrano);

	while (Database.UltimoEsito != 0) {

		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaBrani(Database);

			Database = ModificaDatiBrano(BranoModificato, Database, IdBrano);

		} else if (strcmp(scelta, "2") == 0) {

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificaDatiBrano(Brano BranoModificato, database Database,
		int IdBrano) {

	printf(
			"\n\n\n\n\t\t ###################### ID BRANO DA MODIFICARE ###################### \n\n");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdBrano);

	// verifica dell'id che sia corretto

	if (VerificaIdBrano(Database, IdBrano) == FALSO) {

		Database.UltimoEsito = 1;
		printf(
				"\n\n\n\n\t\t ++++++++++++++++ ID BRANO INESISTENTE ++++++++++++++++ \n\n\t\t [1] MODIFICA UN ALTRO BRANO \n\n\t\t [2] NO ");

	} else {

		do {

			printf("\n\t MODIFICA TITOLO: ");
			scanf(" %[^\n]", BranoModificato.titolo);
			ModificaStringa(BranoModificato.titolo);

		} while ((strlen(BranoModificato.titolo) >= 30)
				|| (strlen(BranoModificato.titolo) < 0));

		do {

			printf("\n\t MODIFICA ANNO: ");
			scanf("%d", &BranoModificato.anno);

		} while (BranoModificato.anno < 1900);

		if (TrovaIdBrano(Database, BranoModificato.titolo,
				BranoModificato.anno) != SENTINELLA) {

			Database.UltimoEsito = 1;
			printf(
					"\n\n\n\n\n\t\t +++++++++++++++ BRANO GIA' ESISTENTE +++++++++++++++ \n\n\t\t [1] MODIFICA UN ALTRO BRANO \n\n\t\t [2] NO ");

		} else {

			// verifica che il brano che si intende aggiungere non sia gi� presente

			Database = CancellareCollegamentiBrano(IdBrano, Database);

			do {

				printf("\n\t MODIFICA DURATA(sec): ");
				scanf("%d", &BranoModificato.durata);

			} while (BranoModificato.durata <= 0);

			do {

				printf("\n\t MODIFICA ASCOLTI: ");
				scanf("%d", &BranoModificato.ascolti);

			} while (BranoModificato.ascolti < 0);

			BranoModificato.idBrano = IdBrano;

			Database.Brano[BranoModificato.idBrano] = BranoModificato;

			Database = CreareCollegamentiBrano(BranoModificato, Database);

			Database.UltimoEsito = 0;
		}

	}

	return Database;
}

database ModificareAlbum(database Database) {

	char scelta[20];
	int IdAlbum = 0;
	Album AlbumModificato;

	VisualizzaAlbum(Database);

	Database = ModificaDatiAlbum(AlbumModificato, Database, IdAlbum);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t\t ++++++++++++++++++++ ID INESISTENTE O ALBUM GIA' PRESENTE +++++++++++++++++ \n\n\t\t [1] MODIFICA UN ALTRO ALBUM \n\n\t\t [2] NO ");
		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaAlbum(Database);

			Database = ModificaDatiAlbum(AlbumModificato, Database, IdAlbum);

		} else if (strcmp(scelta, "2") == 0) {

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificaDatiAlbum(Album AlbumModificato, database Database,
		int IdAlbum) {

	printf(
			"\n\n\n\n\t\t ########################### ID ALBUM DA MODIFICARE ########################### ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdAlbum);

	if (VerificaIdAlbum(Database, IdAlbum) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		do {

			printf("\n\t\t MODIFICA TITOLO: ");
			scanf(" %[^\n]", AlbumModificato.titolo);
			ModificaStringa(AlbumModificato.titolo);

		} while ((strlen(AlbumModificato.titolo) >= 30)
				|| (strlen(AlbumModificato.titolo) < 0));

		do {

			printf("\n\t\t MODIFICA ANNO: ");
			scanf("%d", &AlbumModificato.anno);

		} while (AlbumModificato.anno < 1900);

		if (TrovaIdAlbum(Database, AlbumModificato.titolo,
				AlbumModificato.anno) != SENTINELLA) {

			Database.UltimoEsito = 1;

		} else {

			Database = CancellaCollegamentiAlbumBrani(IdAlbum, Database);

			AlbumModificato.idAlbum = IdAlbum;

			Database.Album[AlbumModificato.idAlbum] = AlbumModificato;

			Database = CreareCollegamentiAlbumBrani(Database, AlbumModificato);

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificareGenere(database Database) {

	char scelta[20];
	int IdGenere = 0;
	Genere GenereModificato;

	VisualizzaGeneri(Database);

	Database = ModificaDatiGenere(GenereModificato, Database, IdGenere);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t ++++++++++++ ID INESISTENTE O GENERE GIA' PRESENTE ++++++++++++ \n\n\t\t [1] MODIFICARE UN ALTRO GENERE \n\n\t\t [2] NO ");

		printf("\n\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaGeneri(Database);

			Database = ModificaDatiGenere(GenereModificato, Database, IdGenere);

		} else if (strcmp(scelta, "2") == 0) {

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificaDatiGenere(Genere GenereModificato, database Database,
		int IdGenere) {

	printf(
			"\n\n\n\n\t\t ###################### ID GENERE DA MODIFICARE ###################### ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdGenere);

	if (VerificaIdGenere(Database, IdGenere) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		do {

			printf("\n\t\t MODIFICA NOME: ");
			scanf(" %[^\n]", GenereModificato.nome);
			ModificaStringa(GenereModificato.nome);

		} while ((strlen(GenereModificato.nome) >= 30)
				|| (strlen(GenereModificato.nome) < 0));

		if (TrovaIdGenere(Database, GenereModificato.nome) != SENTINELLA) {

			Database.UltimoEsito = 1;

		} else {

			Database = CancellaCollegamentiGenereBrani(IdGenere, Database);

			GenereModificato.idGenere = IdGenere;

			Database.Genere[GenereModificato.idGenere] = GenereModificato;

			Database = CreareCollegamentiGenereBrani(Database,
					GenereModificato);

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificarePlaylist(database Database) {

	char scelta[20];
	int IdPlaylist = 0;
	Playlist PlaylistModificata;

	VisualizzaPlaylist(Database);

	Database = ModificaDatiPlaylist(PlaylistModificata, Database, IdPlaylist);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\t\t ++++++++++++ ID PLAYLIST INESISTENTE O PLAYLIST GIA' PRESENTE ++++++++++++ \n\n\t\t [1] MODIFICARE UN ALTRA PLAYLIST \n\n\t\t [0] ESCI ");

		printf("\n\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaPlaylist(Database);

			Database = ModificaDatiPlaylist(PlaylistModificata, Database,
					IdPlaylist);

		} else if (strcmp(scelta, "0") == 0) {

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificaDatiPlaylist(Playlist PlaylistModificata, database Database,
		int IdPlaylist) {

	int esito = FALSO;

	printf(
			"\n\n\n\n\t\t ########################### ID PLAYLIST DA MODIFICARE ########################### ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdPlaylist);

	if (VerificaIdPlaylist(Database, IdPlaylist) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		do {

			printf("\n\t\t MODIFICA NOME: ");

			scanf(" %[^\n]", PlaylistModificata.nome);

			ModificaStringa(PlaylistModificata.nome);

		} while ((strlen(PlaylistModificata.nome) >= 30)
				|| (strlen(PlaylistModificata.nome) < 0));

		while (esito != VERO) {

			printf("\n\t\t MODIFICA PUBBLICA( [1] SI - [0] NO ): ");
			scanf("%d", &PlaylistModificata.pubblica);

			if ((PlaylistModificata.pubblica == 1)
					|| (PlaylistModificata.pubblica == 0)) {

				esito = VERO;

			}

		}

		if (TrovaIdPlaylist(Database, PlaylistModificata.nome,
				PlaylistModificata.pubblica) != SENTINELLA) {

			Database.UltimoEsito = 1;

		} else {

			Database = CancellaCollegamentiPlaylistBrani(IdPlaylist, Database);

			do {

				printf("\n\t\t MODIFICA DESCRIZIONE: ");

				scanf(" %[^\n]", PlaylistModificata.descrizione);
				ModificaStringa(PlaylistModificata.descrizione);

			} while ((strlen(PlaylistModificata.descrizione) >= 250)
					|| (strlen(PlaylistModificata.descrizione) < 0));

			PlaylistModificata.idPlaylist = IdPlaylist;

			Database.Playlist[PlaylistModificata.idPlaylist] =
					PlaylistModificata;

			Database = CreareCollegamentiPlaylistBrani(Database,
					PlaylistModificata);

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificareArtista(database Database) {

	char scelta[20];
	int IdArtista = 0;
	Artista ArtistaModificato;

	VisualizzaArtisti(Database);

	Database = ModificaDatiArtista(ArtistaModificato, Database, IdArtista);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t ++++++++++++ ID ARTISTA NON PRESENTE O ARTISTA GIA' PRESENTE ++++++++++++ \n\n\t\t [1] MODIFICARE UN ALTRO ARTISTA \n\n\t\t [2] NO ");
		printf("\n\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaArtisti(Database);

			Database = ModificaDatiArtista(ArtistaModificato, Database,
					IdArtista);

		} else if (strcmp(scelta, "2") == 0) {

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificaDatiArtista(Artista ArtistaModificato, database Database,
		int IdArtista) {

	printf(
			"\n\n\n\n\t\t ################# ID ARTISTA DA MODIFICARE ################# ");

	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdArtista);

	if (VerificaIdArtista(Database, IdArtista) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		do {

			printf("\n\t\t MODIFICA NOME: ");
			scanf(" %[^\n]", ArtistaModificato.nome);
			ModificaStringa(ArtistaModificato.nome);

		} while ((strlen(ArtistaModificato.nome) >= 30)
				|| (strlen(ArtistaModificato.nome) < 0));

		do {

			printf("\n\t\t MODIFICA COGNOME: ");
			scanf(" %[^\n]", ArtistaModificato.cognome);
			ModificaStringa(ArtistaModificato.cognome);

		} while ((strlen(ArtistaModificato.cognome) >= 30)
				|| (strlen(ArtistaModificato.cognome) < 0));

		if (TrovaIdArtista(Database, ArtistaModificato.nome,
				ArtistaModificato.cognome) != SENTINELLA) {

			Database.UltimoEsito = 1;

		} else {

			do {

				printf("\n\t\t MODIFICA NOME ARTE: ");
				scanf(" %[^\n]", ArtistaModificato.nomeArte);
				ModificaStringa(ArtistaModificato.nomeArte);

			} while ((strlen(ArtistaModificato.cognome) >= 30)
					|| (strlen(ArtistaModificato.cognome) < 0));

			Database = CancellaCollegamentiArtistaBrani(IdArtista, Database);

			ArtistaModificato.idArtista = IdArtista;

			Database.Artista[ArtistaModificato.idArtista] = ArtistaModificato;

			Database = CreareCollegamentiArtistaBrani(Database,
					ArtistaModificato);

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificareUtente(database Database) {

	char scelta[20];
	int IdUtente = 0;
	Utente UtenteModificato;

	VisualizzaUtenti(Database);

	Database = ModificaDatiUtente(UtenteModificato, Database, IdUtente);

	while (Database.UltimoEsito != 0) {

		printf(
				"\n\n\n\n\n\t\t ++++++++++++ ID UTENTE INESISTENTE O UTENTE GIA' PRESENTE ++++++++++++ \n\n\t\t [1] MODIFICARE UN ALTRO UTENTE \n\n\t\t [2] ESCI ");

		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			VisualizzaUtenti(Database);

			Database = ModificaDatiUtente(UtenteModificato, Database, IdUtente);

		} else if (strcmp(scelta, "2") == 0) {

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

database ModificaDatiUtente(Utente UtenteModificato, database Database,
		int IdUtente) {

	int esito = FALSO;

	printf(
			"\n\n\n\n\t\t ################## ID UTENTE DA MODIFICARE ################## ");
	printf("\n\n\n\t\t ID: ");
	scanf("%d", &IdUtente);

	if (VerificaIdUtente(Database, IdUtente) == FALSO) {

		Database.UltimoEsito = 1;

	} else {

		do {

			printf("\n\n\t\t USERNAME( Min 6 caratteri ): ");
			scanf(" %[^\n]", UtenteModificato.nomeUtente);

		} while ((strlen(UtenteModificato.nomeUtente) >= 60)
				|| (strlen(UtenteModificato.nomeUtente) < 6));

		do {

			LeggerePassword(UtenteModificato.password);

		} while ((strlen(UtenteModificato.password) >= 30)
				|| (strlen(UtenteModificato.password) < 6));

		while (esito != VERO) {

			printf("\n\n\t\t ADMIN( [1] SI - [0] NO ): ");
			scanf("%d", &UtenteModificato.admin);

			if ((UtenteModificato.admin == 1)
					|| (UtenteModificato.admin == 0)) {

				esito = VERO;
			}

		}

		if (TrovaIdUtente(Database, UtenteModificato.nomeUtente,
				UtenteModificato.password) != SENTINELLA) {

			Database.UltimoEsito = 1;

		} else {

			UtenteModificato.idUtente = IdUtente;

			Database.Utente[UtenteModificato.idUtente] = UtenteModificato;

			Database.UltimoEsito = 0;

		}

	}

	return Database;
}

