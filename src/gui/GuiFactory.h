#pragma once

#include <QIcon>
#include <QFont>
#include <QMovie>
#include "global/global.h"
#include "core/ConnectionTypes.h"
#include "common/patterns/singleton_pattern.hpp"

namespace fastoredis
{
    class GuiFactory
            : public common::patterns::lazy_singleton<GuiFactory>
    {
    public:
        typedef common::patterns::lazy_singleton<GuiFactory> base_class;
        friend class common::patterns::lazy_singleton<GuiFactory>;
        const QIcon &openIcon() const;
        const QIcon &mainWindowIcon() const;
        const QIcon &connectIcon() const;
        const QIcon &disConnectIcon() const;
        const QIcon &redisConnectionIcon() const;
        const QIcon &serverIcon() const;
        const QIcon &addIcon() const;
        const QIcon &removeIcon() const;
        const QIcon &editIcon() const;
        const QIcon &messageBoxInformationIcon() const;
        const QIcon &executeIcon() const;
        const QIcon &stopIcon() const;
        const QIcon &timeIcon() const;
        const QIcon &databaseIcon() const;
        QFont font() const;
        const QIcon &getIcon(connectionTypes type) const;
        const QIcon &getIcon(fastoType type) const;
        const QIcon &loadIcon() const;
        const QIcon &saveIcon() const;
        const QIcon &saveAsIcon() const;
        const QIcon &textIcon() const;
        const QIcon &tableIcon() const;
        const QIcon &treeIcon() const;
        const QString &loadingPathFilePath() const;
    };
}
