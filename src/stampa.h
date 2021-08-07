#ifndef STAMPA_H_INCLUDED
#define STAMPA_H_INCLUDED

#include "MusicProject.h"


// logo del progetto

void logo();

/* funzioni di visualizazzione delle tabelle  a video */

void VisualizzaBrani( database Database );

void VisualizzaAlbum( database Database );

void VisualizzaArtisti( database Database );

void VisualizzaPlaylist( database Database );

void VisualizzaUtenti( database Database );

void VisualizzaGeneri( database Database );


/* stampa delle info della singola struttura del database */

void StampareInfoBrano( database Database , int IdBrano );

void StampareInfoAlbum( database Database , int IdAlbum );

void StampareInfoGenere( database Database , int idGenere );

void StampareInfoArtista( database Database , int IdArtista );

void StampareInfoPlaylist( database Database , int IdPlaylist );

void StampareInfoUtente(database  Database ,int IdUtente );




#endif // STAMPA_H_INCLUDED
