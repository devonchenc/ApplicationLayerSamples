#pragma once

#include "ApplicationBase.h"

class AutoFrequencyAppPrivate;

class APPLICATIONLAYER_EXPORT AutoFrequencyApp : public ApplicationBase
{
public:
    AutoFrequencyApp(const std::string& name);

    bool init() override;

    // 显示后处理数据
    void showProcessedData() override;

    // 保存后处理数据
    bool saveProcessedData() override;
    bool saveProcessedData(const std::string& fileName) override;

    // 返回是否搜索成功
    bool searchSucceeded() const;

    // 返回搜索的中心频率
    std::optional<double> frequencyResult() const;

    // 返回FFT数组
    const std::shared_ptr<Point3[]>& FFTData() const;

    // 返回FFT后数值对应的频率数组
    const std::shared_ptr<double[]>& frequencyData() const;

private:
    APP_DECLARE_PRIVATE(AutoFrequencyApp)
};