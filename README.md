# BuildaDroid_sound_generator
Easy to build soundgenerator module for:
https://makerworld.com/de/models/1549117-build-a-droid-cyberbrick-based-robot-kit?from=search#profileId-1689536

Uses servo PWM signal to trigger the soundmodule. 4$ build cost.

Needed Parts:
- Arduino Nano v3
- Speaker
- Servo cable

Wiring (also see arduino_soundmodule_wiring.jpg) :
- Arduino GND (upper pin row): Speaker Ground
- Arudino D11 (upper pin row): Speaker Positive
- Arduino GND (lower pin row): Servo Ground (brown or black wire)
- Arduino VIN (lower pin row): Servo Positive (red wire)
- Arduino D2 (upper pin row): Servo PWM signal wire

How to build:
- upload BuildaDroid_sound_generator.ino to arduino
- solder as mentioned above
- connect arduino module to S2 of the droid receiver
- replace your cyberbrick config with Astromech+Sound.json and upload it to both (!) the receiver AND transmitter
- use the left shoulder button to let the droid talk

