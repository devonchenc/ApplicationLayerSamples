#pragma once

#include "ApplicationBase.h"

class PulseWidthFinderAppPrivate;

class APPLICATIONLAYER_EXPORT PulseWidthFinderApp : public ApplicationBase
{
public:
    PulseWidthFinderApp(const std::string& name);

    bool init() override;

    // ���������ļ�
    void saveConfig() override;

    // ׼����ʼɨ��
    void prepareScan() override;

    // ��ʾ��������
    void showProcessedData() override;

    // �����������
    bool saveProcessedData(const std::string& fileName) override;

    // ����һϵ�лز��źŷ�ֵ������
    const std::vector<DoublePoint>& amplitudeData() const;

    // ���ظ������������ɢ������
    const std::vector<DoublePoint>& fittedData() const;

    // ������ϲ��� y = A * cos(Omega * x + Phi) + K
    std::optional<double> fittedA() const;
    std::optional<double> fittedOmega() const;
    std::optional<double> fittedPhi() const;
    std::optional<double> fittedK() const;

    // �����ĸ���ϲ���
    std::tuple<std::optional<double>, std::optional<double>, std::optional<double>, std::optional<double>> fittedResult() const;

    // ������Ͻ��pw90��pw180
    std::optional<double> pw90Result() const;
    std::optional<double> pw180Result() const;

private:
    APP_DECLARE_PRIVATE(PulseWidthFinderApp)
};
