#pragma once

#include "ApplicationBase.h"

class AutoT2AppPrivate;

class APPLICATIONLAYER_EXPORT AutoT2App : public ApplicationBase
{
public:
    AutoT2App(const std::string& name);

    bool init() override;

    // ���������ļ�
    void saveConfig() override;

    // ׼����ʼɨ��
    void prepareScan() override;

    // ��ʾ��������
    void showProcessedData() override;

    // �����������
    bool saveProcessedData(const std::string& fileName) override;

    // ������ķ�ֵ����
    const std::shared_ptr<double[]>& compressedAmpData() const;

    // �������ʱ������(ms)
    const std::shared_ptr<double[]>& compressedTimeData() const;

    // ����������鳤��
    int compressedLen() const;

    // ������ϲ��� y = A * exp(-B * x) + C
    std::optional<double> fittedA() const;
    std::optional<double> fittedB() const;
    std::optional<double> fittedC() const;

    // ����������ϲ���
    std::tuple<std::optional<double>, std::optional<double>, std::optional<double>> fittedResult() const;

private:
    APP_DECLARE_PRIVATE(AutoT2App)
};
