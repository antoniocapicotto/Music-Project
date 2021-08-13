//Libreria
#include "./../include/MusicProject.h"

// Funzione che crea collegamenti con il brano

database CreareCollegamentiBrano(Brano NuovoBrano, database Database) {

	Database = CreaCollegamentoBranoAlbum(NuovoBrano, Database);
	Database = CreaCollegamentoBranoGenere(NuovoBrano, Database);
	Database = CreaAssociazioneBranoArtista(NuovoBrano, Database);
	Database = CreaCollegamentoPlaylistBrano(NuovoBrano, Database);

	return Database;

}

database CreaCollegamentoBranoAlbum(Brano NuovoBrano, database Database) {

	char scelta[20];
	int IdAlbum = 0;

	do {

		printf(
				"\n\n\n\n\t\t  ################ IL BRANO \"%s\" DI QUALE ALBUM FA PARTE? ############## \n\n\t\t [1] ASSOCIA IL BRANO \"%s\" IN UN ALBUM PRESENTE NEL SISTEMA \n\n\t\t [2] CREA UN NUOVO ALBUM A CUI ASSOCIARE IL BRANO \"%s\" \n\n\t\t [3] VISUALIZZA LA LISTA DI TUTTI GLI ALBUM GIA' PRESENTI  \n\n\t\t [0] NON INSERIRE IL BRANO IN NESSUN ALBUM",
				NuovoBrano.titolo, NuovoBrano.titolo, NuovoBrano.titolo);
		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t ############ INSERISCI L'ID DELL'ALBUM DA COLLEGARE AL BRANO \"%s\" ############",
					NuovoBrano.titolo);
			printf("\n\n\t\t SCELTA: ");
			scanf("%d", &IdAlbum);

			Database = AssociaBranoAlbum(Database, NuovoBrano.idBrano, IdAlbum);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireAlbum(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaAlbum(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}

database AssociaBranoAlbum(database Database, int IdBrano, int IdAlbum) {

	int i = 0;

	if (VerificaCollegamentoBranoAlbum(IdBrano, Database) == 1) {

		Database.UltimoEsito = 1;

	} else {

		i = 0;
		while (Database.BranoAlbum[i].idBrano != -1) {

			i++;
		}

		Database.BranoAlbum[i].idBrano = IdBrano;
		Database.BranoAlbum[i].idAlbum = IdAlbum;
		Database.BranoAlbum[i + 1].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	}

	return Database;

}

database CreaCollegamentoBranoGenere(Brano NuovoBrano, database Database) {

	char scelta[20];
	int IdGenere = 0;

	do {

		printf(
				"\n\n\n\n\t\t ################ IL BRANO \"%s\" DI QUALE GENERE FA PARTE? ############## \n\n\t\t [1] ASSOCIA IL BRANO \"%s\" A UN GENERE GIA' PRESENTE \n\n\t\t [2] CREA UN NUOVO GENERE A CUI COLLEGARE IL BRANO \"%s\" \n\n\t\t [3] VISUALIZZA LA LISTA DEI GENERI MUSICALI GIA' PRESENTI \n\n\t\t [0] NON INSERIRE IL BRANO IN NESSUN GENERE",
				NuovoBrano.titolo, NuovoBrano.titolo, NuovoBrano.titolo);

		printf("\n\n\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t ############ ID GENERE DA ASSOCIARE ############ ");
			printf("\n\n\t\t ID: ");
			scanf("%d", &IdGenere);

			Database = AssociaBranoGenere(Database, NuovoBrano.idBrano,
					IdGenere);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireGenere(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaGeneri(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}

database AssociaBranoGenere(database Database, int IdBrano, int IdGenere) {

	int i = 0;

	if (VerificaCollegamentoBranoGenere(IdBrano, Database) == 1) {

		Database.UltimoEsito = 1;

	} else {

		i = 0;
		while (Database.BranoGenere[i].idBrano != -1) {

			i++;
		}

		Database.BranoGenere[i].idBrano = IdBrano;

		Database.BranoGenere[i].idGenere = IdGenere;

		Database.BranoGenere[i + 1].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	}

	return Database;

}

database CreaCollegamentoPlaylistBrano(Brano NuovoBrano, database Database) {

	char scelta[20];
	int IdPlaylist = 0;

	do {

		printf(
				"\n\n\n\n\t\t ################## IL BRANO \"%s\" DI QUALE PLAYLIST FA PARTE? ################## \n\n\t\t [1] INSERISCI L'ID DI UNA PLAYLIST PRESENTE \n\n\t\t [2] NUOVA PLAYLIST \n\n\t\t [3] VISUALIZZA LISTA PLAYLIST \n\n\t\t [0] NON INSERIRE IL BRANO IN NESSUNA PLAYLIST",
				NuovoBrano.titolo);
		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t ############ ID PLAYLIST DA ASSOCIARE ############ ");
			printf("\n\n\t\t SCELTA: ");
			scanf("%d", &IdPlaylist);

			Database = AssociaPlaylistBrano(Database, NuovoBrano.idBrano,
					IdPlaylist);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserirePlaylist(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaPlaylist(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}

database AssociaPlaylistBrano(database Database, int IdBrano, int IdPlaylist) {

	int i = 0;

	if (VerificaCollegamentoBranoPlaylist(IdBrano, Database) == 1) {

		Database.UltimoEsito = 1;

	} else {

		i = 0;
		while (Database.PlaylistBrano[i].idBrano != SENTINELLA) {

			i++;
		}

		Database.PlaylistBrano[i].idBrano = IdBrano;
		Database.PlaylistBrano[i].idPlaylist = IdPlaylist;
		Database.PlaylistBrano[i + 1].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	}

	return Database;

}

database CreaAssociazioneBranoArtista(Brano NuovoBrano, database Database) {

	char scelta[20];
	int IdArtista = 0;

	do {

		printf(
				"\n\n\n\n\t\t ################ IL BRANO \"%s\" DI QUALE ARTISTA FA PARTE? ################ \n\n\t\t [1] INSERISCI L'ID DI UN ARTISTA PRESENTE \n\n\t\t [2] INSERISCI UN NUOVO ARTISTA \n\n\t\t [3] VISUALIZZARE LISTA ARTISTI \n\n\t\t [0] NON ASSOCIARE IL BRANO A NESSUN ARTISTA",
				NuovoBrano.titolo);
		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t ############ ID ARTISTA DA ASSOCIARE ############ ");
			printf("\n\n\t\t SCELTA: ");
			scanf("%d", &IdArtista);

			Database = AssociaBranoArtista(Database, NuovoBrano.idBrano,
					IdArtista);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireArtista(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaArtisti(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}

database AssociaBranoArtista(database Database, int IdBrano, int IdArtista) {

	int i = 0;

	if (VerificaCollegamentoBranoArtista(IdBrano, Database) == VERO) {

		Database.UltimoEsito = 1;

	} else {

		i = 0;
		while (Database.BranoArtista[i].idBrano != SENTINELLA) {

			i++;
		}

		Database.BranoArtista[i].idBrano = IdBrano;
		Database.BranoArtista[i].idArtista = IdArtista;
		Database.BranoArtista[i + 1].idBrano = SENTINELLA;

		Database.UltimoEsito = 0;

	}

	return Database;

}

database CreareCollegamentiAlbumBrani(database Database, Album NuovoAlbum) {

	char scelta[20];
	int IdBrano = 0;

	do {

		printf(
				"\n\n\n\n\t\t\t ############## L'ALBUM \"%s\" DI QUALI BRANI FA PARTE? ############## \n\n\t\t [1] INSERISCI ID DEL BRANO PRESENTE IN QUESTO ELENCO \n\n\t [2] NUOVO BRANO A CUI ASSOCIARE L'ALBUM %s \n\n\t\t [3] VISUALIZZA LISTA BRANI \n\n\t\t [0] NESSUNO \n\n",
				NuovoAlbum.titolo, NuovoAlbum.titolo);
		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t\t ########################### ID BRANO DA ASSOCIARE ########################### \n\n");
			printf("\n\n\t\t\t SCELTA: ");
			scanf("%d", &IdBrano);

			Database = AssociaBranoAlbum(Database, IdBrano, NuovoAlbum.idAlbum);

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireBrano(Database);

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaBrani(Database);

		}

	} while (strcmp(scelta, "0") == 1);

	return Database;
}

database CreareCollegamentiGenereBrani(database Database, Genere NuovoGenere) {

	char scelta[20];
	int IdBrano = 0;

	do {

		printf(
				"\n\n\n\n\t\t ################ IL GENERE \"%s\" DI QUALI BRANI FA PARTE? ################ \n\n\t\t [1] COLLEGARE BRANO GIA' PRESENTE A QUESTO GENERE \n\n\t\t [2] CREA NUOVO BRANO DA COLLEGARE A QUESTO GENERE \n\n\t\t [3] VISUALIZZA LISTA BRANI \n\n\t\t [0] ESCI \n\n",
				NuovoGenere.nome);
		printf("\n\n\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t\t ###################### ID BRANO DA ASSOCIARE ###################### ");
			printf("\n\n\t\t\t SCELTA: ");
			scanf("%d", &IdBrano);

			Database = AssociaBranoGenere(Database, IdBrano,
					NuovoGenere.idGenere);

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireBrano(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaBrani(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}

database CreareCollegamentiPlaylistBrani(database Database,
		Playlist NuovaPlaylist) {

	char scelta[20];
	int IdBrano = 0;

	do {

		printf(
				"\n\n\n\n\t\t ########### QUALI BRANI FANNO PARTE DELLA PLAYLIST \"%s\" ? ########### \n\n\t\t [1] ASSOCIARE LA PLAYLIST A UN BRANO PRESENTE \n\n\t\t [2] INSERIRE UN NUOVO BRANO \n\n\t\t [3] VISUALIZZA LISTA BRANI \n\n\n\t\t [0] ESCI \n\n",
				NuovaPlaylist.nome);

		printf("\n\t\t SCELTA: ");

		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t ############# INSERISCI L'ID DI UN BRANO DA ASSCOCIARE A QUESTO GENERE #############");

			printf("\n\n\t\t SCELTA: ");
			scanf("%d", &IdBrano);

			Database = AssociaPlaylistBrano(Database, IdBrano,
					NuovaPlaylist.idPlaylist);

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireBrano(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaBrani(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}

database CreareCollegamentiArtistaBrani(database Database, Artista NuovoArtista) {

	char scelta[20];
	int IdBrano = 0;

	do {

		printf(
				"\n\n\n\n\t\t ############## QUALI BRANI FANNO PARTE DELL'ARTISTA \"%s\" ? ############### \n\n\t [1] COLLEGARE L'ARTISTA A UN BRANO GIA' PRESENTE \n\n\t [2] CREA UN NUOVO BRANO DA ASSOCIARE ALL'ARTISTA \n\n\t [3] VISUALIZZA LISTA BRANI \n\n\t [0] NESSUNO \n\n",
				NuovoArtista.nome);

		printf("\n\t\t SCELTA: ");
		scanf(" %[^\n]", scelta);

		if (strcmp(scelta, "1") == 0) {

			printf(
					"\n\n\n\n\n\t\t ############# ID DEL BRANO DA COLLEGARE ALL'ARTISTA \"%s\" ############# \n\n",
					NuovoArtista.nome);
			printf("\n\n\t\t SCELTA: ");
			scanf("%d", &IdBrano);

			Database = AssociaBranoArtista(Database, IdBrano,
					NuovoArtista.idArtista);

		} else if (strcmp(scelta, "2") == 0) {

			Database = InserireBrano(Database);

			strcpy(scelta, "0");

		} else if (strcmp(scelta, "3") == 0) {

			VisualizzaBrani(Database);
		}

	} while (strcmp(scelta, "0") == 1);

	return Database;

}
