MOUSEKEY_ENABLE = no     # Mouse keys

RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

VIA_ENABLE      = no    # Enable VIA
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

COMBO_ENABLE    = yes
CONSOLE_ENABLE  = no

LUNA_ENABLE = yes
WPM_ENABLE = yes



DYNAMIC_TAPPING_TERM_ENABLE = yes
CAPS_WORD_ENABLE = yes


SRC += features/achordion.c
