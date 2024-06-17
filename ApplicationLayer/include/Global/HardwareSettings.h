#pragma once

#include "../Global/Global.h"

//! 硬件设置类
class APPLICATIONLAYER_EXPORT HardwareSettings final
{
public:
    static HardwareSettings& instance();

    //! 加载中心频率等系统参数
    void loadSettings();

    //! 返回中心频率
    double frequency() const { return _frequency; }

    //! 设置中心频率
    void setFrequency(double freq) { _frequency = freq; }

    //! 修正中心频率(单位Hz)
    void offsetFrequency(double offset)
    {
        _frequency += offset * 1e-6;
    }

    //! 重新读取中心频率
    void reloadFrequency();

    //! 返回90度脉冲宽度
    double pw90() const { return _pw90; }

    //! 设置90度脉冲宽度
    void setpw90(double pw90) { _pw90 = pw90; }

    //! 返回180度脉冲宽度
    double pw180() const { return _pw180; }

    //! 设置180度脉冲宽度
    void setpw180(double pw180) { _pw180 = pw180; }

    //! 重新读取脉冲宽度
    void reloadPW();

    //! 是否对应用使用设置
    bool autoApplySettings() { return _autoApplySettings; }

private:
    HardwareSettings()
        : _frequency(0)
        , _pw90(0)
        , _pw180(0)
    {}

    //! 中心频率MHz
    double _frequency = 0;

    //! pw90和pw180
    double _pw90 = 0;
    double _pw180 = 0;

    //! 是否对应用使用设置
    bool _autoApplySettings = true;
};