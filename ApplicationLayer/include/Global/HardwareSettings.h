#pragma once

#include "../Global/Global.h"

//! Ӳ��������
class APPLICATIONLAYER_EXPORT HardwareSettings final
{
public:
    static HardwareSettings& instance();

    //! ��������Ƶ�ʵ�ϵͳ����
    void loadSettings();

    //! ��������Ƶ��
    double frequency() const { return _frequency; }

    //! ��������Ƶ��
    void setFrequency(double freq) { _frequency = freq; }

    //! ��������Ƶ��(��λHz)
    void offsetFrequency(double offset)
    {
        _frequency += offset * 1e-6;
    }

    //! ���¶�ȡ����Ƶ��
    void reloadFrequency();

    //! ����90��������
    double pw90() const { return _pw90; }

    //! ����90��������
    void setpw90(double pw90) { _pw90 = pw90; }

    //! ����180��������
    double pw180() const { return _pw180; }

    //! ����180��������
    void setpw180(double pw180) { _pw180 = pw180; }

    //! ���¶�ȡ������
    void reloadPW();

    //! �Ƿ��Ӧ��ʹ������
    bool autoApplySettings() { return _autoApplySettings; }

private:
    HardwareSettings()
        : _frequency(0)
        , _pw90(0)
        , _pw180(0)
    {}

    //! ����Ƶ��MHz
    double _frequency = 0;

    //! pw90��pw180
    double _pw90 = 0;
    double _pw180 = 0;

    //! �Ƿ��Ӧ��ʹ������
    bool _autoApplySettings = true;
};