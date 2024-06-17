#pragma once

#include "ApplicationlayerGlobal.h"
#include "Global/HardwareSettings.h"
#include "Application/ApplicationFactory.h"

class APPLICATIONLAYER_EXPORT ApplicationLayer
{
public:
    static ApplicationLayer& instance();

    void init();

    void exit();

private:
    ApplicationLayer() {}
};
