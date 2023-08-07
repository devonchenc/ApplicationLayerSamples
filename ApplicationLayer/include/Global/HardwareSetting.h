#pragma once

#include "../Global/Global.h"

class APPLICATIONLAYER_EXPORT HardwareSetting final
{
public:
    static HardwareSetting& instance();

    // 加载中心频率等系统参数
    void loadSetting();

    // 返回中心频率
    double frequency() { return _frequency; }

    void setFrequency(double freq) { _frequency = freq; }

    // offset(单位Hz)
    void offsetFrequency(double offset)
    {
        _frequency += offset * 1e-6;
    }

    // 重新读取中心频率
    void reloadFrequency();

    // 返回90度脉冲宽度
    double pw90() { return _pw90; }

    void setpw90(double pw90) { _pw90 = pw90; }

    // 返回180度脉冲宽度
    double pw180() { return _pw180; }

    void setpw180(double pw180) { _pw180 = pw180; }

    // 重新读取脉冲宽度
    void reloadPW();

private:
    HardwareSetting()
        : _frequency(0)
        , _pw90(0)
        , _pw180(0)
    {}

    // 中心频率MHz
    double _frequency = 0;

    double _pw90 = 0;
    double _pw180 = 0;
};