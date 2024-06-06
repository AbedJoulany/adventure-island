//-----------------------------INCLUDES------------------------------


#include "Sound.h"


//--------------------------TEXTURES_PATHS---------------------------


#define BLOCKSPATH "Blocks.png"
#define TRAMPOLINEPATH "trampoline.png"
#define BIRDPATH "bird.png"
#define FROGPATH "frog.png"
#define FIREWOODPATH "fireWood.png"
#define BACKGROUNDPATH "menu.jpg"
#define HEROPATH "Hero.png"
#define HEROSKATEBOARDPATH "heroSkateBoard.png"
#define EGGPATH "Egg.png"
#define BONUSAPPLEPATH "Bonus-Apple.png"
#define BONUSBANANAPATH "Bonus-Banana.png"
#define BONUSPINEAPPLEPATH "Bonus-PineApple.png"
#define BONUSTOMATOPATH "Bonus-Tomato.png"
#define BONUSSKATEBOARDPATH "Bonus-SkateBoard.png"
#define WEAPONAXEPATH "WeaponAxe.png"
#define WEAPONFIREPATH "WeaponFireball.png"



//---------------------------LEVELS_PATHS----------------------------


#define LEVELSPATH "Levels.txt"


//---------------------------SOUNDS_PATHS----------------------------


#define BONUSOUNDSPATH "bonus.ogg"
#define GAMEOVERSOUNDSPATH "gameover.ogg"
#define JUMPSOUNDSPATH "jump.wav"
#define MAINTHEMESOUNDSPATH "main_theme.ogg"
#define MENUSOUNDPATH "menu.ogg"
#define DIEDSOUNDPATH "died.ogg"
#define PAUSESOUNDSPATH "pause.wav"
#define STOMPSOUNDSPATH "stomp.wav"
#define VICTORYPATH "victory.ogg"
#define WINSOUNDSPATH "winlevel.ogg"
#define TRAMPOLINESOUNDPATH "trampoline.wav"
#define POWERUPSOUNDPATH "powerup.wav"
#define CLICKSOUNDPATH "click.wav"
#define ENEMYKILLED "enemyKilled.ogg"


//---------------------------FONTS_PATHS-----------------------------


#define FONTSPATH "AdventureIsland.ttf"


//------------------------------ID'S---------------------------------


#define FONTID "font1" 
#define HEROID "player"
#define HEROSKATEID "skate"
#define BIRDID 'e'
#define FROGID 'f'
#define FIREWOODID 'G'
#define SNAILID 's'
#define FINISHLINEID 'F'
#define WHITESPACEID '-'
#define STONEID '1' 
#define TRAMPOLINEID 'T'
#define GRASSTOPID '4'
#define GRASSLEFTCORNERID '5'
#define GRASSLEFTID '6'
#define DIRTID '7'
#define GRASSRIGHTID '8'
#define GRASSRIGHTCORNER '9'
#define BONUSAPPLEID 'A'
#define BONUSPINEAPPLEID 'P'
#define BONUSTOMATOID 'O'
#define BONUSBANANAID 'B'
#define BONUSAXEID 'X'
#define BONUSFIREID 'R'
#define BONUSSKATEBOARDID 'S'
#define EGGID 'E'
#define TOPLEFTCLOUD 'i'
#define TOPRIGHTCLOUD 'o'
#define BOTTOMLEFTCLOUD 'k'
#define BOTTOMRIGHTCLOUD 'l'
#define WEAPONAXEID "WeaponAxe"
#define WEAPONFIREID "WeaponFire"


//------------------------------CONSTS-------------------------------

#define GAMETITLE "Adventure Island"
#define WINDOWWIDTH 700
#define WINDOWHIEGHT 650
#define GRAVITY .0075f
#define WEAPONGRAVITY .00175f
#define OBJECTHEIGHT 1
#define OBJECTWIDTH 1
#define PLAYERHEIGHT 2
#define ENEMYSPEED .04f
#define WEAPONSPEED .2f
#define PLAYERSPEED .01f
#define PLAYERJUMPSPEED -.25f
#define PLAYERMAXSPEED .15f
#define PLAYERSTOPSPEED .005f
#define PLAYERFIRSTPOS { 10.f, 10.f }
#define ENEMYLIFE 1
#define PLAYERLIFE 3
#define MAX_WEAPON 3
#define ALLOWED_WEAPON 3

#define MAX_MAIN_MENU 10

#define NUMOFLEVELS 5

#define ZERO 0

#define PLAY "Play"
#define BUTTONS "BUTTONS"
#define EXIT "Exit"

#define MOVEMENT "Movement:    Arrow/WASD"
#define FIRE	 "Fire:        Space"
#define VOL "Volume:"
#define PAUSE "         P                       Pause"
#define VOLUME "         B/N/M  increas/decrease/mute"
#define PLAYAGAIN "play again"
#define BACK "<-BACK"


//--------------------------------------------------------------------------------------------------