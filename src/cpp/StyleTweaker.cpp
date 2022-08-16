#include "StyleTweaker.h"


StyleTweaker::StyleTweaker(const QString &key) : QProxyStyle(key) {
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

int StyleTweaker::styleHint(QStyle::StyleHint hint, const QStyleOption *option, const QWidget *widget,
    QStyleHintReturn *returnData) const {

  if (m_styleHintOverride.count(hint) != 0) {
    return m_styleHintOverride.at(hint);
  }

  return QProxyStyle::styleHint(hint, option, widget, returnData);
}

void StyleTweaker::setStyleHint(QStyle::StyleHint hint, int value) {
  m_styleHintOverride[hint] = value;
}

void StyleTweaker::unsetStyleHint(QStyle::StyleHint hint) {
  m_styleHintOverride.erase(hint);
}
