#include "./../include/MusicProject.h"

/* Funione che permette il caricamento del database tutti i collegamenti branoartista */

database CaricareBranoArtista(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("branoartista.txt", "r");

	if (File == NULL) {

		fopen("branoartista.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, "%d", &Database.BranoArtista[i].idBrano);
			fscanf(File, "%d", &Database.BranoArtista[i].idArtista);

			i++;
		}

		Database.BranoArtista[i - 1].idBrano = SENTINELLA;

		fclose(File);

	}

	return Database;

}

/* Funione che permette il caricamento del database tutti i collegamenti branoalbum */

database CaricareBranoAlbum(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("branoalbum.txt", "r");

	if (File == NULL) {

		fopen("branoalbum.txt", "w");
		fclose(File);

	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, "%d", &Database.BranoAlbum[i].idBrano);
			fscanf(File, "%d", &Database.BranoAlbum[i].idAlbum);

			i++;

		}

		Database.BranoAlbum[i - 1].idBrano = SENTINELLA;

		fclose(File);

	}

	return Database;

}

// Funzione che permettere di caricare il file brano genere

database CaricareBranoGenere(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("branogenere.txt", "r");

	if (File == NULL) {

		fopen("branogenere.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, "%d", &Database.BranoGenere[i].idBrano);
			fscanf(File, "%d", &Database.BranoGenere[i].idGenere);

			i++;
		}

		Database.BranoGenere[i - 1].idBrano = SENTINELLA;

		fclose(File);

	}

	return Database;

}

database CaricarePlaylistBrano(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("playlistbrano.txt", "r");

	if (File == NULL) {

		fopen("playlistbrano.txt", "w");
		fclose(File);
	} else {

		i = 0;
		while (!feof(File)) {

			fscanf(File, "%d", &Database.PlaylistBrano[i].idBrano);
			fscanf(File, "%d", &Database.PlaylistBrano[i].idPlaylist);

			i++;
		}

		Database.PlaylistBrano[i - 1].idBrano = SENTINELLA;

		fclose(File);

	}

	return Database;

}

void SalvareFileBranoArtista(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("branoartista.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.BranoArtista[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.BranoArtista[i].idBrano);
		fprintf(File, "%d\n", Database.BranoArtista[i].idArtista);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFileBranoAlbum(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("branoalbum.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");
	}

	i = 0;
	while (Database.BranoAlbum[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.BranoAlbum[i].idBrano);
		fprintf(File, "%d\n", Database.BranoAlbum[i].idAlbum);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFileBranoGenere(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("branogenere.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.BranoGenere[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.BranoGenere[i].idBrano);
		fprintf(File, "%d\n", Database.BranoGenere[i].idGenere);

		i++;
	}

	fclose(File);

	return;

}

void SalvareFilePlaylistBrano(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("playlistbrano.txt", "w");

	if (File == NULL) {

		printf("\n errore! \n");

	}

	i = 0;
	while (Database.PlaylistBrano[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.PlaylistBrano[i].idBrano);
		fprintf(File, "%d\n", Database.PlaylistBrano[i].idPlaylist);

		i++;
	}

	fclose(File);

	return;

}

/* Funzione che permette di ripristinare tutti i collegamanti brano - artista  all'interno del database */

database RipristinoBranoArtista(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupbranoartista.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE BRANOARTISTI! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, "%d", &Database.BranoArtista[i].idBrano);

		fscanf(File, "%d", &Database.BranoArtista[i].idArtista);

		i++;
	}

	Database.BranoArtista[i - 1].idBrano = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutti i collegamanti brano - album  all'interno del database */

database RipristinoBranoAlbum(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupbranoalbum.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE BRANOALBUM! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, "%d", &Database.BranoAlbum[i].idBrano);
		fscanf(File, "%d", &Database.BranoAlbum[i].idAlbum);

		i++;

	}

	Database.BranoAlbum[i - 1].idBrano = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutti i collegamanti brano - genere  all'interno del database */

database RipristinoBranoGenere(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupbranogenere.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE BRANOGENERE! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, "%d", &Database.BranoGenere[i].idBrano);
		fscanf(File, "%d", &Database.BranoGenere[i].idGenere);

		i++;
	}

	Database.BranoGenere[i - 1].idBrano = SENTINELLA;

	fclose(File);

	return Database;

}

/* Funzione che permette di ripristinare tutti i collegamanti brano - playlist all'interno del database */

database RipristinoPlaylistBrano(database Database) {

	FILE *File;
	int i = 0;

	File = fopen("backupplaylistbrano.txt", "r");

	if (File == NULL) {

		printf("\n\n\t ERRORE RIPRISTINO FILE PLAYLISTBRANO! \n");
	}

	i = 0;
	while (!feof(File)) {

		fscanf(File, "%d", &Database.PlaylistBrano[i].idBrano);
		fscanf(File, "%d", &Database.PlaylistBrano[i].idPlaylist);
		i++;
	}

	Database.PlaylistBrano[i - 1].idBrano = SENTINELLA;

	fclose(File);

	return Database;

}

void BackupBranoArtista(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupbranoartista.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.BranoArtista[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.BranoArtista[i].idBrano);
		fprintf(File, "%d\n", Database.BranoArtista[i].idArtista);

		i++;
	}

	fclose(File);

	return;

}

void BackupBranoAlbum(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupbranoalbum.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.BranoAlbum[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.BranoAlbum[i].idBrano);
		fprintf(File, "%d\n", Database.BranoAlbum[i].idAlbum);

		i++;
	}

	fclose(File);

	return;

}

void BackupBranoGenere(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupbranogenere.txt", "w");

	if (File == NULL) {

		printf("\n errore \n");

	}

	i = 0;
	while (Database.BranoGenere[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.BranoGenere[i].idBrano);
		fprintf(File, "%d\n", Database.BranoGenere[i].idGenere);

		i++;
	}

	fclose(File);

	return;

}

void BackupPlaylistBrano(database Database) {

	int i = 0;
	FILE *File;

	File = fopen("backupplaylistbrano.txt", "w");

	if (File == NULL) {

		printf("\n errore! \n");

	}

	i = 0;
	while (Database.PlaylistBrano[i].idBrano != SENTINELLA) {

		fprintf(File, "%d\t", Database.PlaylistBrano[i].idBrano);
		fprintf(File, "%d\n", Database.PlaylistBrano[i].idPlaylist);

		i++;
	}

	fclose(File);

	return;

}
