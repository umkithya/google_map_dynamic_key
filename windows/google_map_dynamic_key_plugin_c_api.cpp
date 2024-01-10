#include "include/google_map_dynamic_key/google_map_dynamic_key_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "google_map_dynamic_key_plugin.h"

void GoogleMapDynamicKeyPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  google_map_dynamic_key::GoogleMapDynamicKeyPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
