#pragma once

#include <napi.h>

#include "StyleTweaker.h"
#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"


class DLL_EXPORT StyleTweakerWrap : public Napi::ObjectWrap<StyleTweakerWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  StyleTweaker* instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  StyleTweakerWrap(const Napi::CallbackInfo& info);
  StyleTweaker* getInternalInstance();

  // Wrapped methods
  Napi::Value pixelMetric(const Napi::CallbackInfo& info);
  Napi::Value polish(const Napi::CallbackInfo& info);
  Napi::Value unpolish(const Napi::CallbackInfo& info);

  Napi::Value setPixelMetric(const Napi::CallbackInfo& info);
  Napi::Value unsetPixelMetric(const Napi::CallbackInfo& info);
};
