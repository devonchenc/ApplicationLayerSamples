#pragma once

#include "ApplicationBase.h"

class T1T2SpectrumAppPrivate;

class APPLICATIONLAYER_EXPORT T1T2SpectrumApp : public ApplicationBase
{
public:
    T1T2SpectrumApp(const std::string& name);

    bool init() override;

    // 保存配置文件
    void saveConfig() override;

    // 准备开始扫描
    void prepareScan() override;

    // 显示后处理数据
    void showProcessedData() override;

    // 保存时域数据
    bool saveTimeDomainData() override;
    bool saveTimeDomainData(const std::string& fileName) override;

    // 返回历次扫描的幅值数据
    const std::vector<std::vector<Point3>>& amplitudeTotalData() const;

    // 返回历次扫描的时间数组
    const std::vector<std::vector<float>>& timeTotalData() const;

private:
    APP_DECLARE_PRIVATE(T1T2SpectrumApp)
};
