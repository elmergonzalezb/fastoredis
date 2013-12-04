#pragma once

#include "global/global.h"
#include "common/qt_helper/utils_qt.h"

namespace fastoredis
{
    namespace EventsInfo
    {
        struct EventInfoBase
                : public common::utils_qt::EventInfo<error::ErrorInfo>
        {
            typedef common::utils_qt::EventInfo<error::ErrorInfo> base_class;
            EventInfoBase(const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(er){}
        };

        struct ConnectInfoRequest
                : public EventInfoBase
        {
            typedef EventInfoBase base_class;
            ConnectInfoRequest(const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(er)
            {

            }
        };

        struct ConnectInfoResponce
                : ConnectInfoRequest
        {
            typedef ConnectInfoRequest base_class;
            ConnectInfoResponce(const base_class &request, const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(request)
            {
                base_class::errorInfo_ = er;
            }
            std::string _prompt;
        };

        struct DisonnectInfoRequest
                : public EventInfoBase
        {
            typedef EventInfoBase base_class;
            DisonnectInfoRequest(const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(er)
            {

            }
        };

        struct DisConnectInfoResponce
                : DisonnectInfoRequest
        {
            typedef DisonnectInfoRequest base_class;
            DisConnectInfoResponce(const base_class &request, const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(request)
            {
                base_class::errorInfo_ = er;
            }
        };

        struct ExecuteInfoRequest
                : public EventInfoBase
        {
            typedef EventInfoBase base_class;
            ExecuteInfoRequest(const std::string &text, const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(er), _text(text)
            {

            }
            const std::string _text;
        };

        struct ExecuteInfoResponce
                : ExecuteInfoRequest
        {
            typedef ExecuteInfoRequest base_class;            
            ExecuteInfoResponce(const base_class &request, const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(request), _out(FastoObject::createRoot())
            {
                base_class::errorInfo_ = er;
            }
            FastoObjectPtr _out;
        };

        struct InteruptInfoRequest
                : public EventInfoBase
        {
            typedef EventInfoBase base_class;
            InteruptInfoRequest(const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(er)
            {

            }
        };

        struct InteruptInfoResponce
                : InteruptInfoRequest
        {
            typedef InteruptInfoRequest base_class;
            InteruptInfoResponce(const base_class &request, const error::ErrorInfo &er = error::ErrorInfo())
                : base_class(request)
            {
                base_class::errorInfo_ = er;
            }
            EventInfoBase _interuptedEvent;
        };

        struct ProgressResponceInfo
        {
            ProgressResponceInfo(int pr)
                : _progress(pr){}

            const int _progress;
        };
    }
}
