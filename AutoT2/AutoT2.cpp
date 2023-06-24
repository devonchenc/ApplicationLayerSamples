#include <iostream>

#include "ApplicationLayer.h"
#include "Application/AutoT2App.h"

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
    std::string typeName = "AutoT2";
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

        // 保存时域数据
        std::string timeDomainDataName = "timeDomain.csv";
        app->saveTimeDomainData(timeDomainDataName);
    }

    ApplicationLayer::instance().exit();
}

