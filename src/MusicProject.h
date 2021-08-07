#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

//Librerie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//Costanti
#define SENTINELLA -1
#define FINESTRINGA '\0'
#define VERO 1
#define FALSO 0


//Strutture
typedef struct {

	int     idBrano;                          //  Identificativo univoco del brano

	char    titolo[ 30 ];                     //  Titolo del brano

	int     durata;                           //  Durata del brano in secondi

	int     anno;                             //  Anno di uscita del brano

	int     ascolti;                          //  Numero di ascolti

} Brano;                                       // Questa è la struttura dati di Brano


typedef struct {

	int     idArtista;                         //  Identificativo univoco dell'artista

	char    nome[ 30 ];                        //  Nome dell'artista

	char    cognome[ 30 ];                     //  Cognome dell'artista

    char    nomeArte[ 30 ];                    //  Nome d'arte dell'artista

} Artista;                                      //  Struttura dati dell'artista


typedef struct {

    int     idBrano;                         // Identificativo del brano

    int     idArtista;                       // Identificativo dell'artista

} BranoArtista;                               // Struttura dati del BranoArtista


typedef struct {

	int     idAlbum;                            //  Identificativo univoco dell'artista

	char    titolo[ 30 ];                       //  titolo dell'album

	int     anno;                               //  Anno di uscita dell'album

} Album;                                        //  Struttura dati dell'album


typedef struct {

    int    idAlbum;                             // Identificativo dell'album

    int    idBrano;                             // Identificativo del brano

} BranoAlbum;                                   // Struttura dati del branoAlbum


typedef struct {

	int     idGenere;                           // Codice univoco del genere

	char    nome[ 30 ];                         // Nome del genere musicale

} Genere;                                       //Struttura dati del genere


typedef struct {

    int     idBrano;                             // Identificativo del brano

    int     idGenere;                            // Identificativo del genere

} BranoGenere;                                   // Struttura dati del BranoGenere


typedef struct {

    int     idPlaylist;                      // Identificativo della playlist

    char    nome[ 30 ];                      // Nome della playlist

    char    descrizione[ 250 ];              // Descrizione playlist

    int     pubblica;                        // Tipologia playlist

} Playlist;                                  // Struttura dati della playlist


typedef struct {

    int     idPlaylist;                      // Identificativo della playlist

    int     idBrano;                         // Identificativo del brano

} PlaylistBrano;                             // Struttura dati della PlylistBrano


typedef struct {

    int     idUtente;                        // Identificativo dell’utente

    char    nomeUtente[ 60 ];                // Nominativo dell'utente

    char    password[ 60 ];                  // Password dell'utente

    int     admin;                           // Controllo ruolo utente

} Utente;                                    // Struttura dati dell'utente


typedef struct {

    int             utenteCorrente;          // Identificativo dell'utente corrente

    Brano           Brano         [ 30 ];    // Tabella brani

    Artista         Artista       [ 30 ];    // Tabella artista

    BranoArtista    BranoArtista  [ 30 ];    // Tabella che indica la relazione tra Brano e Artista

    Album           Album         [ 30 ];    // Tabella Album

    BranoAlbum      BranoAlbum    [ 30 ];    // Tabella che indica la relazione tra Brano e Album

    Genere          Genere        [ 30 ];    // Tabella Genere

    BranoGenere     BranoGenere   [ 30 ];    // Tabella che indica la relazione tra Brano e Genere

    Playlist        Playlist      [ 30 ];    // Tabella Playlist

    PlaylistBrano   PlaylistBrano [ 30 ];    // Tabella che indica la relazione tra Plylist e Brano

    Utente          Utente        [ 30 ];    // Tabella Utente

    int             UltimoEsito;             // Intero >= 0, se esito = 0 vuol dire che l'operazione è andata a buon fine
                                             // altrimenti esito rappresenta il codice dell'errore che si è verificato


} database;                                  // Struttura dati del Database




#include "backup.h"

#include "stampa.h"

#include "ricerca.h"

#include "inserimento.h"

#include "modifica.h"

#include "cancellazione.h"

#include "collegamenti.h"


#endif // MAIN_H_INCLUDED
