# ApplicationLayer

应用层ApplicationLayer动态链接库使用C++ 17语言编写，所使用的编译工具为Visual Studio 2017，其包含一系列.h头文件、ApplicationLayer.lib和ApplicationLayer.dll以及相关依赖动态链接库，支持的平台为Windows x64。

# 1. 应用层类ApplicationLayer
应用层ApplicationLayer类负责应用层环境初始化和销毁。

## 1.1 ApplicationLayer::instance
```
static ApplicationFactory& ApplicationLayer::instance();
```
函数说明：静态成员函数，用来获取该类示例

调用参数：无

函数返回：工厂类ApplicationFactory的引用

## 1.2 ApplicationLayer::init
```
void ApplicationLayer::int();
```
函数说明：应用层环境初始化函数，必须在其它应用层接口函数调用前执行。

调用参数：无

函数返回：无

## 1.3 ApplicationLayer::exit
```
void ApplicationLayer::exit();
```
函数说明：退出应用层函数，在函数内部将对应用层资源进行释放，因此必须在其它应用层接口函数之后执行。

调用参数：无

函数返回：无

调用示例：

```
#include "ApplicationLayer.h"

// 初始化应用层
ApplicationLayer::instance().init();

......

// 退出应用层
ApplicationLayer::instance().exit();
```

# 2. 工厂类ApplicationFactory
工厂类ApplicationFactory的作用是用来创建各种应用类的实例。它采用单例模式实现，使用方式为调用该类的静态成员函数 instance() 获取该类实例，然后使用接口函数 createApp() 创建其它应用类。

## 2.1 ApplicationFactory::instance
```
static ApplicationFactory& ApplicationFactory::instance();
```
函数说明：静态成员函数，用来获取该类实例

调用参数：无

函数返回：工厂类ApplicationFactory的引用

调用示例：

```
ApplicationFactory& instance = ApplicationFactory::instance();
```
## 2.2 ApplicationFactory::createApp
```
AppPtr ApplicationFactory::createApp(const std::string& type);
```
函数说明：创建应用类示例

调用参数：

type

应用程序名

函数返回：指向应用类ApplicationBase的std::shared_ptr<ApplicationBase>智能指针

AppPtr的定义为typedef std::shared_ptr<ApplicationBase> AppPtr;

调用示例：

```
std::string typeName = "AutoFrequency";
AppPtr app = ApplicationFactory::instance().createApp(typeName);
```
备注：目前支持的应用类型包括自动调频应用"AutoFrequency"、脉宽搜索应用"PulseWidthFinder"、自动T2应用"AutoT2"、T1T2谱应用"T1T2Spectrum"。


# 3. 应用类基类ApplicationBase
ApplicationBase是所有应用类的基类，其包含了应用子类的共同接口。

## 3.1 ApplicationBase::setWorkDirectory
```
bool setWorkDirectory(const std::string& directory);
```
函数说明：设置应用工作目录

调用参数：

directory

目录名

函数返回：true或false。如果返回false，检查传入参数是否是有效路径。

## 3.2 ApplicationBase::workDirectory
```
std::string workDirectory() const;
```
函数说明：返回应用工作目录

调用参数：无

函数返回：应用工作目录

## 3.3 ApplicationBase::init

bool init();

函数说明：初始化应用

调用参数：无

函数返回：true或false。初始化成功返回true。如果返回false，检查该应用的配置文件是否有效。

## 3.4 ApplicationBase::prepareScan

void prepareScan();

函数说明：执行扫描前的准备工作

调用参数：无

函数返回：无

## 3.5 ApplicationBase::setAcquireCallback
```
void setAcquireCallback(AcquireCallback callback);
```
函数说明：设置扫描过程中的回调函数

调用参数：

callback

函数指针，其定义为typedef std::function<void(const std::shared_ptr<Point3[]>&, const std::shared_ptr<double[]>&, int)> AcquireCallback;

函数返回：无

调用示例：

```
void func(const std::shared_ptr<const Point3[]>& timeDomainData,
          const std::shared_ptr<const double[]>& timeArray, int length)
{
    std::cout << "Time domain data acquired." << std::endl;
    // 此处添加处理代码
}

// 设置采集中的回调函数
app->setAcquireCallback(func);
```
## 3.6 ApplicationBase::executeScan
```
bool executeScan(bool isAsync = false);
```
函数说明：执行扫描

调用参数：

isAsync

是否执行异步调用，false 为同步调用，true为异步调用。默认为同步调用。

函数返回：true或false。扫描顺利完成返回true。如果返回false，检查日志输出。

## 3.7 ApplicationBase::saveTimeDomainData
```
bool saveTimeDomainData();
bool saveTimeDomainData(const std::string& fileName);
```
函数说明：保存核磁时域数据为csv文件

调用参数：

1. 无（根据当前日期和时间自动生成文件名）

2. fileName

自定义保存文件名

函数返回：true或false。保存成功返回true。如果返回false，检查扫描步骤执行是否顺利完成。

## 3.8 ApplicationBase::saveProcessedData
```
bool saveProcessedData();
bool saveProcessedData(const std::string& fileName);
```
函数说明：保存核磁后处理数据为csv文件

调用参数：

1. 无（根据当前日期和时间自动生成文件名）

2. fileName

自定义保存文件名

函数返回：true或false。保存成功返回true。如果返回false，检查后处理步骤执行是否顺利完成。

## 3.9 ApplicationBase::timeDomainData
```
const std::shared_ptr<Point3[]>& timeDomainData() const;
```
函数说明：返回时域数据数组

调用参数：无

函数返回：指向存储为Point3类型数组的智能指针，Point3结构体定义如下：

```
typedef struct RawPoint3
{
    float real;     // 实部
    float imag;     // 虚部
    float ampl;     // 幅值
}Point3;
```
## 3.10 ApplicationBase::timeArray
```
const std::shared_ptr<double[]>& timeArray() const;
```
函数说明：返回时域数据对应的时间数组

调用参数：无

函数返回：指向存储为double类型数组的智能指针

## 3.11 ApplicationBase::dataLength
```
int dataLength() const;
```
函数说明：返回时域数据的数组长度，即数组timeDomainData和timeArray的长度

调用参数：无

函数返回：数组长度

## 3.12 ApplicationBase::scanStatus()
```
bool scanStatus();
```
函数说明：返回当前扫描状态

调用参数：无

函数返回：enum ScanStatus枚举类型，定义如下

```
enum ScanStatus
{
    Idle,         // 设备未开始扫描
    Scanning,     // 设备正在扫描中
    Canceling     // 设备扫描取消中
};
```
## 3.13 ApplicationBase::stopScan()
```
void stopScan();
```
函数说明：停止设备扫描。如果在扫描过程中调用该函数，设备状态将由Scanning先变为Canceling，表示设备正在取消扫描中，数秒之后状态再变为Idle。

调用参数：无

函数返回：无

# 4. 自动调频应用类AutoFrequencyApp
自动调频应用类AutoFrequencyApp是ApplicationBase的子类，其作用是用来搜寻设备的拉莫尔频率，并自动进行更新。其创建方式是调用工厂类的createApp()函数时传入字符串"AutoFrequency"，
```
ApplicationFactory::instance().createApp("AutoFrequency");
```
## 4.1 AutoFrequencyApp::searchSucceeded
```
bool searchSucceeded() const;
```
函数说明：返回自动调频是否搜索成功

调用参数：无

函数返回：true或false。搜索成功返回true。如果返回false，检查日志输出。

## 4.2 AutoFrequencyApp::frequencyResult
```
std::optional<double> frequencyResult() const;
```
函数说明：返回自动调频搜索得到的中心频率

调用参数：无

函数返回：std::optional<double>类型。如果拟合失败或未完成，则为std::nullopt，否则其存储的double数值为中心频率的值。

## 4.3 AutoFrequencyApp::FFTData
```
const std::shared_ptr<Point3[]>& FFTData() const;
```
函数说明：返回FFT变换后的数据

调用参数：无

函数返回：指向存储为Point3类型数组的智能指针

## 4.4 AutoFrequencyApp::frequencyData
```
const std::shared_ptr<double>& frequencyData() const;
```
函数说明：返回FFT变换后数据的对应频率数据

调用参数：无

函数返回：指向存储为double类型数组的智能指针

# 5. 脉宽搜索应用类PulseWidthFinderApp
脉宽搜索应用类PulseWidthFinderApp是ApplicationBase的子类，目的是搜寻设备的90°脉宽和180°脉宽，将90°和180°脉冲的最优宽度记录下来，并在后续扫描其它应用的序列时用最优脉冲宽度来自动更新序列的其它参数。其创建方式是调用工厂类的createApp()函数时传入字符串"PulseWidthFinder"，
```
ApplicationFactory::instance().createApp("PulseWidthFinder");
```
## 5.1 PulseWidthFinderApp::amplitudeData
```
const std::vector<DoublePoint>& amplitudeData() const;
```
函数说明：返回一系列回波信号幅值的数组

调用参数：无

函数返回：指向存储为DoublePoint类型数组的智能指针，DoublePoint为双精度浮点类型坐标类，类型定义如下

```
class DoublePoint
{
public:
    double x() const { return _x; }   // 返回X值
    double y() const { return _y; }   // 返回y值

    void setX(double x) { _x = x; }   // 设置X值
    void setY(double y) { _y = y; }   // 设置y值
}
```
此处，DoublePoint中存储的坐标值x()为对应的脉冲宽度，y()为对应的幅值。

## 5.2 PulseWidthFinderApp::fittedData
```
const std::vector<DoublePoint>& fittedData() const;
```
函数说明：返回拟合的幅值数组

调用参数：无

函数返回：指向存储为DoublePoint类型数组的智能指针。

## 5.3 PulseWidthFinderApp::pw90Result
```
std::optional<double> pw90Result() const;
```
函数说明：返回90°脉宽搜索结果

调用参数：无

函数返回：std::optional<double>类型。如果搜索失败或未完成，则为std::nullopt，否则其存储的double数值为90°脉宽的值。

## 5.4 PulseWidthFinderApp::pw180Result
```
std::optional<double> pw180Result() const;
```
函数说明：返回180°脉宽搜索结果

调用参数：无

函数返回：std::optional<double>类型。如果搜索失败或未完成，则为std::nullopt，否则其存储的double数值为180°脉宽的值。

# 6. 自动T2应用类AutoT2App
自动T2应用类AutoT2App是ApplicationBase的子类，其目的是自动测量样品的T2时间。其创建方式是调用工厂类的createApp()函数时传入字符串"AutoT2"，
```
ApplicationFactory::instance().createApp("AutoT2");
```

# 7. T1T2谱应用类T1T2SpectrumApp
T1T2谱应用类T1T2SpectrumApp是ApplicationBase的子类，该应用会测量多个SR_CPMG序列，每次扫描会改变TI值、回波数目NE、扫描次数NS等，从而得到一系列的回波衰减曲线。其创建方式是调用工厂类的createApp()函数时传入字符串"T1T2Spectrum"，
```
ApplicationFactory::instance().createApp("T1T2Spectrum");
```