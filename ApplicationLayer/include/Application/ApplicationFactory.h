#pragma once

#include "ApplicationBase.h"

//! 创建应用工厂类
class APPLICATIONLAYER_EXPORT ApplicationFactory final
{
public:
    static ApplicationFactory& instance();

    //! 创建应用
    AppPtr createApp(const std::string& type);

    //! 创建应用
    AppPtr createApp(const std::string& type, const std::string& name);

private:
    ApplicationFactory() {}
};