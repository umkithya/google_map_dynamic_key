#include "include/google_map_dynamic_key/google_map_dynamic_key_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#include "google_map_dynamic_key_plugin_private.h"

#define GOOGLE_MAP_DYNAMIC_KEY_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), google_map_dynamic_key_plugin_get_type(), \
                              GoogleMapDynamicKeyPlugin))

struct _GoogleMapDynamicKeyPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(GoogleMapDynamicKeyPlugin, google_map_dynamic_key_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void google_map_dynamic_key_plugin_handle_method_call(
    GoogleMapDynamicKeyPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getPlatformVersion") == 0) {
    response = get_platform_version();
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

FlMethodResponse* get_platform_version() {
  struct utsname uname_data = {};
  uname(&uname_data);
  g_autofree gchar *version = g_strdup_printf("Linux %s", uname_data.version);
  g_autoptr(FlValue) result = fl_value_new_string(version);
  return FL_METHOD_RESPONSE(fl_method_success_response_new(result));
}

static void google_map_dynamic_key_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(google_map_dynamic_key_plugin_parent_class)->dispose(object);
}

static void google_map_dynamic_key_plugin_class_init(GoogleMapDynamicKeyPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = google_map_dynamic_key_plugin_dispose;
}

static void google_map_dynamic_key_plugin_init(GoogleMapDynamicKeyPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  GoogleMapDynamicKeyPlugin* plugin = GOOGLE_MAP_DYNAMIC_KEY_PLUGIN(user_data);
  google_map_dynamic_key_plugin_handle_method_call(plugin, method_call);
}

void google_map_dynamic_key_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  GoogleMapDynamicKeyPlugin* plugin = GOOGLE_MAP_DYNAMIC_KEY_PLUGIN(
      g_object_new(google_map_dynamic_key_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "google_map_dynamic_key",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
