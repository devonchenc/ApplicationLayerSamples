#pragma once

#include <optional>

// ���ò���
struct ApplicationConfig
{
    // �ز����us
    std::optional<double> TE;

    // �ȴ�ʱ��ms
    std::optional<double> TW;

    // �ָ�ʱ��ms
    std::optional<double> TI;

    // ��λѭ��
    std::optional<int> NP;

    // ɨ�����
    std::optional<int> NS;

    // �ز���Ŀ
    std::optional<int> NE;

    // Ԥ��T1ֵms
    std::optional<double> defaultT1;
};
