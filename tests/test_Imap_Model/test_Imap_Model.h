/* Copyright (C) 2010 Jan Kundrát <jkt@gentoo.org>

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

#ifndef TEST_IMAP_MODEL
#define TEST_IMAP_MODEL

#include "Imap/Model/Model.h"
#include "Streams/SocketFactory.h"


/** @short Unit tests for the Imap::Mailbox::Model

The purpose of these unit tests is to verify the high-level operation of the
Imap::Mailbox::Model, for example mailbox re-synchronization.
*/
class ImapModelTest : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void cleanup();
    void initTestCase();

    void testSyncMailbox();
private:
    Imap::Mailbox::Model* model;
    Imap::Mailbox::CachePtr cache;
    Imap::Mailbox::FakeSocketFactory* factory;

};

#endif
