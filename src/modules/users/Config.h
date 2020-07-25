/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   SPDX-FileCopyrightText: 2020 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *   License-Filename: LICENSE
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

#ifndef USERS_CONFIG_H
#define USERS_CONFIG_H

#include <QObject>
#include <QVariantMap>

class Config : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString userShell READ userShell WRITE setUserShell NOTIFY userShellChanged )

    Q_PROPERTY( QString autologinGroup READ autologinGroup WRITE setAutologinGroup NOTIFY autologinGroupChanged )
    Q_PROPERTY( QString sudoersGroup READ sudoersGroup WRITE setSudoersGroup NOTIFY sudoersGroupChanged )

public:
    Config( QObject* parent = nullptr );
    ~Config();

    void setConfigurationMap( const QVariantMap& );

    /** @brief Full path to the user's shell executable
     *
     * Typically this will be /bin/bash, but it can be set from
     * the config file with the *userShell* setting.
     */
    QString userShell() const { return m_userShell; }

    /// The group of which auto-login users must be a member
    QString autologinGroup() const { return m_autologinGroup; }
    /// The group of which users who can "sudo" must be a member
    QString sudoersGroup() const { return m_sudoersGroup; }

public Q_SLOTS:
    /** @brief Sets the user's shell if possible
     *
     * If the path is empty, that's ok: no shell will be explicitly set,
     * so the user will get whatever shell is set to default in the target.
     *
     * The given non-empty @p path must be an absolute path (for use inside
     * the target system!); if it is not, the shell is not changed.
     */
    void setUserShell( const QString& path );

    /// Sets the autologin group; empty is ignored
    void setAutologinGroup( const QString& group );
    /// Sets the sudoer group; empty is ignored
    void setSudoersGroup( const QString& group );

signals:
    void userShellChanged( const QString& );
    void autologinGroupChanged( const QString& );
    void sudoersGroupChanged( const QString& );

private:
    QString m_userShell;
    QString m_autologinGroup;
    QString m_sudoersGroup;
};

#endif
