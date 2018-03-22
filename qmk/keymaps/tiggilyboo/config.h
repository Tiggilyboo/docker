#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(NO_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

#ifndef LIGHT_CONFIG_H
#define BACKLIGHT_BREATHING
#endif
#define TAPPING_TERM 150

#define MUSIC_MASK (keycode != KC_NO)

                               
#endif
