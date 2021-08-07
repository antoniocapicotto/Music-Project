

#ifndef BACKUP_COLLEGAMENTI_H_
#define BACKUP_COLLEGAMENTI_H_

#include "MusicProject.h"

/* caricamento dei collegamenti dai file di testo */

database CaricareBranoArtista( database Database );

database CaricareBranoAlbum( database Database );

database CaricareBranoGenere( database Database );

database CaricarePlaylistBrano( database Database );


/* salvataggio dei file dei diversi collegamanti nel database */

void SalvareFileBranoArtista( database Database );

void SalvareFileBranoAlbum( database Database );

void SalvareFileBranoGenere( database Database );

void SalvareFilePlaylistBrano( database Database );


/* ripristino dei collegamenti dai file di backup */

database RipristinoBranoArtista( database Database );

database RipristinoBranoAlbum( database Database );

database RipristinoBranoGenere( database Database );

database RipristinoPlaylistBrano( database Database );

/* funzioni di backup dei diversi collegamenti sui file di backup */

void BackupBranoArtista( database Database );

void BackupBranoAlbum( database Database );

void BackupBranoGenere( database Database );

void BackupPlaylistBrano( database Database );





#endif /* BACKUP_COLLEGAMENTI_H_ */
