#pragma once

#include "core/types.h"

#include "common/qt/gui/base/table_model.h"

namespace fastoredis
{
    class KeyTableItem
            : public common::qt::TableItem
    {
    public:
        enum eColumn
        {
            kKey = 0,
            kType = 1,
            kCountColumns = 2
        };

        KeyTableItem(const NKey& key);
        QString key() const;
        QString typeText() const;
        common::Value::Type type() const;

    private:
        const NKey key_;
    };

    class KeysTableModel
            : public common::qt::TableModel
    {
        Q_OBJECT
    public:
        KeysTableModel(QObject *parent = 0);
        virtual ~KeysTableModel();

        virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
        virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

        virtual int columnCount(const QModelIndex& parent) const;
        void clear();
    };
}


