#ifndef RICERCA_H_INCLUDED
#define RICERCA_H_INCLUDED

#include "MusicProject.h"

/// ==================== UTENTE ===================== ///

database LoginUtente(database *Database);
database VerificareUtente(database *Database);

/// ===================== BRANO ====================== ///

void RicercaPerAnagrafico(database Database);
int TrovaIdBrano(database Database, char titolo[], int anno);

/// ================================== ALBUM ========================================== ///

void RicercaPerAlbum(database Database);
int TrovaIdAlbum(database Database, char titolo[], int anno);

/// ============================== ARTISTA =============================================== ///

void RicercaPerArtista(database Database);
int TrovaIdArtista(database Database, char nome[], char cognome[]);

/// ================================ GENERE ============================================ ///

void RicercaPerGenere(database Database);
int TrovaIdGenere(database Database, char nome[]);

/// ================================= PLAYLIST =================================== ///

void RicercaPerPlaylist(database Database);
int TrovaIdPlaylist(database Database, char nome[], int pubblica);

/// ================================== UTENTE ======================================= ///

void RicercaPerUtente(database Database);
int TrovaIdUtente(database Database, char username[], char password[]);

#endif // RICERCA_H_INCLUDED
