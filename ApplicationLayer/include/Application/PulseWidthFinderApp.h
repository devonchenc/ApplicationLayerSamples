#pragma once

#include "ApplicationBase.h"

class PulseWidthFinderAppPrivate;

class APPLICATIONLAYER_EXPORT PulseWidthFinderApp : public ApplicationBase
{
public:
    PulseWidthFinderApp(const std::string& name);

    bool init() override;

    // 保存配置文件
    void saveConfig() override;

    // 准备开始扫描
    void prepareScan() override;

    // 显示后处理数据
    void showProcessedData() override;

    // 保存后处理数据
    bool saveProcessedData(const std::string& fileName) override;

    // 返回一系列回波信号幅值的数组
    const std::vector<DoublePoint>& amplitudeData() const;

    // 返回根据拟合曲线离散的数据
    const std::vector<DoublePoint>& fittedData() const;

    // 返回拟合参数 y = A * cos(Omega * x + Phi) + K
    std::optional<double> fittedA() const;
    std::optional<double> fittedOmega() const;
    std::optional<double> fittedPhi() const;
    std::optional<double> fittedK() const;

    // 返回四个拟合参数
    std::tuple<std::optional<double>, std::optional<double>, std::optional<double>, std::optional<double>> fittedResult() const;

    // 返回拟合结果pw90和pw180
    std::optional<double> pw90Result() const;
    std::optional<double> pw180Result() const;

private:
    APP_DECLARE_PRIVATE(PulseWidthFinderApp)
};
