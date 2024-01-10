import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'google_map_dynamic_key_method_channel.dart';

abstract class GoogleMapDynamicKeyPlatform extends PlatformInterface {
  /// Constructs a GoogleMapDynamicKeyPlatform.
  GoogleMapDynamicKeyPlatform() : super(token: _token);

  static final Object _token = Object();

  static GoogleMapDynamicKeyPlatform _instance = MethodChannelGoogleMapDynamicKey();

  /// The default instance of [GoogleMapDynamicKeyPlatform] to use.
  ///
  /// Defaults to [MethodChannelGoogleMapDynamicKey].
  static GoogleMapDynamicKeyPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [GoogleMapDynamicKeyPlatform] when
  /// they register themselves.
  static set instance(GoogleMapDynamicKeyPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
  Future<void> setGoogleMapApiKey(String mapKey) {
    throw UnimplementedError('setgoogleMapApiKey() has not been implemented.');
  }
}
