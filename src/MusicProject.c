// Libreria
#include "./../include/MusicProject.h"

int main() {

	/*  ============================= DICHIARAZIONI VARIABILI ============================= */

	database Database;      // database nel quale verranno caricati tutti i dati
	char scelta[1];       // variabile utilizzata per il men� a scelta multipla
	int controllo_stato_caricamento = 0; // variabile che indica se � necessaria l'installazione dei file
	int controllo_stato_backup = 0; // variabile che controlla se � presente un backup

	/* ================================= FASE DI INSTALLAZIONE ===================================== */

	controllo_stato_caricamento = controllo_caricamento_file(
			controllo_stato_caricamento);

	if (controllo_stato_caricamento == 0) {

		printf(
				"\n\n\t\t ********************** INSTALLAZINE DEL PROGRAMMA,RIAVVIARE ********************** \n\n");

		Database = CaricareSuFile(Database);

	} else {

		do {

			/* ================================= FASE DI INPUT ===================================== */

			printf(
					"\n\n\t\t ********************** STEP 1 di 2 - RIPRISTINO BACKUP ********************* \n\n\n\t\t [1] NO \n\n\t\t [2] SI");
			printf("\n\n\n\t\t SCELTA: ");
			scanf(" %[^\n]", scelta);

			if (strcmp(scelta, "1") == 0) {
				Database = CaricareSuFile(Database);
				strcpy(scelta, "0");

			} else if (strcmp(scelta, "2") == 0) {

				controllo_stato_backup = controllo_backup(
						controllo_stato_backup);

				if (controllo_stato_backup == 0) {

					printf(
							"\n\n\t\t +++++++++++++++++++++++++ NESSUN BACKUP PRESENTE +++++++++++++++++++++++++ \n\n ");

				} else {

					Database = RipristinoDaFile(Database);

					strcpy(scelta, "0");
				}
			}

		} while (strcmp(scelta, "0") == 1);

		/* ============================= FASE DI LOGIN ============================= */

		do {

			printf(
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ************************* STEP 2 di 2 - LOGIN UTENTE ************************ \n\n\t\t [1] LOGIN UTENTE \n\n\t\t [2] REGISTRATI");
			printf("\n\n\n\n\t\t SCELTA: ");
			scanf(" %[^\n]", scelta);

			if (strcmp(scelta, "1") == 0) {

				/* login delle credenziali dell'utente */
				Database = LoginUtente(&Database);

				strcpy(scelta, "0");

			} else if (strcmp(scelta, "2") == 0) {

				/* creazione del nuovo utente e login */
				Database = InserireUtente(Database);
				Database = LoginUtente(&Database);

				strcpy(scelta, "0");

			}

		} while (strcmp(scelta, "0") == 1);

		/* ====================================  MENU' UTENTE ==================================== */

		if (Database.Utente[Database.utenteCorrente].admin == 0) {

			do {

				logo();

				printf(
						"\n\n\t\t   [1] NUOVO BRANO \t\t [2] RICERCA BRANO\t [3] LISTA BRANI \n\n\t\t   [4] NUOVO ALBUM \t\t [5] RICERCA ALBUM\t [6] LISTA ALBUM \n\n\t\t   [7] NUOVO GENERE \t\t [8] RICERCA GENERE\t [9] LISTA GENERI \n\n\t\t   [10] NUOVA PLAYLIST\t         [11] RICERCA PLAYLIST\t [12] LISTA PLAYLIST \n\n\t\t   [13] NUOVO ARTISTA \t         [14] RICERCA ARTISTA \t [15] LISTA ARTISTI\n\n\n\t\t   [0] ESCI DAL PROGRAMMA");
				printf("\n\n\n\n\t\t   SCELTA: ");
				scanf(" %[^\n]", scelta);

				if (strcmp(scelta, "1") == 0) {

					/* Inserimento di un nuovo brano */
					Database = InserireBrano(Database);

				} else if (strcmp(scelta, "2") == 0) {

					/* ricerca di un brano all'interno del database */
					RicercaPerAnagrafico(Database);

				} else if (strcmp(scelta, "3") == 0) {

					/* visualizza la lista brani  */
					VisualizzaBrani(Database);

				} else if (strcmp(scelta, "4") == 0) {

					/* Inserimento di una nuovo album all'interno del database */
					Database = InserireAlbum(Database);

				} else if (strcmp(scelta, "5") == 0) {

					/* ricerca di un album presente nel database */
					RicercaPerAlbum(Database);

				} else if (strcmp(scelta, "6") == 0) {

					/* Ricerca del brano per titolo e anno */
					VisualizzaAlbum(Database);

				} else if (strcmp(scelta, "7") == 0) {

					/* inserimento di un nuovo genere nel database */
					Database = InserireGenere(Database);

				} else if (strcmp(scelta, "8") == 0) {

					/* ricerca del genere per nome */
					RicercaPerGenere(Database);

				} else if (strcmp(scelta, "9") == 0) {

					/* stampa della lista dei generi musicali */
					VisualizzaGeneri(Database);

				} else if (strcmp(scelta, "10") == 0) {

					/* inserimento di una nuova playlist all'interno del database */
					Database = InserirePlaylist(Database);

				} else if (strcmp(scelta, "11") == 0) {

					/* ricerca di una playlist nel sistema */
					RicercaPerPlaylist(Database);

				} else if (strcmp(scelta, "12") == 0) {

					/* visualizza la lista playlist */
					VisualizzaPlaylist(Database);

				} else if (strcmp(scelta, "13") == 0) {

					/* inserisce un nuovo artista nel database*/
					Database = InserireArtista(Database);

				} else if (strcmp(scelta, "14") == 0) {

					/* ricerca un artista presente nel database*/
					RicercaPerArtista(Database);

				} else if (strcmp(scelta, "15") == 0) {

					/* visualizza la lista artisti presenti nel database */
					VisualizzaArtisti(Database);
				}

			} while (strcmp(scelta, "0") == 1);

			/* ============================= MENU' ADMIN ============================= */

		} else if (Database.Utente[Database.utenteCorrente].admin == 1) {

			do {

				logo();

				printf(
						"\n\n\n [1]  NUOVO BRANO \t [2]  CANCELLA BRANO \t [3]  MODIFICA BRANO \t [4]  RICERCA BRANO \t [5]  LISTA BRANI \n\n [6]  NUOVO ALBUM \t [7]  CANCELLA ALBUM \t [8]  MODIFICA ALBUM \t [9]  RICERCA ALBUM \t [10] LISTA ALBUM \n\n [11] NUOVO ARTISTA \t [12] CANCELLA ARTISTA \t [13] MODIFICA ARTISTA \t [14] RICERCA ARTISTA \t [15] LISTA ARTISTI \n\n [16] NUOVO GENERE \t [17] CANCELLA GENERE \t [18] MODIFICA GENERE \t [19] RICERCA GENERE \t [20] LISTA GENERI\n\n [21] NUOVA PLAYLIST\t [22] CANCELLA PLAYLIST  [23] MODIFICA PLAYLIST  [24] RICERCA PLAYLIST \t [25] LISTA PLAYLIST \n\n [26] NUOVO UTENTE \t [27] CANCELLA UTENTE \t [28] MODIFICA UTENTE \t [29] RICERCA UTENTE \t [30] LISTA UTENTI \n\n [0] ESCI");
				printf("\n\n\n  SCELTA: ");
				scanf(" %[^\n]", scelta);

				if (strcmp(scelta, "1") == 0) {

					/* inserimento di un brano dal database */
					Database = InserireBrano(Database);

				} else if (strcmp(scelta, "2") == 0) {

					/* cancellazione di un  brano */
					Database = CancellareBrano(Database);

				} else if (strcmp(scelta, "3") == 0) {

					/* modifica di un brano presente nel database */
					Database = ModificareBrano(Database);

				} else if (strcmp(scelta, "4") == 0) {

					/* ricerca di un brano presente nel database */
					RicercaPerAnagrafico(Database);

				} else if (strcmp(scelta, "5") == 0) {

					/* visualizazzione di tutti i brani */
					VisualizzaBrani(Database);

				} else if (strcmp(scelta, "6") == 0) {

					/* Inserimento di un nuovo album nel database */
					Database = InserireAlbum(Database);

				} else if (strcmp(scelta, "7") == 0) {

					/* cancellazione di un album presente nel database */
					Database = CancellareAlbum(Database);

				} else if (strcmp(scelta, "8") == 0) {

					/* modifica di un album presente nel database */
					Database = ModificareAlbum(Database);

				} else if (strcmp(scelta, "9") == 0) {

					/* ricerca di un album presente nel database */
					RicercaPerAlbum(Database);

				} else if (strcmp(scelta, "10") == 0) {

					/* visualizza la lista album */
					VisualizzaAlbum(Database);

				} else if (strcmp(scelta, "11") == 0) {

					/* Inserire un nuovo artista nel database */
					Database = InserireArtista(Database);

				} else if (strcmp(scelta, "12") == 0) {

					/* Cancellare un artista dal database */
					Database = CancellareArtista(Database);

				} else if (strcmp(scelta, "13") == 0) {

					/* modifica di un artista del database */
					Database = ModificareArtista(Database);

				} else if (strcmp(scelta, "14") == 0) {

					/* ricerca di un artista presente nel database */
					RicercaPerArtista(Database);

				} else if (strcmp(scelta, "15") == 0) {

					/* visualizza la lista artisti */
					VisualizzaArtisti(Database);

				} else if (strcmp(scelta, "16") == 0) {

					/* inserimento di un nuovo genere all'interno del database */
					Database = InserireGenere(Database);

				} else if (strcmp(scelta, "17") == 0) {

					/* cancellazione  di un genere presente nel database */
					Database = CancellareGenere(Database);

				} else if (strcmp(scelta, "18") == 0) {

					/* modificare un genere presente nel database */
					Database = ModificareGenere(Database);

				} else if (strcmp(scelta, "19") == 0) {

					/* ricerca di un  genere all'interno del database */
					RicercaPerGenere(Database);

				} else if (strcmp(scelta, "20") == 0) {

					/* visualizza la lista dei generi musicali presenti nel database */
					VisualizzaGeneri(Database);

				} else if (strcmp(scelta, "21") == 0) {

					/* inserimento di una nuova playlist all'interno del database */
					Database = InserirePlaylist(Database);

				} else if (strcmp(scelta, "22") == 0) {

					/* cancellazione di una playlsit presente nel database */
					Database = CancellarePlaylist(Database);

				} else if (strcmp(scelta, "23") == 0) {

					/* modifica di una playlist presente nel database */
					Database = ModificarePlaylist(Database);

				} else if (strcmp(scelta, "24") == 0) {

					/* ricerca di una playlist presente nel sistema*/
					RicercaPerPlaylist(Database);

				} else if (strcmp(scelta, "25") == 0) {

					/* visualizza una playlist presente nel sistema*/
					VisualizzaPlaylist(Database);

				} else if (strcmp(scelta, "26") == 0) {

					/*inserisci un nuovo utente nel database */
					Database = InserireUtente(Database);

				} else if (strcmp(scelta, "27") == 0) {

					/* cancella un utente presente nel database*/
					Database = CancellareUtente(Database);

				} else if (strcmp(scelta, "28") == 0) {

					/*modifica i dati di un utente presente nel database */
					Database = ModificareUtente(Database);

				} else if (strcmp(scelta, "29") == 0) {

					/* ricerca un utente presente nel database*/
					RicercaPerUtente(Database);

				} else if (strcmp(scelta, "30") == 0) {

					/* visualizza la lista di utenti presenti nel database*/
					VisualizzaUtenti(Database);

				}

			} while (strcmp(scelta, "0") == 1);

		}

		/* ================================ FASE DI SALVATAGGIO ================================== */

		/* salvataggio sui diversi file di tutto il database */

		SalvataggioSuFile(Database);

		/* ================================ FASE DI BACKUP ==================================== */

		do {

			printf(
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ######################### VUOI EFFETTUARE UN BACKUP ? ######################## \n\n\t\t [1] SI \n\n\t\t [2] NO \n\n");
			printf("\n\n\t\t SCELTA: ");
			scanf(" %[^\n]", scelta);

			if (strcmp(scelta, "1") == 0) {

				BackupSuFile(Database);

				strcpy(scelta, "0");

			} else if (strcmp(scelta, "2") == 0) {

				strcpy(scelta, "0");
			}

		} while (strcmp(scelta, "0") == 1);

	}

	/* ============================= FINE ============================== */

	printf("\n\n\n\n\n\t\t");
	system("pause");

	return 0;
}

