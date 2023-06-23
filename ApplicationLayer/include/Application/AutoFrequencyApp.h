#pragma once

#include "ApplicationBase.h"

class AutoFrequencyAppPrivate;

class APPLICATIONLAYER_EXPORT AutoFrequencyApp : public ApplicationBase
{
public:
    AutoFrequencyApp(const std::string& name);

    bool init() override;

    // ��ʾ��������
    void showProcessedData() override;

    // �����������
    bool saveProcessedData() override;
    bool saveProcessedData(const std::string& fileName) override;

    // �����Ƿ������ɹ�
    bool searchSucceeded() const;

    // ��������������Ƶ��
    std::optional<double> frequencyResult() const;

    // ����FFT����
    const std::shared_ptr<Point3[]>& FFTData() const;

    // ����FFT����ֵ��Ӧ��Ƶ������
    const std::shared_ptr<double[]>& frequencyData() const;

private:
    APP_DECLARE_PRIVATE(AutoFrequencyApp)
};