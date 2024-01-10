#import "GoogleMapDynamicKeyPlugin.h"
#import <GoogleMaps/GoogleMaps.h>

@implementation GoogleMapDynamicKeyPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"google_map_dynamic_key"
            binaryMessenger:[registrar messenger]];
  GoogleMapDynamicKeyPlugin* instance = [[GoogleMapDynamicKeyPlugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
  if ([@"getPlatformVersion" isEqualToString:call.method]) {
    result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
  }else if ([call.method isEqualToString:@"setGoogleMapKey"]) { 
    NSDictionary *jsonResult = call.arguments;
     NSString *googleMapsApiKey = jsonResult[@"mapKey"] ?: @"";

    [GMSServices provideAPIKey:googleMapsApiKey];
    result([@"iOS " stringByAppendingString:googleMapsApiKey]);
  }else {
    result(FlutterMethodNotImplemented);
  }
}
@end
