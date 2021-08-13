// Libreria
#include "./../include/MusicProject.h"

int controllo_caricamento_file(int flag) {

	FILE *File;
	File = fopen("utenti.txt", "r");

	if (File == NULL) {

		flag = 0;

	} else {

		flag = 1;

	}

	return flag;

}

database CaricareSuFile(database Database) {

	Database = CaricareBrani(Database);
	Database = CaricareAlbum(Database);
	Database = CaricareGeneri(Database);
	Database = CaricareArtisti(Database);
	Database = CaricarePlaylist(Database);
	Database = CaricareUtenti(Database);
	Database = CaricareBranoArtista(Database);
	Database = CaricareBranoAlbum(Database);
	Database = CaricareBranoGenere(Database);
	Database = CaricarePlaylistBrano(Database);

	return Database;

}

/* Funzione che permette il caricamento di tutti i brani all'interno del database */

database CaricareBrani(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("brani.txt", "r");

	if (File == NULL) {

		fopen("brani.txt", "w");
		fclose(File);

	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, " %[^\n]", Database.Brano[i].titolo);
			fscanf(File, "%d", &Database.Brano[i].anno);
			fscanf(File, "%d", &Database.Brano[i].durata);
			fscanf(File, "%d", &Database.Brano[i].ascolti);
			fscanf(File, "%d", &Database.Brano[i].idBrano);

			i = i + 1;
		}

		Database.Brano[i - 1].idBrano = SENTINELLA;

		fclose(File);

	}

	return Database;

}

/* Funzione che permette il caricamento tutti gli album nel database */

database CaricareAlbum(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("album.txt", "r");

	if (File == NULL) {

		fopen("album.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, " %[^\n]", Database.Album[i].titolo);
			fscanf(File, "%d", &Database.Album[i].anno);
			fscanf(File, "%d", &Database.Album[i].idAlbum);

			i = i + 1;
		}

		Database.Album[i - 1].idAlbum = SENTINELLA;

		fclose(File);

	}

	return Database;

}

/* Funione che permette il caricamento del database tutti gli artisti */

database CaricareArtisti(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("artisti.txt", "r");

	if (File == NULL) {

		fopen("artisti.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, " %[^\n]", Database.Artista[i].nome);
			fscanf(File, " %[^\n]", Database.Artista[i].cognome);
			fscanf(File, " %[^\n]", Database.Artista[i].nomeArte);
			fscanf(File, "%d", &Database.Artista[i].idArtista);

			i++;
		}

		Database.Artista[i - 1].idArtista = SENTINELLA;

		fclose(File);

	}

	return Database;

}

/* Funione che permette il caricamento del database tutte le playlist */

database CaricarePlaylist(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("playlist.txt", "r");

	if (File == NULL) {

		fopen("playlist.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, " %[^\n]", Database.Playlist[i].nome);
			fscanf(File, " %[^\n]", Database.Playlist[i].descrizione);
			fscanf(File, "%d", &Database.Playlist[i].pubblica);
			fscanf(File, "%d", &Database.Playlist[i].idPlaylist);

			i++;
		}

		Database.Playlist[i - 1].idPlaylist = SENTINELLA;

		fclose(File);

	}

	return Database;

}

/* Funione che permette il caricamento del database tutti gli utenti */

database CaricareUtenti(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("utenti.txt", "r");

	if (File == NULL) {

		fopen("utenti.txt", "w");
		fclose(File);

	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, " %[^\n]", Database.Utente[i].nomeUtente);
			fscanf(File, " %[^\n]", Database.Utente[i].password);
			fscanf(File, "%d", &Database.Utente[i].admin);
			fscanf(File, "%d", &Database.Utente[i].idUtente);

			i++;
		}

		Database.Utente[i - 1].idUtente = SENTINELLA;

		fclose(File);

	}

	return Database;

}

/* Funione che permette il caricamento del database tutti i generi */

database CaricareGeneri(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("generi.txt", "r");

	if (File == NULL) {

		fopen("generi.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, " %[^\n]", Database.Genere[i].nome);
			fscanf(File, "%d", &Database.Genere[i].idGenere);

			i++;
		}

		Database.Genere[i - 1].idGenere = SENTINELLA;

		fclose(File);

	}

	return Database;
}

/* ================================= SALVATAGGIO SU FILE ==================================== */

void SalvataggioSuFile(database Database) {

	SalvareFileBrani(Database);
	SalvareFileArtisti(Database);
	SalvareFileBranoArtista(Database);
	SalvareFileAlbum(Database);
	SalvareFileBranoAlbum(Database);
	SalvareFileGeneri(Database);
	SalvareFileBranoGenere(Database);
	SalvareFilePlaylist(Database);
	SalvareFilePlaylistBrano(Database);
	SalvareFileUtenti(Database);

	return;

}
void SalvareFileBrani(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("brani.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");
	}

	i = 0;
	while (Database.Brano[i].idBrano != SENTINELLA) {

		fprintf(File, "%s\n", Database.Brano[i].titolo);
		fprintf(File, "%d\n", Database.Brano[i].anno);
		fprintf(File, "%d\n", Database.Brano[i].durata);
		fprintf(File, "%d\n", Database.Brano[i].ascolti);
		fprintf(File, "%d\n", Database.Brano[i].idBrano);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFileAlbum(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("album.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Album[i].idAlbum != SENTINELLA) {

		fprintf(File, "%s\n", Database.Album[i].titolo);
		fprintf(File, "%d\n", Database.Album[i].anno);
		fprintf(File, "%d\n", Database.Album[i].idAlbum);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFileArtisti(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("artisti.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Artista[i].idArtista != SENTINELLA) {

		fprintf(File, "%s\n", Database.Artista[i].nome);
		fprintf(File, "%s\n", Database.Artista[i].cognome);
		fprintf(File, "%s\n", Database.Artista[i].nomeArte);
		fprintf(File, "%d\n", Database.Artista[i].idArtista);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFileGeneri(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("generi.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Genere[i].idGenere != SENTINELLA) {

		fprintf(File, "%s\n", Database.Genere[i].nome);
		fprintf(File, "%d\n", Database.Genere[i].idGenere);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFilePlaylist(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("playlist.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Playlist[i].idPlaylist != -1) {

		fprintf(File, "%s\n", Database.Playlist[i].nome);
		fprintf(File, "%s\n", Database.Playlist[i].descrizione);
		fprintf(File, "%d\n", Database.Playlist[i].pubblica);
		fprintf(File, "%d\n", Database.Playlist[i].idPlaylist);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFileUtenti(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("utenti.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");
	}

	i = 0;
	while (Database.Utente[i].idUtente != SENTINELLA) {

		fprintf(File, "%s\n", Database.Utente[i].nomeUtente);
		fprintf(File, "%s\n", Database.Utente[i].password);
		fprintf(File, "%d\n", Database.Utente[i].admin);
		fprintf(File, "%d\n", Database.Utente[i].idUtente);

		i++;
	}

	fclose(File);

	return;

}

/* ====================================== RIPRISTINO DA FILE DI BACKUP ================================= */

database RipristinoDaFile(database Database) {

	/*  ripristino di tutti i dati dal backup */

	Database = RipristinoBrani(Database);
	Database = RipristinoAlbum(Database);
	Database = RipristinoGeneri(Database);
	Database = RipristinoArtisti(Database);
	Database = RipristinoPlaylist(Database);
	Database = RipristinoUtenti(Database);

	/* ripristino di tutti i collegamenti dal backup */

	Database = RipristinoBranoArtista(Database);
	Database = RipristinoBranoAlbum(Database);
	Database = RipristinoBranoGenere(Database);
	Database = RipristinoPlaylistBrano(Database);

	return Database;

}
/* Funzione che permette di ripristinare tutti i brani all'interno del database */

database RipristinoBrani(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupbrani.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE BRANI! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, " %[^\n]", Database.Brano[i].titolo);
		fscanf(File, "%d", &Database.Brano[i].anno);
		fscanf(File, "%d", &Database.Brano[i].durata);
		fscanf(File, "%d", &Database.Brano[i].ascolti);
		fscanf(File, "%d", &Database.Brano[i].idBrano);

		i = i + 1;
	}

	Database.Brano[i - 1].idBrano = SENTINELLA;

	fclose(File);

	return Database;
}

/* Funzione che permette di ripristinare tutti gli album all'interno del database */

database RipristinoAlbum(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupalbum.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE ALBUM! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, " %[^\n]", Database.Album[i].titolo);
		fscanf(File, "%d", &Database.Album[i].anno);
		fscanf(File, "%d", &Database.Album[i].idAlbum);

		i = i + 1;
	}

	Database.Album[i - 1].idAlbum = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutti gli artisti all'interno del database */

database RipristinoArtisti(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupartisti.txt", "r");

	if (File == NULL) {

		printf("\nerrore!\n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, " %[^\n]", Database.Artista[i].nome);
		fscanf(File, " %[^\n]", Database.Artista[i].cognome);
		fscanf(File, " %[^\n]", Database.Artista[i].nomeArte);
		fscanf(File, "%d", &Database.Artista[i].idArtista);

		i++;
	}

	Database.Artista[i - 1].idArtista = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutte le playlist all'interno del database */

database RipristinoPlaylist(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupplaylist.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE PLAYLIST! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, " %[^\n]", Database.Playlist[i].nome);
		fscanf(File, " %[^\n]", Database.Playlist[i].descrizione);
		fscanf(File, "%d", &Database.Playlist[i].pubblica);
		fscanf(File, "%d", &Database.Playlist[i].idPlaylist);

		i++;
	}

	Database.Playlist[i - 1].idPlaylist = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutti gli utenti all'interno del database */

database RipristinoUtenti(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backuputenti.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE UTENTI! \n");

	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, " %[^\n]", Database.Utente[i].nomeUtente);
		fscanf(File, " %[^\n]", Database.Utente[i].password);
		fscanf(File, "%d", &Database.Utente[i].admin);
		fscanf(File, "%d", &Database.Utente[i].idUtente);

		i++;
	}

	Database.Utente[i - 1].idUtente = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutti i generi all'interno del database */

database RipristinoGeneri(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupgeneri.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE GENERI! \n");

	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, " %[^\n]", Database.Genere[i].nome);
		fscanf(File, "%d", &Database.Genere[i].idGenere);

		i++;
	}

	Database.Genere[i - 1].idGenere = SENTINELLA;

	fclose(File);

	return Database;
}

int controllo_backup(int controllo) {

	FILE *File;
	File = fopen("backuputenti.txt", "r");

	if (File == NULL) {

		controllo = 0;

	} else {

		controllo = 1;
	}

	return controllo;

}

void BackupSuFile(database Database) {

	BackupBrani(Database);
	BackupAlbum(Database);
	BackupArtisti(Database);
	BackupGeneri(Database);
	BackupPlaylist(Database);
	BackupUtenti(Database);
	BackupBranoArtista(Database);
	BackupBranoAlbum(Database);
	BackupBranoGenere(Database);
	BackupPlaylistBrano(Database);

	return;

}
void BackupBrani(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupbrani.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Brano[i].idBrano != SENTINELLA) {

		fprintf(File, "%s\n", Database.Brano[i].titolo);
		fprintf(File, "%d\n", Database.Brano[i].anno);
		fprintf(File, "%d\n", Database.Brano[i].durata);
		fprintf(File, "%d\n", Database.Brano[i].ascolti);
		fprintf(File, "%d\n", Database.Brano[i].idBrano);

		i++;
	}

	fclose(File);

	return;

}

void BackupAlbum(database Database) {

	int i = 0;

	FILE *File;

	File = fopen("backupalbum.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Album[i].idAlbum != SENTINELLA) {

		fprintf(File, "%s\n", Database.Album[i].titolo);
		fprintf(File, "%d\n", Database.Album[i].anno);
		fprintf(File, "%d\n", Database.Album[i].idAlbum);

		i++;
	}

	fclose(File);

	return;

}

void BackupArtisti(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupartisti.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Artista[i].idArtista != SENTINELLA) {

		fprintf(File, "%s\n", Database.Artista[i].nome);
		fprintf(File, "%s\n", Database.Artista[i].cognome);
		fprintf(File, "%s\n", Database.Artista[i].nomeArte);
		fprintf(File, "%d\n", Database.Artista[i].idArtista);

		i++;
	}

	fclose(File);

	return;

}

void BackupGeneri(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupgeneri.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Genere[i].idGenere != SENTINELLA) {

		fprintf(File, "%s\n", Database.Genere[i].nome);
		fprintf(File, "%d\n", Database.Genere[i].idGenere);

		i++;
	}

	fclose(File);

	return;

}

void BackupPlaylist(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupplaylist.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Playlist[i].idPlaylist != SENTINELLA) {

		fprintf(File, "%s\n", Database.Playlist[i].nome);
		fprintf(File, "%s\n", Database.Playlist[i].descrizione);
		fprintf(File, "%d\n", Database.Playlist[i].pubblica);
		fprintf(File, "%d\n", Database.Playlist[i].idPlaylist);

		i++;
	}

	fclose(File);

	return;

}

void BackupUtenti(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backuputenti.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.Utente[i].idUtente != SENTINELLA) {

		fprintf(File, "%s\n", Database.Utente[i].nomeUtente);
		fprintf(File, "%s\n", Database.Utente[i].password);
		fprintf(File, "%d\n", Database.Utente[i].admin);
		fprintf(File, "%d\n", Database.Utente[i].idUtente);

		i++;
	}

	fclose(File);

	return;

}
