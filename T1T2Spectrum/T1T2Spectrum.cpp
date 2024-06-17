#include <iostream>

#include "ApplicationLayer.h"
#include "Application/T1T2SpectrumApp.h"

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
    std::string typeName = "T1T2Spectrum";
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
        const std::shared_ptr<Point3[]> timeDomainData = app->timeDomainData();
        const std::shared_ptr<double[]> timeArray = app->timeArray();

        //  获取后处理数据
        std::shared_ptr<T1T2SpectrumApp> spectrumApp = std::dynamic_pointer_cast<T1T2SpectrumApp>(app);
        const std::vector<std::vector<Point3>>& amplitudeVec = spectrumApp->amplitudeTotalData();
        const std::vector<std::vector<float>>& timeVec = spectrumApp->timeTotalData();
        for (int i = 0; i < amplitudeVec.size(); i++)
        {
            for (int j = 0; j < amplitudeVec[i].size(); j++)
            {
                // 使用amplitudeVec[i][j]或timeVec[i][j]可以访问单个数据
                std::cout << amplitudeVec[i][j].ampl << std::endl;
            }
        }
    }

    ApplicationLayer::instance().exit();

    return 0;
}