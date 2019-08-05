/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2019, Adriaan de Groot <groot@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOCALE_TRANSLATABLECONFIGURATION_H
#define LOCALE_TRANSLATABLECONFIGURATION_H

#include "DllMacro.h"

#include <QLocale>
#include <QMap>
#include <QVariant>

namespace CalamaresUtils
{
namespace Locale
{
    /** @brief A human-readable string from a configuration file
     * 
     * The configuration files can contain human-readable strings,
     * but those need their own translations and are not supported
     * by QObject::tr or anything else.
     */
    class DLLEXPORT TranslatedString
    {
    public:
        /** @brief Get all the translations connected to @p key
         */
        TranslatedString( const QVariantMap& map, const QString& key );
        /** @brief Not-actually-translated string.
         */
        TranslatedString( const QString& string );
        
        int count() const { return m_strings.count(); }
        
    private:
        // Maps locale name to human-readable string, "" is English
        QMap< QString, QString > m_strings;
    };
}  // namespace Locale
}  // namespace CalamaresUtils

#endif
