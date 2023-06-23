#pragma once

#include "ApplicationBase.h"

class APPLICATIONLAYER_EXPORT ApplicationFactory final
{
public:
    static ApplicationFactory& instance();

    AppPtr createApp(const std::string& type);

    AppPtr createApp(const std::string& type, const std::string& name);

private:
    ApplicationFactory() {}
};