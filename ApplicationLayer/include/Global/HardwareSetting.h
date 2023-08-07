#pragma once

#include "../Global/Global.h"

class APPLICATIONLAYER_EXPORT HardwareSetting final
{
public:
    static HardwareSetting& instance();

    // ��������Ƶ�ʵ�ϵͳ����
    void loadSetting();

    // ��������Ƶ��
    double frequency() { return _frequency; }

    void setFrequency(double freq) { _frequency = freq; }

    // offset(��λHz)
    void offsetFrequency(double offset)
    {
        _frequency += offset * 1e-6;
    }

    // ���¶�ȡ����Ƶ��
    void reloadFrequency();

    // ����90��������
    double pw90() { return _pw90; }

    void setpw90(double pw90) { _pw90 = pw90; }

    // ����180��������
    double pw180() { return _pw180; }

    void setpw180(double pw180) { _pw180 = pw180; }

    // ���¶�ȡ������
    void reloadPW();

private:
    HardwareSetting()
        : _frequency(0)
        , _pw90(0)
        , _pw180(0)
    {}

    // ����Ƶ��MHz
    double _frequency = 0;

    double _pw90 = 0;
    double _pw180 = 0;
};