#pragma once

#include <memory>
#include <optional>

#include "../Global/Global.h"

class ApplicationBase;
class SampleData;
typedef std::shared_ptr<SampleData> SampleDataPtr;

class SamplePrivate;

#ifndef TIME_UNIT
#define TIME_UNIT
enum TimeUnit
{
    second = 0,     // sec
    milli = 1,      // ms
    micro = 2,      // us
};
#endif

//! ��Ʒ��
class APPLICATIONLAYER_EXPORT Sample
{
public:
    Sample(const std::string& appName, const std::string& name, const std::string& number, float weight, const std::string& type,
           const std::string& source, const std::string& scannerName, const std::string& comment);

    explicit Sample(const std::shared_ptr<ApplicationBase>& app, const std::string& name);

    explicit Sample(const std::string& appName, const std::string& name, float weight);

    explicit Sample(const std::string& appName, const std::string& dirName);

    explicit Sample(const Sample& rhs, const std::string& originalName, int index);

    Sample(const Sample&) = delete;                 // non construction-copyable
    Sample& operator=(const Sample&) = delete;      // non copyable

    ~Sample();

    //! �Ƿ���ɨ��
    bool scanned() const;
    void setScanned(bool scanned);

    //! �Ƿ��Ǳ���
    bool standardSample() const;
    void setStandardSample(bool standardSample);

    //! ������Ʒ��
    std::string name() const;
    void setName(const std::string& name);

    //! ������Ʒ���
    std::string number() const;
    void setNumber(const std::string& number);

    //! ������Ʒ����
    float weight() const;
    void setWeight(float weight);

    //! ��Ʒ�����ı���Ӧ����
    void onWeightChanged(float weight);

    //! ��Ʒ�̺����ı���Ӧ����
    void onSolidContentChanged(double solidContent);

    //! ������Ʒ����
    std::string type() const;
    void setType(const std::string& type);

    //! ������Ʒ��Դ
    std::string source() const;
    void setSource(const std::string& source);

    //! ����ɨ����Ա
    std::string scannerName() const;
    void setScannerName(const std::string& scannerName);

    //! ������Ʒ��ע��Ϣ
    std::string comment() const;
    void setComment(const std::string& comment);

    //! ������Ʒɨ��ʱ��
    std::string scanDate() const;
    void setScanDate(const std::string& scanTime);

    //! ������Ʒ�̺���
    std::optional<double> solidContent() const;
    void setSolidContent(std::optional<double> solidContent);

    //! ������Ϣ(��ͬӦ�õ���Ʒ��ʾ��ͬ������Ϣ)
    std::string additionalInfo() const;

    //! ������ƷĿ¼
    bool setDirectory(const std::string& workDirectory);
    std::string directory() const;

    //! ��Ʒ������
    bool rename(const std::string& newName);

    //! ����ɨ������
    SampleDataPtr sampleData() const;

    //! �������ļ�������Ʒ��Ϣ
    bool loadInformation();

    //! ������Ʒ��Ϣ�������ļ�
    bool saveInformation();

    //! ������Ʒ����
    bool saveTimeDomainData(const std::string& fileName, const std::shared_ptr<Point3[]>& timeDomainData,
                            const std::shared_ptr<double[]>& timeArray, TimeUnit timeUnit, int dataLength);

private:
    APP_DECLARE_PRIVATE(Sample)

    SamplePrivate* const d_ptr = nullptr;
};

typedef std::shared_ptr<Sample> SamplePtr;