/*
 * Copyright (C) 2021 CutefishOS Team.
 *
 * Author:     rekols <revenmartin@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DOCKSETTINGS_H
#define DOCKSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QFileSystemWatcher>

class DockSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Direction direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int iconSize READ iconSize WRITE setIconSize NOTIFY iconSizeChanged)
    Q_PROPERTY(int edgeMargins READ edgeMargins WRITE setEdgeMargins)
    Q_PROPERTY(bool roundedWindowEnabled READ roundedWindowEnabled WRITE setRoundedWindowEnabled NOTIFY roundedWindowEnabledChanged)

public:
    enum Direction {
        Left = 0,
        Bottom,
        Right
    };
    Q_ENUMS(Direction)

    enum Visibility {
        AlwaysVisible = 0,
        AutoHide,
        AlwaysHide
    };
    Q_ENUMS(Visibility)

    static DockSettings *self();
    explicit DockSettings(QObject *parent = nullptr);

    int iconSize() const;
    void setIconSize(int iconSize);

    Direction direction() const;
    void setDirection(const Direction &direction);

    Visibility visibility() const;
    void setVisibility(const Visibility &visibility);

    int edgeMargins() const;
    void setEdgeMargins(int edgeMargins);

    bool roundedWindowEnabled() const;
    void setRoundedWindowEnabled(bool enabled);

private slots:
    void onConfigFileChanged();

signals:
    void iconSizeChanged();
    void directionChanged();
    void visibilityChanged();
    void roundedWindowEnabledChanged();

private:
    int m_iconSize;
    int m_edgeMargins;
    bool m_roundedWindowEnabled;
    Direction m_direction;
    Visibility m_visibility;
    QSettings *m_settings;
    QFileSystemWatcher *m_fileWatcher;
};

#endif // DOCKSETTINGS_H
