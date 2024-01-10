//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <google_map_dynamic_key/google_map_dynamic_key_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) google_map_dynamic_key_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "GoogleMapDynamicKeyPlugin");
  google_map_dynamic_key_plugin_register_with_registrar(google_map_dynamic_key_registrar);
}
