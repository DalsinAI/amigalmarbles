LMarbles 1.1.2 for AmigaOS 3.x
==============================

LMarbles (Michael Speck, https://lgames.sourceforge.io/LMarbles/), the
puzzle game after Atomix: slide the marbles around the board (each one
rolls until something stops it) to build the figure shown on the right,
before the time runs out. Level sets with one-way arrows, teleports and
crumbling walls, and player profiles that keep your progress. For
AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG screen, on
OpenGPU's SDL 1.2 (sdl12-compat).

Base: lmarbles_1.1.2.orig.tar.gz from Debian (sha256
294902c1be2facd2805b8531eae00f2cba89216ed995e8432741ee3986103f36), with
Debian's patches (1.1.2-1: the manual page and desktop file) as the
second commit. Branch team2/lmarbles-amiga. In Team 2's next ten it takes
XJump's place: XJump turned out to be an X11 (Xaw) program, not SDL.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the menu, New Game, puzzle 1-1 (a marble chosen and rolled with
the cursor keys, the clock running), Escape and its question back to the
menu, and Quit; user/lmarbles.conf and user/lmarbles.prf written. The lab
is muted, so the sounds were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the LMarbles icon, or run LMarbles from a Shell. Click a marble to
choose it, then roll it with the cursor keys; Escape leaves a level. Options on the menu has the controls, sound
and the look. The manual is manual/manual.html in the drawer. The level
sets, pictures and sounds are in data/; your settings and profile in
user/.


Building
--------

    make -f amiga/Makefile.amigaos dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers and the OpenGPU kit
(see the Makefile's head). The drawer is dist/LMarbles (and
dist/LMarbles.info).


What was changed
----------------

- src/cfg.c: the settings and profiles are in the drawer's user/ on
  AmigaOS (upstream: $HOME/.lmarbles). The data is PROGDIR:data (SRC_DIR).
- amiga/Makefile.amigaos builds src/Makefile.am's sources, with
  amiga/config.h for configure's (no gettext, so English).
- No SDL_mixer 1.2 for OpenGPU's SDL 1.2: the Team's amiga/sdl_mixer_lite.c
  (WAV, from the Hex-a-hop port) stands in. SDL_RWFromFile is plain stdio
  (amiga/amiga_rwops.c, -Wl,--wrap), as in the Hex-a-hop and Xye ports.
- amiga/stack.c: 256 KB of stack.


Licences
--------

LMarbles, its pictures, levels and sounds: GPL 2 or later (COPYING.txt).
The Amiga files (amiga/): the AmiCradle Team; the mixer and the rwops
come from the Team's Wizznic and Gigalomania ports and are GPL 3 or later,
so the program as built here is GPL 3 or later.
