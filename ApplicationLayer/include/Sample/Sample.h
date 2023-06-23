#pragma once

#include <memory>

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

class APPLICATIONLAYER_EXPORT Sample
{
public:
    Sample(const std::string& appName, const std::string& name, const std::string& number, float weight, const std::string& type,
           const std::string& source, const std::string& scannerName, const std::string& comment);

    explicit Sample(const std::shared_ptr<ApplicationBase>& app, const std::string& name);

    explicit Sample(const std::string& appName, const std::string& name, float weight);

    explicit Sample(const std::string& appName, const std::string& dirName);

    Sample(const Sample&) = delete;                 // non construction-copyable
    Sample& operator=(const Sample&) = delete;      // non copyable

    ~Sample();

    bool scanned() const;
    void setScanned(bool scanned);

    std::string name() const;
    void setName(const std::string& name);

    std::string number() const;
    void setNumber(const std::string& number);

    float weight() const;
    void setWeight(float weight);

    std::string type() const;
    void setType(const std::string& type);

    std::string source() const;
    void setSource(const std::string& source);

    std::string scannerName() const;
    void setScannerName(const std::string& scannerName);

    std::string comment() const;
    void setComment(const std::string& comment);

    std::string scanDate() const;
    void setScanDate(const std::string& scanTime);

    // 设置样品目录
    bool setDirectory(const std::string& workDirectory);
    std::string directory() const;

    // 返回扫描数据
    SampleDataPtr sampleData() const;

    // 从配置文件加载样品信息
    bool loadInformation();

    // 保存样品信息到配置文件
    bool saveInformation();

    // 保存样品数据
    bool saveTimeDomainData(const std::string& fileName, const std::shared_ptr<Point3[]>& timeDomainData,
                            const std::shared_ptr<double[]>& timeArray, TimeUnit timeUnit, int dataLength);

private:
    void createSampleData(const std::string& appName);

private:
    APP_DECLARE_PRIVATE(Sample)

    SamplePrivate* const d_ptr;
};

typedef std::shared_ptr<Sample> SamplePtr;