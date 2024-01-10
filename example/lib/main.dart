import 'package:flutter/material.dart';
import 'dart:async';

// import 'package:flutter/services.dart';
import 'package:google_map_dynamic_key/google_map_dynamic_key.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final _googleMapDynamicKeyPlugin = GoogleMapDynamicKey();
  bool isLoading = false;

  @override
  void initState() {
    super.initState();
    // initPlatformState();
    initGoogleMapKey();
  }

  Future<void> initGoogleMapKey() async {
    setState(() {
      isLoading = true;
    });
    await _googleMapDynamicKeyPlugin
        .setGoogleApiKey("Your API KEY")
        .then((value) {
      setState(() {
        isLoading = false;
      });
    });
  }

  static const LatLng _kMapCenter = LatLng(11.541352, 104.9208219);

  static const CameraPosition _kInitialPosition =
      CameraPosition(target: _kMapCenter, zoom: 11.0, tilt: 0, bearing: 0);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
          appBar: AppBar(
            title: const Text('Plugin example app'),
          ),
          body: isLoading
              ? const CircularProgressIndicator.adaptive()
              : const GoogleMap(initialCameraPosition: _kInitialPosition)),
    );
  }
}
