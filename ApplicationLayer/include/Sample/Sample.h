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

//! 样品类
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

    //! 是否已扫描
    bool scanned() const;
    void setScanned(bool scanned);

    //! 是否是标样
    bool standardSample() const;
    void setStandardSample(bool standardSample);

    //! 返回样品名
    std::string name() const;
    void setName(const std::string& name);

    //! 返回样品编号
    std::string number() const;
    void setNumber(const std::string& number);

    //! 返回样品重量
    float weight() const;
    void setWeight(float weight);

    //! 样品重量改变响应函数
    void onWeightChanged(float weight);

    //! 样品固含量改变响应函数
    void onSolidContentChanged(double solidContent);

    //! 返回样品类型
    std::string type() const;
    void setType(const std::string& type);

    //! 返回样品来源
    std::string source() const;
    void setSource(const std::string& source);

    //! 返回扫描人员
    std::string scannerName() const;
    void setScannerName(const std::string& scannerName);

    //! 返回样品备注信息
    std::string comment() const;
    void setComment(const std::string& comment);

    //! 返回样品扫描时间
    std::string scanDate() const;
    void setScanDate(const std::string& scanTime);

    //! 设置样品固含量
    std::optional<double> solidContent() const;
    void setSolidContent(std::optional<double> solidContent);

    //! 附加信息(不同应用的样品显示不同附加信息)
    std::string additionalInfo() const;

    //! 设置样品目录
    bool setDirectory(const std::string& workDirectory);
    std::string directory() const;

    //! 样品重命名
    bool rename(const std::string& newName);

    //! 返回扫描数据
    SampleDataPtr sampleData() const;

    //! 从配置文件加载样品信息
    bool loadInformation();

    //! 保存样品信息到配置文件
    bool saveInformation();

    //! 保存样品数据
    bool saveTimeDomainData(const std::string& fileName, const std::shared_ptr<Point3[]>& timeDomainData,
                            const std::shared_ptr<double[]>& timeArray, TimeUnit timeUnit, int dataLength);

private:
    APP_DECLARE_PRIVATE(Sample)

    SamplePrivate* const d_ptr = nullptr;
};

typedef std::shared_ptr<Sample> SamplePtr;