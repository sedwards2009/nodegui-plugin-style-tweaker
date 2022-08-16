#pragma once

//#include <napi.h>
#include "Extras/Utils/nutils.h"
// ^ FIXME: For some reason napi.h and nutils.h don't link ok on MSVC when used together.

#include "StyleTweaker.h"
#include "core/Component/component_macro.h"


class StyleTweakerWrap : public Napi::ObjectWrap<StyleTweakerWrap> {
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

  Napi::Value setStyleHint(const Napi::CallbackInfo& info);
  Napi::Value unsetStyleHint(const Napi::CallbackInfo& info);
};
