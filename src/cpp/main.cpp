#include <napi.h>

#include "StyleTweaker_wrap.h"


Napi::Object Main(Napi::Env env, Napi::Object exports) {
  StyleTweakerWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
