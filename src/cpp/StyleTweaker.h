#pragma once

#include <map>

#include <QProxyStyle>


class StyleTweaker : public QProxyStyle {

  public:
    explicit StyleTweaker(const QString &key);

    virtual int pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option = nullptr,
                            const QWidget *widget = nullptr) const override;
    void setPixelMetric(QStyle::PixelMetric metric, int value);
    void unsetPixelMetric(QStyle::PixelMetric metric);

    virtual int styleHint(QStyle::StyleHint hint, const QStyleOption *option = nullptr, const QWidget *widget = nullptr,
                          QStyleHintReturn *returnData = nullptr) const override;

    void setStyleHint(QStyle::StyleHint hint, int value);
    void unsetStyleHint(QStyle::StyleHint hint);

  private:
    std::map<QStyle::PixelMetric, int> m_pixelMetricOverride;
    std::map<QStyle::StyleHint, int> m_styleHintOverride;
};
