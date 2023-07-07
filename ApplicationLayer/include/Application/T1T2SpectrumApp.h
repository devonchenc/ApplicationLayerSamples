#pragma once

#include "ApplicationBase.h"

class T1T2SpectrumAppPrivate;

class APPLICATIONLAYER_EXPORT T1T2SpectrumApp : public ApplicationBase
{
public:
    T1T2SpectrumApp(const std::string& name);

    bool init() override;

    // ���������ļ�
    void saveConfig() override;

    // ׼����ʼɨ��
    void prepareScan() override;

    // ��ʾ��������
    void showProcessedData() override;

    // ����ʱ������
    bool saveTimeDomainData() override;
    bool saveTimeDomainData(const std::string& fileName) override;

    // ��������ɨ��ķ�ֵ����
    const std::vector<std::vector<Point3>>& amplitudeTotalData() const;

    // ��������ɨ���ʱ������
    const std::vector<std::vector<float>>& timeTotalData() const;

private:
    APP_DECLARE_PRIVATE(T1T2SpectrumApp)
};
