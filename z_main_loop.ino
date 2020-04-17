void loop() {

  if ( Serial.available() > 0 )
  {
    msg = Serial.read();
    if (msg == 'q') {
      Serial.println("Turned off");
      turn_off();
      animation_mode = animation_modes(0);
      Serial.println(animation_mode);
    }
    if (msg == 'w') {
      Serial.println("Animation Up");
      animation_mode = animation_modes(animation_mode + 1);
      if (animation_mode >= number_of_modes) {
        animation_mode = animation_modes(1);
      }
    }
    if (msg == 's') {
      Serial.println("Animation Down");
      animation_mode  = animation_modes(animation_mode - 1);
      if (animation_mode <= 0) {
        animation_mode = animation_modes(number_of_modes - 1);
      }
    }

    if (msg == 'd') {
      Serial.println("Speed increased");
      duration -= 5;
      if (duration < 1) {
        duration = 1;
      }
    }
    if (msg == 'a') {
      Serial.println("Speed decreased");
      duration += 5;
    }
    if (msg == 'i') {
      Serial.println("Speed increased a lot");
      duration -= 100;
      if (duration < 1) {
        duration = 1;
      }
    }
    if (msg == 'o') {
      Serial.println("Speed decreased a lot");
      duration += 100;
    }


    if (msg == 'j') {
      Serial.println("Palette <<");
      palettes_mode = palettes_modes(palettes_mode - 1);
      if (palettes_mode < 0) {
        palettes_mode = palettes_modes(number_of_palettes - 1);
      }
      line = 0;
    }
    if (msg == 'k') {
      Serial.println("Palette >>");
      palettes_mode = palettes_modes(palettes_mode + 1);
      if (palettes_mode >= number_of_palettes) {
        palettes_mode = palettes_modes(0);
      }
      line = 0;
    }

    if (msg == 'n') {
      Serial.println("Brightness decreased");
      brightness -= 10;
      if (brightness <= 0) {
        brightness = 1;
      }
      strip.setBrightness(brightness);
    }
    if (msg == 'm') {
      Serial.println("Brightness increased");
      brightness += 10;
      if (brightness >= 255) {
        brightness = 255;
      }
      strip.setBrightness(brightness);
    }

    if ( msg == 'x') {
      Serial.println("Commands:\n");
      Serial.println("q to turn off\n");
      Serial.println("w animation +");
      Serial.println("s animation -\n");
      Serial.println("a to reduce speed");
      Serial.println("d to increase speed");
      Serial.println("i to reduce speed a lot");
      Serial.println("o to increase speed a lot\n");
      Serial.println("j to palette -");
      Serial.println("k to palette +\n");
      Serial.println("n to reduce brightness");
      Serial.println("m to increase brightness\n");
      Serial.println("z to show selections");
      Serial.println("x to show this help");
    }

    if ( msg == 'z') {
      Serial.println("\nCurrent setup is\n");
      Serial.print("Brigthness \t\t");
      Serial.print(brightness);
      Serial.println("/255");
      Serial.print("Update period \t\t");
      Serial.print(duration);
      Serial.println(" ms");
      Serial.print("Selected Pallet \t");
      Serial.println(palettes_modes(palettes_mode));
      Serial.print("Selected animation \t");
      Serial.println(animation_mode);

//      Serial.println("\n\tAvailable palettes:");
//      Serial.println("\tRETROWAVE \t= 0,\n\tRAINBOW   \t= 1,\n\tPINK      \t= 2,\n\tRED       \t= 3,\n\tORANGE    \t= 4,\n\tYELLOW    \t= 5,\n\tBROWN     \t= 6,\n\tGREEN     \t= 7,\n\tCYAN      \t= 8,\n\tBLUE      \t= 9,\n\tPURPLE    \t= 10,\n\tWHITE     \t= 11,\n\tBLACK     \t= 12 ");
//      Serial.println("\n\tAvailable animations:");
//      Serial.println("\tOFF \t\t= 0,\n\tCOLORWIPE \t= 1,\n\tCURTAINS \t= 2,\n\tDIAMONDS \t= 3,\n\tRANDOM_DIAMONDS = 4,\n\tTHEATER \t= 5");
    }
  }

  update_palettes();

  //  rainbow(10);             // Flowing rainbow cycle along the whole strip
  //  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
}
