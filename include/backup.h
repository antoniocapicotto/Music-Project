#ifndef BACKUP_H_INCLUDED
#define BACKUP_H_INCLUDED

#include "MusicProject.h"

/* =============  CARICAMENTO ==========================*/

int controllo_caricamento_file(int flag);

/* caricamento dei dati nella database dai vari file di testo */

database CaricareSuFile(database Database);

database CaricareBrani(database Database);
database CaricareAlbum(database Database);
database CaricareArtisti(database Database);
database CaricarePlaylist(database Database);
database CaricareUtenti(database Database);
database CaricareGeneri(database Database);

/* ================= SALVATAGGIO ==============  */

void SalvataggioSuFile(database Database);

/* Funzioni di salvataggio su file dei diversi dati del database */

void SalvareFileBrani(database Database);
void SalvareFileAlbum(database Database);
void SalvareFileArtisti(database Database);
void SalvareFileGeneri(database Database);
void SalvareFilePlaylist(database Database);
void SalvareFileUtenti(database Database);

/* ============================  RIPRISTINO  ======================= */

database RipristinoDaFile(database Database);

/* ripristino dei dati dai file di backup */

database RipristinoBrani(database Database);
database RipristinoAlbum(database Database);
database RipristinoArtisti(database Database);
database RipristinoPlaylist(database Database);
database RipristinoUtenti(database DataBase);
database RipristinoGeneri(database Database);

/* =========================  BACKUP =============================== */

int controllo_backup(int controllo);

void BackupSuFile(database Database);

/* funzioni di backup sui file di backup */

void BackupBrani(database Database);
void BackupAlbum(database Database);
void BackupArtisti(database Database);
void BackupGeneri(database Database);
void BackupPlaylist(database Database);
void BackupUtenti(database Database);

#endif // BACKUP_H_INCLUDED
