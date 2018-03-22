# This gets included at the beginning of the Planck's Makefile.
# Alternatively, you can run make from the keymap directory
# and the main Makefile will be included after.

COMMAND_ENABLE   = no   # Disable shift combination, which conflicts with shift-parens
NKRO_ENABLE      = yes  # N-key rollover required for use as a steno board
AUDIO_ENABLE     = no   # Audio output on port C6
SLEEP_LED_ENABLE = yes
TAP_DANCE_ENABLE = no
MOUSEKEY_ENABLE  = no
CONSOLE_ENABLE = no
BACKLIGHT_ENABLE = yes
BREATHING_PERIOD = 10
BACKLIGHT_LEVELS = 5
ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
