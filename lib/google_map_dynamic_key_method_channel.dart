import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'google_map_dynamic_key_platform_interface.dart';

/// An implementation of [GoogleMapDynamicKeyPlatform] that uses method channels.
class MethodChannelGoogleMapDynamicKey extends GoogleMapDynamicKeyPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('google_map_dynamic_key');

  @override
  Future<String?> getPlatformVersion() async {
    final version =
        await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }

  @override
  Future<void> setGoogleMapApiKey(String mapKey) async {
    Map<String, dynamic> requestData = {"mapKey": mapKey};

    methodChannel.invokeMethod('setGoogleMapKey', requestData).then((value) {
      debugPrint("setGoogleMapKey :$value");
    });
  }
}
