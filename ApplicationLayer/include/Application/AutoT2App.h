#pragma once

#include "ApplicationBase.h"

class AutoT2AppPrivate;

class APPLICATIONLAYER_EXPORT AutoT2App : public ApplicationBase
{
public:
    AutoT2App(const std::string& name);

    bool init() override;

    // 保存配置文件
    void saveConfig() override;

    // 准备开始扫描
    void prepareScan() override;

    // 显示后处理数据
    void showProcessedData() override;

    // 保存后处理数据
    bool saveProcessedData(const std::string& fileName) override;

    // 抽样后的幅值数组
    const std::shared_ptr<double[]>& compressedAmpData() const;

    // 抽样后的时间数组(ms)
    const std::shared_ptr<double[]>& compressedTimeData() const;

    // 抽样后的数组长度
    int compressedLen() const;

    // 返回拟合参数 y = A * exp(-B * x) + C
    std::optional<double> fittedA() const;
    std::optional<double> fittedB() const;
    std::optional<double> fittedC() const;

    // 返回三个拟合参数
    std::tuple<std::optional<double>, std::optional<double>, std::optional<double>> fittedResult() const;

private:
    APP_DECLARE_PRIVATE(AutoT2App)
};
