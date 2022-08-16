#include "StyleTweaker_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtWidgets/QWidget/qwidget_wrap.h"


Napi::FunctionReference StyleTweakerWrap::constructor;

Napi::Object StyleTweakerWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "StyleTweaker";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("pixelMetric", &StyleTweakerWrap::pixelMetric),
                   InstanceMethod("polish", &StyleTweakerWrap::polish),
                   InstanceMethod("unpolish", &StyleTweakerWrap::unpolish),
                   InstanceMethod("setPixelMetric", &StyleTweakerWrap::setPixelMetric),
                   InstanceMethod("unsetPixelMetric", &StyleTweakerWrap::unsetPixelMetric),
                   InstanceMethod("setStyleHint", &StyleTweakerWrap::setStyleHint),
                   InstanceMethod("unsetStyleHint", &StyleTweakerWrap::unsetStyleHint),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(StyleTweakerWrap)
       });
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

StyleTweakerWrap::StyleTweakerWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<StyleTweakerWrap>(info) {
  Napi::Env env = info.Env();
  std::string baseStyleName = info[0].As<Napi::String>().Utf8Value();
  this->instance = new StyleTweaker(QString::fromStdString(baseStyleName));
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

StyleTweaker* StyleTweakerWrap::getInternalInstance() {
  return this->instance;
}

Napi::Value StyleTweakerWrap::pixelMetric(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int metricInt = info[0].As<Napi::Number>().Int32Value();
  QStyle::PixelMetric metric = static_cast<QStyle::PixelMetric>(metricInt);

  return Napi::Value::From(env, this->instance->pixelMetric(metric));
}

Napi::Value StyleTweakerWrap::polish(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Object qwidgetObject = info[0].As<Napi::Object>();
  NodeWidgetWrap* qwidgetWrap =
      Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(qwidgetObject);
  QWidget* qwidget = qwidgetWrap->getInternalInstance();
  this->instance->polish(qwidget);
  return env.Null();
}

Napi::Value StyleTweakerWrap::unpolish(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Object qwidgetObject = info[0].As<Napi::Object>();
  NodeWidgetWrap* qwidgetWrap =
      Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(qwidgetObject);
  QWidget* qwidget = qwidgetWrap->getInternalInstance();
  this->instance->unpolish(qwidget);
  return env.Null();
}

Napi::Value StyleTweakerWrap::setPixelMetric(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int metricInt = info[0].As<Napi::Number>().Int32Value();
  int value = info[1].As<Napi::Number>().Int32Value();
  this->instance->setPixelMetric(static_cast<QStyle::PixelMetric>(metricInt), value);
  return env.Null();
}

Napi::Value StyleTweakerWrap::unsetPixelMetric(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int metricInt = info[0].As<Napi::Number>().Int32Value();
  this->instance->unsetPixelMetric(static_cast<QStyle::PixelMetric>(metricInt));
  return env.Null();
}

Napi::Value StyleTweakerWrap::setStyleHint(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int hintInt = info[0].As<Napi::Number>().Int32Value();
  int value = info[1].As<Napi::Number>().Int32Value();
  this->instance->setStyleHint(static_cast<QStyle::StyleHint>(hintInt), value);
  return env.Null();
}

Napi::Value StyleTweakerWrap::unsetStyleHint(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int hintInt = info[0].As<Napi::Number>().Int32Value();
  this->instance->unsetStyleHint(static_cast<QStyle::StyleHint>(hintInt));
  return env.Null();
}
