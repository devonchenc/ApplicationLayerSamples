#pragma once

#include <optional>

// 配置参数
struct ApplicationConfig
{
    // 回波间隔us
    std::optional<double> TE;

    // 等待时间ms
    std::optional<double> TW;

    // 恢复时间ms
    std::optional<double> TI;

    // 相位循环
    std::optional<int> NP;

    // 扫描次数
    std::optional<int> NS;

    // 回波数目
    std::optional<int> NE;

    // 预估T1值ms
    std::optional<double> defaultT1;
};
