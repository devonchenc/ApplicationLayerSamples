#include <iostream>

#include "ApplicationLayer.h"
#include "Application/PulseWidthFinderApp.h"

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
    std::string typeName = "PulseWidthFinder";
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

        //  获取后处理数据
        std::shared_ptr<PulseWidthFinderApp> pwfApp = std::dynamic_pointer_cast<PulseWidthFinderApp>(app);
        const std::vector<DoublePoint>& amplitudeData = pwfApp->amplitudeData();
        // 获取正弦拟合参数 y = A * cos(Omega * x + Phi) + K
        std::optional<double> A = pwfApp->fittedA();
        std::optional<double> omega = pwfApp->fittedOmega();
        std::optional<double> phi = pwfApp->fittedPhi();
        std::optional<double> k = pwfApp->fittedK();

        // 获取拟合结果
        std::optional<double> pw90Result = pwfApp->pw90Result();
        std::optional<double> pw180Result = pwfApp->pw180Result();

        // 保存时域数据
        std::string timeDomainDataName = "timeDomain.csv";
        app->saveTimeDomainData(timeDomainDataName);
        // 保存后处理数据
        std::string processedDataName = "processed.csv";
        app->saveProcessedData(processedDataName);
    }

    ApplicationLayer::instance().exit();

    return 0;
}
