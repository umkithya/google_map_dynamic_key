# Google Map Dynamic Key

Instead of hard coding, Google maps API key in AndroidManifest.xml and AppDelegate.swift. We can change the Google Maps key dynamically anytime.

We can store the Google Maps key on the server and can get using the rest API. Map key can change the key at runtime after getting from the server.

## Examples

Here are small examples that show you how to use Google Map Dynamic Key.

### Coding

### Flutter Dart Code Implementation

```dart
final _googleMapDynamicKeyPlugin = GoogleMapDynamicKey();
await _googleMapDynamicKeyPlugin
        .setGoogleApiKey("Your API KEY")
        .then((value) {
      setState(() {
        isLoading = false;
      });
    });
```

## Developer

Made by Um Kithya Senior Flutter Developer with ❤️
