#pragma once

#include "ApplicationBase.h"

//! ����Ӧ�ù�����
class APPLICATIONLAYER_EXPORT ApplicationFactory final
{
public:
    static ApplicationFactory& instance();

    //! ����Ӧ��
    AppPtr createApp(const std::string& type);

    //! ����Ӧ��
    AppPtr createApp(const std::string& type, const std::string& name);

private:
    ApplicationFactory() {}
};