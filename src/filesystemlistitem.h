/*
 * Copyright (C) 2020 KylinSoft Co., Ltd.
 *
 * Authors:
 *  Kobe Lee    xiangli@ubuntukylin.com/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef FILESYSTEMLISTITEM_H
#define FILESYSTEMLISTITEM_H

#include <QObject>
#include <QPainter>
#include <QPen>
#include <qgsettings.h>

#include "filesystemdata.h"
#include "shell/customstyle.h"
#include "../shell/macro.h"

class FileSystemListItem : public QObject
{
    Q_OBJECT
    
public:
    FileSystemListItem(FileSystemData *info);
    ~FileSystemListItem();
    
    bool isSameItem(FileSystemListItem *item);
    void drawCellBackground(QRect rect, QPainter *painter, int level);
    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect, QString currentTheme);
    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect, bool isSeparator);

    QString getDeviceName() const;
    QString getDirectory() const;

    void initThemeMode();
    void initFontSize();
    
private:
    FileSystemData *m_data;
    int iconSize;
    int padding;
    int textPadding;

    int fontSize;

    QGSettings * qtSettings;
    QGSettings *fontSettings;
    QString currentThemeMode;
};

#endif // FILESYSTEMLISTITEM_H
