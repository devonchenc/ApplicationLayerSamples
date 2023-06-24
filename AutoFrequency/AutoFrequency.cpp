#include <iostream>
#include <fstream>
#include <cassert>

#include "ApplicationLayer.h"
#include "Application/AutoFrequencyApp.h"

void func(int count, int total, const std::shared_ptr<const Point3[]>& timeDomainData, const std::shared_ptr<const double[]>& timeArray, int length)
{
    std::cout << "Time domain data acquired " << count << "/" << total << std::endl;
    // 此处添加处理代码
}

int main()
{
    // 初始化应用层
    ApplicationLayer::instance().init();

    // 创建应用
    std::string typeName = "AutoFrequency";
    AppPtr app = ApplicationFactory::instance().createApp(typeName);
    if (!app)
    {
        std::cout << "Failed to create applicaition " << typeName << std::endl;
        ApplicationLayer::instance().exit();
        return false;
    }

    // 设置应用工作目录
    std::string workDirectory = "D:/";
    app->setWorkDirectory(workDirectory);

    // 设置采集中的回调函数
    app->setAcquireCallback(func);

    // 应用初始化
    if (!app->init())
    {
        std::cout << "Failed to init applicaition " << typeName << std::endl;
        ApplicationLayer::instance().exit();
        return false;
    }

    // 开始准备扫描
    app->prepareScan();

    // 执行扫描
    if (app->executeScan())
    {
        //  获取时域数据
        const int length = app->dataLength();
        const std::shared_ptr<Point3[]>& timeDomainData = app->timeDomainData();
        const std::shared_ptr<double[]>& timeArray = app->timeArray();
        // 将其中的时间数组保存为文件
        std::fstream file;
        file.open("timeArray.raw", std::ios_base::out | std::ios_base::binary);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char*>(timeArray.get()), length * sizeof(double));
            file.close();
        }

        //  获取后处理数据
        std::shared_ptr<AutoFrequencyApp> autoFrequencyApp = std::dynamic_pointer_cast<AutoFrequencyApp>(app);
        const std::shared_ptr<Point3[]>& fftData = autoFrequencyApp->FFTData();
        const std::shared_ptr<double[]>& frequencyData = autoFrequencyApp->frequencyData();

        if (autoFrequencyApp->searchSucceeded())
        {
            assert(autoFrequencyApp->frequencyResult().has_value());
            std::cout << autoFrequencyApp->frequencyResult().value() << std::endl;
        }

        // 保存时域数据
        std::string timeDomainDataName = "timeDomain.csv";
        app->saveTimeDomainData(timeDomainDataName);
        // 保存后处理数据
        std::string processedDataName = "processed.csv";
        app->saveProcessedData(processedDataName);
    }

    // 退出应用层
    ApplicationLayer::instance().exit();

    return 0;
}
