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

    // 初次构造
    virtual bool init();

    // 保存配置到ini文件
    virtual void saveConfig() {}

    // 准备开始扫描
    virtual void prepareScan() {}

    // 显示时域数据
    virtual void showTimeDomainData();

    // 显示后处理数据
    virtual void showProcessedData() {}

    // 保存时域数据
    virtual bool saveTimeDomainData();
    virtual bool saveTimeDomainData(const std::string& fileName);

    // 保存后处理数据
    virtual bool saveProcessedData();
    virtual bool saveProcessedData(const std::string& fileName);

    // 用户命名
    std::string useDefinedName() const;

    // 内置名称
    std::string innerName() const;

    // 开始扫描样品(false为同步调用, true为异步调用)
    bool executeScan(bool isAsync = false);

    // 添加样品
    void addSample(SamplePtr sample);

    // 移除样品
    void removeSample(SamplePtr sample);

    // 设置当前样品
    bool setActiveSample(SamplePtr sample);

    // 返回当前样品
    SamplePtr activeSample();

    // 返回样品列表
    const std::list<SamplePtr>& sampleList();

    // 返回所有样品数量
    int totalSampleNum();

    // 返回未扫描样品数量
    int unscannedSampleNum();

    // 设置App父目录和App工作目录名
    bool setWorkDirectory(const std::string& directory, const std::string& subDirectory = "");

    // 返回App工作目录
    std::string workDirectory() const;

    // 从文件夹加载
    bool loadFromDirectory(const std::string& directory);

    // 返回配置文件名
    std::string configFileName() const;

    // 样品目录
    std::string sampleDirectory() const;

    // 返回App配置参数
    ApplicationConfig& appConfig();

    // 返回时域数据
    const std::shared_ptr<Point3[]>& timeDomainData() const;

    // 返回时域数据的时间数组
    const std::shared_ptr<double[]>& timeArray() const;

    // 时域数组长度
    int dataLength() const;

    // 设置采集过程中回调函数
    void setAcquireCallback(AcquireCallback callback);

    // 返回扫描状态
    static ScanStatus scanStatus();

    // 停止扫描
    static void stopScan();

    // 返回当前扫描样品
    static SamplePtr scanningSample();

protected:
    APP_DECLARE_PRIVATE(ApplicationBase)

    ApplicationBase(ApplicationBasePrivate& d);

    ApplicationBasePrivate* const d_ptr;
};

typedef std::shared_ptr<ApplicationBase> AppPtr;