#ifndef QUA_ZIPFILEINFO_H
#define QUA_ZIPFILEINFO_H

/*
Copyright (C) 2005-2014 Sergey A. Tachenov

This file is part of QuaZIP.

QuaZIP is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

QuaZIP is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with QuaZIP.  If not, see <http://www.gnu.org/licenses/>.

See COPYING file for the full LGPL text.

Original ZIP package is copyrighted by Gilles Vollant and contributors,
see quazip/(un)zip.h files for details. Basically it's the zlib license.
*/

#include <QByteArray>
#include <QDateTime>
#include <QFile>

#include "quazip_global.h"

/// Information about a file inside archive.
/** Call QuaZip::getCurrentFileInfo() or QuaZipFile::getFileInfo() to
 * fill this structure. */
struct QUAZIP_EXPORT QuaZipFileInfo {
  /// File name.
  QString name;
  /// Version created by.
  quint16 versionCreated;
  /// Version needed to extract.
  quint16 versionNeeded;
  /// General purpose flags.
  quint16 flags;
  /// Compression method.
  quint16 method;
  /// Last modification date and time.
  QDateTime dateTime;
  /// CRC.
  quint32 crc;
  /// Compressed file size.
  quint32 compressedSize;
  /// Uncompressed file size.
  quint32 uncompressedSize;
  /// Disk number start.
  quint16 diskNumberStart;
  /// Internal file attributes.
  quint16 internalAttr;
  /// External file attributes.
  quint32 externalAttr;
  /// Comment.
  QString comment;
  /// Extra field.
  QByteArray extra;
  /// Get the file permissions.
  /**
    Returns the high 16 bits of external attributes converted to
    QFile::Permissions.
    */
  QFile::Permissions getPermissions() const;
};

/// Information about a file inside archive (with zip64 support).
/** Call QuaZip::getCurrentFileInfo() or QuaZipFile::getFileInfo() to
 * fill this structure. */
struct QUAZIP_EXPORT QuaZipFileInfo64 {
  /// File name.
  QString name;
  /// Version created by.
  quint16 versionCreated;
  /// Version needed to extract.
  quint16 versionNeeded;
  /// General purpose flags.
  quint16 flags;
  /// Compression method.
  quint16 method;
  /// Last modification date and time.
  QDateTime dateTime;
  /// CRC.
  quint32 crc;
  /// Compressed file size.
  quint64 compressedSize;
  /// Uncompressed file size.
  quint64 uncompressedSize;
  /// Disk number start.
  quint16 diskNumberStart;
  /// Internal file attributes.
  quint16 internalAttr;
  /// External file attributes.
  quint32 externalAttr;
  /// Comment.
  QString comment;
  /// Extra field.
  QByteArray extra;
  /// Get the file permissions.
  /**
    Returns the high 16 bits of external attributes converted to
    QFile::Permissions.
    */
  QFile::Permissions getPermissions() const;
  /// Converts to QuaZipFileInfo
  /**
    If any of the fields are greater than 0xFFFFFFFFu, they are set to
    0xFFFFFFFFu exactly, not just truncated. This function should be mainly used
    for compatibility with the old code expecting QuaZipFileInfo, in the cases
    when it's impossible or otherwise unadvisable (due to ABI compatibility
    reasons, for example) to modify that old code to use QuaZipFileInfo64.

    \return \c true if all fields converted correctly, \c false if an overflow
    occured.
    */
  bool toQuaZipFileInfo(QuaZipFileInfo &info) const;
};

#endif
