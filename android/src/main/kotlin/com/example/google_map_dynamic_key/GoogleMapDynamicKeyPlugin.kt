package com.example.google_map_dynamic_key

import androidx.annotation.NonNull
import android.content.pm.PackageManager
import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler
import io.flutter.plugin.common.MethodChannel.Result
import android.content.Context


/** GoogleMapDynamicKeyPlugin */
class GoogleMapDynamicKeyPlugin: FlutterPlugin, MethodCallHandler {
  /// The MethodChannel that will the communication between Flutter and native Android
  ///
  /// This local reference serves to register the plugin with the Flutter Engine and unregister it
  /// when the Flutter Engine is detached from the Activity
  private lateinit var channel : MethodChannel
  private lateinit var context: Context

  override fun onAttachedToEngine(flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
    channel = MethodChannel(flutterPluginBinding.binaryMessenger, "google_map_dynamic_key")
    channel.setMethodCallHandler(this)
    this.context = flutterPluginBinding.applicationContext

  }

  override fun onMethodCall(call: MethodCall, result: Result) {
    if (call.method == "getPlatformVersion") {
      result.success("Android ${android.os.Build.VERSION.RELEASE}")
    }  else if (call.method == "setGoogleMapKey") {
      val mapKey = call.argument<String>("mapKey")
      mapKey?.let { setMapKey(it) }
      result.success("Android:" + mapKey)
    }else {
      result.notImplemented()
    }
  }
  fun setMapKey(mapKey: String) {
    try {
      val packageManager: PackageManager = this.context.packageManager
        val applicationInfo =
        packageManager.getApplicationInfo(this.context.packageName, PackageManager.GET_META_DATA)
        applicationInfo.metaData.putString("com.google.android.geo.API_KEY", mapKey)
    } catch (e: PackageManager.NameNotFoundException) {
        e.printStackTrace()
      }
  }

  override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
    channel.setMethodCallHandler(null)
  }
}
