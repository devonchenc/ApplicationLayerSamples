#pragma once

#include <deque>
#include <list>
#include <functional>

#include "../Global/Global.h"
#include "../Sample/Sample.h"
#include "ApplicationConfig.h"

class ApplicationBasePrivate;

#ifndef SCAN_STATUS
#define SCAN_STATUS
enum ScanStatus
{
    Idle,
    Scanning,
    Canceling
};
#endif

typedef std::function<void(int count, int total, const std::shared_ptr<Point3[]>&, const std::shared_ptr<double[]>&, int)> AcquireCallback;

class APPLICATIONLAYER_EXPORT ApplicationBase
{
public:
    ApplicationBase(const std::string& useDefinedName, const std::string& innerName);
    virtual ~ApplicationBase();

    ApplicationBase(const ApplicationBase&) = delete;               // non construction-copyable
    ApplicationBase& operator=(const ApplicationBase&) = delete;    // non copyable

    // ���ι���
    virtual bool init();

    // �������õ�ini�ļ�
    virtual void saveConfig() {}

    // ׼����ʼɨ��
    virtual void prepareScan() {}

    // ��ʾʱ������
    virtual void showTimeDomainData();

    // ��ʾ��������
    virtual void showProcessedData() {}

    // ����ʱ������
    virtual bool saveTimeDomainData();
    virtual bool saveTimeDomainData(const std::string& fileName);

    // �����������
    virtual bool saveProcessedData();
    virtual bool saveProcessedData(const std::string& fileName);

    // �û�����
    std::string useDefinedName() const;

    // ��������
    std::string innerName() const;

    // ��ʼɨ����Ʒ(falseΪͬ������, trueΪ�첽����)
    bool executeScan(bool isAsync = false);

    // �����Ʒ
    void addSample(SamplePtr sample);

    // �Ƴ���Ʒ
    void removeSample(SamplePtr sample);

    // ���õ�ǰ��Ʒ
    bool setActiveSample(SamplePtr sample);

    // ���ص�ǰ��Ʒ
    SamplePtr activeSample();

    // ������Ʒ�б�
    const std::list<SamplePtr>& sampleList();

    // ����������Ʒ����
    int totalSampleNum();

    // ����δɨ����Ʒ����
    int unscannedSampleNum();

    // ����App��Ŀ¼��App����Ŀ¼��
    bool setWorkDirectory(const std::string& directory, const std::string& subDirectory = "");

    // ����App����Ŀ¼
    std::string workDirectory() const;

    // ���ļ��м���
    bool loadFromDirectory(const std::string& directory);

    // ���������ļ���
    std::string configFileName() const;

    // ��ƷĿ¼
    std::string sampleDirectory() const;

    // ����App���ò���
    ApplicationConfig& appConfig();

    // ����ʱ������
    const std::shared_ptr<Point3[]>& timeDomainData() const;

    // ����ʱ�����ݵ�ʱ������
    const std::shared_ptr<double[]>& timeArray() const;

    // ʱ�����鳤��
    int dataLength() const;

    // ���òɼ������лص�����
    void setAcquireCallback(AcquireCallback callback);

    // ����ɨ��״̬
    static ScanStatus scanStatus();

    // ֹͣɨ��
    static void stopScan();

    // ���ص�ǰɨ����Ʒ
    static SamplePtr scanningSample();

protected:
    APP_DECLARE_PRIVATE(ApplicationBase)

    ApplicationBase(ApplicationBasePrivate& d);

    ApplicationBasePrivate* const d_ptr;
};

typedef std::shared_ptr<ApplicationBase> AppPtr;