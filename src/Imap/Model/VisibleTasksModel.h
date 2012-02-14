/* Copyright (C) 2006 - 2011 Jan Kundrát <jkt@gentoo.org>

   This file is part of the Trojita Qt IMAP e-mail client,
   http://trojita.flaska.net/

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or the version 3 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef IMAP_MODEL_VISIBLETASKSMODEL_H
#define IMAP_MODEL_VISIBLETASKSMODEL_H

#include <QSortFilterProxyModel>

class KDescendantsProxyModel;

namespace Imap {
namespace Mailbox {

/** @short Proxy model showing a list of tasks that are active or pending

In contrast to the full tree model, this proxy will show only those ImapTasks that somehow correspond to an activity requested by
user.  This means that auxiliary tasks like GetAnyConnectionTask, KeepMailboxOpenTask etc are not shown.

The goal is to have a way of showing an activity indication whenever the IMAP connection is "doing something".
*/
class VisibleTasksModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit VisibleTasksModel(QObject *parent, QAbstractItemModel *taskModel);
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
private:
    KDescendantsProxyModel *m_flatteningModel;
};

}
}

#endif // IMAP_MODEL_VISIBLETASKSMODEL_H
