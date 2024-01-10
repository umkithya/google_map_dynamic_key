#ifndef FLUTTER_PLUGIN_GOOGLE_MAP_DYNAMIC_KEY_PLUGIN_H_
#define FLUTTER_PLUGIN_GOOGLE_MAP_DYNAMIC_KEY_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace google_map_dynamic_key {

class GoogleMapDynamicKeyPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  GoogleMapDynamicKeyPlugin();

  virtual ~GoogleMapDynamicKeyPlugin();

  // Disallow copy and assign.
  GoogleMapDynamicKeyPlugin(const GoogleMapDynamicKeyPlugin&) = delete;
  GoogleMapDynamicKeyPlugin& operator=(const GoogleMapDynamicKeyPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace google_map_dynamic_key

#endif  // FLUTTER_PLUGIN_GOOGLE_MAP_DYNAMIC_KEY_PLUGIN_H_
