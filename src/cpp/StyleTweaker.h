#pragma once

#include <map>

#include "Extras/Export/export.h"
#include <QProxyStyle>


class DLL_EXPORT StyleTweaker : public QProxyStyle {
  public:
    explicit StyleTweaker(const QString &key);

    virtual int pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option = nullptr,
                            const QWidget *widget = nullptr) const override;
    void setPixelMetric(QStyle::PixelMetric metric, int value);
    void unsetPixelMetric(QStyle::PixelMetric metric);

  private:
    std::map<QStyle::PixelMetric, int> m_pixelMetricOverride;
};
