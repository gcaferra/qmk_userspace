MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE    = no
RGB_MATRIX_ENABLE  = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
NKRO_ENABLE        = no
WPM_ENABLE = yes
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
EXTRAKEY_ENABLE = no        # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
SPLIT_KEYBOARD = yes
AUTO_SHIFT_ENABLE = no
BLUETOOTH_ENABLE = no
KEY_LOCK_ENABLE = no
SWAP_HANDS_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no


# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# if firmware size over limit, try this option
EXTRAFLAGS += -flto
