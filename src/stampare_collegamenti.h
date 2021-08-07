

#ifndef STAMPARE_COLLEGAMENTI_H_
#define STAMPARE_COLLEGAMENTI_H_

#include "MusicProject.h"


/* funzioni di visualizazzione dei collegamenti  */

void VisualizzaBranoArtista( database Database );
void VisualizzaBranoAlbum( database Database );
void VisualizzaBranoGenere( database Database );
void VisualizzaPlaylistBrano( database Database );

// funzioni di stampa delle info dei collegamenti del brano con le altre tabelle

void StampareInfoCollegamentiBrano( database Database , int IdBrano );
void StamapareInfoBranoAlbum( database Database , int IdBrano );
void StampareInfoBranoGenere(database Database ,int IdBrano );
void StampareInfoBranoArtista( database Database ,int IdBrano );
void StampareInfoBranoPlaylist( database Database , int IdBrano );

/* stampa dei collegamenti album - brani */
void StampareInfoCollegamentiAlbum( database Database , int IdAlbum );

/* stampa dei collegamenti artista - brani */
void StampareInfoCollegamentiArtista( database Database , int IdArtista );

/* stampa dei collegamenti genere brani */
void StampareInfoCollegamentiGenere( database Database , int IdGenere );

/* stampa del collegamenti playlist-brani */
void StampareInfoCollegamentiPlaylist( database Database , int IdPlaylist );



#endif /* STAMPARE_COLLEGAMENTI_H_ */
