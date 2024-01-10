library google_map_dynamic_key;

import 'google_map_dynamic_key_platform_interface.dart';

class GoogleMapDynamicKey {
  Future<String?> getPlatformVersion() {
    return GoogleMapDynamicKeyPlatform.instance.getPlatformVersion();
  }

  Future<void> setGoogleApiKey(String key) async {
    return await GoogleMapDynamicKeyPlatform.instance.setGoogleMapApiKey(key);
  }
}
