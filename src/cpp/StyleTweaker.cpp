#include "StyleTweaker.h"


StyleTweaker::StyleTweaker(const QString &key) : QProxyStyle(key) {
    // m_rgb[7] = selectedOffRgb;
}

int StyleTweaker::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const {
    if (m_pixelMetricOverride.count(metric) != 0) {
        return m_pixelMetricOverride.at(metric);
    }

    return QProxyStyle::pixelMetric(metric, option, widget);
}

void StyleTweaker::setPixelMetric(QStyle::PixelMetric metric, int value) {
    m_pixelMetricOverride[metric] = value;
}

void StyleTweaker::unsetPixelMetric(QStyle::PixelMetric metric) {
    m_pixelMetricOverride.erase(metric);
}
