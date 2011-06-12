/**
 *
 *  This file is part of the kuiviewer package
 *  Copyright (c) 2003 Richard Moore <rich@kde.org>
 *  Copyright (c) 2003 Ian Reinhart Geiser <geiseri@kde.org>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License version 2 as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this library; see the file COPYING.LIB.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 **/

#ifndef KUIVIEWERPART_H
#define KUIVIEWERPART_H

#include <tqguardedptr.h>
#include <kparts/part.h>

class TQWidget;
class KURL;
class TQVBox;
class KAboutData;
class KListAction;
class KListView;

/**
 * This is a "Part".  It that does all the real work in a KPart
 * application.
 *
 * @short Main Part
 * @author Richard Moore <rich@kde.org>
 * @version 0.1
 */
class KUIViewerPart : public KParts::ReadOnlyPart
{
    Q_OBJECT
  TQ_OBJECT
public:
    /**
     * Default constructor
     */
    KUIViewerPart(TQWidget *tqparentWidget, const char *widgetName,
                    TQObject *tqparent, const char *name, const TQStringList &args);

    /**
     * Destructor
     */
    virtual ~KUIViewerPart();

    static KAboutData *createAboutData();

public slots:
     bool openURL( const KURL& );
     void slotStyle(int);
     void slotGrab();
     void updateActions();

protected:
    /**
     * This must be implemented by each part
     */
    virtual bool openFile();

private:
    TQVBox *m_widget;
    TQGuardedPtr<TQWidget> m_view;
    KListAction *m_style;
    KAction *m_copy;
};

#endif // KUIVIEWERPART_H

